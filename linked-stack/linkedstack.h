/**
 * linkedstack.h
 *
 * linked stack header file
 *
 * Create By Houor
 */

#ifndef LINKED_STACK_H
#define LINKED_STACK_H


#define ElementType int

#define TRUE             1
#define FALSE            0
#define OK               1
#define ERROR            0

#define FULL            11
#define EMPTY           10

#define INFEASIBLE      -1
#define OVERFLOW        -2
#define NONE            -11

int debug;

typedef struct LinkNode {
    ElementType element;// data
    struct LinkNode *next;// pointer
} LinkNode, *Node;

typedef struct LinkStack {
    Node top;
    Node base;
    int count; // the number of element
} Stack;


/**
 * initialize stack
 *
 * @param stack
 * @return the status of initializing
 */
int initializeStack(Stack *stack);


/**
 * destroy stack while the stack has initialized
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

#endif //LINKED_STACK_H
