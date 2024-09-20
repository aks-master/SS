/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
29. Write a program to remove the message queue.
Date: 20/9/24
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int qKey;
    int qIdentifier;
    int msgctlStatus;

    qKey = ftok("..", 'p');

    if (qKey == -1)
    {
        perror("Error1: ");
        exit(0);
    }

    qIdentifier = msgget(qKey, IPC_CREAT | 0666);
    if (qIdentifier == -1)
    {
        perror("Error2: ");
        exit(0);
    }

    printf("Key: %d\n", qKey);
    printf("Message Queue Identifier: %d\n\n", qIdentifier);

    msgctlStatus = msgctl(qIdentifier, IPC_RMID, NULL);

    if (msgctlStatus == -1)
    {
        perror("Error3: ");
        exit(0);
    }
    return 0;
}
/*Output
***before program execution****

aks@aks-Virtual-Machine:~/SS/Handson 2/question 29$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x7a020854 0          aks        666        0            0
0x7a020856 1          aks        700        4128         4
0x70020856 2          aks        666        1032         1
0x7a020857 3          aks        700        0            0
0x70020857 4          aks        666        0            0
0x700206dd 5          aks        666        0            0
0x7a020858 6          aks        777        0            0

aks@aks-Virtual-Machine:~/SS/Handson 2/question 29$ gcc 29.c -o 29.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 29$ ./29.out
Key: 1879181021
Message Queue Identifier: 5

***after program execution****
aks@aks-Virtual-Machine:~/SS/Handson 2/question 29$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x7a020854 0          aks        666        0            0
0x7a020856 1          aks        700        4128         4
0x70020856 2          aks        666        1032         1
0x7a020857 3          aks        700        0            0
0x70020857 4          aks        666        0            0
0x7a020858 6          aks        777        0            0

aks@aks-Virtual-Machine:~/SS/Handson 2/question 29$ ^C
aks@aks-Virtual-Machine:~/SS/Handson 2/question 29$
 */