/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
11 - > WAP to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
b. use dup2()
date: 30/8/24
*/



#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void append_to_file(int fd, const char *data) {
    lseek(fd, 0, SEEK_END);  // Move to the end of the file
    write(fd, data, strlen(data)); // Write data to the file
}

void print_file_content(const char *file_path) {
    char buffer[256];
    int fd = open(file_path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(0);
    }

    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    if (bytes_read < 0) {
        perror("read");
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    int fd1, fd2;

    // open the file for the next demonstration using dup2
    fd1 = open(argv[1], O_RDWR | O_APPEND | O_CREAT, 0777);
    if (fd1 < 0) {
        perror("open");
        exit(0);
    }

    // Using dup2 to duplicate file descriptor
    fd2 = dup2(fd1, fd1 + 1);
    if (fd2 < 0) {
        perror("dup2");
        close(fd1);
        exit(0);
    }

    // Append data using both file descriptors
    append_to_file(fd1, "file question 11(B) normal FD\n");
    append_to_file(fd2, "file question 11(B) dup2() FD\n");

    // Close file descriptors
    close(fd1);
    close(fd2);

    // Print file content to check updates
    printf("File content after appending with dup2:\n");
    print_file_content(argv[1]);

    return 0;
}
/*note
The program itself shows output, but here is the file contents
file question 11(B) normal FD
file question 11(B) dup() FD
*/

