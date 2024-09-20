/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
17. Write a program to execute ls -l | wc.
a. use dup
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
        close(1);
        dup(pipefd[1]);
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
        close(0);
        dup(pipefd[0]);
        ;
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
aks@aks-Virtual-Machine:~/SS/Handson 2/question 17$ ls -l | wc
      3      20     103
aks@aks-Virtual-Machine:~/SS/Handson 2/question 17$ ./17a.out
      3      20     103
aks@aks-Virtual-Machine:~/SS/Handson 2/question 17$
*/