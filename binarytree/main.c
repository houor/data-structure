/**
 * main.c
 *
 * test for binary tree
 *
 * created by Houor
 */

#include "stdio.h"

#include "binarytree.h"

int main() {

    BiTree tree;

    ElementType elements[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#', 'G', '#', '#', 'F', '#', '#', '#'};

    initializeBinaryTree(tree);

    printf("create tree by pre order...\n");

    tree = preCreateBinaryTree(elements);

    if (tree != NULL) {
        printf("Pre Order Traverse: \n");
        preOrderTraverse(tree);
        printf("\n");

        printf("In Order Traverse: \n");
        inOrderTraverse(tree);
        printf("\n");


        printf("Post Order Traverse: \n");
        postOrderTraverse(tree);
        printf("\n");

        printf("node count: %d.\n", count(tree));
        printf("leaf count: %d.\n", leafCount(tree));
        printf("tree depth: %d.\n", depth(tree));

        printf("destroy tree in end.\n");
        destroyBinaryTree(tree);
    }

    return OK;
}