/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
9-> WAP to get information about file
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
date: 17/8/24 (date first pushed)
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{ // as argv[0] is program name itself. there must be two arguments.
		printf("Wrong way to use this program");
		exit(0);
	}
	struct stat info;
	int ret = stat(argv[1], &info);
	if (ret == -1)
	{
		perror("error: ");
		exit(0);
	}
	printf("\n %s info fo file \n", argv[1]);
	printf("A. inode: %ld\n", info.st_ino);
	printf("B. number of hard links: %ld\n", info.st_nlink);
	printf("C. uid: %d\n", info.st_uid);
	printf("D. gid: %d\n", info.st_gid);
	printf("E. size: %ld\n", info.st_size);
	printf("F. block size: %ld\n", info.st_blksize);
	printf("G. number of blocks: %ld\n", info.st_blocks);
	printf("H. time of last access: %s\n", ctime(&info.st_atim.tv_sec));
	printf("I. time of last modification: %s\n", ctime(&info.st_mtim.tv_sec));
	printf("J. time of last change: %s\n", ctime(&info.st_ctim.tv_sec));
	return 0;
}
/* note
to check info of a file using this program pass the filename as command line argument.
eg output.
aks@aks-Virtual-Machine:~/SS/handson 1/question 9$ gcc 9.c -o 9.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 9$ ./9.out 9.out

 9.out info fo file
A. inode: 1063741
B. number of hard links: 1
C. uid: 1000
D. gid: 1000
E. size: 16176
F. block size: 4096
G. number of blocks: 32
H. time of last access: Wed Aug 28 09:15:37 2024

I. time of last modification: Wed Aug 28 09:15:26 2024

J. time of last change: Wed Aug 28 09:15:26 2024

aks@aks-Virtual-Machine:~/SS/handson 1/question 9$
*/
