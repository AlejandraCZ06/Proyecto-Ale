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

// Definimos un tipo de función para las operaciones, lo que nos permite almacenar funciones en un mapa
typedef function<double(double, double)> Operacion;

// Funciones para las operaciones aritméticas

// Función para sumar dos números
double sumar(double x, double y) {
    // Calcula la suma de los dos números proporcionados y devuelve el resultado
    return x + y;
}

// Función para restar el segundo número del primero
double restar(double x, double y) {
    // Calcula la diferencia restando el segundo número del primero y devuelve el resultado
    return x - y;
}

// Función para multiplicar dos números
double multiplicar(double x, double y) {
    // Calcula el producto de los dos números y devuelve el resultado
    return x * y;
}

// Función para dividir el primer número por el segundo, con verificación de división por cero
double dividir(double x, double y) {
    // Comprueba si el divisor es cero para evitar errores de ejecución
    if (y == 0) {
        // Si el divisor es cero, muestra un mensaje de error y devuelve cero para indicar un problema
        cerr << "Error: No se puede dividir por cero" << endl;
        return 0;
    }
    // Si el divisor no es cero, realiza la división y devuelve el resultado
    return x / y;
}

int main() {
    // Mapa para vincular operadores con funciones, permitiendo la ejecución dinámica de operaciones
    unordered_map<char, Operacion> operaciones;
    operaciones['+'] = sumar;      // Asocia el operador '+' con la función 'sumar'
    operaciones['-'] = restar;     // Asocia el operador '-' con la función 'restar'
    operaciones['*'] = multiplicar; // Asocia el operador '*' con la función 'multiplicar'
    operaciones['/'] = dividir;    // Asocia el operador '/' con la función 'dividir'

    double numero1, numero2;
    char operador;

    // Solicitar al usuario que ingrese los números y el operador deseado
    cout << "Ingrese la operación que desea realizar (Operaciones disponibles: +, -, *, /): ";
    cin >> numero1 >> operador >> numero2;

    // Verificar si el operador ingresado es válido y ejecutar la operación correspondiente
    if (operaciones.find(operador) != operaciones.end()) {
        // Ejecuta la operación correspondiente al operador ingresado utilizando el mapa
        double resultado = operaciones[operador](numero1, numero2);
        // Muestra el resultado de la operación al usuario
        cout << "Resultado: " << resultado << endl;
    } else {
        // Informa al usuario que el operador ingresado no es válido
        cout << "Operador no reconocido" << endl;
    }

    return 0;
}