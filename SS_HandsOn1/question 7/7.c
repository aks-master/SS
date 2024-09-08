/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
7-> WAP to copy file 1 into file 2
date: 17/8/24 (date first pushed)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char buffer[1024];
    int srcFD = -1, dstFD = -1;
    ssize_t count;

    /* Check for number of parameters */
    if (argc < 3)
    {
        printf("please use the program corretly ./7.out src dst");
        exit(0);
    }
    srcFD = open(argv[1], O_RDONLY);
    if (srcFD == -1) // file cannot be opened.
    {
        printf("src cannot be opened\n");
        exit(0);
    }
    dstFD = open(argv[2], O_WRONLY | O_CREAT, 0777);
    if (dstFD == -1) // file cannot be opened
    {
        printf("dst cannot be opened\n");
        close(srcFD);
        exit(0);
    }

    count = read(srcFD, buffer, 1024);
    write(dstFD, buffer, count);
    return 0;
}
/*note
to run the program correctly: ./7.c <file> <copy>
eg output
aks@aks-Virtual-Machine:~/SS/handson 1$ cd 'question 7'
aks@aks-Virtual-Machine:~/SS/handson 1/question 7$ ls -l
total 28
-rw-rw-r-- 1 aks aks   918 Aug 28 09:03 7.c
-rwxrwxr-x 1 aks aks 16256 Aug 12 19:18 7.out
-rwxrwxr-x 1 aks aks    19 Aug 12 19:18 copy.txt
-rw-rw-r-- 1 aks aks    19 Aug 12 18:50 original.txt
aks@aks-Virtual-Machine:~/SS/handson 1/question 7$ cat original.txt
Text to be copied.
aks@aks-Virtual-Machine:~/SS/handson 1/question 7$ cat copy.txt
Text to be copied.
aks@aks-Virtual-Machine:~/SS/handson 1/question 7$
*/
