#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

using namespace std;

class Vehicle {

private:

    string type;
    double speed;
    double mileage;

public:

    Vehicle(
        string t,
        double s,
        double m
    ) {

        type = t;
        speed = s;
        mileage = m;
    }

    string getType() {
        return type;
    }

    double getSpeed() {
        return speed;
    }

    double getMileage() {
        return mileage;
    }
};

#endif