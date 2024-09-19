/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 19/9/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pipefd[2]; // File descriptors for the pipe 0-->read 1-->write
    int pid;
    char buffer[100]; // Buffer to hold data read from the pipe

    // Create the pipe
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        close(pipefd[0]);
        write(pipefd[1], "Hello from the child process!", 30);
        close(pipefd[1]);
        exit(0);
    }
    else
    {
        close(pipefd[1]);
        read(pipefd[0], buffer, sizeof(buffer));
        printf("child message= %s\n", buffer);
        close(pipefd[0]);
    }

    return 0;
}

/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 14$ gcc 14.c -o 14.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 14$ ./14.out
child message= Hello from the child process!
aks@aks-Virtual-Machine:~/SS/Handson 2/question 14$
*/