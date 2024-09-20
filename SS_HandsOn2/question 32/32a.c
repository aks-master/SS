/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
Date: 20/9/24
*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ticketDB = "./ticketDB.txt";
    int fileDescriptor;
    int readBytes;
    int lseekOffset;
    int data;

    int semKey;
    int semIdentifier;
    int semctlStatus;
    int semopStatus;

    fileDescriptor = open(ticketDB, O_CREAT | O_RDWR, S_IRWXU);
    if (fileDescriptor == -1)
    {
        perror("Error: ");
        exit(0);
    }

    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
    } semSet;

    semKey = ftok(".", 's');
    if (semKey == -1)
    {
        perror("Error: ");
        exit(1);
    }

    semIdentifier = semget(semKey, 1, 0);
    if (semIdentifier == -1)
    {
        semIdentifier = semget(semKey, 1, IPC_CREAT | 0700);
        if (semIdentifier == -1)
        {
            perror("Error: ");
            exit(0);
        }

        semSet.val = 1;
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            perror("Error: ");
            exit(0);
        }
    }

    struct sembuf semOp;
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("Press enter to obtain lock on the critical section\n");
    getchar();
    semOp.sem_op = -1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error: ");
        exit(0);
    }

    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");
    /****start of critical section****/

    readBytes = read(fileDescriptor, &data, sizeof(data));
    if (readBytes == -1)
    {
        perror("Error: ");
        exit(0);
    }
    else if (readBytes == 0) // Ticket file has no data
        data = 1;
    else
    {
        data += 1;
        lseekOffset = lseek(fileDescriptor, 0, SEEK_SET);
        if (lseekOffset == -1)
        {
            perror("Error: ");
            exit(0);
        }
    }

    if (write(fileDescriptor, &data, sizeof(data)) == -1)
    {
        perror("Error: ");
        exit(0);
    }

    printf("Your ticker number is %d\n", data);

    printf("Press enter to exit from critical section!\n");
    getchar();

    /****end of critical section****/

    // Use semaphore to unlock the critical section
    semOp.sem_op = 1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error: ");
        exit(0);
    }
    close(fileDescriptor);
    return 0;
}
/*Output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 32$ gcc 32a.c -o 32a.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 32$ ./32a.out
Press enter to obtain lock on the critical section

Obtained lock on critical section!
Now entering critical section!
Your ticker number is 3
Press enter to exit from critical section!

aks@aks-Virtual-Machine:~/SS/Handson 2/question 32$
 */