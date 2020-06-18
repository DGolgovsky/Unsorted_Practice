#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define UNIXSTR_PATH "/tmp/database_socket"

typedef unsigned char uchar;

#pragma pack(push, 1) /* отмена выравнивания */
struct args /* Структура для передачи на сервер */
{
	uchar cmd[6];
	uchar key[BUFSIZ];
	uchar value[BUFSIZ];
};
#pragma pack(pop)

void to_lower(uchar *str) {
	while (*str) {
		if (*str >= 'A' && *str <= 'Z') {
			*str = *str + 32;
		}
		str++;
	}
}

void error(const char *msg) {
	printf("[ERROR] %s\n", msg);
	exit(1);
}

void work_with(struct args *args, char **argv) {
/*
  * LIST                 - Вывести список доступных ключей
  * GET   <key>          - Получить значение по ключу <key>
  * PUT   <key> <value>  - Добавить в базу запись с ключом <key> и значением <value>;
                           если такая запись уже существует, перезаписать её
  * ERASE <key>          - Удалить запись с ключом <key> из таблицы
*/
	int last = 0;
	if (argv[1]) {
		to_lower(argv[1]);
		last = strlen(argv[1]);
		argv[1][last] = '\0';
		strcpy(args->cmd, argv[1]);
		if (!strcmp(argv[1], "put")) {                /* если PUT */
			if (!argv[2] || !argv[3])
				error("Need <key> and <value>");
		} else if (!strcmp(argv[1], "get")            /* если GET */
				   || !strcmp(argv[1], "erase")) {            /* или ERASE */
			if (!argv[2])
				error("Need <key>");
		} else if (strcmp(args->cmd, "list")) {
			error("Unknown command");
		}
		if (argv[2]) {
			last = strlen(argv[2]);
			argv[2][last] = '\0';
			strcpy(args->key, argv[2]);
		}
		if (argv[3]) {
			last = strlen(argv[3]);
			argv[3][last] = '\0';
			strcpy(args->value, argv[3]);
		}
	} else
		error("Unknown arguments");
}

int main(int argc, char *argv[]) {
	struct args args;

	if (argc < 2 || argc > 4)
		error("Use with args: <cmd> <key> <value>");

	int fd_socket = socket(AF_UNIX, SOCK_STREAM, 0);

	work_with(&args, argv);

	struct sockaddr_un sock_addr;
	sock_addr.sun_family = AF_UNIX;
	strcpy(sock_addr.sun_path, UNIXSTR_PATH);

	int result = connect(fd_socket,
						 (struct sockaddr *) &sock_addr,
						 sizeof(sock_addr));
	if (result == -1)
		error("Connect to server");

	send(fd_socket, (char *) &args, sizeof(args), MSG_NOSIGNAL);

/* DEBUGGER */
/*	printf("-->Send: [%s] [%s] [%s]\n",
		   args.cmd,
		   args.key,
		   args.value);
*/
	shutdown(fd_socket, SHUT_RDWR);
	close(fd_socket);

	return 0;
}
