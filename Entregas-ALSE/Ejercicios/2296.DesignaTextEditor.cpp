#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Definición de la clase TextEditor
class TextEditor {
public:
    string left, right; // Dos cadenas para simular el texto a la izquierda y derecha del cursor

    // Constructor: inicializa las cadenas vacías
    TextEditor() {}

    // Método para agregar texto a la izquierda del cursor
    void addText(string text) {
        left += text; // Simplemente se concatena al final de la cadena 'left'
    }

    // Método para borrar hasta 'k' caracteres a la izquierda del cursor
    int deleteText(int k) {
        int cnt = min(k, (int)left.size()); // No se puede borrar más de lo que hay
        left.erase(left.end() - cnt, left.end()); // Borra los 'cnt' caracteres desde el final
        return cnt; // Devuelve cuántos caracteres se borraron efectivamente
    }

    // Método para mover el cursor 'k' posiciones a la izquierda
    string cursorLeft(int k) {
        int cnt = min(k, (int)left.size()); // No se puede mover más de lo que hay
        // Pasar los 'cnt' últimos caracteres de 'left' al principio de 'right'
        right = left.substr(left.size() - cnt, cnt) + right;
        left.erase(left.end() - cnt, left.end()); // Eliminar esos caracteres de 'left'
        // Devolver los últimos 10 caracteres a la izquierda del cursor (o menos si no hay)
        return left.substr(max(0, (int)left.size() - 10));
    }

    // Método para mover el cursor 'k' posiciones a la derecha
    string cursorRight(int k) {
        int cnt = min(k, (int)right.size()); // No se puede mover más de lo que hay
        // Pasar los 'cnt' primeros caracteres de 'right' al final de 'left'
        left += right.substr(0, cnt);
        right.erase(0, cnt); // Eliminar esos caracteres de 'right'
        // Devolver los últimos 10 caracteres a la izquierda del cursor (o menos si no hay)
        return left.substr(max(0, (int)left.size() - 10));
    }
};

int main() {
    TextEditor editor; // Crear instancia de TextEditor
    vector<string> results; // Vector para guardar los resultados de las operaciones

    // Simulación de las operaciones del ejemplo dado:

    // Operación: "TextEditor"
    results.push_back("null"); // Constructor no devuelve nada

    // Operación: "addText" con "leetcode"
    editor.addText("leetcode");
    results.push_back("null"); // addText tampoco devuelve nada

    // Operación: "deleteText" con 4
    int deleted1 = editor.deleteText(4);
    results.push_back("4"); // Se espera que se borren 4 caracteres

    // Operación: "addText" con "practice"
    editor.addText("practice");
    results.push_back("null"); // addText no devuelve nada

    // Operación: "cursorRight" con 3
    string result1 = editor.cursorRight(3);
    results.push_back(result1); // Guardamos lo que devuelve

    // Operación: "cursorLeft" con 8
    string result2 = editor.cursorLeft(8);
    results.push_back(result2);

    // Operación: "deleteText" con 10
    int deleted2 = editor.deleteText(10);
    results.push_back(to_string(deleted2)); // Guardamos cuántos caracteres se borraron

    // Operación: "cursorLeft" con 2
    string result3 = editor.cursorLeft(2);
    results.push_back(result3);

    // Operación: "cursorRight" con 6
    string result4 = editor.cursorRight(6);
    results.push_back(result4);

    // Mostrar todos los resultados en consola
    cout << "Resultados:" << endl;
    for (const string& res : results) {
        cout << res << endl; // Imprimir cada uno
    }

    return 0;
}