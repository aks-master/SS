/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
6 -> WAP to read from stdin and output on stdout
date: 17/8/24 (date first pushed)
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    char message[80];
    printf("Program to read from STDIN and write on STDOUT (Limit: 80 characters)\n");
    int charRead = read(STDIN_FILENO, message, 80);
    // int size=strlen(message);
    // printf("%d\n",charRead);
    write(STDOUT_FILENO, message, charRead);

    return 0;
}
/*note
eg.
aks@aks-Virtual-Machine:~/SS/handson 1/question 6$ ./6.out
Program to read from STDIN and write on STDOUT (Limit: 80 characters)
AKS is a good boy
AKS is a good boy
aks@aks-Virtual-Machine:~/SS/handson 1/question 6$


*/
