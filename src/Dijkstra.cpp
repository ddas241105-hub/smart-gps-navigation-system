#include "../include/Dijkstra.h"

#include <queue>
#include <unordered_map>
#include <climits>

void Dijkstra::shortestPath(Graph& graph,
                            string start,
                            string destination) {

    auto adjList = graph.getAdjList();

    unordered_map<string, int> distance;

    for (auto city : adjList) {
        distance[city.first] = INT_MAX;
    }

    priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        greater<pair<int, string>>
    > pq;

    distance[start] = 0;

    pq.push({0, start});

    while (!pq.empty()) {

        string currentCity = pq.top().second;
        int currentDistance = pq.top().first;

        pq.pop();

        for (auto neighbor : adjList[currentCity]) {

            string nextCity = neighbor.first;
            int roadDistance = neighbor.second;

            if (currentDistance + roadDistance
                < distance[nextCity]) {

                distance[nextCity]
                    = currentDistance + roadDistance;

                pq.push({
                    distance[nextCity],
                    nextCity
                });
            }
        }
    }

    cout << "\n===== SHORTEST PATH RESULT =====\n";

    if (distance[destination] == INT_MAX) {
        cout << "No route found.\n";
    }
    else {
        cout << "Shortest distance from "
             << start << " to "
             << destination << " = "
             << distance[destination]
             << " km\n";
    }
}