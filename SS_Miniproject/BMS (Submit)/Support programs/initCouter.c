#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "../AllStructures/allStruct.h"
#define COUNTERPATH "../db/counter.db"

int main()
{
    int f6 = open(COUNTERPATH, O_CREAT | O_RDONLY, 0644);

    /*********** Initialize Loan Counter *********** */

    struct Counter ct;
    ct.count = 0;
    lseek(f6, 0, SEEK_SET);
    int returnValue = write(f6, &ct, sizeof(ct));
    struct Counter new;
    // lseek(f6, -sizeof(new), SEEK_CUR);
    // returnValue = read(f6, &new, sizeof(new));
    // printf(" counter: %d", new.count);
    close(f6);
    return 0;
}