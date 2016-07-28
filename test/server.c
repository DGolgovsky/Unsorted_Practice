#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>

#include <fcntl.h>
#include "set_nonblock.h" /* функция перевода в неблокирующий режим */

#define UNIXSTR_PATH "/tmp/database_socket"
#define TBLSIZE 21     /* размер таблицы */

/* типы ключа и значения */
typedef unsigned char uchar;
typedef uchar *KEY;
typedef uchar *VAL;

uchar *str_upd(const uchar *s) /* создание копии строки в "куче" */
{
	uchar *p =  (uchar *) malloc(strlen(s) + 1);
	strcpy(p, s);
	return p;
}

unsigned int hash; /* последнее вычисленное значение хэш-функции */

int HASHFUNC(KEY key)
{
	unsigned int i = 0;
	uchar *keysrc = key;
	while (*key) {
		i = (i << 1)|(i >> 15); /* ROL */
		i ^= *key++;
    }
	hash = i % TBLSIZE;
	/* printf("hash(%s)=%d\n", keysrc, hash);  /* отладка */
	return hash;
}

#define EQKEY(s1, s2)   (strcmp(s1, s2) == 0)
#define FREEKEY(s)      free(s)
#define FREEVAL(s)      free(s)
#define PUTVAL(at,s)    at = str_upd(s)
#define PUTKEY(at,s)    at = str_upd(s)
#define KEYFMT          "%s"
#define VALFMT          "%s"

struct cell
{
	struct cell *next;	/* ссылка на очередной элемент */
	KEY key;			/* ключ     */
	VAL val;			/* значение */
} *table[TBLSIZE];		/* таблица */

/* итератор */
struct celliter
{
	int index;
	struct cell *ptr;
};

/* выдать очередное значение */
struct cell *nextpair(struct celliter *ci)
{
	struct cell *result;
	while((result = ci->ptr) == NULL) {
		if(++(ci->index) >= TBLSIZE)
			return NULL;    /* больше нет */
		ci->ptr = table[ci->index];
	}
	ci->ptr = result->next;
	return result;
}

/* инициализация итератора */
struct cell *resetiter(struct celliter *ci)
{
	ci->index = (-1);
	ci->ptr = NULL;
    return nextpair(ci);  /* первое значение */
}

struct args
{
	uchar cmd[6];
	uchar key[BUFSIZ];
	uchar value[BUFSIZ];
};

/* получение значения по ключу */
struct cell *get(KEY key)
{
	struct cell *p;
	for (p = table[HASHFUNC(key)]; p; p = p->next)
		if (EQKEY(p->key, key))
			return p;
	return NULL;    /* отсутствует */
}

void cmd_GET(KEY key)
{
	struct cell *val;
	/* printf("GET: [%s]\n", key);  /* отладка */
	if ((val = get(key)) != NULL) { /* КЛЮЧ :найти значение */
		printf(VALFMT, val->val);
		putchar('\n');
	}
}
/* занести пару ключ:значение в таблицу */
void cmd_PUT(KEY key, VAL val)
{
	/* printf("PUT: [%s] [%s]\n", key, val);  /* отладка */
	
	struct cell *p;
	/* проверить - не было ли звена с таким ключом */
	if ((p = get(key)) == NULL) {       /* не было   */
		if(!(p = (struct cell *) malloc(sizeof(*p))))
			return;
        PUTKEY(p->key, key);
        p->next = table[hash]; /* hash вычислено в get() */
        table[hash] = p;
	} else /* уже было: изменить значение */
		FREEVAL(p->val);
	PUTVAL(p->val, val);
}

/* удаление по ключу */
void cmd_ERASE(KEY key)
{
	int indx = HASHFUNC(key);
	struct cell *p, *prev = NULL;
	if ((p = table[indx]) == NULL)
		return;
    for ( ;p ;prev = p, p = p->next)
		if (EQKEY(p->key, key)) {
			FREEVAL(p->val);
			FREEKEY(p->key);
			if (p == table[indx]) /* голова списка */
				table[indx] = p->next;
            else
				prev->next = p->next;
            free((void *)p); /* удален */
		}
}

/* распечатать пару ключ:значение */
void printcell(struct cell *ptr)
{
	printf( KEYFMT, ptr->key );
	putchar(' ');
	printf( VALFMT, ptr->val );
}

/* распечатка таблицы (для отладки) */
void cmd_LIST()
{
	struct celliter ci;
	struct cell *cl;

	for(cl = resetiter(&ci); cl; cl = nextpair(&ci))
		printcell(cl), putchar('\n');
}


void error(const char *msg)
{
	printf("[ERROR] %s\n", msg);
	return;
}

void work_with(int fd)
{
	struct args args;

	recv(fd, &args, sizeof(args), MSG_NOSIGNAL);

/* DEBUG */
/*	printf("<--Recv: [%s] [%s] [%s] [%d]\n",
		   args.cmd,
		   args.key,
		   args.value,
		   sizeof(args));
*/
	if (!strcmp(args.cmd, "list")) {
		cmd_LIST();
	} else if (!strcmp(args.cmd, "get")) {
		cmd_GET(args.key);
	} else if (!strcmp(args.cmd, "put")) {
		cmd_PUT(args.key, args.value);
	} else if (!strcmp(args.cmd, "erase")) {
		cmd_ERASE(args.key);
	} else {
		/* error("Unknown command or arguments"); */
	}
}

int main(void)
{
	unlink(UNIXSTR_PATH);

	struct args args;
	/**
	 * ls -s здесь используется для тестирования системы
	 */
	extern FILE *popen();    FILE *fp;
	fp = popen( "ls -s", "r" );
	while( fscanf( fp, "%s%s", args.value, args.key) == 2 )
		cmd_PUT(args.key, args.value);
	pclose(fp);

	int fd_server = socket(AF_LOCAL, SOCK_STREAM, 0);
	if (fd_server < 0)
		error("Socket");

	struct sockaddr_un server_addr;
	server_addr.sun_family = AF_LOCAL;
	strcpy(server_addr.sun_path, UNIXSTR_PATH);

	if (bind(fd_server,
			(struct sockaddr *)&server_addr,
			sizeof(server_addr)) == -1) {
		close(fd_server);
        error("Bind");
	}

	if (listen(fd_server, SOMAXCONN) == -1) {
		close(fd_server);
		error("Listen");
    }

	signal(SIGCHLD, SIG_IGN);

	while (1) {
		int fd_client = accept(fd_server, 0, 0);

		if (!fork()) {
            /* child process */
			close(fd_server);

			work_with(fd_client);

			close(fd_client);
            exit(0);
		}
        /* parent process */
		shutdown(fd_client, SHUT_RDWR);
        close(fd_client);
    }

    return 0;
}
