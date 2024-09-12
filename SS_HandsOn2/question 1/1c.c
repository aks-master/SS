/* 
Name: Abhishek Kumar Singh
Roll#: MT2024006
1(c) C Write a program to set a interval timer in 10sec and
10micro second
c. ITIMER_PROF
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>


void catch(int signal) {
    printf("ITIMER_PROF expired\n");
    time_t current_time;
    struct tm *local_time;
    time(&current_time);
    local_time = localtime(&current_time);
    printf("signal catch time: %d:%d:%d\n",local_time->tm_hour,local_time->tm_min,local_time->tm_sec);
    exit(0);
    
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, catch);

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
    printf("time before settimer(ITIMER_PROF): %d:%d:%d\n",local_time->tm_hour,local_time->tm_min,local_time->tm_sec);
       
    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("error: ");
        exit(0);
    }

    for(;;);
    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 1$ ./1c.out
time before settimer(ITIMER_PROF): 16:42:33
ITIMER_PROF expired
signal catch time: 16:42:43
aks@aks-Virtual-Machine:~/SS/handson 2/question 1$ 
*/

