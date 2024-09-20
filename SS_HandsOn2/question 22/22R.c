/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 20/9/24
*/
#include <sys/types.h> // Import for `open`, `select`
#include <sys/stat.h>  // Import for `open`
#include <fcntl.h>     // Import for `open`
#include <sys/time.h>  // Import for `select`
#include <unistd.h>    // Import for `select`, `read`
#include <stdio.h>     // Import for `perror`

#include "./common.h" // Import for FIFO file name

void main()
{
    int fileDescriptor, readBytes;
    char data[100];

    fd_set readFDSet;
    struct timeval timer;
    int selectStatus;

    init();

    fileDescriptor = open(fifoName, O_NONBLOCK | O_RDONLY);

    if (fileDescriptor == -1)
    {
        perror("Error while opening FIFO file!");
        _exit(0);
    }

    FD_ZERO(&readFDSet);
    FD_SET(fileDescriptor, &readFDSet); // Adding FIFO file's descriptor to the set of file descriptors to read from

    // Setting the time to wait to 10s
    timer.tv_sec = 10;
    timer.tv_usec = 0;

    selectStatus = select(fileDescriptor + 1, &readFDSet, NULL, NULL, &timer);

    if (selectStatus == -1)
        perror("Error while calling for select!");
    else if (selectStatus)
    {
        readBytes = read(fileDescriptor, &data, 100);

        if (readBytes == -1)
            perror("Error while reading from FIFO!");
        else
            printf("Data received : %s\n", data);
    }
    else
        printf("You didn't send any data for 10 seconds! :(\n");

    close(fileDescriptor);
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 22$ gcc 22R.c -o 22R.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 22$ gcc 22W.c -0 22W.out
gcc: error: unrecognized command-line option ‘-0’
aks@aks-Virtual-Machine:~/SS/Handson 2/question 22$ gcc 22W.c -o 22W.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 22$ ./22R.out
Data received : Hello there...
aks@aks-Virtual-Machine:~/SS/Handson 2/question 22$

*/