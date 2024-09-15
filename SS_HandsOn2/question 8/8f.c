
/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

8. Write a separate program using signal system call to catch the following signals.
    f. SIGVTALRM (use setitimer system call)

Date: 12/9/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>



void handle_sigvtalrm(int sig) {
    printf("Caught SIGVTALRM (Virtual timer expired)\n");
    exit(EXIT_SUCCESS);
}

int main() {
  
    signal(SIGVTALRM, handle_sigvtalrm);

    
    struct itimerval timer;
    // SIGVTALRM using setitimer
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    printf("catching sigvtalrm\n");

    // Simulate work
    while (1);

    return 0;
}


/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ gcc 8f.c -o 8f.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ ./8f.out
catching sigvtalrm
Caught SIGVTALRM (Virtual timer expired)
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ 
*/
