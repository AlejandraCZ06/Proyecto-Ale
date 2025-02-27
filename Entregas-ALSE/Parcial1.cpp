/*
Metodología de solución:
Este programa implementa el cálculo de la distancia euclidiana más cercana entre un punto
dado por el usuario y un conjunto de puntos. Utiliza una estructura Point para representar
las coordenadas y aplica la fórmula de distancia euclidiana.

Características principales:
- Usa una estructura Point para coordenadas x,y
- Calcula distancias euclidianas entre puntos
- Encuentra la menor distancia y su índice
- Implementa paso por referencia para el índice
- Utiliza arreglos de puntos y cálculos con doubles

Autor: Alejandra Calderon
Fecha: 27/02/2025
*/

#include <iostream>
#include <cmath>
using namespace std;

// Definición de la estructura Point
struct Point {
    double x, y;
};

// Función principal para calcular la distancia más cercana
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, 
                                  int &indiceMasCercano) {
    // Inicialización de variables
    double distanciaMinima = INFINITY;
    indiceMasCercano = 0;
    
    // Iteración sobre todos los puntos para encontrar la distancia mínima
    for(int i = 0; i < n; i++) {
        // Cálculo de la distancia euclidiana usando la fórmula
        double distanciaActual = sqrt(
            pow(puntos[i].x - pUsuario.x, 2) + 
            pow(puntos[i].y - pUsuario.y, 2)
        );
        
        // Actualización de la distancia mínima si se encuentra una menor
        if(distanciaActual < distanciaMinima) {
            distanciaMinima = distanciaActual;
            indiceMasCercano = i;
        }
    }
    
    return distanciaMinima;
}

int main() {
    // Ejemplo de uso
    Point puntos[] = {{1,1}, {2,2}, {3,3}};
    Point usuario = {0,0};
    int indiceMasCercano;
    
    // Llamada a la función y presentación de resultados
    double distancia = calcularDistanciaMasCercana(puntos, 3, usuario, indiceMasCercano);
    
    cout << "Distancia más cercana: " << distancia << endl;
    cout << "Índice del punto más cercano: " << indiceMasCercano << endl;
    
    return 0;
}