/**
 * structure.c
 *
 * memory allocation
 *   1. allocate memory
 *   2. reallocate memory
 *     2.1 new size > origin size
 *       2.1.1 has enough space after the origin address
 *       2.1.2 has't enough space after the origin address
 *     2.2 new size < origin size
 *   3. free memory
 *
 * Create By Houor
 */

#include "stdio.h"
#include "stdlib.h"

#define INIT_SIZE 16

void memory_allocation() {

    int i;

    int *mi = (int *) malloc(INIT_SIZE * sizeof(int));

    if (!mi)
        exit(0);

    printf("\nmemory address: %xH\n", mi);

    printf("\nthe value in memory before initializing...\n");
    for (i = 0; i < INIT_SIZE; i++) {
        printf("%d\t", *(mi + i));
    }
    printf("\n");


    printf("\nC program language does not protect memory boundary(memory size = 16): *(address + 100) = %d\n",
           *(mi + 100));


    printf("\n=================================\n");

    for (i = 0; i < INIT_SIZE; i++) {
        *(mi + i) = i;
    }
    printf("\nthe value in memory after initializing...\n");
    for (i = 0; i < INIT_SIZE; i++) {
        printf("%d\t", *(mi + i));
    }
    printf("\n");


    printf("\n=================================\n");

    mi = (int *) realloc(mi, 32 * sizeof(int));
    if (!mi)
        exit(0);
    printf("\nmemory address after reallocating(may have enough space): %xH\n", mi);


    mi = (int *) realloc(mi, 128 * sizeof(int));
    if (!mi)
        exit(0);
    printf("\nmemory address after reallocating(may have not enough space): %xH\n", mi);

    printf("\nthe value in memory after reallocating...\n");
    for (i = 0; i < INIT_SIZE; i++) {
        printf("%d\t", *(mi + i));
    }
    printf("\n");

    mi = (int *) realloc(mi, INIT_SIZE * sizeof(int));
    if (!mi)
        exit(0);
    printf("\nmemory address after reallocating(new size < origin size): %xH\n", mi);

    free(mi);

    *(mi + 4) = 8;

    printf("\nthe value in memory after free operation can be accessed but not safe\n");
    for (i = 0; i < INIT_SIZE; i++) {
        printf("%d\t", *(mi + i));
    }

}