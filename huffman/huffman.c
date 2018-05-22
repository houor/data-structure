/**
 * huffman.c
 *
 * implementation file of huffman tree
 *
 * Created by Houor
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "huffman.h"

int debugLevel = 0;

void select(HuffmanTree HT, int n, int *s1, int *s2) {
    int i = 1;
    while (HT[i].parent != 0)
        i++;
    *s1 = i;

    i++;
    while (HT[i].parent != 0)
        i++;
    *s2 = i;

    for (; i <= n; i++) {
        if (HT[i].parent == 0) {
            if (HT[i].weight < HT[*s1].weight) {
                *s2 = *s1;
                *s1 = i;
            } else if (HT[i].weight < HT[*s2].weight) {
                *s2 = i;
            }
        }
    }
}


int createHuffmanTree(HuffmanTree *huffmanTree, int *weight, ElementType *data, int n) {
    int m, i, j;
    int s1, s2;

    if (n <= 1)
        return ERROR;

    m = 2 * n - 1;

    (*huffmanTree) = (HuffmanTree) malloc((m + 1) * sizeof(HuffmanTreeNode));
    if (!(*huffmanTree)) {
        return OVERFLOW;
    }

    // HuffmanTree[0] is not used
    HuffmanTree tree = (*huffmanTree);
    HuffmanTree p = (*huffmanTree) + 1;

    // initialize huffman tree
    // leaf node
    for (i = 1; i <= n; i++, p++, weight++, data++) {
        p->data = *data;
        p->weight = *weight;
        p->parent = 0;
        p->rightChild = 0;
        p->leftChild = 0;
    }

    // in node
    for (; i <= m; i++, ++p) {
        p->weight = 0;
        p->parent = 0;
        p->rightChild = 0;
        p->leftChild = 0;
    }

    // create Huffman tree
    // generate in-node from huffman tree node by selecting two small node
    for (i = n + 1; i <= m; i++) {
        // select from 1 to i - 1
        select(tree, i - 1, &s1, &s2);
        tree[s1].parent = i;
        tree[s2].parent = i;
        tree[i].leftChild = s1;
        tree[i].rightChild = s2;
        tree[i].weight = tree[s1].weight + tree[s2].weight;

        if (debugLevel == TRUE) {
            for (j = 1; j <= i; j++) {
                printf("%6d%6d%6d%6d%6d\n", j, tree[j].weight, tree[j].parent, tree[j].leftChild, tree[j].rightChild);
            }
            printf("=====================================\n");
        }
    }


    return OK;
}


int codeHuffmanTree(HuffmanTree huffmanTree, HuffmanCode *huffmanCode, int n) {
    int c, m, f, i, start;
    char *cd;


    (*huffmanCode) = (HuffmanCode) malloc((n + 1) * sizeof(char *)); //分配n个字符编码的头指针向量

    if (!(*huffmanCode)) {
        return OVERFLOW;
    }

    HuffmanCode hfCode = (*huffmanCode);

    // allocate memory workspace for coding
    cd = (char *) malloc(n * sizeof(char));
    // code terminator
    cd[n - 1] = '\0';
    for (i = 1; i <= n; ++i) {
        start = n - 1;

        // coding from leaf to root node
        for (c = i, f = huffmanTree[i].parent; f != 0; c = f, f = huffmanTree[f].parent) {
            if (huffmanTree[f].leftChild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }

        // allocate memory for the character
        //  0 1 2 3 4 ... start ... n-2 n-1
        // |...not use....|.....code....\0|
        // length(not use) = start
        // length(code) = n - start
        hfCode[i] = (char *) malloc((n - start) * sizeof(char));
        strcpy(hfCode[i], cd + start);
    }
    free(cd);

    if (debugLevel == TRUE) {
        for (i = 1; i <= m; i++) {
            printf("%c: %s\n", huffmanTree[i].data, hfCode[i]);
        }
    }

    return OK;

}

int destroy(HuffmanTree huffmanTree, HuffmanCode huffmanCode) {
    if (huffmanCode != NULL) {
        free(huffmanCode);
    }
    if (huffmanTree != NULL) {
        free(huffmanTree);
    }
    return OK;
}


void setDebugLevel(int level) {
    debugLevel = level;
}
