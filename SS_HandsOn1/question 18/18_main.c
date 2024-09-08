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

    printf("There are total 3 records in the file \n select the record to perform read or write operation on 1 or 2 or 3 \n");
    int n;
    scanf("%d",&n);
    if(n > 3 || n <1)
    {
        printf("Invalid input so terminating program \n");
        exit(0);
    }
    
    printf("press 1-> read\n2-> write (default 1). \n");
    int t;
    scanf("%d",&t);
    struct flock locking;
  if(t == 2)
  locking.l_type = F_WRLCK;
  else
  locking.l_type = F_RDLCK;
  
  
    
    int fd = open("record.txt",O_RDWR);
  if(fd == -1)
  {
    perror("File cannot be opened \n");
    exit(0);
  }
  
  
  
  locking.l_whence = SEEK_SET;
  locking.l_start = sizeof(db1)*(n-1);
  locking.l_len = sizeof(db1);
  int stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    perror("Cannot obtained the lock for writing so exiting the program \n");
    exit(0);
  }
  
  if(t == 2)
  {
      printf("Enter the roll number : ");
      scanf("%d",&(db1.roll));
      printf("Enter the marks : ");
      scanf("%d",&(db1.marks));
      lseek(fd,sizeof(db1)*(n-1),SEEK_SET);
      write(fd,&db1,sizeof(db1));
      
  }
  else
  {
      lseek(fd,sizeof(db1)*(n-1),SEEK_SET);
      if(read(fd,&db1,sizeof(db1)))
      {
            printf("%d  %d\n",db1.roll, db1.marks);
      }
      else
      {
          perror("Error while reading file \n");
          
      }
  }
  
  
  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  close(fd);
  
  printf("Contents of the records after modification : \n");
  
  
  fd = open("record.txt",O_RDONLY);
  locking.l_type = F_RDLCK;
  
  stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    perror("Cannot obtained the lock  for reading file so exiting the program  \n");
    exit(0);
  }
  
  
  while(read(fd,&db1,sizeof(db1)))
  {
    printf("%d  %d \n",db1.roll,db1.marks);
  }
  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  close(fd);
    
}
/*note
first run the 18_init program. record.txt must pre exist.
aks@aks-Virtual-Machine:~/SS/handson 1/question 18$ ./18_init.out
1  80 
2  85 
3  90 
aks@aks-Virtual-Machine:~/SS/handson 1/question 18$ ./18_main.out
There are total 3 records in the file 
 select the record to perform read or write operation on 1 or 2 or 3 
3
press 1-> read
2-> write (default 1). 
1
3  90
Contents of the records after modification : 
1  80 
2  85 
3  90 
aks@aks-Virtual-Machine:~/SS/handson 1/question 18$ 


*/
