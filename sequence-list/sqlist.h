/**
 * sqlist.h
 * sequence list head
 *
 * Created by Houor
 *
 */

#ifndef SEQUENCE_LIST_SQLIST_H
#define SEQUENCE_LIST_SQLIST_H

#define ElementType int


#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 100

#define TRUE             1
#define FALSE            0
#define OK               1
#define ERROR            0
#define INFEASIBLE      -1
#define OVERFLOW        -2

typedef struct {
    ElementType *elementList;// the list
    int length;// the current length of the list itself
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
 * destory list when the list has initialized
 *
 * @param list
 * @return the status of destroying
 */
int destoryList(List *list);// 销毁线性表


/**
 * determine whether the table is empty
 *
 * @param list
 * @return TRUE is empty, FALSE is not empty, if not initialized, then INFEASIBLE
 */
int isEmpty(List *list);// 线性表是否为空


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
int insertElement(List *list, int index, ElementType element, int debug, void (*visit)(ElementType e));


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
int deleteElement(List *list, int index, ElementType *element, int debug, void (*visit)(ElementType e));


/**
 * get the first element location where is equals to given value
 *
 * @param list
 * @param element
 * @param compare
 * @return
 */
int locateElement(List *list, ElementType element, int (*compare)(ElementType e, ElementType list_element));

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

#endif //SEQUENCE_LIST_SQLIST_H