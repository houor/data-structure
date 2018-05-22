#include "stdio.h"
#include "stdlib.h"
#include "huffman.h"

int main() {

    int status;
    int n = 8;
    int weight[8] = {5, 29, 7, 8, 14, 23, 3, 11};
    int i;

    ElementType data[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    HuffmanTree huffmanTree = NULL;
    HuffmanCode huffmanCode = NULL;

    setDebugLevel(TRUE);

    status = createHuffmanTree(&huffmanTree, weight, data, n);
    if (status == OK) {

        status = codeHuffmanTree(huffmanTree, &huffmanCode, n);


        if (status == OK) {
            printf("Huffman Code:\n");
            for (i = 1; i <= n; i++) {
                printf("%c: %s\n", huffmanTree[i].data, huffmanCode[i]);
            }
        }
    }


    destroy(huffmanTree, huffmanCode);

    return 0;
}