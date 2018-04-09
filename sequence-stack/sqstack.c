/**
 * sqstack.c
 *
 * implementation of sequence stack
 *
 * Created by Houor
 */


#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"

int initializeStack(Stack *stack) {
    stack->base = (ElementType *) malloc(STACK_INIT_SIZE * sizeof(ElementType));
    if (!stack->base)
        return OVERFLOW;

    stack->top = stack->base;
    stack->stackSize = STACK_INIT_SIZE;

    return OK;
}

int destroyStack(Stack *stack) {
    if (!stack->base) {
        return INFEASIBLE;
    }
    if (stack->base != NULL)
        free(stack->base);

    stack->base = NULL;
    stack->top = NULL;
    stack->stackSize = 0;

    return OK;
}

int isEmpty(Stack *stack) {
    if (!stack->base) {
        return INFEASIBLE;
    }

    if (stack->base == stack->top) {
        return TRUE;
    } else {
        return FALSE;
    }

}

int length(Stack *stack) {
    if (!stack->base) {
        return INFEASIBLE;
    }

    return stack->stackSize;
}


int count(Stack *stack) {
    if (!stack->base) {
        return INFEASIBLE;
    }

    return stack->top - stack->base;
}


int clear(Stack *stack) {
    if (!stack->base) {
        return INFEASIBLE;
    }

    stack->top = stack->base;

    return OK;
}


int push(Stack *stack, ElementType element) {
    if (!stack->base) {
        return INFEASIBLE;
    }

    // check whether the stack is full
    // if the stack is full, then add memory space
    if ((stack->top - stack->base) >= stack->stackSize) {
        stack->base = (ElementType *) realloc(stack->base, (stack->stackSize + STACK_INCREMENT) * sizeof(ElementType));
        if (!stack->base)
            return OVERFLOW;

        /**
         * after reallocate memory to the stack, the stack base pointer may change
         * we should move top pointer to the new memory address
         */
        stack->top = stack->base + stack->stackSize;
        stack->stackSize += STACK_INCREMENT;
    }

    // push the element to the stack
    // *(stack->top++) = element;
    *(stack->top) = element;
    stack->top++;

    return OK;
}

int pop(Stack *stack, ElementType *element) {
    if (!stack->base) {
        return INFEASIBLE;
    }

    // if the stack is empty
    if (stack->top == stack->base) {
        return EMPTY;
    }

    // pop the top element
    // *element = *(--stack->top);
    stack->top--;
    *element = *(stack->top);

    return OK;
}

int getTop(Stack *stack, ElementType *element) {
    if (!stack->base) {
        return INFEASIBLE;
    }

    // if the stack is empty
    if (stack->top == stack->base) {
        return EMPTY;
    }

    *element = *(stack->top - 1);

    return OK;
}

int traverseStack(Stack *stack, int (*visit)(ElementType)) {

    if (!stack->base) {
        return INFEASIBLE;
    }

    // if the stack is empty
    if (stack->top == stack->base) {
        return EMPTY;
    }

    ElementType *p;

    // visit the element one by one
    for (p = stack->base; p < stack->top; p++) {
        visit(*p);
    }

    printf("\n");

    return OK;
}