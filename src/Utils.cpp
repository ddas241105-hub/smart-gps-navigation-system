#include "../include/Utils.h"

#include <fstream>

void Utils::loadRoadData(Graph& graph,
                         string filename) {

    ifstream file(filename);

    string city1, city2;
    int distance;

    while (file >> city1 >> city2 >> distance) {

        graph.addRoad(city1,
                      city2,
                      distance);
    }

    file.close();
}