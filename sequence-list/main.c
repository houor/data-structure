#include <stdio.h>
#include "sqlist.h"

void visit(ElementType e);

int compare(ElementType e, ElementType list_element);

int main() {
    int status;
    int index;
    int list_length;
    int list_count;

    List list;

    ElementType element = 0;

    // 未初始化状态
    printf("顺序表未初始化状态......\n");
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

    // 初始化顺序表
    initializeList(&list);

    // 刚初始化时的状态
    printf("顺序表初始化状态......\n");
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

    printf("================================\n");
    // 添加元素到顺序表

    element = 0;
    printf("\n添加元素%d到列表\n", element);
    addElement(&list, element);
    printf("遍历列表\n");
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

    printf("================================\n");
    // 获取指定位置元素
    printf("获取指定位置元素\n\n");

    index = 3;
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
    insertElement(&list, index, element, TRUE, visit);


    index = 4;
    element = -3;
    printf("在位置%d插入元素%d\n", index, element);
    insertElement(&list, index, element, TRUE, visit);


    printf("================================\n");
    // 在指定位置删除元素

    printf("在指定位置删除一个元素\n\n");

    index = 4;
    printf("在位置%d删除元素\n", index);
    deleteElement(&list, index, &element, TRUE, visit);
    printf("删除的元素值为%d\n", element);

    index = 0;
    printf("在位置%d删除元素\n", index);
    deleteElement(&list, index, &element, TRUE, visit);
    printf("删除的元素值为%d\n", element);


    printf("================================\n");
    // 查找指定元素

    printf("查找指定元素位置\n\n");
    element = 4;
    index = locateElement(&list, element, compare);
    if (index != -1) {
        printf("元素%d的位置为%d\n", element, index);
    } else {
        printf("列表中没有元素%d\n", element);
    }

    element = 100;
    index = locateElement(&list, element, compare);
    if (index != -1) {
        printf("元素%d的位置为%d\n", element, index);
    } else {
        printf("列表中没有元素%d\n", element);
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