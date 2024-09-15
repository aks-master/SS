
/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
7. Write a simple program to print the created thread ids.
Date: 12/9/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function that each thread will execute
void* print_thread_id(void* arg) {
    pthread_t thread_id = pthread_self();
    printf("thread id: %lu\n", (unsigned long)thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];

    // Create and start several threads
    for (int i = 0; i < 3; ++i) {
        if (pthread_create(&threads[i], NULL, print_thread_id, NULL)) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < 3; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

/*output
aks@aks-Virtual-Machine:~/SS/handson 2/question 7$ gcc 7.c -o 7.out
aks@aks-Virtual-Machine:~/SS/handson 2/question 7$ ./7.out
thread id: 124286150899264
thread id: 124286134113856
thread id: 124286142506560
aks@aks-Virtual-Machine:~/SS/handson 2/question 7$ 
*/