/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 19/9/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <PID>\n", argv[0]);
        return 0;
    }

    int pid = atoi(argv[1]);
    if (kill(pid, SIGSTOP) == -1)
    {
        perror("Failed to send SIGSTOP");
        return 0;
    }

    printf("Sent SIGSTOP to process %d\n", pid);
    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 13$ ./13b.out 5283
Sent SIGSTOP to process 5283
aks@aks-Virtual-Machine:~/SS/Handson 2/question 13$
*/
