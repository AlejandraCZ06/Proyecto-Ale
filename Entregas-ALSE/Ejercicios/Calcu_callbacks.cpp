/*
Este programa implementa una calculadora básica en C++ que permite realizar operaciones
aritméticas fundamentales: suma, resta, multiplicación y división.

La calculadora está diseñada para ser modular y extensible. Utiliza un mapa para asociar
operadores aritméticos con funciones específicas, lo que facilita la adición de nuevas
operaciones en el futuro. El usuario ingresa dos números y un operador, y el programa
ejecuta la operación correspondiente, mostrando el resultado. La implementación incluye
una verificación para evitar la división por cero, asegurando así la robustez del programa.

Autor: Alejandra Calderon
*/

#include <iostream>
#include <functional>
#include <unordered_map>
using namespace std;

// Definimos un tipo de función para las operaciones
typedef function<double(double, double)> Operacion;

// Funciones para las operaciones aritméticas

// Función para sumar dos números
double sumar(double x, double y) {
    // Devuelve la suma de x e y
    return x + y;
}

// Función para restar el segundo número del primero
double restar(double x, double y) {
    // Devuelve la resta de x menos y
    return x - y;
}

// Función para multiplicar dos números
double multiplicar(double x, double y) {
    // Devuelve el producto de x e y
    return x * y;
}

// Función para dividir el primer número por el segundo, con verificación de división por cero
double dividir(double x, double y) {
    // Verifica si el divisor es cero para evitar una división por cero
    if (y == 0) {
        // Si el divisor es cero, muestra un mensaje de error y devuelve cero
        cerr << "Error: No se puede dividir por cero" << endl;
        return 0;
    }
    // Si el divisor no es cero, devuelve el resultado de la división
    return x / y;
}

int main() {
    // Mapa para vincular operadores con funciones
    unordered_map<char, Operacion> operaciones;
    operaciones['+'] = sumar;      // Vincula '+' con la función 'sumar'
    operaciones['-'] = restar;     // Vincula '-' con la función 'restar'
    operaciones['*'] = multiplicar; // Vincula '*' con la función 'multiplicar'
    operaciones['/'] = dividir;    // Vincula '/' con la función 'dividir'

    double numero1, numero2;
    char operador;

    // Solicitar al usuario que ingrese los números y el operador
    cout << "Ingrese la operación que desea realizar (Operaciones disponibles: +, -, *, /): ";
    cin >> numero1 >> operador >> numero2;

    // Verificar y ejecutar la operación
    if (operaciones.find(operador) != operaciones.end()) {
        // Ejecuta la función correspondiente al operador ingresado
        double resultado = operaciones[operador](numero1, numero2);
        // Muestra el resultado de la operación
        cout << "Resultado: " << resultado << endl;
    } else {
        // Si el operador no es válido, muestra un mensaje de error
        cout << "Operador no reconocido" << endl;
    }

    return 0;
}