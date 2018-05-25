/**
 * linkedlist.h
 *
 * linked list with head and tail node
 *
 * Created by Houor
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define ElementType int

#define TRUE             1
#define FALSE            0
#define OK               1
#define ERROR            0
#define INFEASIBLE      -1
#define OVERFLOW        -2
#define NONE            -11


typedef struct LinkNode {
    ElementType element;
    struct LinkNode *next;
} LinkNode, *Node;

typedef struct {
    Node head;
    Node tail;
    int count; // the count of element in this list
} List;

/**
 * initialize sequence list
 *
 * @param
 * @return the status of initializing
 */
int initializeList(List *list);


/**
 * destroy list when the list has initialized
 *
 * @param list
 * @return the status of destroying
 */
int destroyList(List *list);


/**
 * determine whether the table is empty
 *
 * @param list
 * @return TRUE is empty, FALSE is not empty, if not initialized, then INFEASIBLE
 */
int isEmpty(List *list);


/**
 * get the length of the list
 *
 * @param list
 * @return the length of list
 */
int length(List *list);


/**
 * get the number of element in the list
 *
 * @param list
 * @return the count of element
 */
int count(List *list);


/**
 * add the element
 * append the element to the last on
 *
 * @param list
 * @param element
 * @return the status of add operation
 */
int addElement(List *list, ElementType element);


/**
 * get the element of the specified location
 *
 * @param list
 * @param index from 0 to n - 1
 * @param element the result
 *
 * @return retrieve status
 */
int getElement(List *list, int index, ElementType *element);


/**
 * update the element of the specified location
 *
 * @param list
 * @param index from 0 to n - 1
 * @param element
 * @return update status
 */
int updateElement(List *list, int index, ElementType element);

/**
 * insert the element of given index to the list
 *
 * @param list
 * @param index from 0 to n
 * @param element
 * @param debug true for printing steps of operation
 * @param visit
 * @return insert status
 */
int insertElement(List *list, int index, ElementType element);


/**
 * delete the element of the given index
 *
 * @param list
 * @param index from 0 to n - 1
 * @param element
 * @param debug true for printing steps of operation
 * @param visit
 * @return delete status
 */
int deleteElement(List *list, int index, ElementType *element);


/**
 * get the first element location where is equals to given value
 *
 * @param list
 * @param element
 * @param compare
 * @return
 */
int locateElement(List *list, ElementType element, int *index, int (*compare)(ElementType e, ElementType list_element));

/**
 * remove all value in the list
 *
 * @param list
 * @return operation status
 */
int clearList(List *list);

/**
 * traverse the list
 *
 * @param list
 * @param visit visit function
 */
void traverseList(List *list, void (*visit)(ElementType e));

void setDebugLevel(int level);

#endif //LINKED_LIST_H
