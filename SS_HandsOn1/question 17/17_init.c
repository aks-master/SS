/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
17 -> Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
date: 31/8/24
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("ticket.dat", "w");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Initialize ticket number
    int ticket_number = 1000;
    if (fprintf(file, "%d", ticket_number) < 0) {
        perror("fprintf");
        fclose(file);
        return EXIT_FAILURE;
    }

    fclose(file);
    printf("Ticket number initialized to %d\n", ticket_number);
    return EXIT_SUCCESS;
}

