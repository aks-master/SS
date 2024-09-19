/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 19/9/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int pipe1[2];
    int pipe2[2];
    int pid;
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1)
    {
        perror("pipe");
        exit(0);
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(0);
    }

    if (pid == 0)
    {
        close(pipe1[1]);
        close(pipe2[0]);
        char buffer[100];
        read(pipe1[0], buffer, sizeof(buffer));
        printf("Child received from parent: %s\n", buffer);
        const char *response = "Hello from the child!";
        write(pipe2[1], response, strlen(response) + 1);
        close(pipe1[0]);
        close(pipe2[1]);
        exit(0);
    }
    else
    {
        close(pipe1[0]);
        close(pipe2[1]);
        const char *message = "Hello from the parent!";
        write(pipe1[1], message, strlen(message) + 1);

        char buffer[100];
        read(pipe2[0], buffer, sizeof(buffer));
        printf("Parent received from child: %s\n", buffer);

        close(pipe1[1]);
        close(pipe2[0]);
        wait(NULL);
    }

    return 0;
}

/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 16$ gcc 16.c -o 16.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 16$ ./16.out
Child received from parent: Hello from the parent!
Parent received from child: Hello from the child!
aks@aks-Virtual-Machine:~/SS/Handson 2/question 16$
*/