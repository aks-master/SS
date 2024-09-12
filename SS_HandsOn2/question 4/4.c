/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 12/9/24
*/

#include <stdio.h>
#include <stdint.h>
#include <unistd.h> 

// Function to read the Time Stamp Counter
static inline uint64_t rdtsc() {
    unsigned int hi, lo;
    // Use inline assembly to read the TSC
    __asm__ volatile("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)lo) | (((uint64_t)hi) << 32);
}

int main() {
    uint64_t start, end;
    int pid;

    // Read TSC before getpid()
    start = rdtsc();

    // Call getpid() system call
    for(int i=0;i<100;i++)
    pid = getpid();

    // Read TSC after getpid()
    end = rdtsc();

    // Calculate the time taken in CPU cycles
    uint64_t num_cycles = end - start;
    //calculate time in seconds
    /*
    assume 4 Ghz processor.
    4x10^9 cycles per second
    1 cycle = 1/(4x10^9) seconds
    x cycles = x/(4x10^9) seconds
    =x/4 nano seconds as 1 sec= 10^9 ns
    */
    
    double ns = num_cycles/4;

    // Output the results
    printf("Time taken for getpid(): %lf nano seconds\n", ns);

    return 0;
}
/*note
eg output
aks@aks-Virtual-Machine:~/SS/handson 2/question 4$ gcc 4.c -o 4.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 4$ ./4.out
Time taken for getpid(): 19594.000000 nano seconds
aks@aks-Virtual-Machine:~/SS/handson 2/question 4$ 

*/
