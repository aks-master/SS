/* 
Name: Abhishek Kumar Singh
Roll#: MT2024006
2 Write a program to print the system resource limits. Use getrlimit system call
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

void print_resource_limit(int res, const char *resdes) {
    struct rlimit r;

    if (getrlimit(res, &r) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    printf("%s: ", resdes);
    printf("\tSoft limit: %ld\tHard limit: %ld\n", r.rlim_cur, r.rlim_max);
}

int main() {
    printf("Some System Resource Limits:\n");

    print_resource_limit(RLIMIT_AS, "Virtual memory Address Space");
    print_resource_limit(RLIMIT_CORE, "This is the maximum size of a core file in bytes");
    print_resource_limit(RLIMIT_CPU, "This is a limit, in seconds, on the amount of CPU time that the process can consume");
    print_resource_limit(RLIMIT_DATA, "max amount of memory a program can aloocate for its data segment in bytes: ");
    print_resource_limit(RLIMIT_FSIZE, "This is the maximum size in bytes of files that the process may create. ");
    
    
    printf("\nThere are more System Resource Limits: use man page learn more about getrlimit\n");
    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 2$ gcc 2.c -o 2.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 2$ ./2.out
Some System Resource Limits:
Virtual memory Address Space: 	Soft limit: -1	Hard limit: -1
This is the maximum size of a core file in bytes: 	Soft limit: 0	Hard limit: -1
This is a limit, in seconds, on the amount of CPU time that the process can consume: 	Soft limit: -1	Hard limit: -1
max amount of memory a program can aloocate for its data segment in bytes: : 	Soft limit: -1	Hard limit: -1
This is the maximum size in bytes of files that the process may create. : 	Soft limit: -1	Hard limit: -1

There are more System Resource Limits: use man page learn more about getrlimit
aks@aks-Virtual-Machine:~/SS/handson 2/question 2$ 

*/
