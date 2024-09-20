/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 20/9/24
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{

    int mkfifo_status, mknod_status; // 0 -> Success, -1 -> Error

    // Using `mkfifo` library function
    mkfifo_status = mkfifo("mkfifo", S_IRWXU);

    if (mkfifo_status == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");

    // Using `mknod` system call
    mkfifo_status = mknod("mknod", __S_IFIFO | S_IRWXU, 0);

    if (mknod_status == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");
    return 0;
}
/*
aks@aks-Virtual-Machine:~/SS/Handson 2/question 19$ gcc 19.c -o 19.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 19$ ./19.out
Succesfully created FIFO file. Check using `ll` or `ls -l` command!
Succesfully created FIFO file. Check using `ll` or `ls -l` command!
aks@aks-Virtual-Machine:~/SS/Handson 2/question 19$ ls -l
total 20
-rw-rw-r-- 1 aks aks   984 Sep 20 11:20 19.c
-rwxrwxr-x 1 aks aks 16080 Sep 20 11:20 19.out
prwx------ 1 aks aks     0 Sep 20 11:20 mkfifo
prwx------ 1 aks aks     0 Sep 20 11:20 mknod
aks@aks-Virtual-Machine:~/SS/Handson 2/question 19$
 */