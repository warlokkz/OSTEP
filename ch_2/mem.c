#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"


int main(int argc, char *argv[])
{
    // allocate memory for a pointer
    int *p = malloc(sizeof(int));
    // assert that the pointer is not null
    assert(p != NULL);
    // the pid address is pointed to by this pointer
    printf("(%d) address pointed to by p: %p\n", getpid(), p);
    // reset the pointer value
    *p = 0;
    while (1) {
        Spin(1);
        // we're going to check each memory space by assigning it
        // into the pointer and incrementing it by one every second
        // then we'll check what address is pointed to by p
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);
    }
    return 0;
}
