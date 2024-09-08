/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
26 -> Write a program to execute an executable program.
b. pass some input to an executable program.
Date: 31/8/24
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <argument>\n", argv[0]);
        return 1;
    }

    printf("External program received argument: %s\n", argv[1]);
    return 0;
}

