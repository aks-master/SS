/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 19/9/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
    int pid = fork();
    if (pid == 0)
    {
        printf("Child PID %d, parent PID %d\n", getpid(), getppid());
        kill(getppid(), SIGKILL); // Terminate the parent process
        sleep(2);
        printf("Child PID %d, parent PID %d\n", getpid(), getppid());
        sleep(1); // Keep the child alive for a while to observe
    }
    else
    {
        sleep(1); // ensure child runs first
        printf("parent PID %d\n", getpid());
        sleep(2); // Sleep for a moment to ensure the child is running
        exit(0);  // Parent terminates
    }
    return 0;
}

/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 12$ ./12.out
Child PID 5273, parent PID 5272
Killed
aks@aks-Virtual-Machine:~/SS/Handson 2/question 12$ Child PID 5273, parent PID 1574
^C
aks@aks-Virtual-Machine:~/SS/Handson 2/question 12$

//systemd process id 1547
top - 07:24:33 up 15 min,  1 user,  load average: 0.79, 0.71, 0.60
Tasks:   1 total,   0 running,   1 sleeping,   0 stopped,   0 zombie
%Cpu(s): 12.6 us,  3.7 sy,  0.0 ni, 83.6 id,  0.0 wa,  0.0 hi,  0.1 si,  0.0 st
MiB Mem :   8339.7 total,   4400.5 free,   2620.1 used,   1703.2 buff/cache
MiB Swap:   4096.0 total,   4096.0 free,      0.0 used.   5719.7 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
   1574 aks       20   0   21088  12836   9472 S   0.0   0.2   0:00.77 systemd


*/