/**
 * structure.c
 *
 * test for c pointer
 *   1. passing by value can not affect the calling function
 *   2. passing by pointer can affect the calling function
 *
 * Create By Houor
 */

#include <stdio.h>

void swap(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap_by_pointer(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort() {
    int a[10] = {2, 5, 1, 9, 8, -1, 7, 0, 3, 4};
    int cnt = 10;
    int i, j;
    int temp;

    printf("\tbefore sorting: ");
    for (i = 0; i < cnt; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");

    for (i = 0; i < cnt - 1; i++) {
        for (j = i + 1; j < cnt; j++) {
            if (a[i] > a[j]) {
                /*
				this method does not work
				swap(a[i], a[j]);
				*/
                swap_by_pointer(&a[i], &a[j]);
            }
        }
    }

    printf("\tafter sorting: ");
    for (i = 0; i < cnt; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");

}

