/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
10 -> WAP to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data. (you have to open terminal and type od -c <filename>.
date: 17/8/24 (date first pushed)
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
int main()
{
    printf("Enter a file name: This program open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.\n:");
    char filename[30];
    scanf("%s", filename);
    int FD = open(filename, O_RDWR | O_CREAT, 0777);
    if (FD == -1)
    {
        perror("open error");
        exit(0);
    }

    char *data1 = "1516171819"; // data to write first 10 bytes
    int written1 = write(FD, data1, strlen(data1));
    if (written1 == -1)
    {
        perror("write error");
        close(FD);
        exit(0);
    }

    // Move the file pointer by 10 bytes
    int offset = lseek(FD, 10, SEEK_CUR);
    if (offset == -1)
    {
        perror("lseek");
        close(FD);
        exit(0);
    }
    // printf("lseek value after moving 10 bytes %d\n",offset);
    // data to write second 10 bytes
    char *data2 = "2021222324";
    int written2 = write(FD, data2, strlen(data2));
    if (written2 == -1)
    {
        perror("write");
        close(FD);
        exit(0);
    }

    // Close the file
    close(FD);
    return 0;
}
/*note.
eg output:
aks@aks-Virtual-Machine:~/SS/handson 1/question 10$ od -c aks.txt
0000000   1   5   1   6   1   7   1   8   1   9  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   2   0   2   1   2   2   2   3   2   4
0000036
aks@aks-Virtual-Machine:~/SS/handson 1/question 10$ ^C
aks@aks-Virtual-Machine:~/SS/handson 1/question 10$

*/
