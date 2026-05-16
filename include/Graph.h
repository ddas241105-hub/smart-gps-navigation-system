#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adjList;

public:
    void addRoad(string city1, string city2, int distance);

    void displayMap();

    unordered_map<string, vector<pair<string, int>>> getAdjList();
};

#endif