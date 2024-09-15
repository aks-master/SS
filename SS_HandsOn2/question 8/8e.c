
/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

8. Write a separate program using signal system call to catch the following signals.

    e. SIGALRM (use setitimer system call)


Date: 12/9/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handle_sigalrm(int sig) {
    printf("Caught SIGALRM (Alarm clock signal)\n");
    exit(0);
}
int main() {
    signal(SIGALRM, handle_sigalrm);
    struct itimerval timer;
    // SIGALRM using setitimer
    timer.it_value.tv_sec = 2; 
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);

    printf("catching sigalrm\n");

    // Simulate work
    while (1);
    return 0;
}


/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ gcc 8e.c -o 8e.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ ./8e.out
catching sigalrm
Caught SIGALRM (Alarm clock signal)
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ 
*/
