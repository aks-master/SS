/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
34. Write a program to create a concurrent server.
a. use fork
Date: 20/9/24
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int socketFileDescriptor, connectionFileDescriptor;
    int bindStatus;
    int listenStatus;
    int clientSize;
    struct sockaddr_in address, client;
    int readBytes, writeBytes;
    char dataFromClient[1024];
    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        perror("Error: ");
        exit(0);
    }
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    bindStatus = bind(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (bindStatus == -1)
    {
        perror("Error: ");
        exit(0);
    }
    listenStatus = listen(socketFileDescriptor, 2);
    if (listenStatus == -1)
    {
        perror("Error while listening for connections");
        exit(0);
    }
    printf("listening for connections...\n");
    while (1)
    {
        clientSize = (int)sizeof(client);
        connectionFileDescriptor = accept(socketFileDescriptor, (struct sockaddr *)&client, &clientSize);
        if (connectionFileDescriptor == -1)
            perror("Error while accepting a connection");
        else
        {
            if (fork() == 0)
            {
                writeBytes = write(connectionFileDescriptor, "I'm the server", 15);
                if (writeBytes == -1)
                    perror("Error while writing to network via socket");
                else
                    printf("Data sent to client\n");

                readBytes = read(connectionFileDescriptor, dataFromClient, 100);
                if (readBytes == -1)
                    perror("Error while reading from network via socket");
                else
                    printf("Data from client: %s\n", dataFromClient);
            }
            else
            {
                close(connectionFileDescriptor);
            }
        }
    }

    close(socketFileDescriptor);
    return (0);
}
/*Output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 34$ gcc 34aserver.c -o 34aserver.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 34$ ./34aserver.out
listening for connections...
Data sent to client
Data from client: I'm client
Data sent to client
Data from client: I'm client
^C
aks@aks-Virtual-Machine:~/SS/Handson 2/question 34$
 */