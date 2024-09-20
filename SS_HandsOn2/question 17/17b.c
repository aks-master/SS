/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
17. Write a program to execute ls -l | wc.
a. use dup2
date: 20/9/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pipefd[2];
    pid_t pid1, pid2;

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(0);
    }

    if ((pid1 = fork()) == -1)
    {
        perror("fork");
        exit(0);
    }

    if (pid1 == 0)
    {
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(0);
    }

    if ((pid2 = fork()) == -1)
    {
        perror("fork");
        exit(0);
    }

    if (pid2 == 0)
    {
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[1]);
        close(pipefd[0]);
        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(0);
    }

    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 17$ gcc 17b.c -o 17b.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 17$ ./17b.out
      5      38     197
aks@aks-Virtual-Machine:~/SS/Handson 2/question 17$ ls -l | wc
      5      38     197
aks@aks-Virtual-Machine:~/SS/Handson 2/question 17$

*/