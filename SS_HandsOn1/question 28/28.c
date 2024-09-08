/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
28 -> Write a program to get maximum and minimum real time priority.
Date: 31/8/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>

int main() {
    // Real-time scheduling policies
    int policies[] = { SCHED_FIFO, SCHED_RR };
    const char *policy_names[] = { "SCHED_FIFO", "SCHED_RR" };
    int num_policies = sizeof(policies) / sizeof(policies[0]);

    for (int i = 0; i < num_policies; i++) {
        int policy = policies[i];
        int max_priority, min_priority;

        // Get maximum priority for the policy
        max_priority = sched_get_priority_max(policy);
        if (max_priority == -1) {
            perror("sched_get_priority_max");
            exit(EXIT_FAILURE);
        }

        // Get minimum priority for the policy
        min_priority = sched_get_priority_min(policy);
        if (min_priority == -1) {
            perror("sched_get_priority_min");
            exit(EXIT_FAILURE);
        }

        // Print results
        printf("Scheduling Policy: %s\n", policy_names[i]);
        printf("Maximum Priority: %d\n", max_priority);
        printf("Minimum Priority: %d\n", min_priority);
        printf("\n");
    }

    return 0;
}

/*note
eg output:
aks@aks-Virtual-Machine:~/SS/handson 1/question 28$ ./28.out
Scheduling Policy: SCHED_FIFO
Maximum Priority: 99
Minimum Priority: 1

Scheduling Policy: SCHED_RR
Maximum Priority: 99
Minimum Priority: 1

aks@aks-Virtual-Machine:~/SS/handson 1/question 28$ 
*/
