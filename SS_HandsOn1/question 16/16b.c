/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
16 -> Write a program to perform mandatory locking.
b. Implement read lock multiple programs should be allowed, but no writer.
date: 30/8/24
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{
  
  
  printf("reader id: %d\n",getpid());
  int fd = open("file16.txt",O_RDONLY);
  if(fd == -1)
  {
    printf("File cannot be opened \n");
    exit(0);
  }
  struct flock locking;
  locking.l_type = F_RDLCK; //write lock
  locking.l_whence = SEEK_SET;
  locking.l_start = 0;
  locking.l_len = 0;
  fd = open("file16.txt",O_RDONLY);
  locking.l_type = F_RDLCK; // read lock
  
  int stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    printf("Cannot obtain read lock \n");
    exit(0);
  }
  
  char ss[80];; //buffer for reading
  
  while(read(fd,ss,1))
  {
    printf("%c",ss[0]);
  }
  printf("press a key to unlock\n");
  while(1){
  if(getc(stdin)) break;
  } //this loop is there to prevent instant unlocking
  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  close(fd);
  
  return 0;

}
/*note
I run 2 readers at same time.
reader 1
aks@aks-Virtual-Machine:~/SS/handson 1/question 16$ ./16b.out
reader id: 10166
writing in file 
press a key to unlock

reader 2
aks@aks-Virtual-Machine:~/SS/handson 1/question 16$ ./16b.out
reader id: 10170
writing in file 
press a key to unlock



*/
