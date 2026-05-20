#include "include/Graph.h"
#include "include/Dijkstra.h"
#include "include/AStar.h"
#include "include/TrafficManager.h"
#include "include/Utils.h"
#include "include/HistoryManager.h"
#include "include/ASCIIVisualizer.h"
#include "include/CSVManager.h"
#include "include/Vehicle.h"

#include <chrono>
#include <fstream>

#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"

using namespace std;
using namespace chrono;

void displayMenu() {

    cout << CYAN;

    cout << "\n========== SMART GPS MENU ==========\n";

    cout << "1. Display City Map\n";
    cout << "2. Find Best Route\n";
    cout << "3. View Route History\n";
    cout << "4. Display ASCII Map\n";
    cout << "5. Add New City\n";
    cout << "6. Add New Road\n";
    cout << "7. Exit\n";

    cout << "====================================\n";

    cout << RESET;
}

void showHistory() {

    ifstream file("data/history.txt");

    if (!file) {

        cout << RED;
        cout << "\nNo history found.\n";
        cout << RESET;

        return;
    }

    cout << YELLOW;
    cout << "\n========== ROUTE HISTORY ==========\n";
    cout << RESET;

    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main() {

    Graph cityMap;

    Utils::loadRoadData(
        cityMap,
        "data/roads.txt"
    );

    cityMap.addCoordinates("Kolkata", 0, 0);
    cityMap.addCoordinates("Howrah", 2, 1);
    cityMap.addCoordinates("SaltLake", 4, 2);
    cityMap.addCoordinates("Airport", 6, 3);
    cityMap.addCoordinates("NewTown", 7, 4);
    cityMap.addCoordinates("Rajarhat", 8, 5);
    cityMap.addCoordinates("Bidhannagar", 5, 3);
    cityMap.addCoordinates("DumDum", 5, 2);
    cityMap.addCoordinates("Barasat", 10, 5);

    cityMap.addCoordinates("Bardhaman", 15, 8);
    cityMap.addCoordinates("Durgapur", 22, 10);
    cityMap.addCoordinates("Asansol", 28, 12);
    cityMap.addCoordinates("Raniganj", 30, 13);
    cityMap.addCoordinates("Dhanbad", 36, 16);

    cityMap.addCoordinates("Bolpur", 18, 14);
    cityMap.addCoordinates("Krishnanagar", 16, 4);
    cityMap.addCoordinates("Berhampore", 22, 5);
    cityMap.addCoordinates("Malda", 30, 7);

    cityMap.addCoordinates("Kharagpur", 12, -6);
    cityMap.addCoordinates("Midnapore", 10, -10);
    cityMap.addCoordinates("Haldia", 18, -12);
    cityMap.addCoordinates("Digha", 8, -18);

    cityMap.addCoordinates("Siliguri", 42, 20);
    cityMap.addCoordinates("Jalpaiguri", 46, 22);
    cityMap.addCoordinates("CoochBehar", 52, 24);

    cout << CYAN;
    cout << "\nSMART GPS NAVIGATION SYSTEM\n";
    cout << RESET;

    TrafficManager traffic;

    traffic.simulateTraffic(cityMap);

    string choice;

    while (true) {

        displayMenu();

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == "1" || choice == "1.") {

            cityMap.displayMap();
        }

        else if (choice == "2" || choice == "2.") {

            traffic.simulateTraffic(cityMap);

            cout << CYAN;
            cout << "\nTraffic recalculated.\n";
            cout << RESET;
            
            cout << "\nChoose Vehicle Type:\n";

            cout << "1. Car\n";
            cout << "2. Bike\n";
            cout << "3. Truck\n";

            string vehicleChoice;

            cout << "Enter choice: ";
            cin >> vehicleChoice;

            Vehicle selectedVehicle(
                "Car",
                50,
                15
            );

            if (vehicleChoice == "2") {

                selectedVehicle =
                    Vehicle(
                        "Bike",
                        60,
                        35
                    );
            }

            else if (vehicleChoice == "3") {

                selectedVehicle =
                    Vehicle(
                        "Truck",
                        35,
                        8
                    );
            }

            string start, destination;

            cout << "\nEnter starting city: ";
            cin >> start;

            cout << "Enter destination city: ";
            cin >> destination;

            Dijkstra dijkstraNavigator;

            auto dijkstraStart =
                high_resolution_clock::now();

            double dijkstraDistance =
                dijkstraNavigator.shortestPath(
                    cityMap,
                    start,
                    destination
                );

            auto dijkstraEnd =
                high_resolution_clock::now();

            auto dijkstraRuntime =
                duration_cast<microseconds>(
                    dijkstraEnd - dijkstraStart
                );

            AStar astarNavigator;

            auto astarStart =
                high_resolution_clock::now();

            double astarDistance =
                astarNavigator.shortestPath(
                    cityMap,
                    start,
                    destination
                );

            auto astarEnd =
                high_resolution_clock::now();

            auto astarRuntime =
                duration_cast<microseconds>(
                    astarEnd - astarStart
                );

            double averageSpeed = selectedVehicle.getSpeed();

            double travelTime =
                dijkstraDistance / averageSpeed;

            double mileage = selectedVehicle.getMileage();

            double fuelUsed =
                dijkstraDistance / mileage;

            cout << GREEN;

            cout << "\n===== JOURNEY ANALYSIS =====\n";

            cout << "Vehicle Type: "
                 << selectedVehicle.getType()
                 << "\n";
                 
            cout << "Estimated Travel Time: "
                 << travelTime
                 << " hrs\n";

            cout << "Estimated Fuel Required: "
                 << fuelUsed
                 << " L\n";

            cout << "\n===== ALGORITHM RUNTIME =====\n";

            cout << "Dijkstra Runtime: "
                 << dijkstraRuntime.count()
                 << " microseconds\n";

            cout << "A* Runtime: "
                 << astarRuntime.count()
                 << " microseconds\n";

            cout << RESET;

            CSVManager::exportReport(
                start,
                destination,
                dijkstraDistance,
                fuelUsed,
                dijkstraRuntime.count()
            );

            HistoryManager::saveHistory(
                "Dijkstra",
                start,
                destination,
                dijkstraDistance,
                travelTime,
                fuelUsed
            );

            HistoryManager::saveHistory(
                "A*",
                start,
                destination,
                astarDistance,
                travelTime,
                fuelUsed
            );

            cout << YELLOW;

            cout << "\nRoute saved to history.\n";

            cout << RESET;
        }

        else if (choice == "3" || choice == "3.") {

            showHistory();
        }

        else if (choice == "4" || choice == "4.") {

            ASCIIVisualizer::displayASCIIMap(
                cityMap
            );
        }

        else if (choice == "5" || choice == "5.") {

        string newCity;
        int x, y;

        cout << "\nEnter new city name: ";
        cin >> newCity;

        cout << "Enter X coordinate: ";
        cin >> x;

        cout << "Enter Y coordinate: ";
        cin >> y;

        cityMap.addCity(newCity);

        cityMap.addCoordinates(
            newCity,
            x,
            y
        );

        cout << GREEN;
        cout << "\nCity added successfully.\n";
        cout << RESET;
        }

        else if (choice == "6" || choice == "6.") {
            string city1, city2;
            int distance;

            cout << "\nEnter first city: ";
            cin >> city1;

            cout << "Enter second city: ";
            cin >> city2;

            cout << "Enter road distance: ";
            cin >> distance;

            cityMap.addRoad(
                city1,
                city2,
                distance
            );

            cout << GREEN;
            cout << "\nRoad added successfully.\n";
            cout << RESET;
        }

        else if (choice == "7" || choice == "7.") {

            cout << CYAN;
            cout << "\nThank you for using Smart GPS Navigation System.\n";
            cout << RESET;

            break;
        }

        else {

            cout << RED;
            cout << "\nInvalid choice. Please try again.\n";
            cout << RESET;
        }
    }

    return 0;
}