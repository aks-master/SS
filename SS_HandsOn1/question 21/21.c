/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
21 -> Write a program, call fork and print the parent and child process id.
Date: 31/8/24
*/
#include<stdio.h>
#include<unistd.h>
int main(){
int rt = fork();
if(rt==0){
printf("child process's process id: %d\n",getpid());
}
else{
printf("parent process's process id: %d\n",getpid());
}
return 0;
}
/*note
eg output:
aks@aks-Virtual-Machine:~/SS/handson 1/question 21$ ./21.out
parent process's process id: 3600
child process's process id: 3601

*/
