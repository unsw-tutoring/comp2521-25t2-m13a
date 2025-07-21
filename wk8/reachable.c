#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"

void doReachable(Graph g, Vertex curr, Set visited) {
    if (SetContains(visited, curr)) return;

    SetInsert(visited, curr);

    for (Vertex next = 0; next < GraphNumVertices(g); next++) {
        if (GraphIsAdjacent(g, curr, next)) doReachable(g, next, visited);
    }
}

Set reachable(Graph g, Vertex src) {
    Set visited = SetNew();
    doReachable(g, src, visited);
    return visited;
}
