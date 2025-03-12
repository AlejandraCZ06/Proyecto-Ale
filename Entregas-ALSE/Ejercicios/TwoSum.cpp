#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Crear un mapa hash para almacenar los números y sus índices
        std::unordered_map<int, int> numMap;
        
        // Iterar sobre el vector
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