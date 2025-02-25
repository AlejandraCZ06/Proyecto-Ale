/*
Metodología de solución:
Este programa implementa la verificación de paridad y positividad de un número usando
operadores lógicos. La solución utiliza los tres operadores lógicos principales (&&, ||, !)
para realizar las comprobaciones de manera eficiente.

Características principales:
- Usa operadores lógicos AND (&&), OR (||) y NOT (!)
- Implementa entrada por consola para un número
- Verifica dos condiciones: paridad y positividad
- Proporciona retroalimentación específica sobre las condiciones no cumplidas
- Utiliza estructuras de control if-else para la lógica de decisión

Autor: [Andy Herrera y Alejandra Calderon]
Fecha: [25/02/2025]
*/

#include <iostream>
using namespace std;

int main() {
    // Declaración de variables
    // Se usa una variable simple para almacenar el número a evaluar
    int numero;
    
    // Proceso de entrada de datos
    // Se solicita un único número al usuario
    cout << "Ingrese un numero: ";
    cin >> numero;
    
    // Verificación de condiciones usando operadores lógicos
    // Se usa && para verificar que se cumplan ambas condiciones (par y positivo)
    if ((numero % 2 == 0) && (numero > 0)) {
        cout << "El numero es par y positivo." << endl;
    } 
    // Se usa || y ! para verificar si alguna condición no se cumple
    else if (!(numero % 2 == 0) || !(numero > 0)) {
        cout << "El numero NO es par y positivo porque:" << endl;
        
        // Verificación individual de cada condición
        // Uso del operador ! para negar la condición de paridad
        if (!(numero % 2 == 0)) {
            cout << "- Es impar" << endl;
        }
        // Uso del operador ! para negar la condición de positividad
        if (!(numero > 0)) {
            cout << "- No es positivo" << endl;
        }
    }
    
    return 0;
}

