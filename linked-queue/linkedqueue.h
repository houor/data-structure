/**
 * linkedqueue.h
 *
 * linked queue header file
 *
 * Create By Houor
 */

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H


#define ElementType int

#define TRUE             1
#define FALSE            0
#define OK               1
#define ERROR            0
#define INFEASIBLE      -1
#define OVERFLOW        -2
#define FULL            11
#define EMPTY           10

typedef struct LinkNode {
    ElementType element;
    struct QueueNode *next;
} LinkNode, *Node;

typedef struct {
    Node front;   // header pointer
    Node rear;    // rear pointer
    int count;    // the number of element
} LinkedQueue;

int debug;

/**
 * initialize queue and allocate resource
 *
 * @param queue
 * @return operation result
 */
int initializeQueue(LinkedQueue *queue);


/**
 * destroy queue and free the resource
 *
 * @param queue
 * @return operation result
 */
int destroyQueue(LinkedQueue *queue);


/**
 * test whether the stack is empty
 *
 * @param queue
 * @return INFEASIBLE, TRUE, FALSE
 */
int isEmpty(LinkedQueue *queue);


/**
 * remove all element in queue
 *
 * @param queue
 * @return operation result
 */
int clearQueue(LinkedQueue *queue);


/**
 * the length of the queue itself
 *
 * @param queue
 * @return INFEASIBLE, length
 */
int length(LinkedQueue *queue);

/**
 * the number of element in the queue
 *
 * @param queue
 * @return INFEASIBLE, element numner
 */
int count(LinkedQueue *queue);


/**
 * enqueue
 *
 * @param queue
 * @param element
 * @return operation result
 */
int enQueue(LinkedQueue *queue, ElementType element);


/**
 * dequeue
 *
 * @param queue
 * @param element
 * @return operation result
 */
int deQueue(LinkedQueue *queue, ElementType *e);


/**
 * traverse the queue
 *
 * @param queue
 * @param visit print style
 * @return operation status
 */
int traverseQueue(LinkedQueue *queue, int (*visit)(ElementType));

void setDebugLevel(int level);

#endif //LINKED_QUEUE_H
