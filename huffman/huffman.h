/**
 * huffman.h
 *
 * header file of huffman tree
 *
 * Created by Houor
 */

#ifndef HUFFMAN_H
#define HUFFMAN_H


#define ElementType char

#define TRUE             1
#define FALSE            0
#define OK               1
#define ERROR            0
#define INFEASIBLE      -1
#define OVERFLOW        -2
#define FULL             1
#define EMPTY            0

#define MAXVALUE       200
#define MAXBM           10
#define MAXNODE         10


typedef struct HuffmanTreeNode {
    ElementType data;
    int weight;
    int parent;
    int leftChild;
    int rightChild;
} HuffmanTreeNode, *HuffmanTree;

typedef char **HuffmanCode;


/**
 * create huffman tree
 *
 * @param huffmanTree
 * @param weight
 * @param data the character
 * @param n number of character
 * @return status
 */
int createHuffmanTree(HuffmanTree *huffmanTree, int *weight, ElementType *data, int n);


/**
 * coding by the huffman tree
 *
 * @param huffmanTree
 * @param huffmanCode
 * @param n number of character
 * @return status
 */
int codeHuffmanTree(HuffmanTree huffmanTree, HuffmanCode *huffmanCode, int n);

/**
 * release memory of huffman tree and huffman code
 *
 * @param huffmanTree
 * @param huffmanCode
 * @return status
 */
int destroy(HuffmanTree huffmanTree, HuffmanCode huffmanCode);

void setDebugLevel(int level);

#endif //HUFFMAN_H
