#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    string commandsInput, dataInput;
    cout << "Ingrese los comandos: ";
    getline(cin, commandsInput);
    cout << "Ingrese los datos: ";
    getline(cin, dataInput);

    // Procesar los datos de entrada
    vector<string> commands;
    vector<vector<int>> inputs;
    stringstream ssCommands(commandsInput);
    stringstream ssData(dataInput);
    string command;
    char ch;

    // Leer comandos
    while (ssCommands >> ch) {
        if (ch == '"') {
            getline(ssCommands, command, '"');
            commands.push_back(command);
        }
    }

    // Leer datos
    vector<int> temp;
    int num;
    while (ssData >> ch) {
        if (isdigit(ch)) {
            ssData.putback(ch);
            ssData >> num;
            temp.push_back(num);
        } else if (ch == ']') {
            if (!temp.empty()) {
                inputs.push_back(temp);
                temp.clear();
            }
        }
    }

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
    cout << "Respuesta: [";
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