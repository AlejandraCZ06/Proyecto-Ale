#include <iostream>
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
    int big, medium, small;
    cout << "Ingrese el número de espacios para coches grandes, medianos y pequeños: ";
    cin >> big >> medium >> small;

    // Crear un objeto ParkingSystem con los espacios iniciales
    ParkingSystem* parkingSystem = new ParkingSystem(big, medium, small);

    int carType;
    cout << "Ingrese el tipo de coche (1: grande, 2: mediano, 3: pequeño) o 0 para salir: ";
    while (cin >> carType && carType != 0) {
        if (parkingSystem->addCar(carType)) {
            cout << "Coche estacionado exitosamente." << endl;
        } else {
            cout << "No hay espacio disponible para este tipo de coche." << endl;
        }
        cout << "Ingrese el tipo de coche (1: grande, 2: mediano, 3: pequeño) o 0 para salir: ";
    }

    // Liberar la memoria del objeto ParkingSystem
    delete parkingSystem;

    return 0;
}