
/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

8. Write a separate program using signal system call to catch the following signals.
    a. SIGSEGV

Date: 12/9/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


// Signal handler functions
void handle_sigsegv(int sig) {
    printf("Caught SIGSEGV (Segmentation fault)\n");
    exit(EXIT_FAILURE);
}


int main() {
    // Set up signal handlers
    signal(SIGSEGV, handle_sigsegv); //singal 11
    //use use kill -11 <pid>
    printf("process id:%d \n",getpid());
    // Simulate work 
    while(1);
    return 0;
}


/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ gcc 8a.c -o 8a.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ ./8a.out
process id:6970 
Caught SIGSEGV (Segmentation fault)
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ 

//sending signal
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ kill -11 6970
*/