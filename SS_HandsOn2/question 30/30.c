/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 20/9/24
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int shmKey;
    int shmIdentifier;
    int shmSize = 20; // value of size rounded up to a multiple of PAGE_SIZE
    char *shmPointer, *rdOnlyShmPointer;

    shmKey = ftok(".", 'z');

    if (shmKey == -1)
    {
        perror("Error1: ");
        exit(0);
    }

    shmIdentifier = shmget(shmKey, shmSize, IPC_CREAT | 0700); // Create the shared memory if it doesn't exist; if it exists use the existing one

    if (shmIdentifier == -1)
    {
        perror("Error2: ");
        exit(0);
    }

    /****a****/
    shmPointer = shmat(shmIdentifier, (void *)0, 0);

    if (*shmPointer == -1)
    {
        perror("Error1: ");
        exit(0);
    }

    printf("A. Enter message to write to the shared memory! (10 chars max)\n");
    char msg[11];
    scanf("%s", msg);

    sprintf(shmPointer, msg); // Writing to the shared memory

    /****b****/

    rdOnlyShmPointer = shmat(shmIdentifier, (void *)0, SHM_RDONLY);
    if (*rdOnlyShmPointer == -1)
    {
        perror("Error2: ");
        exit(0);
    }

    printf("B. Press enter to read from the shared memory!\n");
    getchar();
    getchar();

    printf("Data from shared memory: %s\n", rdOnlyShmPointer); // Reading from the shared memory

    /****c****/
    printf("C.Detaching pointer to shared memory!\n");
    shmdt(shmPointer);       // Dettach pointer to Shared Memory
    shmdt(rdOnlyShmPointer); // Dettach pointer to Shared Memory

    /****d****/
    printf("D.Press enter to delete the shared memory!\n");
    getchar();

    // Delete Shared Memory
    shmctl(shmIdentifier, IPC_RMID, NULL);
    return 0;
}
/*Output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 30$ ./30.out
A. Enter message to write to the shared memory! (10 chars max)
aksd
B. Press enter to read from the shared memory!

Data from shared memory: aksd
C.Detaching pointer to shared memory!
D.Press enter to delete the shared memory!

aks@aks-Virtual-Machine:~/SS/Handson 2/question 30$
 */