#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#include <signal.h>

int main(int argc, char *argv[])
{
    /* int s = socket(domain, type, protocol)
     * domain:
     *  AF_INET - IPv4
     *  AF_INET6 - IPv6
     *  AF_UNIX - Unix Socket
     * type:
     *  SOCK_STREAM - TCP
     *  SOCK_DGRAM - UDP
     * protocol:
     *  0 - default
     *  IPPROTO_TCP
     *  IPPROTO_UDP
     *
     * bind (s, (struct sockaddr *)sa, sizeof(sa));
     *   struct sockaddr_in sa; <-- IPv4
     *   struct sockaddr_in6 sa; <-- IPv6
     *      sa.sin_family = AF_INET;
     *      sa.sin_port = htons(12345);
     *      sa.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
     *          INADDR_LOOPBACK (127.0.0.1)
     *          INADDR_ANY (0.0.0.0)
     *      ip = inet_addr("10.0.0.1") <-- Convert address string to int
     *           inet_pton(AF_INET, "10.0.0.1", &(sa.sin_addr));
     *
     *   struct sockaddr_un sa; <-- UNIX Socket
     *      sa.sun_family = AF_UNIX;
     *      strcpy(sa.sun_path, "/tmp/a.sock");
     *
     * listen (s, SOMAXCONN); // 128 default
     * while (s1 = accept(s, 0, 0)) {}
     *      1st 0 <-- struct sockaddr *
     *      2nd 0 <-- size *
     *
     * size_t read (int fd, void *buf, size_t count);
     *        recv (.., .., .., int flags);
     * size_t write (int fd, const void *buf, size_t count);
     *        send (.., .., .., int flags);
     *      SIGPIPE <-- Sys error
     *      signal(SIGPIPE, SIG_IGN) - ignoring
     *  flags:
     *      MSG_NOSIGNAL
     * */
	unlink("/tmp/database.socket");
    int MasterSocket = socket( // Дескриптор сокета
            AF_UNIX /* UNIX */,
            SOCK_STREAM /* TCP */,
            0);

    struct sockaddr_un SockAddr;
    SockAddr.sun_family = AF_UNIX;
    strcpy(SockAddr.sun_path, "/tmp/database.socket");
    bind(MasterSocket, (struct sockaddr *)(&SockAddr), sizeof(SockAddr));

    listen(MasterSocket, SOMAXCONN);
	signal(SIGCHLD, SIG_IGN);

    while(1) {
		char Buffer[BUFSIZ] = " ";
		printf("Server waiting...\n");
        int SlaveSocket = accept(MasterSocket, 0, 0);
		if (fork() == 0) {
			recv(SlaveSocket, Buffer, sizeof(Buffer), MSG_NOSIGNAL);
			printf("Recieved from client: %s\n", Buffer);
			shutdown(SlaveSocket, SHUT_RDWR);
			close(SlaveSocket);
		}
        //send(SlaveSocket, Buffer, sizeof(Buffer), MSG_NOSIGNAL);
        
    }

    return 0;
}

