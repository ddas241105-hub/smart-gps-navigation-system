#ifndef ASTAR_H
#define ASTAR_H

#include "Graph.h"

class AStar {

public:

    double shortestPath(
        Graph& graph,
        string start,
        string destination
    );

    double heuristic(
        Graph& graph,
        string city1,
        string city2
    );
};

#endif