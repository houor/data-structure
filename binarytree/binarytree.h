/**
 * binarytree.h
 *
 * header file of binary tree
 *
 * Created by Houor
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#define ElementType char

#define TRUE             1
#define FALSE            0
#define OK               1
#define ERROR            0
#define INFEASIBLE      -1
#define OVERFLOW        -2
#define FULL             1
#define EMPTY            0

typedef struct BiTreeNode {
    ElementType data;
    struct BiTreeNode *leftchild;
    struct BiTreeNode *rightchild;
} BiTreeNode, *BiTree;


int initBinaryTree(BiTree tree);

BiTree preCreateBinaryTree(ElementType *elements);

int destroyBinaryTree(BiTree tree);

int preOrderTraverse(BiTree tree);

int inOrderTraverse(BiTree tree);

int postOrderTraverse(BiTree tree);


#endif //BINARYTREE_H
