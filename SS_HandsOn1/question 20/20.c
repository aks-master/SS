/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
19 -> Find out the priority of your running program. Modify the priority with nice command.
date: 30/8/24
*/


#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>


int main() {
   int priority;
   printf("process id: run top -p %d in new terminal , to check modifications via renice commad. Press ctrl+c to exit\n",getpid());
    priority = getpriority(PRIO_PROCESS, getpid());
    
    if (priority == -1 && errno != 0) {
        perror("getpriority");
    } else {
        printf("Current priority: %d\n", priority);
    }
    while(1);
    return 0;
}
/*note eg output
program run
aks@aks-Virtual-Machine:~/SS/handson 1/question 20$ gcc 20.c -o 20.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 20$ ./20.out
process id: run top -p 7213 in new terminal , to check modifications via renice commad. Press ctrl+c to exit
Current priority: 0


top output before renice command
top - 23:01:11 up  1:43,  1 user,  load average: 1.23, 1.16, 1.06
Tasks:   1 total,   1 running,   0 sleeping,   0 stopped,   0 zombie
%Cpu(s): 26.9 us,  1.9 sy,  0.0 ni, 70.4 id,  0.0 wa,  0.0 hi,  0.9 si,  0.0 st
MiB Mem :   9279.7 total,   4207.0 free,   2779.5 used,   2293.2 buff/cache
MiB Swap:      0.0 total,      0.0 free,      0.0 used.   5965.9 avail Mem 

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND  
   7213 aks       20   0    2776   1408   1408 R 100.0   0.0   3:17.01 20.out   


renice command
aks@aks-Virtual-Machine:~/SS/handson 1/question 20$ renice -n 20 -p 7213
7213 (process ID) old priority 0, new priority 19


top output after renice command
Tasks:   1 total,   1 running,   0 sleeping,   0 stopped,   0 zombie
%Cpu(s): 13.3 us,  5.7 sy, 14.3 ni, 66.7 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
MiB Mem :   9111.7 total,   4027.8 free,   2773.0 used,   2310.8 buff/cache
MiB Swap:      0.0 total,      0.0 free,      0.0 used.   5812.3 avail Mem 

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND  
   7213 aks       39  19    2776   1408   1408 R 100.0   0.0  11:38.36 20.out   
   
*/


