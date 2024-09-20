/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
17. Write a program to execute ls -l | wc.
a. use fcntl
date: 20/9/24
*/
// Question : Write a program to execute `ls -l | wc`. Use `fcntl`

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pipefd[2];
    int childPid;

    int pipeStatus = pipe(pipefd);

    if (pipeStatus == -1)
    {
        perror("Error while creating the pipe!");
        exit(0);
    }
    childPid = fork();
    if (childPid == 0)
    {
        close(STDIN_FILENO);
        fcntl(pipefd[0], F_DUPFD, STDIN_FILENO); // STDIN will be reassigned to pipefdp[0]
        close(pipefd[1]);
        execl("/usr/bin/wc", "wc", NULL);
    }
    else
    {
        close(STDOUT_FILENO);
        fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO); // STDOUT will be reassigned to pipefd[1]
        close(pipefd[0]);
        execl("/usr/bin/ls", "ls -l", "-l", NULL);
    }
    return 0;
}

/*
aks@aks-Virtual-Machine:~/SS/Handson 2/question 17$ ./17c.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 17$       8      65     336
^C
aks@aks-Virtual-Machine:~/SS/Handson 2/question 17$
 */