#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

// returns an array of length nV containing the shortest
// distance between src and each vertex.
// For an undirected, unweighted graph.
int *findShortestDistance(Graph g, int src) {
    Queue q = QueueNew();
    bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
    int *dist = malloc(GraphNumVertices(g) * sizeof(int));
    for (int i = 0; i < GraphNumVertices(g); i++) {
        dist[i] = INT_MAX;
    }

    QueueEnqueue(q, src);
    visited[src] = true;
    dist[src] = 0;

    while (!QueueIsEmpty(q)) {
        int v = QueueDequeue(q);
        for (int w = 0; w < GraphNumVertices(g); w++) {
            if (GraphIsAdjacent(g, v, w) && !visited[w]) {
                QueueEnqueue(q, w);
                visited[w] = true;
                dist[w] = dist[v] + 1;
            }
        }
    }

    free(visited);
    QueueFree(q);

    return dist;
}
