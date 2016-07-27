#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define UNIXSTR_PATH "/tmp/database_socket"

typedef unsigned char uchar;

struct args /* Структура для передачи на сервер */
{
	//TODO pointers
	uchar cmd[5];
	uchar key[BUFSIZ];
	uchar value[BUFSIZ];
};

void to_lower(char *str)
{
   while(*str)
   {
      if ( *str >= 'A' && *str <= 'Z' )
      {
         *str = *str + 32;
      }
      str++;
   }
}

void error(const char *msg)
{
	printf("[ERROR] %s\n", msg);
	exit(1);
}

void work_with(struct args *args, char *argv[])
{
/*
  * LIST                 - Вывести список доступных ключей
  * GET   <key>          - Получить значение по ключу <key>
  * PUT   <key> <value>  - Добавить в базу запись с ключом <key> и значением <value>;
                           если такая запись уже существует, перезаписать её
  * ERASE <key>          - Удалить запись с ключом <key> из таблицы
*/
	if(argv[1]) {
		to_lower(argv[1]);
		strcat(args->cmd, argv[1]);
		if(!strcmp(args->cmd, "put")) {				/* если PUT */
			if (!argv[2] || !argv[3])				/* и нет ключ-значение */
				error("Need <key> and <value>");
		} else if(!strcmp(args->cmd, "get")			/* если GET */
		   || !strcmp(args->cmd, "erase")) {		/* или ERASE */
			if (!argv[2])							/* и нет ключа */
				error("Need <key>");
		} else if (strcmp(args->cmd, "list")) {
			error("Unknown command");
		}
		if(argv[2])
			strcat(args->key, argv[2]);
		if(argv[3])
			strcat(args->value, argv[3]);
	} else
		error("Unknown arguments");
}

int main(int argc, char *argv[])
{
	struct args args;

	if (argc < 2 || argc > 4)
		error("Use with args: <cmd> <key> <value>");

	int fd_socket = socket(AF_UNIX, SOCK_STREAM, 0);

	work_with(&args, argv);

	struct sockaddr_un sock_addr;
  	sock_addr.sun_family = AF_UNIX;
    strcpy(sock_addr.sun_path, UNIXSTR_PATH);

    int result = connect(fd_socket,
						 (struct sockaddr *)&sock_addr,
						 sizeof(sock_addr));
	if (result == -1)
		error("Connect to server");

	send(fd_socket, &args, sizeof(args), MSG_NOSIGNAL);

/* DEBUGGER */
	printf("-->Send: %s %s %s\n",
		   args.cmd,
		   args.key,
		   args.value);

	shutdown(fd_socket, SHUT_RDWR);
	close(fd_socket);

    return 0;
}
