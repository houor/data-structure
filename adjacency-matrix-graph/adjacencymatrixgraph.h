/**
 * adjacencymatrixgraph.h
 *
 * graph represented by adjacency matrix
 *
 * Create By Houor
 */

#ifndef ADJACENCY_MATRIX_GRAPH_H
#define ADJACENCY_MATRIX_GRAPH_H

#include "../linked-queue/linkedqueue.h"

#define MAX          10000
#define INFINITE     65535

#define TRUE             1
#define FALSE            0
#define OK               1
#define ERROR            0
#define INFEASIBLE      -1
#define OVERFLOW        -2

typedef char VertexType;
typedef int EdgeType;

typedef int Status;

typedef struct {
    VertexType *vertex;
    EdgeType *matrix;
    int vertexNum;
    int edgeNum;
} ADJMTXGraph;

typedef struct {
    int i;
    int j;
    EdgeType weight;
} EdgeNode;

/**
 * create adjacency matrix graph by using a list of edge node
 *
 * @param graph
 * @param vertexNum vertex number
 * @param vertex graph vertex
 * @param edgeNum the number of arc in graph
 * @param edgeNodes edge (i, j, weight) info to create graph
 * @return status
 */
Status createGraph(ADJMTXGraph *graph, int vertexNum, VertexType *vertex, int edgeNum, EdgeNode *edgeNodes);


/**
 * destroy graph
 *
 * @param graph
 * @return
 */
Status destroyGraph(ADJMTXGraph *graph);


/**
 * depth first search
 *
 * depth first search from the index node
 *
 * @param graph
 * @param index the first node to traverse
 * @param dfsVertex traverse result
 * @return
 */
Status DFS(ADJMTXGraph *graph, int index, VertexType *dfsVertex);

/**
 * depth first search
 *
 * traverse from each vertex
 *
 * @param graph
 * @return
 */
Status dfsTraverse(ADJMTXGraph *graph);


/**
 * breadth first search
 *
 * breadth first search from the index node
 *
 * @param graph
 * @param queue
 * @param index
 * @param visited
 * @param dfsVertex
 * @return
 */
Status BFS(ADJMTXGraph *graph, LinkedQueue *queue, int index, int *visited, VertexType *dfsVertex);


/**
 * breadth first search
 *
 * traverse from each vertex
 *
 * @param graph
 * @return
 */
Status bfsTraverse(ADJMTXGraph *graph);

void setDebug(int level);

#endif //ADJACENCY_MATRIX_GRAPH_H
