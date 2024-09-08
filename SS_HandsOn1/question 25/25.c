/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
25 -> Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 31/8/24
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
int i,j,k;
if(!(i=fork())){sleep(1); printf("child i terminated\n");}
else if(!(j=fork())) {sleep(3); printf("child j terminated\n");}
else if(!(k=fork())) {sleep(2); printf("child k terminated\n");}
else {waitpid(k,NULL,0); printf("parent exicted after child k\n");}
return 0;
}
/*note
eg output
aks@aks-Virtual-Machine:~/SS/handson 1/question 25$ ./25.out
child i terminated
child k terminated
parent exicted after child k
aks@aks-Virtual-Machine:~/SS/handson 1/question 25$ child j terminated
*/
