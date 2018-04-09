/**
 * sqstack.h
 *
 * sequence stack header
 *
 * Created by Houor
 */

#ifndef SEQUENCE_STACK_SQSTACK_H
#define SEQUENCE_STACK_SQSTACK_H

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 100

#define ElementType int

#define TRUE             1
#define FALSE            0
#define OK               1
#define ERROR            0
#define INFEASIBLE      -1
#define OVERFLOW        -2
#define EMPTY           -3
#define NONE            -11


int debug;


typedef struct {
    ElementType *base;
    ElementType *top;
    int stackSize;
} Stack;

/**
 * initialize stack
 *
 * @param stack a stack with memory to be allocated
 * @return the status of initializing
 */
int initializeStack(Stack *stack);


/**
 * destroy stack when the stack has initialized
 *
 * @param stack the stack to be destroyed
 * @return the status of destroying
 */
int destroyStack(Stack *stack);


/**
 * test whether the stack is empty
 *     true: empty, false: empty
 *
 * @param stack
 * @param isEmpty whether the stack is empty
 * @return operation status
 */
int isEmpty(Stack *stack);


/**
 *  the lenght of stack
 * @param stack
 * @param length the value of length
 * @return operation status
 */
int length(Stack *stack);


/**
 * get the number of element in the stack
 *
 * @param stack
 * @param count the number of element in the stack
 * @return operation status
 */
int count(Stack *stack);


/**
 * remove all element in stack
 *
 * @param stack
 * @return operation status
 */
int clear(Stack *stack);


/**
 * push a element into the stack
 *
 * @param stack
 * @param element the element to be pushed in the stack
 * @return operation status
 */
int push(Stack *stack, ElementType element);


/**
 * pop the top element from the stack
 *
 * @param stack
 * @param element the element value
 * @return operation status
 */
int pop(Stack *stack, ElementType *element);


/**
 *
 * @param stack
 * @param element
 * @return operation status
 */
int getTop(Stack *stack, ElementType *element);

/**
 * traverse the stack
 *
 * @param stack
 * @param visit print style
 * @return operation status
 */
int traverseStack(Stack *stack, int (*visit)(ElementType));

void setDebugLevel(int level);


#endif //SEQUENCE_STACK_SQSTACK_H
