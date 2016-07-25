#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>

#include <fcntl.h>

#define UNIXSTR_PATH "/tmp/database_socket"

struct args
{
	char cmd[BUFSIZ];
	char key[BUFSIZ];
	char value[BUFSIZ];
};

void error(const char *msg, unsigned char errno)
{
	perror(msg);
	exit(errno);
}

void cmd_LIST()
{
	printf("Command: LIST\n");
}

void cmd_GET(const char *key)
{
	printf("Command: GET\n");
}

void cmd_PUT(const char *key, const char *value)
{
	printf("Command: PUT\n");
}

void cmd_ERASE(const char *key)
{
	printf("Command: ERASE\n");
	int fd_db = open("./db", O_RDWR);
	close(fd_db);
}

void work_with(int fd)
{
/*
  * LIST                 - Вывести список доступных ключей
  * GET   <key>          - Получить значение по ключу <key>
  * PUT   <key> <value>  - Добавить в базу запись с ключом <key> и значением <value>;
                           если такая запись уже существует, перезаписать её
  * ERASE <key>          - Удалить запись с ключом <key> из таблицы
*/
	struct args args;
	recv(fd, &args, sizeof(args), MSG_NOSIGNAL);

	if(!strcmp(args.cmd, "LIST"))
		cmd_LIST();
	else if(!strcmp(args.cmd, "GET"))
		cmd_GET(args.key);
	else if(!strcmp(args.cmd, "PUT"))
		cmd_PUT(args.key, args.value);
	else if(!strcmp(args.cmd, "ERASE"))
		cmd_ERASE(args.key);
	else
		printf("Unknown command.\n");
}

int main(int argc, char *argv[])
{
    unlink(UNIXSTR_PATH);

  	int fd_server = socket(AF_LOCAL, SOCK_STREAM, 0);
    if(fd_server < 0)
		error("Socket error\n", 1);

	struct sockaddr_un server_addr;
    server_addr.sun_family = AF_LOCAL;
    strcpy(server_addr.sun_path, UNIXSTR_PATH);

    if(bind(fd_server,
            (struct sockaddr *)&server_addr,
            sizeof(server_addr)) == -1) {
        close(fd_server);
        error("Bind error\n", 1);
    }

    if(listen(fd_server, SOMAXCONN) == -1) {
        close(fd_server);
        error("Listen error\n", 1);
    }

	signal(SIGCHLD, SIG_IGN);

    while(1) {
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
