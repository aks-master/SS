/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
13 -> Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
date: 30/8/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
int main()
{
fd_set rfds;
struct timeval tv;
int retval;
/* Watch stdin (fd 0) to see when it has input. */
FD_ZERO(&rfds);
FD_SET(0, &rfds);
/* Wait up to five seconds. */
tv.tv_sec = 10;
tv.tv_usec = 0;
retval = select(1, &rfds, NULL, NULL, &tv);
/* Don't rely on the value of tv now! */
if (retval == -1)
    perror("select(): ");
else if (retval)
    printf("Data is available within 10 seconds.\n");
/* FD_ISSET(0, &rfds) will be true. */
else
    printf("Data is not available within 10 seconds.\n");
return 0;
}
/*note
eg output:
aks@aks-Virtual-Machine:~/SS/handson 1/question 13$ ./13.out
aks
Data is available within 10 seconds.

*/

