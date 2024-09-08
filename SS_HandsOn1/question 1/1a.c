/* 
Name: Abhishek Kumar Singh
Roll#: MT2024006
1(a) Create a soft link using system call
date: 15/8/24 (date first pushed)
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
printf("C program to create softlink using symlink system call\n");
printf("First enter file name then softlink name\n");
char filename[30];
char softlink[30];
scanf("%s %s",filename,softlink);
if(symlink(filename,softlink)==0){
printf("Softlink created successfully\n");
}
else{
printf("Cannot create softlink\n");
perror("Error: ");
}
return 0;
}
/* note
Run the program, enter an existing filename and corresponding softlink name, after program finishes successfully run < ls -l >.
Check for your softlink. 
eg. is given below
total 88
-rw-rw-r-- 1 aks aks   692 Aug 27 22:34 1a.c
-rwxrwxr-x 1 aks aks 16144 Aug 11 11:38 1a.out
-rw-rw-r-- 1 aks aks   509 Aug 11 12:08 1b.c
-rwxrwxr-x 1 aks aks 16144 Aug 11 12:08 1b.cout
-rwxrwxr-x 1 aks aks 16144 Aug 11 11:45 1b.out
prw-rw-r-- 1 aks aks     0 Aug 27 22:02 1c
-rw-rw-r-- 1 aks aks   547 Aug 11 12:07 1c.c
-rwxrwxr-x 1 aks aks 16144 Aug 11 12:07 1c.out
prwxrwxr-x 1 aks aks     0 Aug 11 12:08 1c_progPipe
-rw-rw-r-- 3 aks aks    24 Aug 11 11:00 f1.txt
-rw-rw-r-- 3 aks aks    24 Aug 11 11:00 f1.txt_Chardlink
lrwxrwxrwx 1 aks aks     6 Aug 11 11:36 f1.txt_Csoftlink -> f1.txt
-rw-rw-r-- 3 aks aks    24 Aug 11 11:00 f1.txt_hardlink
lrwxrwxrwx 1 aks aks     6 Aug 11 11:04 f1.txt_softlink -> f1.txt
*/
