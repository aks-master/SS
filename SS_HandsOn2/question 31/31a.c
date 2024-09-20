/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
Date: 20/9/24
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    key_t semKey;
    int semIndentifier;
    int semctlStatus;

    union semun
    {
        int val; // Value of the semaphore
    } semSet;

    semKey = ftok(".", 'z');
    if (semKey == -1)
    {
        perror("Error1: ");
        exit(0);
    }

    semIndentifier = semget(semKey, 1, IPC_CREAT | 0777);

    if (semIndentifier == -1)
    {
        perror("Error2: ");
        exit(0);
    }

    semSet.val = 1; // 1 -> binary semaphore

    semctlStatus = semctl(semIndentifier, 0, SETVAL, semSet);

    if (semctlStatus == -1)
    {
        perror("Error3: ");
        exit(1);
    }
    printf("binary semaphore created successfully.\n");
    return 0;
}
/*Output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 31$ gcc 31a.c -o 31a.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 31$ ./31a.out
binary semaphore created successfully.
aks@aks-Virtual-Machine:~/SS/Handson 2/question 31$
 */