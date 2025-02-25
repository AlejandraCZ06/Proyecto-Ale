/*
Metodología de solución:
Este programa implementa la suma de elementos en un arreglo estático usando un ciclo for
para iterar sobre los elementos. La solución es directa y utiliza variables simples para
almacenar los resultados.

Características principales:
- Usa un arreglo estático de 5 elementos
- Implementa entrada por consola para los datos
- Realiza suma secuencial de elementos
- Verifica paridad y signo del resultado
- Utiliza estructuras de control básicas (for, if-else)

Autor: [Andy Herrera  y Alejandra Calderon]
Fecha: [25/02/2025]
*/

#include <iostream>
using namespace std;

int main() {
    // Declaración de variables
    // Se usa un arreglo estático de 5 elementos y una variable para almacenar la suma
    int numeros[5];
    int suma = 0;
    
    // Proceso de entrada de datos
    // Se solicitan 5 números al usuario mediante un ciclo for
    cout << "Ingrese 5 numeros:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Numero " << i+1 << ": ";
        cin >> numeros[i];
        // Se va acumulando la suma en cada iteración
        suma += numeros[i];
    }
    
    // Presentación de resultados
    // Se muestra la suma total
    cout << "\nLa suma es: " << suma << endl;
    
    // Verificación de paridad
    // Se usa el operador módulo para determinar si es par o impar
    if(suma % 2 == 0) {
        cout << "La suma es par" << endl;
    } else {
        cout << "La suma es impar" << endl;
    }
    
    // Verificación del signo
    // Se compara con 0 para determinar si es positivo, negativo o cero
    if(suma > 0) {
        cout << "La suma es positiva" << endl;
    } else if(suma < 0) {
        cout << "La suma es negativa" << endl;
    } else {
        cout << "La suma es cero" << endl;
    }
    
    return 0;
}