/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
24. Write a program to create a message queue and print the key and message queue id.
Date: 20/9/24
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    int qKey;
    int qIdentifier;

    qKey = ftok(".", 'z');

    if (qKey == -1)
    {
        perror("Error: ");
        exit(0);
    }

    qIdentifier = msgget(qKey, IPC_CREAT | IPC_EXCL | 0666);
    if (qIdentifier == -1)
    {
        perror("Error: ");
        exit(0);
    }

    printf("Key: %d\n", qKey);
    printf("Message Queue Identifier: %d\n", qIdentifier);
    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 24$ gcc 24.c -o 24.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 24$ ./24.out
Key: 2046953556
Message Queue Identifier: 0
aks@aks-Virtual-Machine:~/SS/Handson 2/question 24$
*/
