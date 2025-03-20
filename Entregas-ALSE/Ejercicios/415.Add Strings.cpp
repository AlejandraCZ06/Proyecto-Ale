#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        std::string result;
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int digit1 = i >= 0 ? num1[i] - '0' : 0;
            int digit2 = j >= 0 ? num2[j] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
            i--;
            j--;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution;
    std::string num1, num2;

    // Solicitar al usuario que ingrese los números
    std::cout << "Ingrese el primer número: ";
    std::cin >> num1;
    std::cout << "Ingrese el segundo número: ";
    std::cin >> num2;

    // Llamar al método addStrings y mostrar el resultado
    std::string result = solution.addStrings(num1, num2);
    std::cout << "La suma es: " << result << std::endl;

    return 0;
}