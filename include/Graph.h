#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Graph {

private:

    unordered_map<string,
    vector<pair<string, int>>> adjList;

    unordered_map<string,
    pair<int, int>> coordinates;


public:

    void addRoad(string city1,
                 string city2,
                 int distance);

    void updateRoadDistance(string city1,
                            string city2,
                            int newDistance);

    void addCoordinates(string city,
                        int x,
                        int y);

    pair<int, int> getCoordinates(string city);

    void displayMap();
    void addCity(string city);
    
    unordered_map<string,
    vector<pair<string, int>>>& getAdjList();
};

#endif