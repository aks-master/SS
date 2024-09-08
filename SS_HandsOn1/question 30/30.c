/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
30 -> Write a program to run a script at a specific time using a Daemon process.
Date: 31/8/24
*/
#include<unistd.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
if(!fork()) {
setsid();
chdir("/");
umask(0);
while(1){
sleep(4);
printf("Child pid: %d\n",getpid());
printf("Daemon process is running...\n");
}
}
else exit(0);
}
/*note
check with ps -el | grep <pid of process>

aks@aks-Virtual-Machine:~/SS/handson 1/question 30$ ./30.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 30$ Child pid: 5177
Daemon process is running...
Child pid: 5177
Daemon process is running...
Child pid: 5177
Daemon process is running...
Child pid: 5177
Daemon process is running...
Child pid: 5177
Daemon process is running...
Child pid: 5177
Daemon process is running...
Child pid: 5177
Daemon process is running...
Child pid: 5177
Daemon process is running...
Child pid: 5177
Daemon process is running...
Child pid: 5177

output of ps
aks@aks-Virtual-Machine:~/SS/handson 1/question 30$ ps -eL | grep 5177
   5177    5177 ?        00:00:00 30.out
*/
