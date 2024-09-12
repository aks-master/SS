/* 
Name: Abhishek Kumar Singh
Roll#: MT2024006
1(a) C Write a program to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>


void catch(int signal) {
    printf("ITIMER_REAL expired\n");
    time_t current_time;
    struct tm *local_time;
    time(&current_time);
    local_time = localtime(&current_time);
    printf("signal catch time: %d:%d:%d\n",local_time->tm_hour,local_time->tm_min,local_time->tm_sec);
    exit(0);
    
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, catch);

    //disable repeated timer events
    timer.it_interval.tv_sec = 0; 
    timer.it_interval.tv_usec = 0;
    //set timer values 10 seconds and 10 microseconds
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    
    time_t current_time;
    struct tm *local_time;
    time(&current_time);
    local_time = localtime(&current_time);
    printf("time before settimer(ITIMER_REAL): %d:%d:%d\n",local_time->tm_hour,local_time->tm_min,local_time->tm_sec);
       
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("error: ");
        exit(0);
    }

    for(;;);
    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 1$ gcc 1a.c -o 1a.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 1$ ./1a.out
time before settimer(ITIMER_REAL): 16:37:51
ITIMER_REAL expired
signal catch time: 16:38:1
aks@aks-Virtual-Machine:~/SS/handson 2/question 1$ 

*/

