/**
 * binarytree.c
 *
 * implementation file of binary tree
 *
 * created by Houor
 */

#include "stdio.h"
#include "stdlib.h"

#include "binarytree.h"

int arrayIndex = 0;

int initializeBinaryTree(BiTree tree) {
    tree = NULL;
    arrayIndex = 0;
    return OK;
}

BiTree preCreateBinaryTree(ElementType *elements) {
    // in the function, we will use an array to initialize tree
    // if you want initialize the tree by inputting the element,
    // then use 'scanf' function just like the follow
    // char ch;
    // scanf("%c", &ch);

    BiTree tree;
    char ch = *(elements + arrayIndex++);

    if (ch == '#') {
        tree = NULL;
    } else {
        tree = (BiTree) malloc(sizeof(BiTreeNode));

        if (!tree) {
            return OVERFLOW;
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

int count(BiTree tree) {
    if (tree == NULL) {
        return 0;
    } else {
        return count(tree->leftchild) + count(tree->rightchild) + 1;
    }
}

int leafCount(BiTree tree) {
    if (tree == NULL) {
        return 0;
    }
    if (tree->leftchild == NULL && tree->rightchild == NULL) {
        return 1;
    } else {
        return leafCount(tree->leftchild) + leafCount(tree->rightchild);
    }
}


int depth(BiTree tree) {
    if (tree == NULL) {
        return 0;
    }

    int leftNum = depth(tree->leftchild);
    int rightNum = depth(tree->rightchild);

    return leftNum > rightNum ? leftNum + 1 : rightNum + 1;
}
