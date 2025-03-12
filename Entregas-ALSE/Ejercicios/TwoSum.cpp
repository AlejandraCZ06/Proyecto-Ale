#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            numMap[nums[i]] = i;
        }
        
        return {};
    }
};

int main() {
    Solution solution;
    int n, target;
    
    std::cout << "Ingrese el número de elementos: ";
    std::cin >> n;
    
    std::vector<int> nums(n);
    std::cout << "Ingrese los elementos del arreglo: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    
    std::cout << "Ingrese el objetivo (target): ";
    std::cin >> target;
    
    std::vector<int> result = solution.twoSum(nums, target);
    
    if (!result.empty()) {
        std::cout << "Output: [" << result[0] << ", " << result[1] << "]" << std::endl;
    } else {
        std::cout << "No se encontró una solución." << std::endl;
    }
    
    return 0;
}