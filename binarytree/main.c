#include "stdio.h"

#include "binarytree.h"

int main() {

    BiTree tree;

    ElementType elements[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#', 'G', '#', '#', 'F', '#', '#', '#'};

    initBinaryTree(tree);

    tree = preCreateBinaryTree(elements);

    if (tree != NULL) {
        printf("In Order Traverse: \n");
        inOrderTraverse(tree);
        printf("\n");
    }

    destroyBinaryTree(tree);

    return OK;
}