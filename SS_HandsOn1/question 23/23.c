/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
23 -> Write a program to create a Zombie state of the running program.
Date: 31/8/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int rt = fork();

    if (rt == 0) {
        // Child process
        printf("Child process (PID: %d) exiting...\n", getpid());
         } else {
        // Parent process
        printf("Parent process (PID: %d) sleeping...\n", getpid());
        sleep(30); // Sleep for a while to keep the parent alive and the child in zombie state use ps | grep 'Z' to see confrim     child is zombie.
    }

    return 0;
}
/*note:
eg output:
aks@aks-Virtual-Machine:~/SS/handson 1/question 23$ ./23.out
Parent process (PID: 3630) sleeping...
Child process (PID: 3631) exiting...

in a new terminal run ps aux \ grep 'Z'
aks@aks-Virtual-Machine:~/SS/handson 1/question 23$ ps aux | grep 'Z'
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
aks         3631  0.0  0.0      0     0 pts/0    Z+   14:25   0:00 [23.out] <defunct>
aks         3633  0.0  0.0   9080  2432 pts/2    S+   14:25   0:00 grep --color=auto Z
aks@aks-Virtual-Machine:~/SS/handson 1/question 23$ 
 
*/
