#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Clase MyHashSet simulando un conjunto de enteros
class MyHashSet {
private:
    vector<bool> table;

public:
    // Constructor: inicializa una tabla de tamaño suficiente
    MyHashSet() {
        table.resize(1000001, false); // rango de 0 a 1,000,000
    }

    // Agrega el elemento al conjunto
    void add(int key) {
        table[key] = true;
    }

    // Elimina el elemento del conjunto
    void remove(int key) {
        table[key] = false;
    }

    // Verifica si el elemento está presente
    bool contains(int key) {
        return table[key];
    }
};

// Función auxiliar para imprimir vector de resultados
void printResults(const vector<string>& results) {
    cout << "[";
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i];
        if (i != results.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

// Función principal
int main() {
    // Operaciones a realizar (simulando el input JSON del ejemplo)
    vector<string> operations = {"MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"};
    vector<vector<int>> values = {{}, {1}, {2}, {1}, {3}, {2}, {2}, {2}, {2}};

    // Vector para guardar las salidas
    vector<string> results;

    MyHashSet* myHashSet = nullptr;

    for (size_t i = 0; i < operations.size(); ++i) {
        string op = operations[i];

        // Cada operación se explica paso a paso
        if (op == "MyHashSet") {
            myHashSet = new MyHashSet();
            results.push_back("null");
            cout << "Inicializado MyHashSet\n";
        }
        else if (op == "add") {
            int val = values[i][0];
            myHashSet->add(val);
            results.push_back("null");
            cout << "Se agregó " << val << " al conjunto\n";
        }
        else if (op == "remove") {
            int val = values[i][0];
            myHashSet->remove(val);
            results.push_back("null");
            cout << "Se eliminó " << val << " del conjunto\n";
        }
        else if (op == "contains") {
            int val = values[i][0];
            bool exists = myHashSet->contains(val);
            results.push_back(exists ? "true" : "false");
            cout << "¿Contiene " << val << "? " << (exists ? "Sí" : "No") << "\n";
        }
    }

    cout << "\nResultado final:\n";
    printResults(results);

    // Liberar memoria
    delete myHashSet;

    return 0;
}
