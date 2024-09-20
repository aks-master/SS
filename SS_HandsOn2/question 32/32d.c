/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
32. Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore
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
    int semKey;
    int semIndentifier;
    int semctlStatus;

    semKey = ftok(".", 'u');
    if (semKey == -1)
    {
        perror("Error: ");
        exit(0);
    }

    semIndentifier = semget(semKey, 1, 0); // deleting semaphore obtained in 32c

    if (semIndentifier == -1)
    {
        perror("Error : ");
        exit(0);
    }

    printf("Press enter to delete the semaphore!\n");
    getchar();

    semctlStatus = semctl(semIndentifier, 0, IPC_RMID);

    if (semctlStatus == -1)
    {
        perror("Error: ");
        exit(0);
    }
    printf("Semaphore deleted successfully.\n");
    return 0;
}
/*output
***first run 32c.out***
aks@aks-Virtual-Machine:~/SS/Handson 2/question 32$ ./32d.out
Press enter to delete the semaphore!

Semaphore deleted successfully.
aks@aks-Virtual-Machine:~/SS/Handson 2/question 32$
*/