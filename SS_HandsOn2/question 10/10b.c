/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

10. Write a separate program using sigaction system call to catch the following signals.
b. SIGINT

Date: 15/9/24
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Signal handler for SIGSEGV
void handle_sigint(int sig) {
    printf("Caught signal");
    exit(0);
}

int main() {
    struct sigaction sa;

    // Set up the sigaction structure
    sa.sa_handler = handle_sigint;
    sa.sa_flags = 0;  // No special flags

    // Set up the handler for SIGINT
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT handler set up. press ^c\n");
    sleep(10);

    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 10$ gcc 10b.c -o 10b.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 10$ ./10b.out
SIGINT handler set up. press ^c
^CCaught signalaks@aks-Virtual-Machine:~/SS/handson 2/question 10$ 
*/