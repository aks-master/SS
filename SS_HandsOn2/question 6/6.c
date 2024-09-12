/*
Name: Abhishek Kumar Singh
Roll#: MT2024006

6. Write a simple program to create three threads.

Date: 12/9/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function
void *thread_function(void *n) {
    printf("Hello from thread %d\n", *(int *)n);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int i;

    // Create three threads
    for (i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, (void *)&i)) {
            perror("error: ");
            exit(0);
        }
    }

    // Wait for all threads to complete
    for (i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("error");
            exit(0);
        }
    }

    printf("All threads have finished.\n");
    return 0;
}
/* output
aks@aks-Virtual-Machine:~/SS/handson 2/question 6$ gcc 6.c -o 6.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 6$ ./6.out
Hello from thread 0
Hello from thread 0
Hello from thread 0
All threads have finished.
aks@aks-Virtual-Machine:~/SS/handson 2/question 6$ ./6.out
Hello from thread 2
Hello from thread 2
Hello from thread 0
All threads have finished.
aks@aks-Virtual-Machine:~/SS/handson 2/question 6$ ./6.out
Hello from thread 1
Hello from thread 0
Hello from thread 2
All threads have finished.
aks@aks-Virtual-Machine:~/SS/handson 2/question 6$ 


*/

