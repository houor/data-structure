/**
 * linkedstack.c
 *
 * implementation of linked stack
 *
 * Created by Houor
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedstack.h"

int initializeStack(Stack *stack) {
    // allocate head node
    Node head = (Node) malloc(sizeof(LinkNode));

    // allocation failure
    if (!head) {
        return OVERFLOW;
    }

    // allocation success
    // then initialize stack
    head->next = NULL;

    stack->top = head;
    //stack->base = head;
    stack->count = 0;

    return OK;
}

int destroyStack(Stack *stack) {
    // not initialized
    if (!stack->top) {
        return INFEASIBLE;
    }

    if (!stack->top->next) { // empty
        free(stack->top);
    } else { // not empty
        //free all data node
        Node p = stack->top->next;
        Node q;

        while (p) {
            q = p;
            p = p->next;
            if (debug) {
                printf("free %d, count = %d\n", q->element, stack->count--);
            }
            free(q);
        }


        if (debug) {
            printf("element count after destroy = %d\n", stack->count);
        }

        // free head node
        if (debug) {
            printf("free head node at the end of operation.\n");
        }
        free(stack->top);
    }

    //stack->base = NULL;
    stack->top = NULL;
    stack->count = 0;

    return OK;
}

int isEmpty(Stack *stack) {
    if (!stack->top) {
        return INFEASIBLE;
    }

    if (!stack->top->next) {
        return TRUE;
    } else {
        return FALSE;
    }

}

int length(Stack *stack) {
    if (!stack->top) {
        return INFEASIBLE;
    }

    return stack->count;
}


int count(Stack *stack) {
    if (!stack->top) {
        return INFEASIBLE;
    }

    return stack->count;
}


int clear(Stack *stack) {
    if (!stack->top) {
        return INFEASIBLE;
    }

    Node p = stack->top->next;
    Node q;

    while (p) {
        q = p;
        p = p->next;
        if (debug) {
            printf("free %d, count = %d\n", q->element, stack->count--);
        }
        free(q);
    }

    if (debug) {
        printf("element count after clear = %d\n", stack->count);
    }

    stack->top->next = NULL;
    stack->count = 0;

    return OK;
}


int push(Stack *stack, ElementType element) {
    if (!stack->top) {
        return INFEASIBLE;
    }


    // allocate node memory
    Node node = (Node) malloc(sizeof(LinkNode));

    // allocation failure
    if (!node) {
        return OVERFLOW;
    }

    // initialize node
    node->element = element;
    node->next = stack->top->next;

    // push the element to the stack
    stack->top->next = node;
    stack->count++;

    return OK;
}

int pop(Stack *stack, ElementType *element) {
    if (!stack->top) {
        return INFEASIBLE;
    }

    // if the stack is empty
    if (!stack->top->next) {
        return EMPTY;
    }

    // pop the top element
    Node p = stack->top->next;
    *element = p->element;
    stack->top->next = p->next;
    stack->count--;
    free(p);

    return OK;
}

int getTop(Stack *stack, ElementType *element) {
    if (!stack->top) {
        return INFEASIBLE;
    }

    // if the stack is empty
    if (!stack->top->next) {
        return EMPTY;
    }

    *element = stack->top->next->element;

    return OK;
}

int traverseStack(Stack *stack, int (*visit)(ElementType)) {

    if (!stack->top) {
        return INFEASIBLE;
    }

    // if the stack is empty
    if (!stack->top) {
        return EMPTY;
    }

    Node p = stack->top->next;

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