#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define UNIXSTR_PATH "/tmp/database_socket"

struct args /* Структура для передачи на сервер */
{
	char first[BUFSIZ];
	char second[BUFSIZ];
	char third[BUFSIZ];
};

void error(const char *msg, unsigned char errno)
{
	perror(msg);
	exit(errno);
}

void work_with(int fd, char *argv[])
{
/*
  * LIST                 - Вывести список доступных ключей
  * GET   <key>          - Получить значение по ключу <key>
  * PUT   <key> <value>  - Добавить в базу запись с ключом <key> и значением <value>;
                           если такая запись уже существует, перезаписать её
  * ERASE <key>          - Удалить запись с ключом <key> из таблицы
*/
	struct args args;

	if(argv[1])
		strcat(args.first, argv[1]);
	if(argv[2])
		strcat(args.second, argv[2]);
	if(argv[3])
		strcat(args.third, argv[3]);

	send(fd, &args, sizeof(args), MSG_NOSIGNAL);

/* DEBUGGER */
	printf("-->Send: %s %s %s\n",
		   args.first,
		   args.second,
		   args.third);
}

int main(int argc, char *argv[])
{
	if (argc < 2 || argc > 4)
		error("Need some args: <cmd> <key> <value>\n", 1);

	int fd_socket = socket(AF_UNIX, SOCK_STREAM, 0);

	struct sockaddr_un sock_addr;
  	sock_addr.sun_family = AF_UNIX;
    strcpy(sock_addr.sun_path, UNIXSTR_PATH);

    int result = connect(fd_socket,
						 (struct sockaddr *)&sock_addr,
						 sizeof(sock_addr));
	if (result == -1)
		error("Can't connect to server\n", 1);

	work_with(fd_socket, argv);

	shutdown(fd_socket, SHUT_RDWR);
	close(fd_socket);

    return 0;
}
