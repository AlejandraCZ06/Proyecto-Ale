/*
Metodología de solución:
Este programa implementa el algoritmo de Euclides para calcular el Máximo Común Divisor (MCD)
de dos números. El algoritmo se basa en la división sucesiva hasta encontrar un residuo cero.
Se utiliza un enfoque iterativo mediante un ciclo while.

Características principales:
- Implementa el algoritmo de Euclides
- Maneja entrada de dos números enteros positivos
- Utiliza división sucesiva para encontrar el MCD
- Incluye validación de entrada para números positivos
- Proporciona resultado claro y formateado

Autor: [Andy Herrera y Alejandra Calderon]
Fecha: [25/02/2025]
*/

#include <iostream>
using namespace std;

int main() {
    // Declaración de variables para los números y variables temporales
    int num1, num2, a, b, temp;
    
    // Proceso de entrada de datos con validación
    do {
        cout << "Ingrese el primer numero (positivo): ";
        cin >> num1;
    } while (num1 <= 0);
    
    do {
        cout << "Ingrese el segundo numero (positivo): ";
        cin >> num2;
    } while (num2 <= 0);
    
    // Copiamos los valores originales para no modificarlos
    a = num1;
    b = num2;
    
    // Implementación del algoritmo de Euclides
    // Se divide sucesivamente hasta que el residuo sea 0
    while (b != 0) {
        temp = b;
        b = a % b;  // Calculamos el residuo
        a = temp;   // El divisor anterior se convierte en el nuevo dividendo
    }
    
    // El MCD es el último divisor no nulo
    cout << "\nEl Maximo Comun Divisor de " << num1 << " y " << num2;
    cout << " es: " << a << endl;
    
    // Mostrar la comprobación
    cout << "\nComprobacion:" << endl;
    cout << num1 << " es divisible por " << a << ": " << num1 << " / " << a << " = " << num1/a << endl;
    cout << num2 << " es divisible por " << a << ": " << num2 << " / " << a << " = " << num2/a << endl;
    
    return 0;
}