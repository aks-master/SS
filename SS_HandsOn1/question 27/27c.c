/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
27 -> Write a program to execute ls -Rl by the following system calls
c. execle
Date: 31/8/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    execle("/bin/ls", "ls", "-Rl", (char *)NULL,(char *)NULL);

    perror("error: ");
    return 0;
}
/*note
eg output:
aks@aks-Virtual-Machine:~/SS/handson 1/question 27$ ./27c.out
.:
total 60
-rw-rw-r-- 1 aks aks   547 Aug 31 17:06 27a.c
-rwxrwxr-x 1 aks aks 16000 Aug 31 17:01 27a.out
-rw-rw-r-- 1 aks aks   717 Aug 31 17:06 27b.c
-rwxrwxr-x 1 aks aks 16000 Aug 31 17:05 27b.out
-rw-rw-r-- 1 aks aks   730 Aug 31 17:08 27c.c
-rwxrwxr-x 1 aks aks 16000 Aug 31 17:08 27c.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 27$ 

*/
