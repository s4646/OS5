#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // bzero()
#include <sys/socket.h>
#include <unistd.h>  // read(), write(), close()

#define PORT 7777

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;
    int yes = 1, nbytes;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // lose the pesky "address already in use" error message
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("connected to the server..\n");

    char buff[256];
    bzero(buff, sizeof(buff));
    if ((nbytes = read(sockfd, buff, sizeof(buff))) == -1)
    {
        perror("Error: read");
        exit(EXIT_FAILURE);
    }
    if (nbytes == 0)
    {
        printf("Error: Connection refused: full capacity\n");
        exit(EXIT_FAILURE);
    }

    int n;
    while (true)
    {
        bzero(buff, sizeof(buff));
        printf("Enter string: ");
        n = 0;

        while((buff[n++] = getchar()) != '\n') continue;
        
        if ((strncmp(buff, "quit", 4)) == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
    }
    close(sockfd);

    return 0;
}