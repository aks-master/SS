/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
21. Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 20/9/24
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./common.h" // Import for FIFO file name & `init` function

void main()
{
    int readBytes, writeBytes;
    int fifo_A_writeFD, fifo_B_writeFD;
    char data[100];

    init();

    fifo_A_writeFD = open(fifo_A_write, O_WRONLY);
    if (fifo_A_writeFD == -1)
    {
        perror("error: ");
        exit(0);
    }

    fifo_B_writeFD = open(fifo_B_write, O_RDONLY);
    if (fifo_B_writeFD == -1)
    {
        perror("error: ");
        exit(0);
    }

    writeBytes = write(fifo_A_writeFD, "From 21A to 21B", 15);

    if (writeBytes == -1)
        perror("error: ");

    close(fifo_A_writeFD);

    readBytes = read(fifo_B_writeFD, &data, 100);

    if (readBytes == -1)
    {
        perror("error: ");
        exit(0);
    }

    printf("Data from FIFO: %s\n", data);

    close(fifo_B_writeFD);
}

/*output
aks@aks-Virtual-Machine:~/SS/Handson 2/question 21$ ./21A.out
Data from FIFO: From 21B to 21A
aks@aks-Virtual-Machine:~/SS/Handson 2/question 21$
*/
