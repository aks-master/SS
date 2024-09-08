/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
22 -> Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 31/8/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[]) {
    int fd;
    pid_t pid;

        fd = open(argv[1], O_WRONLY, 0777);
    if (!fd) {
        printf("Use the program correclty ./22.out <filename>. The file should be already present.");
        exit(0);
    }

    int rt = fork();
    if (rt == 0) {
        const char *child_msg = "Hello from child.\n";
        if (write(fd, child_msg, strlen(child_msg)) < 0) {
            perror("write");
            close(fd);
            exit(0);
        }
        close(fd);
    } else {
        // Parent process
        const char *parent_msg = "Hello from parent.\n";
        if (write(fd, parent_msg, strlen(parent_msg)) < 0) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }
        close(fd);
    }
    return 0;
}
/*note
eg output
aks@aks-Virtual-Machine:~/SS/handson 1/question 22$ gcc 22.c -o 22.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 22$ ./22.out file22.txt
aks@aks-Virtual-Machine:~/SS/handson 1/question 22$ cat file22.txt
Hello from parent.
Hello from child.
aks@aks-Virtual-Machine:~/SS/handson 1/question 22$ 

*/
