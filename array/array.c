/**
 * array.h
 *
 * implementation of multidimensional array
 *
 * Create By Houor
 */

#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"
#include "math.h"

#include "array.h"

int initializeArray(Array *array, int dimension, ...) {
    int elementTotal = 0;
    va_list ap;
    int i = 0;

    if (dimension < 1 || dimension > MAX_ARRAY_DIM)
        return ERROR;

    // set array's dimension
    array->dimension = dimension;

    // allocate memory for bounds(bound array) of each dimension
    // the length of bounds array is dimension
    array->bounds = (int *) malloc(dimension * sizeof(int));
    if (!array->bounds)
        exit(OVERFLOW);

    // put the upper bound of each dimension in bound array
    // and calculate the total number of element in multidimensional array
    elementTotal = 1;
    va_start(ap, dimension);
    for (i = 0; i < dimension; i++) {
        *(array->bounds + i) = va_arg(ap, int);

        if (debug)
            printf("%d dimension's bound is %d.\n", i, *(array->bounds + i));

        // the upper bound can not be less than 1
        if (*(array->bounds + i) < 1)
            return UNDERFLOW;

        // the total number of element in this array
        elementTotal *= *(array->bounds + i);
    }
    va_end(ap);

    // allocate memory for the multidimensional array
    array->base = (ElementType *) malloc(elementTotal * sizeof(ElementType));
    if (!array->base) {
        exit(OVERFLOW);
    }

    // constants(Ci)
    array->constants = (int *) malloc(dimension * sizeof(int));
    *(array->constants + dimension - 1) = 1;
    for (i = dimension - 2; i >= 0; i--) {
        *(array->constants + i) = *(array->constants + i + 1) * (*(array->bounds + i + 1));
    }

    return OK;
}


int destroyArray(Array *array) {
    if (!array->base) {
        free(array->base);
        array->base = NULL;
    }
    if (!array->bounds) {
        free(array->bounds);
        array->bounds = NULL;
    }
    if (!array->constants) {
        free(array->constants);
        array->constants = NULL;
    }
    return OK;
}


int locate(Array *array, va_list ap, int *offset) {
    *offset = 0;
    int i;
    int index = 0;

    for (i = 0; i < array->dimension; i++) {
        index = va_arg(ap, int);
        if (index < 0 || index >= *(array->bounds + i)) {
            return OVERFLOW;
        }
        // map index to offset
        *offset += *(array->constants + i) * index;
    }

    return OK;
}

int getValue(Array *array, ElementType *element, int dimension, ...) {
    int status;
    int offset;
    va_list ap;

    va_start(ap, dimension);

    // get offset
    status = locate(array, ap, &offset);
    if (status == OVERFLOW) {
        return status;
    }

    va_end(ap);

    *element = *(array->base + offset);
    return OK;
}

int setValue(Array *array, ElementType element, int dim, ...) {
    int status;
    int offset;
    va_list ap;

    va_start(ap, dim);

    // get offset
    status = locate(array, ap, &offset);
    if (status == OVERFLOW) {
        return status;
    }

    va_end(ap);

    *(array->base + offset) = element;
    return OK;
}

void printArray(Array array, int dimension, int start, int end, int level) {
    int i = 0;
    int j = 0;
    if (dimension == array.dimension - 2) {
        for (int k = 0; k < level; k++)
            printf("\t");
        for (i = start, j = 1; i <= end; i++, j++) {

            printf("%6d\t", *(array.base + i));
            if (j % (*(array.bounds + dimension + 1)) == 0) {
                printf("\n");
                for (int k = 0; k < level; k++)
                    printf("\t");
            }

        }
        printf("\n");
    } else {
        for (i = 0; i < *(array.bounds + dimension); i++) {
            for (int k = 0; k < level; k++)
                printf("\t");
            printf("level: %d\n", level);
            int n_start = start + i * (*(array.constants + dimension));
            int n_end = start + (i + 1) * (*(array.constants + dimension)) - 1;
            printArray(array, dimension + 1, n_start, n_end, level + 1);
        }
    }
}

int traverse(Array array) {
    int i;
    int elementTotal = 1;
    for (i = 0; i < array.dimension; i++) {
        elementTotal *= *(array.bounds + i);
    }
    printArray(array, 0, 0, elementTotal, 0);
    return OK;
}

int traverseAsList(Array *array) {
    int i = 0;
    int elementTotal = 1;

    for (i = 0; i < array->dimension; i++) {
        elementTotal *= *(array->bounds + i);
    }

    for (i = 0; i < elementTotal; i++) {
        printf("%6d\t", *(array->base + i));
        if ((i + 1) % 15 == 0)
            printf("\n");
    }

    return OK;
}

void setDebugLevel(int level) {
    debug = level;
}