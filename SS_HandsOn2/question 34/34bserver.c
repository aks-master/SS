/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
34. Write a program to create a concurrent server.
b. use pthread_create
Date: 20/9/24
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
void communicate(int *fd)
{
    ssize_t readBytes, writeBytes;
    char dataFromClient[100];
    writeBytes = write(*fd, "I'm server", 11);
    if (writeBytes == -1)
    {
        perror("Error: ");
        exit(0);
    }
    else
    {
        perror("Error: ");
        exit(0);
    }
    readBytes = read(*fd, dataFromClient, 100);
    if (readBytes == -1)
    {
        perror("Error: ");
        exit(0);
    }
    else
        printf("Data from client: %s\n", dataFromClient);
    close(*fd);
}

int main()
{
    int socketFileDescriptor, connectionFileDescriptor;
    int bindStatus;
    int listenStatus;
    int clientSize;

    struct sockaddr_in address, client;

    pthread_t threadID;

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
        perror("Error: ");
        exit(0);
    }
    printf("listening for connections.....\n");

    while (1)
    {
        clientSize = (int)sizeof(client);
        connectionFileDescriptor = accept(socketFileDescriptor, (struct sockaddr *)&client, &clientSize);
        if (connectionFileDescriptor == -1)
        {
            perror("Error: ");
            exit(0);
        }
        else
        {
            if (pthread_create(&threadID, NULL, (void *)communicate, &connectionFileDescriptor))
            {
                perror("Error: ");
                exit(0);
            }
        }
    }
    close(socketFileDescriptor);
    return (0);
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 34$ ./34bserver.out
listening for connections.....
Error: : Success
aks@aks-Virtual-Machine:~/SS/Handson 2/question 34$
 */