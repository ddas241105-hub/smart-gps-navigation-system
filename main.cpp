#include "include/Graph.h"
#include "include/Dijkstra.h"
#include "include/TrafficManager.h"
#include "include/Utils.h"

int main() {

    Graph cityMap;

    Utils::loadRoadData(
        cityMap,
        "data/roads.txt"
    );

    cityMap.displayMap();

    Dijkstra navigator;

    string start, destination;

    cout << "\nEnter starting city: ";
    cin >> start;

    cout << "Enter destination city: ";
    cin >> destination;

    navigator.shortestPath(
        cityMap,
        start,
        destination
    );

    TrafficManager traffic;

    traffic.simulateTraffic(cityMap);

    return 0;
}