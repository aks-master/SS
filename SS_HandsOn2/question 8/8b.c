
/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

8. Write a separate program using signal system call to catch the following signals.
    b. SIGINT
Date: 12/9/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("Caught SIGINT (Interrupt from keyboard)\n");
    exit(EXIT_SUCCESS);
}


int main() {
    
    signal(SIGINT, handle_sigint);
   
   //use use kill -2 <pid>
    printf("process id:%d \n",getpid());
    // Simulate work 
    while(1);
    return 0;
    return 0;
}


/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ gcc 8b.c -o 8b.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ ./8b.out
process id:7353 
Caught SIGINT (Interrupt from keyboard)
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ 

//sending signal
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ kill -2 7353
*/