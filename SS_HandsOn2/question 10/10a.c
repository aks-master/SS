/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV

Date: 15/9/24
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Signal handler for SIGSEGV
void handle_sigsegv(int sig) {
    printf("Caught signal");
    exit(0);
}

int main() {
    struct sigaction sa;

    // Set up the sigaction structure
    sa.sa_handler = handle_sigsegv;
    sa.sa_flags = 0;  // No special flags

    // Set up the handler for SIGSEGV
    sigaction(SIGSEGV, &sa, NULL);

    printf("SIGSEGV handler set up. Triggering segmentation fault...\n");

    // Trigger a segmentation fault by dereferencing a NULL pointer
    int *ptr = NULL;
    *ptr = 50;  // This will cause a SIGSEGV

    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 10$ ./10a.out
SIGSEGV handler set up. Triggering segmentation fault...
Caught signalaks@aks-Virtual-Machine:~/SS/handson 2/question 10$ 
*/