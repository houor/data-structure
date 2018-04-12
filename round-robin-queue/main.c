#include <stdio.h>
#include "rrqueue.h"

int visit(ElementType e) {
    printf("%d\t", e);
    return OK;
}


int main() {

    ElementType element;
    RRQueue queue;
    int status;
    int i;

    printf("初始化前状态: length = %d, count = %d, state = %s\n", length(&queue), count(&queue),
           isEmpty(&queue) ? "empty" : "not empty");


    printf("初始化......\n");
    initializeQueue(&queue);
    printf("Queue length after init: %d\n", length(&queue));
    printf("初始化前状态: length = %d, count = %d, state = %s\n", length(&queue), count(&queue),
           isEmpty(&queue) ? "empty" : "not empty");

    printf("==============================\n");
    printf("入队......\n");
    element = 1;
    status = enQueue(&queue, element);
    if (status == INFEASIBLE) {
        printf("未初始化.\n");
    } else if (status == FULL) {
        printf("队列已满.\n");
    } else {
        printf("%d进队后状态:\n", element);
        traverseQueue(&queue, visit);
    }

    element = 2;
    status = enQueue(&queue, element);
    if (status == INFEASIBLE) {
        printf("未初始化.\n");
    } else if (status == FULL) {
        printf("队列已满.\n");
    } else {
        printf("%d进队后状态:\n", element);
        traverseQueue(&queue, visit);
    }

    element = 3;
    status = enQueue(&queue, element);
    if (status == INFEASIBLE) {
        printf("未初始化.\n");
    } else if (status == FULL) {
        printf("队列已满.\n");
    } else {
        printf("%d进队后状态:\n", element);
        traverseQueue(&queue, visit);
    }

    element = 4;
    status = enQueue(&queue, element);
    if (status == INFEASIBLE) {
        printf("未初始化.\n");
    } else if (status == FULL) {
        printf("队列已满.\n");
    } else {
        printf("%d进队后状态:\n", element);
        traverseQueue(&queue, visit);
    }

    printf("Queue length after add 4 element: %d\n", length(&queue));
    printf("Queue count after add 4 element: %d\n", count(&queue));

    printf("==============================\n");
    printf("出队......\n");

    status = deQueue(&queue, &element);
    if (status == INFEASIBLE) {
        printf("未初始化.\n");
    } else if (status == EMPTY) {
        printf("队列已空.\n");
    } else {
        printf("%d出队后状态:\n", element);
        traverseQueue(&queue, visit);
    }

    status = deQueue(&queue, &element);
    if (status == INFEASIBLE) {
        printf("未初始化.\n");
    } else if (status == EMPTY) {
        printf("队列已空.\n");
    } else {
        printf("%d出队后状态:\n", element);
        traverseQueue(&queue, visit);
    }

    status = deQueue(&queue, &element);
    if (status == INFEASIBLE) {
        printf("未初始化.\n");
    } else if (status == EMPTY) {
        printf("队列已空.\n");
    } else {
        printf("%d出队后状态:\n", element);
        traverseQueue(&queue, visit);
    }


    printf("==============================\n");
    printf("清空队列......\n");
    clearQueue(&queue);
    if (status == INFEASIBLE) {
        printf("未初始化.\n");
    } else {
        printf("%d清空队列后状态:\n", element);
        traverseQueue(&queue, visit);
    }
    printf("清空队列后状态: length = %d, count = %d, state = %s\n", length(&queue), count(&queue),
           isEmpty(&queue) ? "empty" : "not empty");

    printf("==============================\n");

    printf("添加多个元素(大于QUEUE_MAX_LENGTH): \n");

    int c = QUEUE_MAX_LENGTH + 2;

    for (int i = 0; i < c; i++) {
        status = enQueue(&queue, i);

        if (status == INFEASIBLE) {
            printf("未初始化.\n");
        } else if (status == FULL) {
            printf("队列已满.\n");
        } else {
            printf("%d进队后状态:\n", i);
            traverseQueue(&queue, visit);
        }
    }


    printf("===============\n");
    printf("删除队列......\n");

    status = destroyQueue(&queue);
    if (status == INFEASIBLE) {
        printf("未初始化.\n");
    } else {
        traverseQueue(&queue, visit);
    }
    return 0;
}