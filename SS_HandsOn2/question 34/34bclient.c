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
#include <stdlib.h>

int main()
{
    int socketFileDescriptor;
    int connectStatus;
    struct sockaddr_in address;
    int readBytes, writeBytes;
    char dataFromServer[100];
    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        perror("Error: ");
        exit(0);
    }
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    connectStatus = connect(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (connectStatus == -1)
    {
        perror("Error ");
        exit(0);
    }
    readBytes = read(socketFileDescriptor, dataFromServer, 100);
    if (readBytes == -1)
    {
        perror("Error ");
        exit(0);
    }
    else
        printf("Data from server: %s\n", dataFromServer);
    writeBytes = write(socketFileDescriptor, "I'm client", 11);
    if (writeBytes == -1)
    {
        perror("Error ");
        exit(0);
    }
    else
        printf("Data sent to server\n");
    getchar();
    close(socketFileDescriptor);
    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 34$ gcc 34bclient.c -o 34bclient.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 34$ ./34bclient.out
Data from server: I'm server
Data sent to server

aks@aks-Virtual-Machine:~/SS/Handson 2/question 34$
 */