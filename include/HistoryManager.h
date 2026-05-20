#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H

#include <iostream>
#include <fstream>

using namespace std;

class HistoryManager {

public:

    static void saveHistory(
        string algorithm,
        string start,
        string destination,
        double distance,
        double timeTaken,
        double fuelUsed
    );
};

#endif