/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
26 -> Write a program to execute an executable program.
b. pass some input to an executable program.
Date: 31/8/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *executable = "./26b_executable.out";  // Path to the executable program
    char *args[] = { "26b_executable.out", "HelloWorld", NULL };  // Arguments to pass to the executable

    // Execute the external program
    execvp(executable, args);

    // If execvp returns, there was an error
    perror("execvp");
    return EXIT_FAILURE;
}
/*note 
eg output
aks@aks-Virtual-Machine:~/SS/handson 1/question 26$ gcc 26b_main.c -o 26b_main.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 26$ gcc 26b_executable.c -o 26b_executable.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 26$ ./26b_main.out 
External program received argument: HelloWorld
aks@aks-Virtual-Machine:~/SS/handson 1/question 26$ 

*/

