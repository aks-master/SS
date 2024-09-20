#include <errno.h>

char *fifo_A_write = "./21-fifo_A_write";
char *fifo_B_write = "./21-fifo_B_write";

void init()
{
    int fifo_A_status, fifo_B_status; // Determines the success of the `mkfifo` call

    fifo_A_status = mkfifo(fifo_A_write, S_IRWXU);
    if (!(errno == EEXIST || fifo_A_status != -1))
        perror("Error while creating FIFO file fifo_A_write");

    fifo_B_status = mkfifo(fifo_B_write, S_IRWXU);
    if (!(errno == EEXIST || fifo_B_status != -1))
        perror("Error while creating FIFO file fifo_B_write");
}