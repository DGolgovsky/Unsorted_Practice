#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main(int argc, char *argv[])
{
    /*
     * connect (int fd, struct sockaddr *, size_t);
     *
     * // Close connection:
     * shutdown(s, [SHUT_RDWR <-->
     *              SHUT_RD   ---> read
     *              SHUT_WR   <--- write
     *              ]);
     * close(s);
     * */

    int Socket = socket(AF_UNIX, SOCK_STREAM, 0);

    struct sockaddr_un SockAddr;
    SockAddr.sun_family = AF_UNIX;
    strcpy(SockAddr.sun_path, "/tmp/database.socket");
    int result = connect(Socket, (struct sockaddr *)(&SockAddr), sizeof(SockAddr));
	if (result == -1) {
		perror("Can't connect to server.\n");
		exit(1);
	}
    char *Buffer = NULL;

    while (--argc > 0) {
        Buffer = *++argv;

        send(Socket, Buffer, strlen(Buffer), MSG_NOSIGNAL);
        //recv(Socket, Buffer, strlen(Buffer), MSG_NOSIGNAL);
        printf("send: [%i]%s\n", strlen(Buffer), Buffer);
    }
    shutdown(Socket, SHUT_RDWR);
    close(Socket);

    return 0;
}

