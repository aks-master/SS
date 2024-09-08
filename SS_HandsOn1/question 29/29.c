/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
29 -> Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 31/8/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>

void print_scheduler(int policy) {
    switch (policy) {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        default:
            printf("Current scheduling policy: UNKNOWN (%d)\n", policy);
            break;
    }
}

int main() {
    int policy;
    struct sched_param param;

    // Get the current scheduling policy
    policy = sched_getscheduler(0); // 0 refers to the current process

    if (policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    print_scheduler(policy);

    // Prompt user for new scheduling policy
    printf("Choose new scheduling policy (1 for SCHED_FIFO, 2 for SCHED_RR): ");
    int choice;
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        fprintf(stderr, "Invalid choice.\n");
        exit(EXIT_FAILURE);
    }

    int new_policy = (choice == 1) ? SCHED_FIFO : SCHED_RR;
    param.sched_priority = 10; // Set a reasonable priority (1-99 for FIFO and RR)

    // Set the new scheduling policy
    if (sched_setscheduler(0, new_policy, &param) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    // Verify the change
    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    print_scheduler(policy);
    printf("Scheduling policy changed successfully.\n");

    return 0;
}
/*note
run the program as superuser otherwise it will fail to change scheduling policy.
eg output
aks@aks-Virtual-Machine:~/SS/handson 1/question 29$ sudo ./29.out
[sudo] password for aks: 
Current scheduling policy: SCHED_OTHER
Choose new scheduling policy (1 for SCHED_FIFO, 2 for SCHED_RR): 1
Current scheduling policy: SCHED_FIFO
Scheduling policy changed successfully.
aks@aks-Virtual-Machine:~/SS/handson 1/question 29$ 
*/

