/**
 * rrqueue.c
 *
 * implementation of round robin queue
 *
 * Created by Houor
 */

#include <stdio.h>
#include <stdlib.h>
#include "rrqueue.h"


int initializeQueue(RRQueue *queue) {
    // allocate memory space to the queue
    queue->base = (ElementType *) malloc(QUEUE_MAX_LENGTH * sizeof(ElementType));
    if (!queue->base)
        return OVERFLOW;

    queue->front = 0;
    queue->rear = 0;
    return OK;
}

int destroyQueue(RRQueue *queue) {

    if (!queue->base) {
        return INFEASIBLE;
    }

    // free memory space
    free(queue->base);

    queue->front = 0;
    queue->rear = 0;

    return OK;
}


int isEmpty(RRQueue *queue) {
    if (!queue->base) {
        return INFEASIBLE;
    }

    if (queue->front == queue->rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}


int clearQueue(RRQueue *queue) {
    if (!queue->base) {
        return INFEASIBLE;
    }

    queue->front = 0;
    queue->rear = 0;

    return OK;
}


int length(RRQueue *queue) {
    if (!queue->base) {
        return INFEASIBLE;
    }

    return QUEUE_MAX_LENGTH;
}

int count(RRQueue *queue) {
    if (!queue->base) {
        return INFEASIBLE;
    }

    return (queue->rear - queue->front + QUEUE_MAX_LENGTH) % QUEUE_MAX_LENGTH;
}

int enQueue(RRQueue *queue, ElementType element) {
    if (!queue->base) {
        return INFEASIBLE;
    }

    // check whether the queue is full
    if ((queue->rear + 1) % QUEUE_MAX_LENGTH == queue->front) {
        return FULL;
    }

    *(queue->base + queue->rear) = element;
    queue->rear = (queue->rear + 1) % QUEUE_MAX_LENGTH;

    return OK;
}


int deQueue(RRQueue *queue, ElementType *e) {
    if (!queue->base) {
        return INFEASIBLE;
    }

    // check whether the queue is empty
    if (queue->front == queue->rear)
        return EMPTY;

    *e = *(queue->base + queue->front);
    queue->front = (queue->front + 1) % QUEUE_MAX_LENGTH;

    return OK;
}


int traverseQueue(RRQueue *queue, int (*visit)(ElementType)) {
    if (!queue->base) {
        return INFEASIBLE;
    }

    if (queue->front == queue->rear)
        return EMPTY;

    int index = queue->front;
    while (index != queue->rear) {
        visit(*(queue->base + index));
        index = (index + 1) % QUEUE_MAX_LENGTH;
    }

    printf("\n");
    return OK;
}