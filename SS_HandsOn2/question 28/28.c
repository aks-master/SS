/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
28. Write a program to change the exiting message queue permission. (Use `msqid_ds` structure)
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
    key_t qKey;
    int qIdentifier;
    struct msqid_ds mqInfo;
    int msgctlStatus;

    qKey = ftok(".", 'z');

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

    printf("Key: %d\n", qKey);
    printf("Message Queue Identifier: %d\n\n", qIdentifier);

    msgctlStatus = msgctl(qIdentifier, IPC_STAT, &mqInfo);

    if (msgctlStatus == -1)
    {
        perror("Error: ");
        exit(0);
    }

    printf("Press enter to change the permissions!\n");
    getchar();

    mqInfo.msg_perm.mode = 0777;

    msgctlStatus = msgctl(qIdentifier, IPC_SET, &mqInfo);

    if (msgctlStatus == -1)
    {
        perror("Error: ");
        exit(0);
    }
    return 0;
}
/*Output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 28$ ./28.out
Key: 2046953560
Message Queue Identifier: 6

Press enter to change the permissions!

********ipcs -q output before pressing enter*******
aks@aks-Virtual-Machine:~/SS/Handson 2/question 28$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x7a020854 0          aks        666        0            0
0x7a020856 1          aks        700        4128         4
0x70020856 2          aks        666        1032         1
0x7a020857 3          aks        700        0            0
0x70020857 4          aks        666        0            0
0x700206dd 5          aks        666        0            0
0x7a020858 6          aks        666        0            0

*********after enter**********
aks@aks-Virtual-Machine:~/SS/Handson 2/question 28$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x7a020854 0          aks        666        0            0
0x7a020856 1          aks        700        4128         4
0x70020856 2          aks        666        1032         1
0x7a020857 3          aks        700        0            0
0x70020857 4          aks        666        0            0
0x700206dd 5          aks        666        0            0
0x7a020858 6          aks        777        0            0

aks@aks-Virtual-Machine:~/SS/Handson 2/question 28$
 */