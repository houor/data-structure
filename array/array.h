/**
 * array.h
 *
 * multidimensional array
 *
 * Create By Houor
 */

#ifndef ARRAY_H
#define ARRAY_H


#define MAX_ARRAY_DIM 10

#define ElementType int

#define TRUE             1
#define FALSE            0
#define OK               1
#define ERROR            0
#define INFEASIBLE      -1
#define OVERFLOW        -2
#define UNDERFLOW       -3

int debug;


typedef struct {
    ElementType *base; // the base address of the array
    int dimension;     // the dimension of array, 1 ~ MAX_ARRAY_DIM
    int *bounds;       // the bound of each dimension, 1, 2, 3, 4 for a[1][2][3][4]
    int *constants;    // the step length of each dimension
} Array;

/**
 * initialize array
 *
 * @param array
 * @param dimension
 * @param the number of element for each dimension
 * @return initialize status
 */
int initializeArray(Array *array, int dimension, ...);


/**
 * destroy multidimensional array
 * @param array
 * @return status
 */
int destroyArray(Array *array);


/**
 * get value from array by array index
 *
 * @param array
 * @param element
 * @param dimension
 * @param ...  index of each dimension
 * @return status
 */
int getValue(Array *array, ElementType *element, int dimension, ...);


/**
 * get value to array by array index
 *
 * @param array
 * @param element
 * @param dimension
 * @param ... index of each dimension
 * @return status
 */
int setValue(Array *array, ElementType element, int dimension, ...);

int traverseAsList(Array *array);

int traverse(Array array);

void setDebugLevel(int level);

#endif //ARRAY_H
