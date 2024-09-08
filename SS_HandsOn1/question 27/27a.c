/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
27 -> Write a program to execute ls -Rl by the following system calls
a. execl
Date: 31/8/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    execl("/bin/ls", "ls", "-Rl", (char *)NULL);

    perror("error: ");
    return 0;
}
/*note
eg output:
aks@aks-Virtual-Machine:~/SS/handson 1/question 27$ ./27a.out
.:
total 20
-rw-rw-r-- 1 aks aks   335 Aug 31 17:01 27a.c
-rwxrwxr-x 1 aks aks 16000 Aug 31 17:01 27a.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 27$ 
*/
