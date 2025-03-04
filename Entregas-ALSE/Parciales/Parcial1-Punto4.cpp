/*
* Programa para calcular distancias entre puntos en un plano 2D
* Incluye funcionalidades para:
* - Calcular distancia entre dos puntos
* - Encontrar el punto más cercano a uno dado
* - Calcular la distancia total de un recorrido por todos los puntos
*/

#include <iostream>
#include <cmath>

// Definición de la estructura Point para representar puntos en 2D
struct Point {
    double x, y;
};

// Función para calcular la distancia euclidiana entre dos puntos
// Usa referencias constantes para evitar copias innecesarias y proteger los datos
double calcularDistancia(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Función para leer las coordenadas de varios puntos
// Permite ingreso manual o usa valores predeterminados
void leerPuntos(Point puntos[], int n) {
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> respuesta;

    // Verifica la respuesta considerando mayúsculas y minúsculas
    if (respuesta == 's' || respuesta == 'S') {
        // Lectura manual de puntos
        for (int i = 0; i < n; i++) {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x, y): ";
            std::cin >> puntos[i].x >> puntos[i].y;
        }
    } else {
        // Valores predeterminados para testing
        std::cout << "Usando puntos predeterminados...\n";
        puntos[0] = {0, 0};
        puntos[1] = {3, 4};
        puntos[2] = {6, 8};
        puntos[3] = {9, 12};
    }
}

// Función para encontrar el punto más cercano a un punto dado
// Retorna la distancia mínima y actualiza el índice del punto más cercano
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano) {
    double distanciaMinima = calcularDistancia(puntos[0], pUsuario);
    indiceMasCercano = 0;
    
    // Itera sobre todos los puntos para encontrar el más cercano
    for(int i = 1; i < n; i++) {
        double distanciaActual = calcularDistancia(puntos[i], pUsuario);
        if(distanciaActual < distanciaMinima) {
            distanciaMinima = distanciaActual;
            indiceMasCercano = i;
        }
    }
    return distanciaMinima;
}

// BONUS: Función para calcular la distancia total del recorrido
// Suma las distancias entre puntos consecutivos
double calcularDistanciaTotal(Point puntos[], int n) {
    double distanciaTotal = 0;
    for(int i = 0; i < n-1; i++) {
        distanciaTotal += calcularDistancia(puntos[i], puntos[i+1]);
    }
    return distanciaTotal;
}

// Función para mostrar el resultado del punto más cercano
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia) {
    std::cout << "El punto más cercano es: (" 
              << puntos[indiceMasCercano].x << ", " 
              << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto más cercano es: " << distancia << std::endl;
}

int main() {
    // Solicitar y validar el número de puntos
    int n;
    std::cout << "Ingrese el número de puntos (mínimo 2): ";
    std::cin >> n;

    // Verificación de entrada válida
    if (n < 2) {
        std::cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        return 1;
    }

    // Crear arreglo dinámico de puntos
    Point puntos[n];

    // Obtener los puntos del usuario o usar predeterminados
    leerPuntos(puntos, n);

    // Obtener el punto de referencia del usuario
    Point pUsuario;
    std::cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x, y): ";
    std::cin >> pUsuario.x >> pUsuario.y;

    // Calcular y mostrar el punto más cercano
    int indiceMasCercano;
    double distancia = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);
    mostrarResultado(puntos, indiceMasCercano, distancia);

    // Calcular y mostrar la distancia total del recorrido (BONUS)
    double distanciaTotal = calcularDistanciaTotal(puntos, n);
    std::cout << "La distancia total del recorrido es: " << distanciaTotal << std::endl;

    return 0;
}