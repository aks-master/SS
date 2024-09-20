/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 20/9/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

struct message
{
    long msg_type;   // Message type
    char text[1024]; // Message text
};

int main()
{
    key_t key;
    int msqid;
    key = ftok(".", 'z');
    if (key == -1)
    {
        perror("ftok");
        exit(0);
    }
    msqid = msgget(key, IPC_CREAT | 0666);
    if (msqid == -1)
    {
        perror("msgget");
        exit(0);
    }
    struct msqid_ds msg_info;
    if (msgctl(msqid, IPC_STAT, &msg_info) == -1)
    {
        perror("msgctl");
        exit(0);
    }

    /*print info*/
    printf("A.Access Permissions: %o\n", msg_info.msg_perm.mode);
    printf("B.Owner UID: %d\n", msg_info.msg_perm.uid);
    printf("B.Owner GID: %d\n", msg_info.msg_perm.gid);
    printf("C.Time of Last Message Sent: %ld\n", msg_info.msg_stime);
    printf("C.Time of Last Message Received: %ld\n", msg_info.msg_rtime);
    printf("D.Time of Last Change: %ld\n", msg_info.msg_ctime);
    printf("E.Size of the Queue (bytes): %lu\n", msg_info.__msg_cbytes);
    printf("F.Number of Messages in the Queue: %lu\n", msg_info.msg_qnum);
    printf("G.Maximum Number of Bytes Allowed: %lu\n", msg_info.msg_qbytes);
    printf("H.PID of Last msgsnd: %d\n", msg_info.msg_lspid);
    printf("H.PID of Last msgrcv: %d\n", msg_info.msg_lrpid);
    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 25$ gcc 25.c -o 25.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 25$ ./25.out
A.Access Permissions: 666
B.Owner UID: 1000
B.Owner GID: 1000
C.Time of Last Message Sent: 1726810325
C.Time of Last Message Received: 1726810325
D.Time of Last Change: 1726810325
E.Size of the Queue (bytes): 0
F.Number of Messages in the Queue: 0
G.Maximum Number of Bytes Allowed: 16384
H.PID of Last msgsnd: 10208
H.PID of Last msgrcv: 10208
*/