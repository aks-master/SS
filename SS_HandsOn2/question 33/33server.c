/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
33. Write a program to communicate between two machines using socket.
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

    ssize_t readBytes, writeBytes;
    char dataFromClient[100];

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        perror("Error: ");
        exit(0);
    }
    printf("Server side socket successfully created.\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    bindStatus = bind(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (bindStatus == -1)
    {
        perror("Error: ");
        exit(0);
    }
    printf("Binding to socket was successful.\n");

    listenStatus = listen(socketFileDescriptor, 2);
    if (listenStatus == -1)
    {
        perror("Error: ");
        exit(0);
    }
    printf("Now listening for connections on a socket.\n");

    clientSize = (int)sizeof(client);
    connectionFileDescriptor = accept(socketFileDescriptor, (struct sockaddr *)&client, &clientSize);
    if (connectionFileDescriptor == -1)
    {
        perror("Error: ");
        exit(0);
    }
    else
    {

        /****client server communication****/

        writeBytes = write(connectionFileDescriptor, "I'm the server.", 15);
        if (writeBytes == -1)
        {
            perror("Error: ");
            exit(0);
        }
        else
            printf("Data sent to client.\n");

        readBytes = read(connectionFileDescriptor, dataFromClient, 100);
        if (readBytes == -1)
        {
            perror("Error: ");
            exit(0);
        }
        else
            printf("Data from client: %s\n", dataFromClient);
    }

    close(connectionFileDescriptor);
    close(socketFileDescriptor);

    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 33$ ./33server.out
Server side socket successfully created.
Binding to socket was successful.
Now listening for connections on a socket.
Data sent to client.
Data from client: I'm the client.
aks@aks-Virtual-Machine:~/SS/Handson 2/question 33$
*/