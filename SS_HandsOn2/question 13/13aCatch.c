/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 19/9/24
*/
#include <stdio.h>
#include <unistd.h>

int main()
{
    // sigstop cannot be caught
    printf("Process PID: %d\n", getpid());
    printf("Waiting for SIGSTOP (you can stop this process with 'kill -19 %d' in other terminal)\n", getpid());
    while (1)
        ;
    return 0;
}

/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 13$ ./13a.out
Process PID: 5283
Waiting for SIGSTOP (you can stop this process with 'kill -19 5283' in other terminal)

[1]+  Stopped                 ./13a.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 13$


*/