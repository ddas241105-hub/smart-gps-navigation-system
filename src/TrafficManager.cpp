#include "../include/TrafficManager.h"

#include <cstdlib>
#include <ctime>

#define RESET "\033[0m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

using namespace std;

void TrafficManager::simulateTraffic(Graph& graph) {

    srand(time(0));

    auto &adjList = graph.getAdjList();

    cout << YELLOW;
    cout << "\n===== TRAFFIC CONDITIONS =====\n";
    cout << RESET;

    for (auto &city : adjList) {

        for (auto &neighbor : city.second) {

            int trafficLevel = rand() % 3;

            int extraDistance = 0;

            string trafficLabel;

            if (trafficLevel == 0) {

                trafficLabel = "LOW";
                extraDistance = 2;

                cout << GREEN;
            }

            else if (trafficLevel == 1) {

                trafficLabel = "MEDIUM";
                extraDistance = 5;

                cout << YELLOW;
            }

            else {

                trafficLabel = "HIGH";
                extraDistance = 9;

                cout << RED;
            }

            neighbor.second += extraDistance;

            cout << city.first
                 << " -> "
                 << neighbor.first
                 << " : "
                 << trafficLabel
                 << " traffic\n";

            cout << RESET;
        }
    }
}