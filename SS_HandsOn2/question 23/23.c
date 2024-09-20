/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
23.Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
Date: 20/9/24
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    int fifoStatus;
    long filelimit;
    long pipesize;

    char *fifoName = "fifo_23";
    fifoStatus = mkfifo(fifoName, S_IRWXU);

    if (!(errno == EEXIST || fifoStatus != -1))
        perror("Error while creating FIFO file!");
    else
    {
        filelimit = sysconf(_SC_OPEN_MAX);

        if (filelimit == -1)
        {
            perror("Error: ");
            exit(0);
        }
        else
            printf("Maximum number of files that can be opened is: %ld\n", filelimit);

        pipesize = pathconf(fifoName, _PC_PIPE_BUF);

        if (pipesize == -1)
        {
            perror("Error: ");
            exit(0);
        }
        else
            printf("Maximum size of pipe: %ld\n", pipesize);
    }
    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 23$ gcc 23.c -o 23.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 23$ ./23.out
Maximum number of files that can be opened is: 1048576
Maximum size of pipe: 4096
aks@aks-Virtual-Machine:~/SS/Handson 2/question 23$
*/
