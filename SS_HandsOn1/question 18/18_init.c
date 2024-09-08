/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
18 -> Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
date: 31/8/24
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


#include <stdlib.h>
struct db{
int roll;
int marks;
}db1;



int main()
{
  struct flock locking;
  locking.l_type = F_WRLCK;
  locking.l_whence = SEEK_SET;
  locking.l_start = 0;
  locking.l_len = 0;
  
  int fd = open("record.txt",O_RDWR);
  if(fd == -1)
  {
    printf("File cannot be opened \n");
    return 0;
  }
  
  int stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    printf("Cannot obtained the lock so exiting the program \n");
    return 0;
  }
  
  db1.roll = 1;
  db1.marks = 80;
  write(fd,&db1,sizeof(db1));
  
   db1.roll = 2;
  db1.marks = 85;
  write(fd,&db1,sizeof(db1));
  
   db1.roll = 3;
  db1.marks = 90;
  write(fd,&db1,sizeof(db1));

  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  close(fd);
  
  
   fd = open("record.txt",O_RDONLY);
  locking.l_type = F_RDLCK;
  
  stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    printf("Cannot obtained the lock  for reading file so exiting the program  \n");
    exit(0);
  }
  
  
  while(read(fd,&db1,sizeof(db1)))
  {
    printf("%d  %d \n",db1.roll,db1.marks);
  }
  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  close(fd);
   

  return 0;
}
