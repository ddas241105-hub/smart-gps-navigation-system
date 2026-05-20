#include "../include/AStar.h"

#include <queue>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cctype>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RED "\033[31m"
#define YELLOW "\033[33m"

using namespace std;

string toLowerCaseAStar(string text) {

    for (char &c : text) {
        c = tolower(c);
    }

    return text;
}

double AStar::heuristic(Graph& graph,
                        string city1,
                        string city2) {

    auto p1 = graph.getCoordinates(city1);
    auto p2 = graph.getCoordinates(city2);

    return sqrt(
        pow(p2.first - p1.first, 2)
        +
        pow(p2.second - p1.second, 2)
    );
}

double AStar::shortestPath(Graph& graph,
                           string start,
                           string destination) {

    auto &adjList = graph.getAdjList();

    unordered_map<string, string> normalizedCities;

    for (auto city : adjList) {

        normalizedCities[
            toLowerCaseAStar(city.first)
        ] = city.first;
    }

    start = toLowerCaseAStar(start);
    destination = toLowerCaseAStar(destination);

    if (normalizedCities.find(start)
        == normalizedCities.end()
        ||
        normalizedCities.find(destination)
        == normalizedCities.end()) {

        cout << RED;
        cout << "City not found.\n";
        cout << RESET;

        return -1;
    }

    start = normalizedCities[start];
    destination = normalizedCities[destination];

    unordered_map<string, double> distance;
    unordered_map<string, string> parent;

    for (auto city : adjList) {
        distance[city.first] = INT_MAX;
    }

    priority_queue<
        pair<double, string>,
        vector<pair<double, string>>,
        greater<pair<double, string>>
    > pq;

    distance[start] = 0;

    pq.push({0, start});

    while (!pq.empty()) {

        string currentCity = pq.top().second;

        pq.pop();

        for (auto neighbor : adjList[currentCity]) {

            string nextCity = neighbor.first;
            int roadDistance = neighbor.second;

            double estimatedCost =
                distance[currentCity]
                +
                roadDistance
                +
                heuristic(graph,
                          nextCity,
                          destination);

            if (estimatedCost
                < distance[nextCity]) {

                distance[nextCity]
                    = estimatedCost;

                parent[nextCity]
                    = currentCity;

                pq.push({
                    estimatedCost,
                    nextCity
                });
            }
        }
    }

    cout << CYAN;
    cout << "\n===== A* PATH RESULT =====\n";
    cout << RESET;

    if (parent.find(destination)
        == parent.end()) {

        cout << RED;
        cout << "No route found.\n";
        cout << RESET;

        return -1;
    }

    vector<string> path;

    string current = destination;

    while (current != start) {

        path.push_back(current);

        current = parent[current];
    }

    path.push_back(start);

    reverse(path.begin(),
            path.end());

    cout << GREEN;

    cout << "Estimated Distance: "
         << distance[destination]
         << " km\n\n";

    cout << YELLOW;
    cout << "Optimal A* Route:\n";

    for (int i = 0;
         i < path.size();
         i++) {

        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }

    cout << endl;

    cout << RESET;

    return distance[destination];
}