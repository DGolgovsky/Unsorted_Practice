#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>

#include <fcntl.h>

int main(int argc, char *argv[])
{
    unlink("/tmp/database.socket");
  	int fd_server = socket(AF_LOCAL, SOCK_STREAM, 0);
    if(fd_server < 0) {
        perror("Socket");
        exit(1);
    }

    struct sockaddr_un server_addr;
    server_addr.sun_family = AF_LOCAL;
    strcpy(server_addr.sun_path, "/tmp/database.socket");

    if(bind(fd_server,
            (struct sockaddr *)&server_addr,
            sizeof(server_addr)) == -1) {
        perror("Bind");
        close(fd_server);
        exit(1);
    }

    if(listen(fd_server, SOMAXCONN) == -1) {
        perror("Listen");
        close(fd_server);
        exit(1);
    }

	signal(SIGCHLD, SIG_IGN);
	char buffer[BUFSIZ] = {};

    while(1) {
		int fd_client = accept(fd_server, 0, 0);
        
//		printf("Server waiting...\n");

		if (!fork()) {
            /* child process */
			close(fd_server);
            memset(buffer, 0, BUFSIZ);
			recv(fd_client, buffer, sizeof(buffer), MSG_NOSIGNAL);
			printf("Recieve from client: %s\n", buffer);
/*
			send(fd_client, buffer, sizeof(buffer), MSG_NOSIGNAL);
			printf("Send to client: %s\n", buffer);
*/
            if(!strcmp(buffer, "PUT")) {
                int fd_db = open("./db", O_RDWR);
                printf("Command: PUT\n");
                close(fd_db);
            } else if(!strcmp(buffer, "GET")) {
                int fd_db = open("./db", O_RDWR);
                printf("Command: GET\n");
                close(fd_db);
            }
			close(fd_client);
//            printf("Closing..\n");
            exit(0);
		}
        /* parent process */
		shutdown(fd_client, SHUT_RDWR);
        close(fd_client);
    }

    return 0;
}

