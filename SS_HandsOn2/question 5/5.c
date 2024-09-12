/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

5. Write a program to print the system limitation of
	a. maximum length of the arguments to the exec family of functions.
	b. maximum number of simultaneous process per user id.
	c. number of clock ticks (jiffy) per second.
	d. maximum number of open files
	e. size of a page
	f. total number of pages in the physical memory
	g. number of currently available pages in the physical memory.

Date: 12/9/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    // a. Maximum length of the arguments to the exec family of functions
    long max_arg_length = sysconf(_SC_ARG_MAX);
    if (max_arg_length == -1) {
        perror("sysconf");
        exit(EXIT_FAILURE);
    }
    printf("A. Maximum length of arguments to exec functions: %ld bytes\n", max_arg_length);

    // b. Maximum number of simultaneous processes per user ID
    struct rlimit rl;
    if (getrlimit(RLIMIT_NPROC, &rl) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }
    printf("B. Maximum number of simultaneous processes per user ID: %ld\n", rl.rlim_max);

    // c. Number of clock ticks (jiffies) per second
    long clk_tck = sysconf(_SC_CLK_TCK);
    if (clk_tck == -1) {
        perror("sysconf");
        exit(EXIT_FAILURE);
    }
    printf("C. Number of clock ticks (jiffies) per second: %ld\n", clk_tck);

    // d. Maximum number of open files
    if (getrlimit(RLIMIT_NOFILE, &rl) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }
    printf("D. Maximum number of open files: %ld\n", rl.rlim_max);

    // e. Size of a page
    long page_size = sysconf(_SC_PAGESIZE);
    if (page_size == -1) {
        perror("sysconf");
        exit(EXIT_FAILURE);
    }
    printf("E. Size of a page: %ld bytes\n", page_size);

    // f. Total number of pages in the physical memory
    struct sysinfo si;
    if (sysinfo(&si) == -1) {
        perror("sysinfo");
        exit(EXIT_FAILURE);
    }
    long total_pages = si.totalram / page_size;
    printf("F. Total number of pages in the physical memory: %ld\n", total_pages);

    // g. Number of currently available pages in the physical memory
    long free_pages = si.freeram / page_size;
    printf("G. Number of currently available pages in the physical memory: %ld\n", free_pages);

    return 0;
}
/*
aks@aks-Virtual-Machine:~/SS/handson 2/question 5$ gcc 5.c -o 5.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 5$ ./5.out
A. Maximum length of arguments to exec functions: 2097152 bytes
B. Maximum number of simultaneous processes per user ID: 15441
C. Number of clock ticks (jiffies) per second: 100
D. Maximum number of open files: 1048576
E. Size of a page: 4096 bytes
F. Total number of pages in the physical memory: 2064300
G. Number of currently available pages in the physical memory: 781645
aks@aks-Virtual-Machine:~/SS/handson 2/question 5$ 
*/

