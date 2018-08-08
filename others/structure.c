/**
 * structure.c
 *
 * test for structure
 *
 * Create By Houor
 */

#include "stdio.h"
#include "stdlib.h"

struct SomeDateTypeInAStructure {
    int a;
    float b;
    char c;
};

struct LinkNode {
    int data;
    struct LinkNode *next;
};

void test_struct() {

    struct SomeDateTypeInAStructure sdts;

    sdts.a = 1;
    sdts.b = 2.0;
    sdts.c = 'c';

    printf("Use data by . operator:\n");

    printf("\tint in struct: %d\n", sdts.a);
    printf("\tlong in struct: %f\n", sdts.b);
    printf("\tchar in struct: %c\n", sdts.c);

    printf("\nUse data by pointer and -> operator:\n");

    struct SomeDateTypeInAStructure *pco = &sdts;
    printf("\tint in struct: %d\n", pco->a);
    printf("\tlong in struct: %f\n", pco->b);
    printf("\tchar in struct: %c\n", pco->c);

    printf("\nthe size of struct:\n");
    printf("\tthe size of struct calculating by the data in struct: ");
    printf("%lu\n", sizeof(int) + sizeof(float) + sizeof(char));
    printf("\tthe actual size: ");
    printf("%lu\n", sizeof(struct SomeDateTypeInAStructure));

    printf("\nTest for LinkNode: \n");

    struct LinkNode n1;
    struct LinkNode n2;
    struct LinkNode n3;

    n1.data = 1;
    n2.data = 2;
    n3.data = 3;
    n1.next = &n2;
    n2.next = &n3;

    printf("\tthe 1st data: %d\n", n1.data);
    printf("\tthe 2nd data: %d\n", n2.data);
    printf("\tthe 3rs data: %d\n", n1.next->next->data);

}