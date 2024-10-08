/*
Name: Abhishek Kumar Singh
Roll #: MT2024006
20. Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 20/9/24
*/
#include <sys/types.h> // Import for `open`
#include <sys/stat.h>  // Import for `open`
#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `read`
#include <stdio.h>     // Import for `perror` & `printf`

int main()
{
    int fileDescriptor;           // File descriptor of the FIFO file
    char *fifoFile = "./pipe_20"; // Path name of the FIFO file
    int readBytes;                // Number of bytes read from the FIFO file
    char data[100];               // Data from the FIFO file

    fileDescriptor = open(fifoFile, O_RDONLY);

    if (fileDescriptor == -1)
        perror("Error while opening the FIFO file!");
    else
    {
        readBytes = read(fileDescriptor, data, 100);
        if (readBytes == -1)
            perror("Error while reading from the FIFO file!");
        else
        {
            printf("Read bytes : %d\n", readBytes);
            printf("Data from the FIFO file - %s\n", data);
        }
        close(fileDescriptor);
    }
    return 0;
}
/*
aks@aks-Virtual-Machine:~/SS/Handson 2/question 20$ ./20R.out
Read bytes : 25
Data from the FIFO file - Sending data to pipe_20!
aks@aks-Virtual-Machine:~/SS/Handson 2/question 20$
*/