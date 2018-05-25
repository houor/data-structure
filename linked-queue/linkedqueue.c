/**
 * LinkedQueue.c
 *
 * implementation of round robin queue
 *
 * Created by Houor
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

int debug;


int initializeQueue(LinkedQueue *queue) {
    // allocate head node
    Node head = (Node) malloc(sizeof(LinkNode));

    // allocation failure
    if (!head) {
        return OVERFLOW;
    }

    // allocation success
    // then initialize queue
    head->next = NULL;

    queue->front = head;
    queue->rear = head;
    queue->count = 0;

    return OK;
}

int destroyQueue(LinkedQueue *queue) {

    // not initialized
    if (!queue->front) {
        return INFEASIBLE;
    }

    if (queue->front == queue->rear) { // empty
        // free head node
        if (debug) {
            printf("\nfree head node at the end of operation.\n");
        }
        free(queue->front);
    } else { // not empty
        //free all data node
        Node p = queue->front->next;
        Node q;

        while (p) {
            q = p;
            p = p->next;
            if (debug) {
                printf("free %d, count = %d\n", q->element, queue->count--);
            }
            free(q);
        }


        if (debug) {
            printf("element count after destroy = %d\n", queue->count);
        }

        // free head node
        if (debug) {
            printf("free head node at the end of operation.\n");
        }
        free(queue->front);
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;

    return OK;
}


int isEmpty(LinkedQueue *queue) {
    if (!queue->front) {
        return INFEASIBLE;
    }

    if (queue->front == queue->rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}


int clearQueue(LinkedQueue *queue) {
    if (!queue->front) {
        return INFEASIBLE;
    }

    Node p = queue->front->next;
    Node q;

    while (p) {
        q = p;
        p = p->next;
        if (debug) {
            printf("free %d, count = %d\n", q->element, queue->count--);
        }
        free(q);
    }

    if (debug) {
        printf("element count after clear = %d\n", queue->count);
    }

    queue->front->next = NULL;
    queue->rear = queue->front;
    queue->count = 0;

    return OK;
}


int length(LinkedQueue *queue) {
    if (!queue->front) {
        return INFEASIBLE;
    }

    return queue->count;
}


int count(LinkedQueue *queue) {
    if (!queue->front) {
        return INFEASIBLE;
    }

    return queue->count;
}


int enQueue(LinkedQueue *queue, ElementType element) {

    if (!queue->front) {
        return INFEASIBLE;
    }

    // allocate node memory
    Node node = (Node) malloc(sizeof(LinkNode));
    if (!node) {
        return OVERFLOW;
    }
    node->element = element;
    node->next = NULL;

    // add element to the rear of queue
    queue->rear->next = node;
    queue->rear = node;
    queue->count++;

    return OK;
}


int deQueue(LinkedQueue *queue, ElementType *element) {
    if (!queue->front) {
        return INFEASIBLE;
    }

    // check whether the queue is empty
    if (queue->front == queue->rear)
        return EMPTY;

    Node p = queue->front->next;
    *element = p->element;


    queue->front->next = p->next;

    // if the node is the last one, then move rear pointer to head node
    if (queue->rear == p) {
        queue->rear = queue->front;
    }

    free(p);

    queue->count--;

    return OK;
}


int traverseQueue(LinkedQueue *queue, int (*visit)(ElementType)) {
    if (!queue->front) {
        return INFEASIBLE;
    }

    if (queue->front == queue->rear)
        return EMPTY;

    Node p = queue->front->next;
    while (p) {
        visit(p->element);
        p = p->next;
    }

    printf("\n");
    return OK;
}

void setDebugLevel(int level) {
    debug = level;
}