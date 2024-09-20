/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
32. Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore
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
    char *filename = "./32c.txt";

    int fileDescriptor;
    int readBytes;
    int lseekOffset;
    char data[1024];

    int semKey;
    int semIdentifier;
    int semctlStatus;
    int semopStatus;

    fileDescriptor = open(filename, O_RDONLY);
    if (fileDescriptor == -1)
    {
        perror("Error: ");
        exit(0);
    }

    // Defines a semaphore's structure
    union semun
    {
        int val;
    } semSet;

    semKey = ftok(".", 'u');
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

        semSet.val = 2; // Set a counting semaphore
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            perror("Error: ");
            exit(0);
        }
    }

    struct sembuf semOp; // Defines the operation on the semaphore
    semOp.sem_num = 0;
    semOp.sem_flg = IPC_NOWAIT;

    printf("Press enter to obtain lock for the critical section!\n");
    getchar();

    // Use semaphore to lock the critical section
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

    readBytes = read(fileDescriptor, &data, 1000);
    if (readBytes == -1)
    {
        perror("Error: ");
        exit(0);
    }
    else if (readBytes == 0) // Sample file has no data
        printf("file is empty!\n");
    else
        printf("file contents: \n %s", data);

    printf("\n\nPress enter key to exit critical section!\n");
    getchar();

    // =========== End of Critical Section =============

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
/*output
execution 1
aks@aks-Virtual-Machine:~/SS/Handson 2/question 32$ ./32c.out
Press enter to obtain lock for the critical section!

Obtained lock on critical section!
Now entering critical section!
file contents:
 data stored in 32c.txt

Press enter key to exit critical section!

execution 2
aks@aks-Virtual-Machine:~/SS/Handson 2/question 32$ ./32c.out
Press enter to obtain lock for the critical section!

Obtained lock on critical section!
Now entering critical section!
file contents:
 data stored in 32c.txt

Press enter key to exit critical section!

execution 3
aks@aks-Virtual-Machine:~/SS/Handson 2/question 32$ ./32c.out
Press enter to obtain lock for the critical section!

Error: : Resource temporarily unavailable
aks@aks-Virtual-Machine:~/SS/Handson 2/question 32$

as semaphore value is 2 only 2 programs can access critical section at a time

*/