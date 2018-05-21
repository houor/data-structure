/**
 * rrqueue.h
 *
 * header file of round robin queue
 *
 * Created by Houor
 */

#ifndef ROUND_ROBIN_QUEUE_H
#define ROUND_ROBIN_QUEUE_H

#define QUEUE_MAX_LENGTH 6
#define ElementType int

#define TRUE             1
#define FALSE            0
#define OK               1
#define ERROR            0
#define INFEASIBLE      -1
#define OVERFLOW        -2
#define FULL            11
#define EMPTY           10

typedef struct {
    ElementType *base;
    int front;// front pointer
    int rear;// rear pointer
} RRQueue;


/**
 * initialize queue and allocate resource
 *
 * @param queue
 * @return operation result
 */
int initializeQueue(RRQueue *queue);


/**
 * destroy queue and free the resource
 *
 * @param queue
 * @return operation result
 */
int destroyQueue(RRQueue *queue);


/**
 * test whether the queue is empty
 *
 * @param queue
 * @return INFEASIBLE, TRUE, FALSE
 */
int isEmpty(RRQueue *queue);


/**
 * remove all element in queue
 *
 * @param queue
 * @return operation result
 */
int clearQueue(RRQueue *queue);


/**
 * the length of the queue itself
 *
 * @param queue
 * @return INFEASIBLE, length
 */
int length(RRQueue *queue);

/**
 * the number of element in the queue
 *
 * @param queue
 * @return INFEASIBLE, element numner
 */
int count(RRQueue *queue);


/**
 * enqueue
 *
 * @param queue
 * @param element
 * @return operation result
 */
int enQueue(RRQueue *queue, ElementType element);


/**
 * dequeue
 *
 * @param queue
 * @param element
 * @return operation result
 */
int deQueue(RRQueue *queue, ElementType *e);


/**
 * traverse the queue
 *
 * @param queue
 * @param visit print style
 * @return operation status
 */
int traverseQueue(RRQueue *queue, int (*visit)(ElementType));

#endif //ROUND_ROBIN_QUEUE_H