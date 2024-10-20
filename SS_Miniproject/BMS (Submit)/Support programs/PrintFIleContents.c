#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../AllStructures/allStruct.h"

#define EMPPATH "../db/employee.db"
#define CUSPATH "../db/customer.db"
#define LOANPATH "../db/loan.db"
#define COUNTERPATH "../db/counter.db"
#define HISTORYPATH "../db/history.db"
#define FEEDPATH "../db/feedback.db"

int main()
{
    FILE *f1 = fopen(CUSPATH, "rb+");
    FILE *f2 = fopen(EMPPATH, "rb+");
    FILE *f3 = fopen(LOANPATH, "rb+");
    FILE *f4 = fopen(HISTORYPATH, "rb");
    FILE *f5 = fopen(FEEDPATH, "rb");
    FILE *f6 = fopen(COUNTERPATH, "rb+");

    /*********** Initialize Loan Counter *********** */
    // comment after first run
    struct Counter ct;
    ct.count = 0;
    fwrite(&ct, sizeof(ct), 1, f4);
    printf("%d", ct.count);
    fclose(f4);

    struct Customer temp;
    struct Employee temp1;
    struct LoanDetails temp2;
    struct trans_histroy th;
    struct FeedBack fb;

    printf("/*****customers details*****/\n");
    rewind(f1);
    while (fread(&temp, sizeof(temp), 1, f1) > 0)
    {
        printf("Name: %s\n", temp.Name);
        printf("Account Number: %d\n", temp.accountNumber);
        printf("Balance: %.2f\n", temp.balance);
        printf("Status: %d\n", temp.activeStatus);
        printf("password: %s\n", temp.password);
        printf("*********************************************\n");
    }
    fclose(f1);

    printf("/*****employees details*****/\n");
    rewind(f2);
    while (fread(&temp1, sizeof(temp1), 1, f2) > 0)
    {
        printf("Emp ID: %d\n", temp1.empID);
        printf("FirstName: %s\n", temp1.Name);
        printf("Role: %d\n", temp1.role);
        printf("Password: %s\n", temp1.password);
        printf("*********************************************\n");
    }
    fclose(f2);

    printf("/*****loan details*****/\n");
    rewind(f3);
    while (fread(&temp2, sizeof(temp2), 1, f3) > 0)
    {
        printf("Emp ID: %d\n", temp2.empID);
        printf("Acc No: %d\n", temp2.accountNumber);
        printf("Loan Amount: %d\n", temp2.loanAmount);
        printf("Status: %d\n", temp2.status);
        printf("Loan ID: %d\n", temp2.loanID);
        printf("*********************************************\n");
    }
    fclose(f3);

    printf("/*****all transections details*****/\n");
    rewind(f4);
    while (fread(&th, sizeof(th), 1, f4) > 0)
    {
        printf("Account Number: %d\n", th.acc_no);
        printf("Transaction: %s\n", th.hist);
        printf("*********************************************\n");
    }
    fclose(f4);

    printf("\n/*****feedback details*****/\n");
    rewind(f5);
    while (fread(&fb, sizeof(fb), 1, f5) > 0)
    {
        printf("%s\n", fb.feedback);
        printf("*********************************************\n");
    }
    fclose(f5);

    return 0;
}