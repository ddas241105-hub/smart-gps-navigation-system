#include "../include/HistoryManager.h"

void HistoryManager::saveHistory(
    string algorithm,
    string start,
    string destination,
    double distance,
    double timeTaken,
    double fuelUsed
) {

    ofstream file(
        "data/history.txt",
        ios::app
    );

    file << "================================\n";

    file << "Algorithm: "
         << algorithm << endl;

    file << "Route: "
         << start
         << " -> "
         << destination
         << endl;

    file << "Distance: "
         << distance
         << " km\n";

    file << "Estimated Time: "
         << timeTaken
         << " hrs\n";

    file << "Fuel Required: "
         << fuelUsed
         << " L\n";

    file << "================================\n\n";

    file.close();
}