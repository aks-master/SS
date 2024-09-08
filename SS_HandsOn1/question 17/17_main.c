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
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

// Define file path
#define FILE_PATH "ticket.dat"

// Define the lock file descriptor
#define LOCK_FILE "ticket.lock"

int main() {
    int fd;
    int ticket_number;
    FILE *file;
    int lock_fd;

    // Open the ticket file
    file = fopen(FILE_PATH, "r+");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Open a lock file descriptor for write lock
    lock_fd = open(LOCK_FILE, O_CREAT | O_WRONLY, 0666);
    if (lock_fd < 0) {
        perror("open lock file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Apply write lock
    struct flock lock;
    lock.l_type = F_WRLCK;  // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // Lock the entire file
    if (fcntl(lock_fd, F_SETLKW, &lock) < 0) {
        perror("fcntl");
        close(lock_fd);
        fclose(file);
        return EXIT_FAILURE;
    }

    // Read the ticket number
    if (fscanf(file, "%d", &ticket_number) != 1) {
        perror("fscanf");
        lock.l_type = F_UNLCK;  // Release the lock
        fcntl(lock_fd, F_SETLK, &lock);
        close(lock_fd);
        fclose(file);
        return EXIT_FAILURE;
    }

    // Increment the ticket number
    ticket_number++;

    // Go to the beginning of the file and write the new ticket number
    fseek(file, 0, SEEK_SET);
    if (fprintf(file, "%d", ticket_number) < 0) {
        perror("fprintf");
        lock.l_type = F_UNLCK;  // Release the lock
        fcntl(lock_fd, F_SETLK, &lock);
        close(lock_fd);
        fclose(file);
        return EXIT_FAILURE;
    }

    // Release the lock
    lock.l_type = F_UNLCK;  // Unlock
    if (fcntl(lock_fd, F_SETLK, &lock) < 0) {
        perror("fcntl unlock");
        close(lock_fd);
        fclose(file);
        return EXIT_FAILURE;
    }

    close(lock_fd);
    fclose(file);

    printf("New ticket number: %d\n", ticket_number);
    return EXIT_SUCCESS;
}
/*note
first run 17_init.out
eg output
aks@aks-Virtual-Machine:~/SS/handson 1/question 17$ gcc 17_init.c -o 17_init.out
aks@aks-Virtual-Machine:~/SS/handson 1/question 17$ ./17_init.out
Ticket number initialized to 1000
aks@aks-Virtual-Machine:~/SS/handson 1/question 17$ gcc 17_main.c -o 17_main.outaks@aks-Virtual-Machine:~/SS/handson 1/question 17$ ./17_main.out
New ticket number: 1001
aks@aks-Virtual-Machine:~/SS/handson 1/question 17$ ./17_main.out
New ticket number: 1002
aks@aks-Virtual-Machine:~/SS/handson 1/question 17$ ./17_main.out
New ticket number: 1003
aks@aks-Virtual-Machine:~/SS/handson 1/question 17$ 
*/
