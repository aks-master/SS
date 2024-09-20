/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
20. Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 20/9/24
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    int fifoStatus;
    char data[] = "Sending data to pipe_20!";
    int fileDescriptor;
    char *fifoPipe = "./pipe_20";
    int writeBytes;

    fifoStatus = mkfifo(fifoPipe, S_IRWXU);

    if (fifoStatus == -1)
        perror("Error while creating FIFO file!");
    fileDescriptor = open(fifoPipe, O_WRONLY);
    if (fileDescriptor == -1)
        perror("Error while opening FIFO file for writing");
    else
    {
        writeBytes = write(fileDescriptor, &data, sizeof(data));
        if (writeBytes == -1)
            perror("Error while writing to the file!");
        close(fileDescriptor);
    }
}
/*
aks@aks-Virtual-Machine:~/SS/Handson 2/question 20$ ./20W.out
aks@aks-Virtual-Machine:~/SS/Handson 2/question 20$
*/