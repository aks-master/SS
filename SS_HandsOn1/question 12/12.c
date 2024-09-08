/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
12 -> WAP to find out the opening mode of a file. Use fcntl
date: 30/8/24
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void print_mode(int flags) {
    if (flags & O_RDONLY) {
        printf("File is opened in read-only mode.\n");
    }
    else if (flags & O_WRONLY) {
        printf("File is opened in write-only mode.\n");
    }
    else if (flags & O_RDWR) {
        printf("File is opened in read/write mode.\n");
    }
    /*
    this program does not uses any other flags, but the program can be easily extended to do this.
    */
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("please use the program correctly, ./12.out <filename>");
        exit(0);
    }

    const char *filename = argv[1];
    int x=rand()%3; //generate random number b/w 0-2.
    int fd;
    if(x==0)
    	fd = open(filename, O_RDONLY); // Open the file in read-only mode to get the flags
    else if(x==1)
      	fd = open(filename, O_WRONLY); // Open the file in read-only mode to get the flags
    else if(x==2)
    	fd = open(filename, O_RDWR); // Open the file in read-only mode to get the flags

    if (fd == -1) {
        perror("error: ");
        exit(0);
    }

    int flags = fcntl(fd, F_GETFL); // Get the file descriptor flags
    if (flags == -1) {
        perror("fcntl error: ");
        close(fd);
        exit(0);
    }

    print_mode(flags);

    close(fd);
    return 0;
}
/*note 
eg output:
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ gcc 12.c -o 12.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ ./12.out file12.txt
File is opened in write-only mode.
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ ./12.out file12.txt
File is opened in write-only mode.
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ ./12.out file12.txt
File is opened in write-only mode.
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ ./12.out file12.txt
File is opened in write-only mode.
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ ./12.out file12.txt
File is opened in write-only mode.
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ ./12.out file12.txt
File is opened in write-only mode.
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ ./12.out file12.txt
File is opened in write-only mode.
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ gcc 12.c -o 12.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ ./12.out file12.txt
File is opened in write-only mode.
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ ./12.out file12.txt
File is opened in write-only mode.
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ ^C
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ gcc 12.c -o 12.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ ./12.out file12.txt
File is opened in read/write mode.
aks@aks-Virtual-Machine:~/SS/handson 1/question 12$ ^C

*/


