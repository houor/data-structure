#include <stdio.h>


int main() {
    printf("Test for some features:\n");

    printf("\n\n=====================\n\n");
    printf("Struct feature:\n");
    test_struct();

    printf("\n\n=====================\n\n");
    printf("parameter passing feature:\n");
    bubble_sort();

    printf("\n\n=====================\n\n");
    printf("memory allocation feature:\n");
    memory_allocation();
    return 0;
}