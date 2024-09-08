/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
24 -> Write a program to create an orphan process.
Date: 31/8/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    // Create a new process
    int rt = fork();

   if (rt == 0) {
   	sleep(1); //ensures parent executes first
        // Child process
        printf("Child process PID: %d, patent PID: %d. and going to sleep for 5 seconds\n", getpid(),getppid());
        
        // Child process sleeps to ensure the parent terminates before child
        sleep(5);
        
        // After the parent exits, the child becomes an orphan and is adopted by init
        printf("After sleep\nChild process PID: %d, patent PID: %d.\n", getpid(),getppid());
    } else {
        // Parent process
        printf("Parent process PID: %d \n", getpid());
        sleep(2); //ensures parent remains alive till childs 1st printf.
    }

    return 0;
}
/*note
in my computer process id of systemd is 1131. here is top command output
top - 14:48:52 up 34 min,  1 user,  load average: 0.49, 0.74, 0.59
Tasks:   1 total,   0 running,   1 sleeping,   0 stopped,   0 zombie
%Cpu(s):  5.3 us,  1.5 sy,  0.0 ni, 92.7 id,  0.1 wa,  0.0 hi,  0.3 si,  0.0 st
MiB Mem :   7873.7 total,   3792.5 free,   2241.0 used,   1840.3 buff/cache
MiB Swap:      0.0 total,      0.0 free,      0.0 used.   5132.7 avail Mem 

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND  
   1131 aks       20   0   18000  10600   8064 S   0.0   0.1   0:00.80 systemd  

*****
program output
aks@aks-Virtual-Machine:~/SS/handson 1/question 24$ ./24.out
Parent process PID: 4223 
Child process PID: 4224, patent PID: 4223. and going to sleep for 5 seconds
aks@aks-Virtual-Machine:~/SS/handson 1/question 24$ After sleep
Child process PID: 4224, patent PID: 1131.
*/

