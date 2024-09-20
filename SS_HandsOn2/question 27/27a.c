/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
27. Write a program to receive messages from the message queue.
a. with 0 as a flag
Date: 20/9/24
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    key_t qKey;
    int qIdentifier;
    ssize_t messageSize;

    struct msgbuf
    {
        long mtype;
        char msg[1024];
    } data;

    qKey = ftok("..", 'p');

    if (qKey == -1)
    {
        perror("Error: ");
        exit(0);
    }

    qIdentifier = msgget(qKey, IPC_CREAT | 0666);

    if (qIdentifier == -1)
    {
        perror("Error: ");
        exit(0);
    }

    data.mtype = 1;
    strcpy(data.msg, "Hello AKS");
    messageSize = msgrcv(qIdentifier, &data, sizeof(data), data.mtype, 0); // 0 as flag

    if (messageSize == -1)
    {
        perror("Error: ");
        exit(0);
    }

    printf("Received data: %s\n", data.msg);
    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 27$ ./27a.out
Received data: hello AKS
aks@aks-Virtual-Machine:~/SS/Handson 2/question 27$
*/
