/* 
Name: Abhishek Kumar Singh
Roll#: MT2024006
3. Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 12/9/24
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
    struct rlimit rl;
    if (getrlimit(RLIMIT_CORE, &rl) == -1) { //first we have to getlimits of core file.
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    printf("old limit of core file:\n");
    printf("Soft limit: %ld\n", rl.rlim_cur);
    printf("Hard limit: %ld\n", rl.rlim_max);
    
     rl.rlim_cur = 1024*1024*5;
     

    if (setrlimit(RLIMIT_CORE, &rl) == -1) {
        perror("setrlimit");
        exit(EXIT_FAILURE);
    }
    printf("New limit of core file:\n");
    printf("Soft limit: %ld\n", rl.rlim_cur);
    printf("Hard limit: %ld\n", rl.rlim_max);

    return 0;
}
/* output
aks@aks-Virtual-Machine:~/SS/handson 2/question 3$ gcc 3.c -o 3.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 3$ ./3.out
old limit of core file:
Soft limit: 0
Hard limit: -1
New limit of core file:
Soft limit: 5242880
Hard limit: -1
aks@aks-Virtual-Machine:~/SS/handson 2/question 3$ 
*/
