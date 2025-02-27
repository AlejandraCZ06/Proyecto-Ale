/*
Metodología de solución:
Este programa implementa un sistema completo para calcular distancias entre puntos,
permitiendo al usuario ingresar datos y obtener resultados de cálculos de distancia
euclidiana. Se basa en el manejo de estructuras Point y arrays dinámicos.

Características principales:
- Implementa entrada/salida interactiva con el usuario
- Utiliza estructura Point para coordenadas
- Calcula distancias euclidianas
- Maneja memoria dinámica para arrays de puntos
- Incluye validación de datos de entrada

Autor: [Tu Nombre]
Fecha: [Fecha Actual]
*/

#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// Definición de la estructura Point para manejar coordenadas
struct Point {
    double x, y;
};

// Función para calcular la distancia más cercana
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, 
                                  int &indiceMasCercano) {
    double distanciaMinima = numeric_limits<double>::max();
    indiceMasCercano = 0;
    
    for(int i = 0; i < n; i++) {
        // Cálculo de la distancia euclidiana
        double distanciaActual = sqrt(
            pow(puntos[i].x - pUsuario.x, 2) + 
            pow(puntos[i].y - pUsuario.y, 2)
        );
        
        // Actualización si se encuentra una distancia menor
        if(distanciaActual < distanciaMinima) {
            distanciaMinima = distanciaActual;
            indiceMasCercano = i;
        }
    }
    
    return distanciaMinima;
}

// Función para leer un punto desde la entrada estándar
Point leerPunto() {
    Point p;
    cout << "Ingrese coordenada x: ";
    cin >> p.x;
    cout << "Ingrese coordenada y: ";
    cin >> p.y;
    return p;
}

int main() {
    int n;
    
    // Solicitar cantidad de puntos
    cout << "Ingrese la cantidad de puntos a procesar: ";
    cin >> n;
    
    // Validación de entrada
    while(n <= 0) {
        cout << "Por favor ingrese un número positivo de puntos: ";
        cin >> n;
    }
    
    // Crear array dinámico de puntos
    Point* puntos = new Point[n];
    
    // Leer puntos
    cout << "\nIngrese los puntos del conjunto:\n";
    for(int i = 0; i < n; i++) {
        cout << "\nPunto " << i + 1 << ":\n";
        puntos[i] = leerPunto();
    }
    
    // Leer punto del usuario para comparar
    cout << "\nIngrese el punto de referencia:\n";
    Point pUsuario = leerPunto();
    
    // Calcular y mostrar resultados
    int indiceMasCercano;
    double distanciaMinima = calcularDistanciaMasCercana(puntos, n, pUsuario, 
                                                        indiceMasCercano);
    
    // Mostrar resultados
    cout << "\nResultados:\n";
    cout << "Distancia más cercana: " << distanciaMinima << endl;
    cout << "Índice del punto más cercano: " << indiceMasCercano << endl;
    cout << "Coordenadas del punto más cercano: (" 
         << puntos[indiceMasCercano].x << ", " 
         << puntos[indiceMasCercano].y << ")" << endl;
    
    // Liberar memoria
    delete[] puntos;
    
    return 0;
}