#include "../include/Graph.h"

void Graph::addRoad(string city1, string city2, int distance) {
    adjList[city1].push_back({city2, distance});
    adjList[city2].push_back({city1, distance});
}

void Graph::displayMap() {
    cout << "\n===== CITY MAP =====\n";

    for (auto city : adjList) {
        cout << city.first << " -> ";

        for (auto neighbor : city.second) {
            cout << "(" << neighbor.first
                 << ", " << neighbor.second
                 << " km) ";
        }

        cout << endl;
    }
}

unordered_map<string, vector<pair<string, int>>> Graph::getAdjList() {
    return adjList;
}