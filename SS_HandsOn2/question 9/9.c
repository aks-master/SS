/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.

Date: 15/9/24
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    
    signal(SIGINT, SIG_IGN); 
    
    printf("SIGINT is being ignored. Press Ctrl+C to test. Press enter for default action\n");
    char ch;
    while((ch=getchar())!='\n');

    
    signal(SIGINT, SIG_DFL);

    printf("SIGINT action has been reset to default.\n");

    // Simulate more work to observe the reset behavior
    sleep(10);

    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 9$ gcc 9.c -o 9.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 9$ ./9.out
SIGINT is being ignored. Press Ctrl+C to test. Press enter for default action
^C^C^C^C^C
SIGINT action has been reset to default.

^C
aks@aks-Virtual-Machine:~/SS/handson 2/question 9$ ^C
*/
