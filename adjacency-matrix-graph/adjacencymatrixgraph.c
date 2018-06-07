/**
 * adjacencymatrixgraph.c
 *
 * implementation of graph represented by adjacency matrix
 *
 * Create By Houor
 */

#include "stdio.h"
#include "stdlib.h"

#include "../linked-queue/linkedqueue.h"

#include "adjacencymatrixgraph.h"

int debug = 1;

Status createGraph(ADJMTXGraph *graph, int vertexNum, VertexType *vertex, int edgeNum, EdgeNode *edgeNodes) {

    int i, j, k;
    int n;

    if (vertexNum >= MAX) {
        return INFEASIBLE;
    }

    if (vertexNum <= 0 || edgeNum <= 0) {
        return ERROR;
    }

    graph->vertex = (VertexType *) malloc(vertexNum * sizeof(VertexType));

    if (!graph->vertex) {
        return OVERFLOW;
    }

    n = vertexNum * vertexNum;
    graph->matrix = (EdgeType *) malloc(n * sizeof(EdgeType));
    if (!graph->matrix) {
        return OVERFLOW;
    }

    for (k = 0; k < n; k++) {
        *(graph->matrix + k) = INFINITE;

    }

    for (i = 0; i < vertexNum; ++i) {
        *(graph->vertex + i) = *(vertex + i);
    }
    graph->vertexNum = vertexNum;

    EdgeNode *p = edgeNodes;

    for (k = 0; k < edgeNum; k++, p++) {
        *(graph->matrix + p->i * vertexNum + p->j) = p->weight;
        *(graph->matrix + p->j * vertexNum + p->i) = p->weight;
    }
    graph->edgeNum = edgeNum;

    if (debug == TRUE) {
        printf("\nVertex:\n\t");
        for (i = 0; i < vertexNum; ++i) {
            printf("%6c", *(graph->vertex + i));
        }

        printf("\nAdjacency Matrix:\n");

        for (i = 0; i < vertexNum; i++) {
            printf("\t");
            for (j = 0; j < vertexNum; j++) {
                n = *(graph->matrix + i * vertexNum + j);
                if (n == INFINITE) {
                    printf("%6c", '-');
                } else {
                    printf("%6d", n);
                }
            }
            printf("\n");
        }
    }


    return OK;
}


Status destroyGraph(ADJMTXGraph *graph) {
    if (graph->vertex) {
        free(graph->vertex);
    }

    if (graph->matrix) {
        free(graph->matrix);
    }

    return OK;
}

int dfsIndex = 0;

void dfs(ADJMTXGraph *graph, int i, int *visited, VertexType *dfsVertex) {
    visited[i] = 1;

    *(dfsVertex + dfsIndex++) = graph->vertex[i];

    for (int j = 0; j < graph->vertexNum; j++) {
        if (*(graph->matrix + i * graph->vertexNum + j) != 0 &&
            *(graph->matrix + i * graph->vertexNum + j) != INFINITE && !*(visited + j)) {
            dfs(graph, j, visited, dfsVertex);
        }
    }
}

Status DFS(ADJMTXGraph *graph, int index, VertexType *dfsVertex) {

    int i;

    int *visited = (int *) malloc(graph->vertexNum * sizeof(int));
    if (!visited) {
        return OVERFLOW;
    }

    for (i = 0; i < graph->vertexNum; i++) {
        *(visited + i) = 0;
    }

    dfsIndex = 0;
    dfs(graph, index, visited, dfsVertex);

    free(visited);

    return OK;
}

Status dfsTraverse(ADJMTXGraph *graph) {
    int i;
    int j;

    VertexType *dfsVertex = (VertexType *) malloc(graph->vertexNum * sizeof(VertexType));
    if (!dfsVertex) {
        return OVERFLOW;
    }

    for (i = 0; i < graph->vertexNum; ++i) {
        DFS(graph, i, dfsVertex);

        printf("\t");

        for (j = 0; j < graph->vertexNum; j++) {
            printf("%c", *(dfsVertex + j));

            if (j < graph->vertexNum - 1) {
                printf(" --> ");
            } else {
                printf("\n");
            }
        }
    }

    free(dfsVertex);

    return OK;
}

Status BFS(ADJMTXGraph *graph, LinkedQueue *queue, int index, int *visited, VertexType *dfsVertex) {

    int k = 0;
    int j, t;

    for (k = 0; k < graph->vertexNum; k++) {
        *(visited + k) = 0;
    }

    if (visited[index] == 0) {
        visited[index] = 1;

        if (debug == TRUE) {
            printf("\n\t");
            printf("%c\t", graph->vertex[index]);
        }
        *(dfsVertex++) = graph->vertex[index];


        enQueue(queue, index);

        while (length(queue)) {
            deQueue(queue, &t);

            for (j = 0; j < graph->vertexNum; ++j) {
                if (*(graph->matrix + t * graph->vertexNum + j) != INFINITE && visited[j] == 0) {
                    visited[j] = 1;

                    if (debug == TRUE) {
                        printf("%c\t", graph->vertex[j]);
                    }

                    *(dfsVertex++) = graph->vertex[j];

                    enQueue(queue, j);
                }

            }

        }
    }

    return OK;
}

Status bfsTraverse(ADJMTXGraph *graph) {
    int i, j;
    LinkedQueue queue;
    initializeQueue(&queue);


    int *visited = (int *) malloc(graph->vertexNum * sizeof(int));
    if (!visited) {
        return OVERFLOW;
    }

    VertexType *dfsVertex = (VertexType *) malloc(graph->vertexNum * sizeof(VertexType));
    if (!dfsVertex) {
        return OVERFLOW;
    }


    for (i = 0; i < graph->vertexNum; i++) {

        BFS(graph, &queue, i, visited, dfsVertex);

        printf("\t");

        for (j = 0; j < graph->vertexNum; j++) {
            printf("%c", *(dfsVertex + j));

            if (j < graph->vertexNum - 1) {
                printf(" --> ");
            } else {
                printf("\n");
            }
        }

    }

    free(dfsVertex);
    free(visited);


    destroyQueue(&queue);

    return OK;
}


void setDebug(int level) {
    debug = level;
}