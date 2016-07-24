#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main(int argc, char *argv[])
{
	int fd_socket = socket(AF_UNIX, SOCK_STREAM, 0);

	struct sockaddr_un sock_addr;
  	sock_addr.sun_family = AF_UNIX;
    strcpy(sock_addr.sun_path, "/tmp/database.socket");

    int result = connect(fd_socket,
						 (struct sockaddr *)&sock_addr,
						 sizeof(sock_addr));
	if (result == -1) {
		perror("Can't connect to server.\n");
		exit(1);
	}

	char *buffer = NULL;
	char b[16];
    while (/*--argc > 0*/1) {
		buffer = *++argv;

		scanf ("%s",b);
//		send(fd_socket, buffer, strlen(buffer), MSG_NOSIGNAL);
		send(fd_socket, b, sizeof(b), MSG_NOSIGNAL);
		printf("-->Send: [%d]%s\n", sizeof(b), b);
//		printf("-->Send: [%d]%s\n", strlen(buffer), buffer);
/*
		recv(fd_socket, buffer, strlen(buffer), MSG_NOSIGNAL);
		printf("<--Recv: [%d]%s\n", strlen(buffer), buffer);
*/
	}

	shutdown(fd_socket, SHUT_RDWR);
	close(fd_socket);

    return 0;
}

