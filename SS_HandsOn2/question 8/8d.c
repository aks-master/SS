
/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

8. Write a separate program using signal system call to catch the following signals.
    d. SIGALRM (use alarm system call)

Date: 12/9/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handle_sigalrm(int sig) {
    printf("Caught SIGALRM (Alarm clock signal)\n");
    exit(0);
}


int main() {
   
    signal(SIGALRM, handle_sigalrm);

    // Set up alarm using alarm system call
    alarm(5); // Set alarm for 5 seconds
    printf("pid: %d\n. Alarm signal in 5 sec by default.\n",getpid());
    // use kill -14 <pid>
    // Simulate work
    while (1);
    return 0;
}


/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ gcc 8d.c -o 8d.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ ./8d.out
pid: 11609
. Alarm signal in 5 sec by default.
Caught SIGALRM (Alarm clock signal)
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ 
*/