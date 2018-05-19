/**
 * binarytree.h
 *
 * header file of binary tree
 *
 * Created by Houor
 */



#include "stdio.h"
#include "stdlib.h"

#include "binarytree.h"

int arrayIndex = 0;

int initBinaryTree(BiTree tree) {
    tree = NULL;
    arrayIndex = 0;
    return OK;
}

BiTree preCreateBinaryTree(ElementType *elements) {
    //char ch;
    //scanf("%c", &ch);

    BiTree tree;
    char ch = *(elements + arrayIndex++);

    if (ch == '#') {
        tree = NULL;
    } else {
        tree = (BiTree) malloc(sizeof(BiTreeNode));

        if (!tree) {
            exit(OVERFLOW);
        }

        tree->data = ch;
        tree->leftchild = preCreateBinaryTree(elements);
        tree->rightchild = preCreateBinaryTree(elements);
    }

    return tree;
}

int destroyBinaryTree(BiTree tree) {
    if (tree != NULL) {
        destroyBinaryTree(tree->leftchild);
        destroyBinaryTree(tree->rightchild);
        free(tree);
    }

    return OK;
}

int preOrderTraverse(BiTree tree) {
    if (tree != NULL) {
        printf("%c\t", tree->data);
        preOrderTraverse(tree->leftchild);
        preOrderTraverse(tree->rightchild);
    }
    return OK;
}

int inOrderTraverse(BiTree tree) {

    if (tree != NULL) {
        inOrderTraverse(tree->leftchild);
        printf("%c\t", tree->data);
        inOrderTraverse(tree->rightchild);
    }

    return OK;
}

int postOrderTraverse(BiTree tree) {
    if (tree != NULL) {
        postOrderTraverse(tree->leftchild);
        postOrderTraverse(tree->rightchild);
        printf("%c\t", tree->data);
    }
    return OK;
}


