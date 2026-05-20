#ifndef CSVMANAGER_H
#define CSVMANAGER_H

#include <iostream>
#include <fstream>

using namespace std;

class CSVManager {

public:

    static void exportReport(
        string start,
        string destination,
        double distance,
        double fuel,
        double runtime
    );
};

#endif