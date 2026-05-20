#include "../include/CSVManager.h"

void CSVManager::exportReport(
    string start,
    string destination,
    double distance,
    double fuel,
    double runtime
) {

    ofstream file(
        "data/reports.csv",
        ios::app
    );

    file << start << ",";
    file << destination << ",";
    file << distance << ",";
    file << fuel << ",";
    file << runtime << "\n";

    file.close();
}