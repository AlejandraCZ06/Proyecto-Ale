/*
   Nombre del programa: Sistema de Boletas de Calificaciones de Estudiantes
   Objetivo: Demostrar el uso de memoria estática y dinámica en C++ para manejar calificaciones.
   
   Metodología:
      1. Se define un arreglo estático de tamaño 10 para almacenar las calificaciones iniciales.
      2. Se solicita al usuario ingresar las calificaciones de 10 estudiantes.
      3. Se calcula el promedio, la calificación más alta y la más baja usando el arreglo estático.
      4. Se asigna dinámicamente memoria para un arreglo de 30 elementos para manejar un mayor número de estudiantes.
      5. Se solicitan las calificaciones para 30 estudiantes y se realizan los mismos cálculos (promedio, mayor, menor).
      6. Se libera la memoria dinámica asignada mediante "delete[]".

Autor: [Andy Herrera  y Alejandra Calderon]
Fecha: [26/02/2025]
  
*/


#include <iostream>
#include <limits>
using namespace std;

// Función para solicitar y validar una calificación
float solicitarCalificacion(int estudiante) {
    float calificacion;
    while (true) {
        cout << "Calificación del estudiante " << estudiante << " (entre 1.0 y 5.0): ";
        cin >> calificacion;

        // Verificar si la entrada es válida y está en el rango correcto
        if (cin.fail() || calificacion < 1.0 || calificacion > 5.0) {
            cout << "Calificación inválida. Debe estar entre 1.0 y 5.0." << endl;
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada no válida
        } else {
            return calificacion; // Entrada válida, salir del bucle
        }
    }
}

int main() {
    // Declaración de variables para el arreglo estático para 10 estudiantes
    const int STATIC_SIZE = 10;
    float staticGrades[STATIC_SIZE];

    // Solicitar al usuario ingresar las calificaciones de 10 estudiantes (memoria estática)
    cout << "Ingrese las calificaciones de 10 estudiantes (arreglo estático):" << endl;
    for (int i = 0; i < STATIC_SIZE; i++) {
        staticGrades[i] = solicitarCalificacion(i + 1);
    }

    // Variables para cálculos: suma, promedio, calificación más alta y más baja
    float sum = 0, average = 0;
    float highest = staticGrades[0];
    float lowest = staticGrades[0];

    // Procesar el arreglo estático para calcular suma, promedio, mayor y menor calificación
    for (int i = 0; i < STATIC_SIZE; i++) {
        sum += staticGrades[i];
        if (staticGrades[i] > highest) {
            highest = staticGrades[i];
        }
        if (staticGrades[i] < lowest) {
            lowest = staticGrades[i];
        }
    }
    average = sum / STATIC_SIZE;

    // Mostrar los resultados para el arreglo estático
    cout << "\nResultados usando memoria estática:" << endl;
    cout << "Promedio: " << average << endl;
    cout << "Calificación más alta: " << highest << endl;
    cout << "Calificación más baja: " << lowest << endl;

    // --------------------------------------------------
    // Asignar memoria dinámica para 30 estudiantes (aumento del tamaño de la clase)
    const int DYNAMIC_SIZE = 30;
    float* dynamicGrades = new float[DYNAMIC_SIZE]; // Reserva de memoria dinámica

    // Solicitar al usuario ingresar las calificaciones de 30 estudiantes (memoria dinámica)
    cout << "\nIngrese las calificaciones de 30 estudiantes (arreglo dinámico):" << endl;
    for (int i = 0; i < DYNAMIC_SIZE; i++) {
        dynamicGrades[i] = solicitarCalificacion(i + 1);
    }

    // Reinicializar variables para el nuevo conjunto de datos
    sum = 0;
    highest = dynamicGrades[0];
    lowest = dynamicGrades[0];

    // Procesar el arreglo dinámico para calcular suma, promedio, mayor y menor calificación
    for (int i = 0; i < DYNAMIC_SIZE; i++) {
        sum += dynamicGrades[i];
        if (dynamicGrades[i] > highest) {
            highest = dynamicGrades[i];
        }
        if (dynamicGrades[i] < lowest) {
            lowest = dynamicGrades[i];
        }
    }
    average = sum / DYNAMIC_SIZE;

    // Mostrar los resultados para el arreglo dinámico
    cout << "\nResultados usando memoria dinámica:" << endl;
    cout << "Promedio: " << average << endl;
    cout << "Calificación más alta: " << highest << endl;
    cout << "Calificación más baja: " << lowest << endl;

    // Liberar la memoria dinámica asignada para evitar fugas de memoria
    delete[] dynamicGrades;

    return 0;
}