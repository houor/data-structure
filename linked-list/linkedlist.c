/**
 * linkedlist.c
 *
 * implementation of linked list
 *
 * Created by Houor
 */

#include "stdio.h"
#include "stdlib.h"
#include "linkedlist.h"

int debug;

int initializeList(List *list) {
    // allocate head node
    Node head = (Node) malloc(sizeof(LinkNode));

    // allocation failure
    if (!head) {
        return OVERFLOW;
    }

    // allocation success
    // then initialize list
    head->next = NULL;

    list->head = head;
    list->tail = head;
    list->count = 0;

    return OK;
}


int destroyList(List *list) {

    // not initialized
    if (!list->head) {
        return INFEASIBLE;
    }

    if (list->head == list->tail) { // empty list
        // free head node
        free(list->head);
    } else { // not empty

        //free all data node
        Node p = list->head->next;
        Node q;

        while (p) {
            q = p;
            p = p->next;
            if (debug) {
                printf("free %d, count = %d\n", q->element, list->count--);
            }
            free(q);
        }

        if (debug) {
            printf("element count after destroy = %d\n", list->count);
        }

        // free head node
        if (debug) {
            printf("free head node at the end of operation.\n");
        }
        free(list->head);
    }

    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return OK;
}


int isEmpty(List *list) {
    if (!list->head) {
        return INFEASIBLE;
    }

    if (list->head == list->tail) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int length(List *list) {
    if (!list->head) {
        return INFEASIBLE;
    }
    return list->count;
}

int count(List *list) {
    if (!list->head) {
        return INFEASIBLE;
    }
    return list->count;
}


int addElement(List *list, ElementType element) {

    // allocate node memory
    Node node = (Node) malloc(sizeof(LinkNode));

    // allocation failure
    if (!node) {
        return OVERFLOW;
    }

    // initialize node
    node->element = element;
    node->next = NULL;

    // add new node to list tail

    list->tail->next = node;
    list->tail = node;

    printf("%d\n", list->tail->element);

    list->count++;
    return OK;
}


int getElement(List *list, int index, ElementType *element) {

    if (!list->head) {
        return INFEASIBLE;
    }

    // check whether the index is out of list boundary
    if (index < 0 || index > (list->count - 1)) {
        return ERROR;
    } else {
        Node p = list->head;

        for (int i = 0; i <= index; i++) {
            p = p->next;
        }

        *element = p->element;

        return OK;
    }
}


int updateElement(List *list, int index, ElementType element) {


    if (!list->head) {
        return INFEASIBLE;
    }

    // check whether the index is out of list boundary
    if (index < 0 || index > (list->count - 1)) {
        return ERROR;
    } else {
        Node p = list->head;

        for (int i = 0; i <= index; i++) {
            p = p->next;
        }

        p->element = element;

        return OK;
    }
}


int insertElement(List *list, int index, ElementType element) {


    if (!list->head) {
        return INFEASIBLE;
    }

    // check whether the index is out of list boundary
    if (index < 0 || index > list->count) {
        return ERROR;
    } else {
        Node p = list->head;
        Node q;

        for (int i = 0; i <= index; i++) {
            q = p;
            p = p->next;
        }

        // allocate node memory
        Node node = (Node) malloc(sizeof(LinkNode));

        // allocation failure
        if (!node) {
            return OVERFLOW;
        }

        // initialize node
        node->element = element;

        // insert node
        node->next = q->next;
        q->next = node;

        // check whether the node is the last one
        if (q == list->tail) {
            list->tail = node;
        }

        list->count++;

        return OK;
    }
}


int deleteElement(List *list, int index, ElementType *element) {

    if (!list->head) {
        return INFEASIBLE;
    }

    // check whether the index is out of list boundary
    if (index < 0 || index > list->count - 1) {
        return ERROR;
    } else {
        Node p = list->head;
        Node q;

        for (int i = 0; i <= index; i++) {
            q = p;
            p = p->next;
        }

        // tail node, move tail pointer to previous node
        if (p == list->tail) {
            list->tail = q;
        }

        *element = p->element;
        q->next = p->next;
        free(p);

        list->count--;

        return OK;
    }
}


int
locateElement(List *list, ElementType element, int *index, int (*compare)(ElementType e, ElementType list_element)) {

    int i = 0;

    if (!list->head) {
        return INFEASIBLE;
    }


    Node p = list->head->next;// first node

    while (p) {
        if (compare(element, p->element)) {
            *index = i;
            return OK;
        }
        i++;
        p = p->next;
    }

    // not find
    return NONE;
}

int clearList(List *list) {
    if (!list->head) {
        return INFEASIBLE;
    }

    Node p = list->head->next;// first node
    Node q;

    while (p) {
        q = p;
        p = p->next;
        free(q);
    }

    list->head->next = NULL;
    list->tail = list->head;
    list->count = 0;

    return OK;
}


/**
 * traverse list
 *
 * @param list
 * @param visit callback fuanction
 */
void traverseList(List *list, void (*visit)(ElementType element)) {
    Node p = list->head->next;

    while (p) {
        visit(p->element);
        p = p->next;
    }

    printf("\n");
}

void setDebugLevel(int level) {
    debug = level;
}