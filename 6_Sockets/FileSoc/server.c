#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

// Path Length Limits: UNIX domain socket paths have a maximum length (typically UNIX_PATH_MAX, often 108 bytes). If the path exceeds this limit, the creation will fail.
#define SOCKET_NAME "/home/skif/server.soc"
#define BUF_SIZE 256

static int sfd;

void cleanup_socket(int sockfd)
{
    close(sockfd);
    unlink(SOCKET_NAME);
}

void sighandler(int signum)
{
    cleanup_socket(sfd);
    exit(0);
}

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0); // Set stdout to unbuffered (for logging)
    unlink(SOCKET_NAME);
    
    // Создание сокета (флаг AF_UNIX - файловый сокет)
    sfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sfd == -1)
    {
        perror("socket call error");
        return errno;
    } 
    printf("socket created\n");
    
    struct sockaddr_un sock_addr;
    sock_addr.sun_family = AF_UNIX;
    
    strncpy(sock_addr.sun_path, SOCKET_NAME, sizeof(sock_addr.sun_path) - 1);
    if (bind(sfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1)
    {
        perror("bind call error");
        cleanup_socket(sfd);
        return errno;
    }
    printf("Socket bound successfully to %s\n", SOCKET_NAME);
    
    if (signal(SIGINT, sighandler) == SIG_ERR)
    {
        perror("signal call error");
        cleanup_socket(sfd);
        return errno;
    }
    
    char msg[BUF_SIZE];
    for(;;)
    {
        size_t bytes = recv(sfd, msg, sizeof(msg) - 1, 0);
        if (bytes == -1)
        {
            perror("recv call error");
            cleanup_socket(sfd);
            return errno;
        }
        msg[bytes] = '\0';
        printf("Got message: %s\n", msg);
    }
    
    return 0;
}
