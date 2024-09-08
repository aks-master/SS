/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
14 -> Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
date: 30/8/24
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(mode)) {
        printf("Symbolic link\n");
    } else if (S_ISCHR(mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(mode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISSOCK(mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }
}

int main(int argc, char *argv[]) {
    struct stat file_stat;

    if (argc != 2) {
        printf("Use the program correctly. ./14.out <filename>");
        exit(0);
    }

    const char *filename = argv[1];

    if (stat(filename, &file_stat) == -1) {
        perror("stat");
        exit(0);
    }

    print_file_type(file_stat.st_mode);

    return 0;
}
/*note
eg output:
aks@aks-Virtual-Machine:~/SS/handson 1/question 14$ gcc 14.c -o 14.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 14$ touch file14.txt
aks@aks-Virtual-Machine:~/SS/handson 1/question 14$ ./14.out file14.txt
Regular file
aks@aks-Virtual-Machine:~/SS/handson 1/question 14$ 

*/

