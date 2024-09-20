/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
26. Write a program to send messages to the message queue. Check `ipcs -q`
Date: 20/9/24
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int qKey;
    int qIdentifier;
    int messageSendStatus;

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
    strcpy(data.msg, "hello AKS");

    messageSendStatus = msgsnd(qIdentifier, &data, sizeof(data), 0);

    if (messageSendStatus == -1)
    {
        perror("Error: ");
        exit(0);
    }

    printf("Message sent! Check using `ipcs -q`\n");
    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 26$ gcc 26.c -o 26.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 26$ ./26.out
Message sent! Check using `ipcs -q`
aks@aks-Virtual-Machine:~/SS/Handson 2/question 26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x70020856 2          aks        666        1032         1

aks@aks-Virtual-Machine:~/SS/Handson 2/question 26$
*/