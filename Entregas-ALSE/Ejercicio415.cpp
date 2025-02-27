/*
   Nombre del programa: Suma de Números Representados como Cadenas
   Objetivo: Sumar dos números no negativos representados como cadenas sin usar bibliotecas para manejar enteros grandes.
   
   Metodología:
      1. Se recorren las cadenas de entrada desde el final hacia el inicio, sumando dígito por dígito.
      2. Se maneja el acarreo cuando la suma de dos dígitos es mayor o igual a 10.
      3. Se construye la cadena de resultado a partir de los dígitos sumados.
      4. Se invierte la cadena de resultado antes de devolverla, ya que se construyó en orden inverso.

   Autor: [Andy Herrera  y Alejandra Calderon]
Fecha: [26/02/2025]
*/

#include <iostream>
#include <string>
#include <algorithm> // Para usar std::reverse
using namespace std;

string addStrings(string num1, string num2) {
    string result = ""; // Cadena para almacenar el resultado
    int carry = 0; // Variable para manejar el acarreo
    int i = num1.length() - 1; // Índice para recorrer num1
    int j = num2.length() - 1; // Índice para recorrer num2

    // Recorremos ambas cadenas desde el final hacia el inicio
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry; // Inicializamos la suma con el valor del acarreo

        // Si hay dígitos restantes en num1, los sumamos
        if (i >= 0) {
            sum += num1[i] - '0'; // Convertimos el carácter a entero
            i--;
        }

        // Si hay dígitos restantes en num2, los sumamos
        if (j >= 0) {
            sum += num2[j] - '0'; // Convertimos el carácter a entero
            j--;
        }

        // Calculamos el nuevo dígito y el acarreo
        result += (sum % 10) + '0'; // Convertimos el dígito a carácter y lo añadimos al resultado
        carry = sum / 10; // Actualizamos el acarreo
    }

    // Invertimos la cadena de resultado ya que se construyó en orden inverso
    reverse(result.begin(), result.end());

    return result; // Devolvemos el resultado final
}

int main() {
    string num1, num2;

    // Solicitar al usuario que ingrese los números
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;

    // Mostrar el resultado de la suma
    cout << "La suma de " << num1 << " y " << num2 << " es: " << addStrings(num1, num2) << endl;

    return 0;
}