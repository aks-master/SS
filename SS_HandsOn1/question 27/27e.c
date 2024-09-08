/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
27 -> Write a program to execute ls -Rl by the following system calls
e. execvp
Date: 31/8/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *path = "/bin/ls";
    // Arguments for 'ls'
    char *args[] = { "ls", "-Rl", NULL }; // Argument list must be NULL-terminated
    // Execute 'ls -Rl' using execv
    execvp(path, args);
    perror("error: ");
    return 0;
}
/*note
eg output:
aks@aks-Virtual-Machine:~/SS/handson 1/question 27$ ./27d.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 27$ ./27e.out
.:
total 100
-rw-rw-r-- 1 aks aks   547 Aug 31 17:06 27a.c
-rwxrwxr-x 1 aks aks 16000 Aug 31 17:01 27a.out
-rw-rw-r-- 1 aks aks   717 Aug 31 17:06 27b.c
-rwxrwxr-x 1 aks aks 16000 Aug 31 17:05 27b.out
-rw-rw-r-- 1 aks aks   751 Aug 31 17:11 27c.c
-rwxrwxr-x 1 aks aks 16000 Aug 31 17:08 27c.out
-rw-rw-r-- 1 aks aks   978 Aug 31 17:14 27d.c
-rwxrwxr-x 1 aks aks 16056 Aug 31 17:13 27d.out
-rw-rw-r-- 1 aks aks   980 Aug 31 17:15 27e.c
-rwxrwxr-x 1 aks aks 16056 Aug 31 17:15 27e.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 27$
*/
