
/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

8. Write a separate program using signal system call to catch the following signals.
    c. SIGFPE
    
Date: 12/9/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handle_sigfpe(int sig) {
    printf("Caught SIGFPE (Floating-point exception)\n");
    exit(0);
}


int main() {
    signal(SIGFPE, handle_sigfpe);

    // for(int i = 10; i>-1;i--){
    //     printf("100/%d=%f\n",i,(float)100/i);
    // }
    // for(int i = 10; i>-1;i--){
    //     printf("100/%d=%f\n",i,(float)100/i);
    // }
    /* cannot generate sigfpe therefore manually sending signal*/
    //kill -8 <pid>
    printf("pid=%d\n",getpid());
    while(1);
    return 0;
}


/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ gcc 8c.c -o 8c.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ ./8c.out
pid=8432
Caught SIGFPE (Floating-point exception)
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ 

//sending signal
aks@aks-Virtual-Machine:~/SS/handson 2/question 8$ kill -8 8432
*/