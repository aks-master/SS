/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
5-> WAP to create 5 files and check its file descriptor table
date: 15/8/24 (date first pushed)
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    printf("goto /proc/%d/fd in a new terminal and check fd table\n", getpid());
    int fd1 = creat("file51.txt", S_IRWXU | S_IWUSR | S_IRGRP | S_IROTH);
    int fd2 = creat("file52.txt", S_IRWXU | S_IWUSR | S_IRGRP | S_IROTH);
    int fd3 = creat("file53.txt", S_IRWXU | S_IWUSR | S_IRGRP | S_IROTH);
    int fd4 = creat("file54.txt", S_IRWXU | S_IWUSR | S_IRGRP | S_IROTH);
    int fd5 = creat("file55.txt", S_IRWXU | S_IWUSR | S_IRGRP | S_IROTH);
    while (1)
        ; // to stop program from terminating, else its proc directory will be removed.
    return 0;
}
/*note
creat system call returns fd if successful
eg.
goto /proc/3314/fd in a new terminal and check fd table

aks@aks-Virtual-Machine:/proc/3314/fd$ cd /proc/3314/fd
aks@aks-Virtual-Machine:/proc/3314/fd$ ls -l
total 0
lrwx------ 1 aks aks 64 Aug 27 23:02 0 -> /dev/pts/2
lrwx------ 1 aks aks 64 Aug 27 23:02 1 -> /dev/pts/2
lrwx------ 1 aks aks 64 Aug 27 23:02 2 -> /dev/pts/2
l-wx------ 1 aks aks 64 Aug 27 23:02 3 -> '/home/aks/SS/handson 1/question 5/file51.txt'
l-wx------ 1 aks aks 64 Aug 27 23:02 4 -> '/home/aks/SS/handson 1/question 5/file52.txt'
l-wx------ 1 aks aks 64 Aug 27 23:02 5 -> '/home/aks/SS/handson 1/question 5/file53.txt'
l-wx------ 1 aks aks 64 Aug 27 23:02 6 -> '/home/aks/SS/handson 1/question 5/file54.txt'
l-wx------ 1 aks aks 64 Aug 27 23:02 7 -> '/home/aks/SS/handson 1/question 5/file55.txt'
aks@aks-Virtual-Machine:/proc/3314/fd$


*/
