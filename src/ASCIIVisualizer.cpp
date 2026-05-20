#include "../include/ASCIIVisualizer.h"

#define CYAN "\033[36m"
#define RESET "\033[0m"

using namespace std;

void ASCIIVisualizer::displayASCIIMap(Graph& graph) {

    cout << CYAN;

    cout << "\n============= EAST INDIA NETWORK =============\n\n";

    cout << "                  CoochBehar\n";
    cout << "                       |\n";
    cout << "                 Jalpaiguri\n";
    cout << "                       |\n";
    cout << "                   Siliguri\n";
    cout << "                       |\n";
    cout << "                     Malda\n";
    cout << "                       |\n";
    cout << "                 Berhampore\n";
    cout << "                       |\n";
    cout << " Krishnanagar ---- Barasat\n";
    cout << "                       |\n";
    cout << " DumDum ---- Bidhannagar ---- Rajarhat\n";
    cout << "      |             |             |\n";
    cout << " Howrah ---- Kolkata ---- SaltLake ---- NewTown\n";
    cout << "      |                              |\n";
    cout << "   Airport --------------------------\n";
    cout << "\n";
    cout << " Bardhaman ---- Durgapur ---- Asansol ---- Dhanbad\n";
    cout << "       |                             |\n";
    cout << "    Bolpur                      Raniganj\n";
    cout << "\n";
    cout << " Kharagpur ---- Midnapore ---- Digha\n";
    cout << "      |\n";
    cout << "   Haldia\n";

    cout << "\n================================================\n";

    cout << RESET;
}