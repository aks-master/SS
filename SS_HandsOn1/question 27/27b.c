/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
27 -> Write a program to execute ls -Rl by the following system calls
b. execlp
Date: 31/8/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    execlp("/bin/ls", "ls", "-Rl", (char *)NULL);

    perror("error: ");
    return 0;
}
/*note
eg output:
aks@aks-Virtual-Machine:~/SS/handson 1/question 27$ gcc 27b.c -o 27b.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 27$ ./27b.out
.:
total 40
-rw-rw-r-- 1 aks aks   555 Aug 31 17:02 27a.c
-rwxrwxr-x 1 aks aks 16000 Aug 31 17:01 27a.out
-rw-rw-r-- 1 aks aks   548 Aug 31 17:04 27b.c
-rwxrwxr-x 1 aks aks 16000 Aug 31 17:05 27b.out

aks@aks-Virtual-Machine:~/SS/handson 1/question 27$ 
*/
