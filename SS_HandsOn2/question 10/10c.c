/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

10. Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE

Date: 15/9/24
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Signal handler for SIGSEGV
void handle_sigfpe(int sig) {
    printf("Caught signal");
    exit(0);
}

int main() {
    struct sigaction sa;

    // Set up the sigaction structure
    sa.sa_handler = handle_sigfpe;
    sa.sa_flags = 0;  // No special flags

    // Set up the handler for SIGINT
    sigaction(SIGFPE, &sa, NULL);

    printf("SIGFPE handler set up. use kill -8 %d\n",getpid());
    sleep(30);

    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 10$ gcc 10c.c -o 10c.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 10$ ./10c.out
SIGFPE handler set up. use kill -9 10596
Caught signalaks@aks-Virtual-Machine:~/SS/handson 2/question 10$ 
*/