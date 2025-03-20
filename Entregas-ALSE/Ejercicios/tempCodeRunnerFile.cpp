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
    std::vector<int> resultado = solution.twoSum(nums, target);
    
    // Mostrar el resultado
    if (!resultado.empty()) {
        std::cout << "Resultado: [" << resultado[0] << ", " << resultado[1] << "]" << std::endl;
        // Explicación del resultado
        std::cout << "Explicación: Porque nums[" << resultado[0] << "] + nums[" << resultado[1] << "] == " 
                  << target << ", devolvemos [" << resultado[0] << ", " << resultado[1] << "]." << std::endl;
    } else {
        std::cout << "No se encontró una solución." << std::endl;
    }
    
    return 0;
}