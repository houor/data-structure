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


/**
 * initialize tree
 *
 * @param tree
 * @return
 */
int initializeBinaryTree(BiTree tree);

/**
 * create tree by pre order
 * @param elements
 * @return
 */
BiTree preCreateBinaryTree(ElementType *elements);


/**
 * destroy tree
 *
 * @param tree
 * @return
 */
int destroyBinaryTree(BiTree tree);


/**
 * traverse tree in pre order way
 *
 * @param tree
 * @return
 */
int preOrderTraverse(BiTree tree);


/**
 * traverse tree in middle order way
 *
 * @param tree
 * @return
 */
int inOrderTraverse(BiTree tree);


/**
 * traverse tree in post order way
 *
 * @param tree
 * @return
 */
int postOrderTraverse(BiTree tree);


/**
 * the number of tree node
 *
 * @param tree
 * @return
 */
int count(BiTree tree);


/**
 * the number of leaf node
 *
 * @param tree
 * @return
 */
int leafCount(BiTree tree);


/**
 * the depth of tree
 *
 * @param tree
 * @return
 */
int depth(BiTree tree);


#endif //BINARYTREE_H
