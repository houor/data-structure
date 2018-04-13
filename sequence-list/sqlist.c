/**
 * sqlist.c
 * implementation of sequence list
 *
 * Created by Houor
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"


int initializeList(List *list) {
    // allocate memory to list
    list->elementList = (ElementType *) malloc(LIST_INIT_SIZE * sizeof(ElementType));

    // allocation failure
    if (!list->elementList) {
        return OVERFLOW;
    }

    // allocation success
    list->length = LIST_INIT_SIZE;
    list->count = 0;
    return OK;
}


int destroyList(List *list) {
    if (!list->elementList)
        return INFEASIBLE;

    // reclaim memory
    free(list->elementList);
    list->elementList = NULL;
    list->count = 0;
    list->length = 0;
    return OK;
}


int isEmpty(List *list) {
    if (!list->elementList) {
        return INFEASIBLE;
    }

    if (list->count > 0) {
        return FALSE;
    } else {
        return TRUE;
    }
}

int length(List *list) {
    if (!list->elementList) {
        return INFEASIBLE;
    }
    return list->length;
}

int count(List *list) {
    if (!list->elementList) {
        return INFEASIBLE;
    }
    return list->count;
}


int addElement(List *list, ElementType element) {

    // before adding element to list, we should check whether memory space is enough
    // if there is not enough space, then reallocate memory to list for increasing memory space
    if (list->count >= list->length) {
        ElementType *newBase = (ElementType *) realloc(list->elementList, (list->length + LIST_INCREMENT) *
                                                                          sizeof(ElementType));
        // allocate failure
        if (!newBase) {
            return OVERFLOW;
        }

        // allocate success
        list->elementList = newBase;
        list->length = list->length + LIST_INCREMENT;

    }

    *(list->elementList + list->count) = element;
    list->count++;
    return OK;
}


int getElement(List *list, int index, ElementType *element) {
    // check whether the index is out of list boundary
    if (index < 0 || index >= list->count) {
        return ERROR;
    } else {
        *element = *(list->elementList + index);
        return OK;
    }
}


int updateElement(List *list, int index, ElementType element) {
    // check whether the index is out of list boundary
    if (index < 0 || index >= list->count) {
        return ERROR;
    } else {
        *(list->elementList + index) = element;
        return OK;
    }
}


int insertElement(List *list, int index, ElementType element, int debug, void (*visit)(ElementType et)) {


    // check whether the index is out of list boundary
    // from 0 to n
    if (index < 0 || index > list->count) {
        return ERROR;
    }

    // before inserting element to list, we should check whether memory space is enough
    // if there is not enough space, then reallocate memory to list for increasing memory space
    if (list->count >= list->length) {
        ElementType *newBase = (ElementType *) realloc(list->elementList, (list->length + LIST_INCREMENT) *
                                                                          sizeof(ElementType));
        // allocation failure
        if (!newBase) {
            return OVERFLOW;
        }

        // allocation success
        list->elementList = newBase;
        list->length = list->length + LIST_INCREMENT;

    }

    list->count++;

    // move element
    ElementType *insertPosition = list->elementList + index;
    ElementType *endPosition = list->elementList + list->count - 2;
    if (debug) {
        printf("steps of insertion:\n");
    }
    for (; endPosition >= insertPosition; endPosition--) {
        *(endPosition + 1) = *endPosition;
        if (debug) {
            traverseList(list, visit);
        }
    }

    *insertPosition = element;

    if (debug) {
        printf("Result: ");
        traverseList(list, visit);
    }

    return OK;
}


int deleteElement(List *list, int index, ElementType *element, int debug, void (*visit)(ElementType et)) {

    // check whether the index is out of list boundary
    // from 0 to n - 1
    if (index < 0 || index >= list->count) {
        return ERROR;
    }

    // move element

    if (debug) {
        printf("steps of deletion:\n");
    }
    ElementType *deletePosition = list->elementList + index;
    ElementType *endPosition = list->elementList + list->count - 1;

    *element = *deletePosition;

    for (; deletePosition < endPosition; deletePosition++) {
        *deletePosition = *(deletePosition + 1);
        if (debug) {
            traverseList(list, visit);
        }
    }

    list->count--;

    if (debug) {
        printf("Result: ");
        traverseList(list, visit);
    }
    return OK;
}


int locateElement(List *list, ElementType element, int (*compare)(ElementType e, ElementType list_element)) {
    int i = 0;

    for (; i < list->count; i++) {
        // find it
        if (compare(element, *(list->elementList + i))) {
            return i;
        }
    }

    // not find
    return -1;
}

int clearList(List *list) {
    if (!list->elementList)
        return INFEASIBLE;

    list->count = 0;

    return OK;
}


/**
 * traverse list
 *
 * @param list
 * @param visit callback fuanction
 */
void traverseList(List *list, void (*visit)(ElementType element)) {
    int i;

    for (i = 0; i < list->count; i++) {
        visit(*(list->elementList + i));

    }

    printf("\n");
}