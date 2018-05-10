#include "stdio.h"

#include "array.h"

int main() {

    Array array;
    int status;
    int element = 0;
    int dimension = 5;
    int bounds[5] = {3, 3, 5, 2, 4};
    int i, j, k, l, m;

    setDebugLevel(TRUE);

    printf("initialize multidimensional array:\n");
    printf("\t the multidimensional array's dimension: %d\n", dimension);
    printf("\t the multidimensional array's upper bound of each dimension: ");
    for (i = 0; i < dimension; i++) {
        printf("%d", bounds[i]);
        if (i != dimension - 1)
            printf(", ");
        else
            printf(".\n");
    }

    printf("=======================================================\n");
    status = initializeArray(&array, dimension, bounds[0], bounds[1], bounds[2], bounds[3], bounds[4]);

    if (status == ERROR) {
        printf("the dimension can not be less than 1 or greater than 10.\n");
        return ERROR;
    } else if (status == OVERFLOW) {
        printf("can not allocate memory.\n");
        return OVERFLOW;
    } else if (status == UNDERFLOW) {
        printf("the bound of each dimension can not be less than 1.\n");
        return UNDERFLOW;
    }


    printf("=======================================================\n");
    // set value
    for (i = 0; i < bounds[0]; i++) {
        for (j = 0; j < bounds[1]; j++) {
            for (k = 0; k < bounds[2]; k++) {
                for (l = 0; l < bounds[3]; l++) {
                    for (m = 0; m < bounds[4]; m++) {
                        setValue(&array, element, array.dimension, i, j, k, l, m);
                        element++;
                    }
                }
            }
        }
    }

    printf("=======================================================\n");
    //get value
    status = getValue(&array, &element, array.dimension, 2, 1, 3, 1, 2);
    if (status == OK) {
        printf("array(2, 1, 3, 4) = %d\n", element);
    }
    printf("=======================================================\n");

    traverseAsList(&array);

    printf("=======================================================\n");

    traverse(array);

    destroyArray(&array);


    return 0;
}