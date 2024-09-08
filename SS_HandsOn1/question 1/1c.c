/* 
Name: Abhishek Kumar Singh
Roll#: MT2024006
1(c) Create a FIFO using system call
date: 15/8/24 (date first pushed)
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){
printf("C program to create a FIFO using mkfifo system call\n");
printf("First enter FIFO pipe name (0777 permission is given)\n");
char fifoname[30];
scanf("%s",fifoname);
if(mkfifo(fifoname,0777)==0){
printf("fifo pipe created successfully\n");
}
else{
printf("Cannot create fifo pipe\n");
perror("Error: ");
}
return 0;
}
/* note
runthe program to create a fifo pipe. Then open 2 terminals.
In therminal 1 run ls -l > pipename
In terminal 2 run cat pipename.
We have successfully communicated between 2 terminals using pipe. You can run the 2 commands in any order
eg.
terminal 1
aks@aks-Virtual-Machine:~/SS/handson 1/question 1$ ls -l > 1c


-- the terminals halts till the content of the pipe is read.
terminal 2
aks@aks-Virtual-Machine:~/SS/handson 1/question 1$ cat 1c
total 88
-rw-rw-r-- 1 aks aks  1417 Aug 27 22:36 1a.c
-rwxrwxr-x 1 aks aks 16144 Aug 11 11:38 1a.out
-rw-rw-r-- 1 aks aks  1413 Aug 27 22:41 1b.c
-rwxrwxr-x 1 aks aks 16144 Aug 11 12:08 1b.cout
-rwxrwxr-x 1 aks aks 16144 Aug 11 11:45 1b.out
prw-rw-r-- 1 aks aks     0 Aug 27 23:18 1c
-rw-rw-r-- 1 aks aks   752 Aug 27 22:43 1c.c
-rwxrwxr-x 1 aks aks 16144 Aug 11 12:07 1c.out
prwxrwxr-x 1 aks aks     0 Aug 11 12:08 1c_progPipe
-rw-rw-r-- 3 aks aks    24 Aug 11 11:00 f1.txt
-rw-rw-r-- 3 aks aks    24 Aug 11 11:00 f1.txt_Chardlink
lrwxrwxrwx 1 aks aks     6 Aug 11 11:36 f1.txt_Csoftlink -> f1.txt
-rw-rw-r-- 3 aks aks    24 Aug 11 11:00 f1.txt_hardlink
lrwxrwxrwx 1 aks aks     6 Aug 11 11:04 f1.txt_softlink -> f1.txt
aks@aks-Virtual-Machine:~/SS/handson 1/question 1$ 

*/


