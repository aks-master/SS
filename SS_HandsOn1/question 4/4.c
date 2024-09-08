/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
4 -> C program to open an existing  file
date: 15/8/24 (date first pushed)
*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
int main()
{
    printf("C program to open an existing file\n");
    printf("Enter a file name: ");
    char filename[30];
    scanf("%s", filename);
    int fd = open(filename, O_RDWR | O_EXCL);
    perror("message: ");
    return 0;
}
/*note
open system call return fd when successful. perror() will give respective message based on weather file is present or not.
eg:
(if file is present)
C program to open an existing file
Enter a file name: file4.txt
message: : Success

(if file is not present)
C program to open an existing file
Enter a file name: file
message: : No such file or directory
*/
