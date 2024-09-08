/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
3 -> C program to create a file and print its file descriptor value
date: 15/8/24 (date first pushed)
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(){
printf("C program to create a file and print its file descriptor value\n");
printf("Enter a file name: ");
char filename[30];
scanf("%s",filename);
int fd = creat(filename,0777);
if(fd){
printf("file descriptor value: %d\n",fd);
}
else{
printf("Error\n");
perror("Error: ");
}
return 0;
}
/*note 
run the program, creat returns the file diesciptor value when file is successfully created.
eg.
C program to create a file and print its file descriptor value
Enter a file name: file3.txt
file descriptor value: 3

*/
