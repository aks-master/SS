
/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

8. Write a separate program using signal system call to catch the following signals.
    g. SIGPROF (use setitimer system call)

Date: 12/9/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <fenv.h>


void handle_sigprof(int sig) {
    printf("Caught SIGPROF (Profiling timer expired)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    
    signal(SIGPROF, handle_sigprof);

    
    struct itimerval timer;

    // SIGPROF using setitimer
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_PROF, &timer, NULL);

     printf("catching sigprof\n");

    // Simulate work
    while (10000); //sigprof is caught when process time expires.
    return 0;
}


/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ gcc 8g.c -o 8g.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ ./8g.out
catching sigprof
Caught SIGPROF (Profiling timer expired)
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ 
*/
