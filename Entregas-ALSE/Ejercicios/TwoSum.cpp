#include <iostream>
#include <vector>
#include <unordered_map>

// Clase que contiene la solución al problema Two Sum
class Solution {
public:
    // Función que encuentra dos números que suman el objetivo
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Mapa hash para almacenar los números y sus índices
        std::unordered_map<int, int> numMap;
        
        // Iterar sobre el vector de números
        for (int i = 0; i < nums.size(); ++i) {
            // Calcular el complemento necesario para alcanzar el target
            int complement = target - nums[i];
            
            // Verificar si el complemento ya está en el mapa
            if (numMap.find(complement) != numMap.end()) {
                // Si se encuentra, devolver los índices
                return {numMap[complement], i};
            }
            
            // Si no se encuentra, agregar el número actual y su índice al mapa
            numMap[nums[i]] = i;
        }
        
        // Devolver un vector vacío si no se encuentra solución (aunque se garantiza una solución)
        return {};
    }
};

int main() {
    Solution solution;
    int n, target;
    
    // Solicitar al usuario el número de elementos
    std::cout << "Ingrese el número de elementos: ";
    std::cin >> n;
    
    // Crear un vector para almacenar los números
    std::vector<int> nums(n);
    std::cout << "Ingrese los elementos del arreglo: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    
    // Solicitar al usuario el objetivo (target)
    std::cout << "Ingrese el objetivo (target): ";
    std::cin >> target;
    
    // Llamar a la función twoSum para encontrar los índices
    std::vector<int> result = solution.twoSum(nums, target);
    
    // Mostrar el resultado
    if (!result.empty()) {
        std::cout << "Output: [" << result[0] << ", " << result[1] << "]" << std::endl;
    } else {
        std::cout << "No se encontró una solución." << std::endl;
    }
    
    return 0;
}