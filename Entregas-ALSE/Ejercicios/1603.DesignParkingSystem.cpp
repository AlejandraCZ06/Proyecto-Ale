#include <iostream>
#include <vector>
using namespace std;

// Clase que representa el sistema de estacionamiento
class ParkingSystem {
private:
    int bigSlots;    // Espacios disponibles para coches grandes
    int mediumSlots; // Espacios disponibles para coches medianos
    int smallSlots;  // Espacios disponibles para coches pequeños

public:
    // Constructor que inicializa los espacios para cada tipo de coche
    ParkingSystem(int big, int medium, int small) {
        bigSlots = big;
        mediumSlots = medium;
        smallSlots = small;
    }
    
    // Método para agregar un coche al estacionamiento
    bool addCar(int carType) {
        if (carType == 1) { // Coche grande
            if (bigSlots > 0) {
                bigSlots--; // Decrementa el contador de espacios grandes
                return true;
            }
        } else if (carType == 2) { // Coche mediano
            if (mediumSlots > 0) {
                mediumSlots--; // Decrementa el contador de espacios medianos
                return true;
            }
        } else if (carType == 3) { // Coche pequeño
            if (smallSlots > 0) {
                smallSlots--; // Decrementa el contador de espacios pequeños
                return true;
            }
        }
        return false; // No hay espacio disponible para el tipo de coche
    }
};

int main() {
    vector<string> commands = {"ParkingSystem", "addCar", "addCar", "addCar", "addCar"};
    vector<vector<int>> inputs = {{1, 1, 0}, {1}, {2}, {3}, {1}};
    vector<string> output;

    ParkingSystem* parkingSystem = nullptr;

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "ParkingSystem") {
            parkingSystem = new ParkingSystem(inputs[i][0], inputs[i][1], inputs[i][2]);
            output.push_back("null");
        } else if (commands[i] == "addCar") {
            bool result = parkingSystem->addCar(inputs[i][0]);
            output.push_back(result ? "true" : "false");
        }
    }

    // Imprimir la salida
    cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        cout << output[i];
        if (i < output.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    // Liberar la memoria del objeto ParkingSystem
    delete parkingSystem;

    return 0;
}