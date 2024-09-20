/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
32. Write a program to implement semaphore to protect any critical section.
b. protect shared memory from concurrent write access
Date: 20/9/24
*/
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int semKey;
    int semIdentifier;
    int semctlStatus;
    int semopStatus;

    int shmKey;
    int shmIdentifier;
    int shmSize = 20;
    char *shmPointer;

    // Defines a semaphore's structure
    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
    } semSet;

    semKey = ftok(".", 't');
    if (semKey == -1)
    {
        perror("Error: ");
        exit(0);
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

        semSet.val = 1; // Set a binary semaphore
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            perror("Error: ");
            exit(0);
        }
    }

    shmKey = ftok(".", 3322);

    if (shmKey == -1)
    {
        perror("Error: ");
        exit(0);
    }

    shmIdentifier = shmget(shmKey, shmSize, IPC_CREAT | 0700); // Create the shared memory if it doesn't exist; if it exists use the existing one

    if (shmIdentifier == -1)
    {
        perror("Error: ");
        exit(0);
    }

    shmPointer = shmat(shmIdentifier, (void *)0, 0);

    if (*shmPointer == -1)
    {
        perror("Error: ");
        exit(0);
    }

    struct sembuf semOp;
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("Press enter to lock the critical section!\n");
    getchar();

    semOp.sem_op = -1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }

    printf("Critical Section is now locked!\n");

    printf("Start of the critical section!\n");

    /****start of critical section****/

    printf("Writing to the shared memory!\n");
    // Writing to the shared memory
    sprintf(shmPointer, "aks32b");

    printf("Press enter to read from the shared memory!\n");
    getchar();

    // Reading from the shared memory
    printf("%s\n", shmPointer);

    printf("Press enter to exit the critical section!\n");
    getchar();

    /****end of critical section*****/

    // Use semaphore to unlock the critical section
    semOp.sem_op = 1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error: ");
        exit(1);
    }

    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 32$ ./32b.out
Press enter to lock the critical section!

Critical Section is now locked!
Start of the critical section!
Writing to the shared memory!
Press enter to read from the shared memory!

aks32b
Press enter to exit the critical section!

aks@aks-Virtual-Machine:~/SS/Handson 2/question 32$
*/