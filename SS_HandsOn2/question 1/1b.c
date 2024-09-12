/* 
Name: Abhishek Kumar Singh
Roll#: MT2024006
1(b) C Write a program to set a interval timer in 10sec and
10micro second
b. ITIMER_VIRTUAL
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>


void catch(int signal) {
    printf("ITIMER_VIRTUAL expired\n");
    time_t current_time;
    struct tm *local_time;
    time(&current_time);
    local_time = localtime(&current_time);
    printf("signal catch time: %d:%d:%d\n",local_time->tm_hour,local_time->tm_min,local_time->tm_sec);
}

int main() {
    struct itimerval timer;
    signal(SIGVTALRM, catch);

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
    printf("time before settimer(ITIMER_VIRTUAL): %d:%d:%d\n",local_time->tm_hour,local_time->tm_min,local_time->tm_sec);
       
    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("error: ");
        exit(0);
    }

    for(;;);
     //run infinte loop to keep process in cpu.
    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 1$ gcc 1b.c -o 1b.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 1$ ./1b.out
time before settimer(ITIMER_VIRTUAL): 16:39:24
ITIMER_VIRTUAL expired
signal catch time: 16:39:34
^C
aks@aks-Virtual-Machine:~/SS/handson 2/question 1$ ^C

*/

