#include <stdio.h>

#include "adjacencymatrixgraph.h"

int main() {

    int vn = 6;
    int en = 6;

    Status status;

    VertexType vertexes[] = {'1',
                             '2',
                             '3',
                             '4',
                             '5',
                             '6'};
    EdgeNode nodes[] = {
            {0, 1, 1},
            {0, 2, 1},
            {0, 3, 1},
            {1, 4, 1},
            {2, 4, 1},
            {3, 5, 1}
    };

    ADJMTXGraph graph;

    setDebug(TRUE);

    printf("Create Adjacency Matrix...");
    status = createGraph(&graph, vn, vertexes, en, nodes);
    if (status == OK) {
        printf("Create Adjacency Matrix OK.\n");
    } else {
        return status;
    }

    printf("\nDFS Traverse...\n");
    dfsTraverse(&graph);

    printf("\nBFS Traverse...\n");
    bfsTraverse(&graph);
    printf("\n\n");

    status = destroyGraph(&graph);
    if (status == OK) {
        printf("Destroy Adjacency Matrix OK.");
    }

    return 0;
}