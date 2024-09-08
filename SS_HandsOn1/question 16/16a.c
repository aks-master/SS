/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
16 -> Write a program to perform mandatory locking.
a. Implement write lock. (No other program allowed)
date: 30/8/24
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  
  
  printf("writer id: %d\n",getpid());
  int fd = open("file16.txt",O_WRONLY|O_APPEND);
  if(fd == -1)
  {
    printf("File cannot be opened \n");
    exit(0);
  }
  struct flock locking;
  locking.l_type = F_WRLCK; //write lock
  locking.l_whence = SEEK_SET;
  locking.l_start = 0;
  locking.l_len = 0;
  
  
  int stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    printf("Cannot obtain write lock \n");
    exit(0);
  }
  char *buffer = "writing in file \n";
  write(fd,buffer,strlen(buffer));
  printf("press a key to unlock\n");
  while(1){
  if(getc(stdin)) break;
  } //this loop is there to prevent instant unlocking
  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  
  close(fd);  
  return 0;

}
/*note:
I run 2 writers at same time:
writer 1
aks@aks-Virtual-Machine:~/SS/handson 1/question 16$ ./16a.out
writer id: 9829
press a key to unlock

writer 2
aks@aks-Virtual-Machine:~/SS/handson 1/question 16$ ./16a.out
writer id: 9805
Cannot obtain write lock 
aks@aks-Virtual-Machine:~/SS/handson 1/question 16$ 
*/

