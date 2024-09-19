/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 19/9/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    struct sigaction sa;

    // Step 1: Ignore SIGINT
    sa.sa_handler = SIG_IGN; // Ignore the signal
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is ignored for 5 seconds. Press Ctrl+C to see this effect...\n");
    sleep(5); // Sleep for 5 seconds

    // Step 2: Reset to default action
    sa.sa_handler = SIG_DFL; // Reset to default action
    if (sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("\nSIGINT is now reset to default action. Press Ctrl+C to see this effect...\n");
    sleep(5); // Sleep for 5 seconds

    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 11$ ./11.out
SIGINT is ignored for 5 seconds. Press Ctrl+C to see this effect...
^C
^C^C^C
^C
SIGINT is now reset to default action. Press Ctrl+C to see this effect...
^C
aks@aks-Virtual-Machine:~/SS/Handson 2/question 11$
*/