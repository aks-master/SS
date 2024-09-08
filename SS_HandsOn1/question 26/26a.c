/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
26 -> Write a program to execute an executable program.
a. use some executable program
Date: 31/8/24
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
    printf("Executing ls from a c program\n");
    system("/bin/ls");
    
    perror("msg");// status
    return EXIT_FAILURE;
}
/*note 
eg output
aks@aks-Virtual-Machine:~/SS/handson 1/question 26$ ./26a.out
Executing ls from a c program
26a.c  26a.out	26b_executable.c  26b_main.c  _26.c
msg: Success
aks@aks-Virtual-Machine:~/SS/handson 1/question 26$ 
*/
