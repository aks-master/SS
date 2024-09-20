/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
21. Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 20/9/24
*/
#include <sys/types.h> // Import for & `open`
#include <sys/stat.h>  // Import for & `open`
#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `write`
#include <stdio.h>     // Import for `perror`
#include <stdlib.h>
#include "./common.h" // Import for FIFO file name & `init` function

int main()
{
    int readBytes, writeBytes;
    int fifo_A_writeFD, fifo_B_writeFD;
    char data[100];

    init();

    fifo_A_writeFD = open(fifo_A_write, O_RDONLY);
    if (fifo_A_writeFD == -1)
    {
        perror("error: ");
        exit(0);
    }

    fifo_B_writeFD = open(fifo_B_write, O_WRONLY);
    if (fifo_B_writeFD == -1)
    {
        perror("error: ");
        exit(0);
    }

    writeBytes = write(fifo_B_writeFD, "From 21B to 21A", 15);

    if (writeBytes == -1)
        perror("error: ");

    close(fifo_B_writeFD);

    readBytes = read(fifo_A_writeFD, &data, 100);

    if (readBytes == -1)
    {
        perror("error: ");
        exit(0);
    }

    printf("Data from FIFO: %s\n", data);

    close(fifo_A_writeFD);
    return 0;
}
/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 21$ gcc 21B.c -o 21B.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 21$ ./21B.out
Data from FIFO: From 21A to 21B
aks@aks-Virtual-Machine:~/SS/Handson 2/question 21$
*/