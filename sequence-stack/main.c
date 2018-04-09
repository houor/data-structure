/**
 * main.c
 *
 * test file for sequence stack
 *
 * Create By Houor
 */
#include <stdio.h>
#include "sqstack.h"

int visit(ElementType e) {
    printf("%d\t", e);
    return OK;
}

int main() {

    Stack stack;
    ElementType element;
    int status;
    int i;

    printf("初始化前状态: length = %d, count = %d, state = %s\n", length(&stack), count(&stack),
           isEmpty(&stack) ? "empty" : "not empty");

    printf("初始化栈......\n");
    initializeStack(&stack);


    printf("初始化状态: length = %d, count = %d, state = %s\n", length(&stack), count(&stack),
           isEmpty(&stack) ? "empty" : "not empty");


    printf("==============================\n");
    printf("进栈......\n");
    element = 1;
    status = push(&stack, element);
    if (status == INFEASIBLE) {
        printf("栈未初始化.\n");
    } else if (status == OVERFLOW) {
        printf("内存溢出.\n");
    } else {
        printf("%d进栈后状态.\n", element);
        traverseStack(&stack, visit);
    }

    element = 2;
    push(&stack, element);
    if (status == INFEASIBLE) {
        printf("栈未初始化.\n");
    } else if (status == OVERFLOW) {
        printf("内存溢出.\n");
    } else {
        printf("%d进栈后状态.\n", element);
        traverseStack(&stack, visit);
    }

    element = 3;
    push(&stack, element);
    if (status == INFEASIBLE) {
        printf("栈未初始化.\n");
    } else if (status == OVERFLOW) {
        printf("内存溢出.\n");
    } else {
        printf("%d进栈后状态.\n", element);
        traverseStack(&stack, visit);
    }


    printf("==============================\n");
    printf("出栈......\n");
    status = pop(&stack, &element);
    if (status == INFEASIBLE) {
        printf("栈未初始化.\n");
    } else {
        printf("出栈element = %d, 出栈后状态......\n", element);
        traverseStack(&stack, visit);
    }

    status = getTop(&stack, &element);
    if (status == INFEASIBLE) {
        printf("栈未初始化.\n");
    } else if (status == EMPTY) {
        printf("当前栈为空.\n");
    } else {
        printf("当前栈顶元素 = %d.\n", element);
        traverseStack(&stack, visit);
    }

    printf("当前状态: length = %d, count = %d, state = %s\n", length(&stack), count(&stack),
           isEmpty(&stack) ? "empty" : "not empty");

    printf("==============================\n");
    printf("清理栈......\n");
    status = clear(&stack);
    if (status == INFEASIBLE) {
        printf("栈未初始化.\n");
    } else {
        printf("清理后状态: length = %d, count = %d, state = %s\n", length(&stack), count(&stack),
               isEmpty(&stack) ? "empty" : "not empty");
    }

    printf("==============================\n");
    printf("进栈103个元素......\n");
    for (i = 0; i < 103; i++) {
        push(&stack, i);
    }
    printf("进栈103个元素状态: length = %d, count = %d, state = %s\n", length(&stack), count(&stack),
           isEmpty(&stack) ? "empty" : "not empty");

    printf("==============================\n");
    printf("销毁栈......\n");
    destroyStack(&stack);
    printf("销毁后状态: length = %d, count = %d, state = %s\n", length(&stack), count(&stack),
           isEmpty(&stack) ? "empty" : "not empty");

    return OK;
}