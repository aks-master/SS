/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 20/9/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pipefd1[2], pipefd2[2];
    pid_t pid1, pid2, pid3;

    if (pipe(pipefd1) == -1)
    {
        perror("pipe1");
        exit(0);
    }

    if (pipe(pipefd2) == -1)
    {
        perror("pipe2");
        exit(0);
    }

    if ((pid1 = fork()) == -1)
    {
        perror("fork1");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0)
    {
        dup2(pipefd1[1], STDOUT_FILENO);
        close(pipefd1[0]);
        close(pipefd1[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(0);
    }

    if ((pid2 = fork()) == -1)
    {
        perror("fork2");
        exit(0);
    }

    if (pid2 == 0)
    {
        dup2(pipefd1[0], STDIN_FILENO);
        dup2(pipefd2[1], STDOUT_FILENO);
        close(pipefd1[0]);
        close(pipefd1[1]);
        close(pipefd2[0]);
        execlp("grep", "grep", "^d", NULL);
        perror("execlp grep");
        exit(0);
    }

    if ((pid3 = fork()) == -1)
    {
        perror("fork3");
        exit(0);
    }

    if (pid3 == 0)
    {
        dup2(pipefd2[0], STDIN_FILENO);
        close(pipefd1[0]);
        close(pipefd1[1]);
        close(pipefd2[0]);
        close(pipefd2[1]);
        execlp("wc", "wc", "-l", NULL);
        perror("execlp wc");
        exit(0);
    }

    close(pipefd1[0]);
    close(pipefd1[1]);
    close(pipefd2[0]);
    close(pipefd2[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 18$ gcc 18.c -o 18.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 18$ ./18.out
3
aks@aks-Virtual-Machine:~/SS/Handson 2/question 18$
*/
