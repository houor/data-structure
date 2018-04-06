/**
 * main.c
 *
 * test unit for linked list with head and tail node
 *
 * Created by Houor
 */

#include <stdio.h>
#include "linkedlist.h"

void visit(ElementType e);

int compare(ElementType e, ElementType list_element);


int main() {
    int status;
    int index;
    int list_length;
    int list_count;

    List list;

    ElementType element = 0;

    setDebugLevel(1);

    // 未初始化状态
    printf("链表未初始化状态......\n");
    list_length = length(&list);
    if (list_length == INFEASIBLE) {
        printf("the list is not initializing\n");
    } else {
        printf("length of the list: %d\n", list_length);
    }

    list_count = count(&list);
    if (list_count == INFEASIBLE) {
        printf("the list is not initializing\n");
    } else {
        printf("the number of element in the list: %d\n", list_count);
    }

    // 初始化链表
    status = initializeList(&list);

    if (status == OK) {

        // 刚初始化时的状态
        printf("链表初始化状态......\n");
        list_length = length(&list);
        printf("length of the list: %d\n", list_length);

        list_count = count(&list);
        printf("the number of element in the list: %d\n", list_count);

    } else {
        printf("链表初始化失败");
        return ERROR;
    }

    printf("================================\n");
    // 添加元素到链表

    element = 0;
    printf("\n添加元素%d到列表\n", element);
    addElement(&list, element);
    traverseList(&list, visit);

    element = 1;
    printf("\n添加元素%d到列表\n", element);
    addElement(&list, element);
    traverseList(&list, visit);

    element = 2;
    printf("\n添加元素%d到列表\n", element);
    addElement(&list, element);
    traverseList(&list, visit);

    element = 3;
    printf("\n添加元素%d到列表\n", element);
    addElement(&list, element);
    traverseList(&list, visit);

    element = 4;
    printf("\n添加元素%d到列表\n", element);
    addElement(&list, element);
    traverseList(&list, visit);

    element = 5;
    printf("\n添加元素%d到列表\n", element);
    addElement(&list, element);
    traverseList(&list, visit);

    element = 10;
    printf("\n添加元素%d到列表\n", element);
    addElement(&list, element);
    traverseList(&list, visit);

    printf("================================\n");
    // 获取指定位置元素
    printf("获取指定位置元素\n\n");

    index = 0;
    status = getElement(&list, index, &element);
    if (status != ERROR)
        printf("列表的第%d位元素值为%d\n", index, element);
    else
        printf("元素位置%d越界\n", index);

    index = 4;
    status = getElement(&list, index, &element);
    if (status != ERROR)
        printf("列表的第%d位元素值为%d\n", index, element);
    else
        printf("元素位置%d越界\n", index);

    index = -1;
    status = getElement(&list, index, &element);
    if (status != ERROR)
        printf("列表的第%d位元素值为%d\n", index, element);
    else
        printf("元素位置%d越界\n", index);


    printf("================================\n");
    // 修改指定位置元素

    printf("修改指定位置元素\n\n");

    index = 2;
    element = 9;
    printf("操作：更新第%d位元素为%d\n", index, element);
    status = updateElement(&list, index, element);
    if (status == OK) {
        printf("列表位置%d更新为%d\n", index, element);
    } else {
        printf("元素位置%d越界\n", index);
    }
    printf("遍历更新后列表\n");
    traverseList(&list, visit);
    printf("\n");


    index = 10;
    element = 9;
    printf("操作：更新第%d位元素为%d\n", index, element);
    status = updateElement(&list, index, element);
    if (status == OK) {
        printf("列表位置%d更新为%d\n", index, element);

    } else {
        printf("元素位置%d越界\n", index);
    }
    printf("遍历更新后列表\n");
    traverseList(&list, visit);
    printf("\n");


    printf("================================\n");
    // 在指定位置插入元素

    printf("在指定位置插入一个元素\n\n");

    index = 0;
    element = -1;
    printf("在位置%d插入元素%d\n", index, element);
    insertElement(&list, index, element);
    traverseList(&list, visit);


    index = 4;
    element = -3;
    printf("在位置%d插入元素%d\n", index, element);
    insertElement(&list, index, element);
    traverseList(&list, visit);

    index = list.count;
    element = -100;
    printf("在位置%d插入元素%d\n", index, element);
    insertElement(&list, index, element);
    traverseList(&list, visit);

    index = 1000;
    element = -1000;
    printf("在位置%d插入元素%d\n", index, element);
    status = insertElement(&list, index, element);
    if (status == INFEASIBLE) {
        printf("列表尚未初始化\n");
    } else if (status == ERROR) {
        printf("插入位置超出列表范围\n");
    }
    traverseList(&list, visit);


    printf("================================\n");
    // 在指定位置删除元素

    printf("在指定位置删除一个元素\n\n");

    index = 4;
    printf("在位置%d删除元素\n", index);
    status = deleteElement(&list, index, &element);
    if (status == INFEASIBLE) {
        printf("列表尚未初始化\n");
    } else if (status == ERROR) {
        printf("删除位置超出列表范围\n");
    } else {
        printf("删除的元素值为%d\n", element);
        traverseList(&list, visit);
    }

    index = 0;
    printf("在位置%d删除元素\n", index);
    status = deleteElement(&list, index, &element);
    if (status == INFEASIBLE) {
        printf("列表尚未初始化\n");
    } else if (status == ERROR) {
        printf("删除位置超出列表范围\n");
    } else {
        printf("删除的元素值为%d\n", element);
        traverseList(&list, visit);
    }

    index = list.count - 1;
    printf("在位置%d删除元素\n", index);
    status = deleteElement(&list, index, &element);
    if (status == INFEASIBLE) {
        printf("列表尚未初始化\n");
    } else if (status == ERROR) {
        printf("删除位置超出列表范围\n");
    } else {
        printf("删除的元素值为%d\n", element);
        traverseList(&list, visit);
    }

    index = -1;
    printf("在位置%d删除元素\n", index);
    status = deleteElement(&list, index, &element);
    if (status == INFEASIBLE) {
        printf("列表尚未初始化\n");
    } else if (status == ERROR) {
        printf("删除位置超出列表范围\n");
    } else {
        printf("删除的元素值为%d\n", element);
        traverseList(&list, visit);
    }

    index = 10000;
    printf("在位置%d删除元素\n", index);
    status = deleteElement(&list, index, &element);
    if (status == INFEASIBLE) {
        printf("列表尚未初始化\n");
    } else if (status == ERROR) {
        printf("删除位置超出列表范围\n");
    } else {
        printf("删除的元素值为%d\n", element);
        traverseList(&list, visit);
    }


    printf("================================\n");
    // 查找指定元素

    printf("查找指定元素位置\n\n");
    element = 4;
    status = locateElement(&list, element, &index, compare);
    if (status == INFEASIBLE) {
        printf("列表尚未初始化\n");
    } else if (status == NONE) {
        printf("未查到元素%d\n", element);
    } else {
        printf("元素%d的位置为%d\n", element, index);
        traverseList(&list, visit);
    }


    element = 100;
    status = locateElement(&list, element, &index, compare);
    if (status == INFEASIBLE) {
        printf("列表尚未初始化\n");
    } else if (status == NONE) {
        printf("未查到元素%d\n", element);
    } else {
        printf("元素%d的位置为%d\n", element, index);
        traverseList(&list, visit);
    }

    element = 0;
    status = locateElement(&list, element, &index, compare);
    if (status == INFEASIBLE) {
        printf("列表尚未初始化\n");
    } else if (status == NONE) {
        printf("未查到元素%d\n", element);
    } else {
        printf("元素%d的位置为%d\n", element, index);
        traverseList(&list, visit);
    }

    printf("================================\n");
    // 清空列表

    printf("清空列表所有数据\n\n");
    status = clearList(&list);
    if (status == OK)
        printf("列表清空后，长度为%d，元素个数为%d\n\n", length(&list), count(&list));

    if (isEmpty(&list)) {
        printf("当前列表为空\n\n");
    }


    printf("================================\n");

    printf("添加一些元素\n");

    for (index = 0; index < 10; index++) {
        printf("\n添加元素%d到列表\n", index);
        addElement(&list, index);
        traverseList(&list, visit);
    }


    printf("运行结束，销毁列表并回收内存空间\n");
    destroyList(&list);

    return 0;
}

/**
 * print the element
 *
 * @param e
 */
void visit(ElementType e) {
    printf("%d\t", e);
}

/**
 * test whether the elements are equal
 *
 * @param e
 * @param list_element
 * @return 1 for equal, 0 for not equal
 */
int compare(ElementType e, ElementType list_element) {
    if (e == list_element) {
        return 1;
    } else {
        return 0;
    }
}