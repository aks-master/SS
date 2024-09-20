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
    int socketFileDescriptor;
    int connectStatus;
    struct sockaddr_in address;
    ssize_t readBytes, writeBytes;
    char dataFromServer[1024];

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        perror("Error: ");
        exit(0);
    }
    printf("Client side socket successfully created.\n");

    // Defined server's details
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    connectStatus = connect(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (connectStatus == -1)
    {
        perror("Error: ");
        exit(0);
    }
    printf("Client to server connection successfully established.\n");

    /****client server communication****/

    readBytes = read(socketFileDescriptor, dataFromServer, 100);
    ;
    if (readBytes == -1)
    {
        perror("Error: ");
        exit(0);
    }
    else
        printf("Data from server: %s\n", dataFromServer);

    writeBytes = write(socketFileDescriptor, "I'm the client.", 15);
    if (writeBytes == -1)
    {
        perror("Error: ");
        exit(0);
    }
    else
        printf("Data sent to server.\n");

    close(socketFileDescriptor);
    return 0;
}
/*output
***first run 32c.out***
aks@aks-Virtual-Machine:~/SS/Handson 2/question 33$ ./33client.out
Client side socket successfully created.
Client to server connection successfully established.
Data from server: I'm the server.
Data sent to server.
aks@aks-Virtual-Machine:~/SS/Handson 2/question 33$
*/