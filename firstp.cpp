#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstdint>

// User-defined type (class)
class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}
};

int main() {
    // Fundamental types
    bool boolean = true;  // Boolean type
    char character = 'A';  // Character type
    int integer = 42;  // Integer type
    float floatingPoint = 3.14f;  // Single-precision floating-point type
    double doublePrecision = 2.71828;  // Double-precision floating-point type
    wchar_t wideCharacter = L'B';  // Wide character type

    // Fixed-width integer types
    int8_t int8 = -128;
    uint8_t uint8 = 255;
    int16_t int16 = -32768;
    uint16_t uint16 = 65535;
    int32_t int32 = -2147483648;
    uint32_t uint32 = 4294967295;
    int64_t int64 = -9223372036854775807 - 1;
    uint64_t uint64 = 18446744073709551615;

    // Compound types
    int* pointer = &integer;  // Pointer type
    int& reference = integer;  // Reference type
    int array[5] = {1, 2, 3, 4, 5};  // C-style array
    std::string string = "Hello, World!";  // String type

    // Container types
    std::vector<int> vector = {1, 2, 3, 4, 5};  // Dynamic array
    std::array<int, 5> fixedArray = {1, 2, 3, 4, 5};  // Fixed-size array

    // User-defined type
    Person person("Alice", 30);

    // Print values to demonstrate usage
    std::cout << "Boolean: " << boolean << std::endl;
    std::cout << "Character: " << character << std::endl;
    std::cout << "Integer: " << integer << std::endl;
    std::cout << "Float: " << floatingPoint << std::endl;
    std::cout << "Double: " << doublePrecision << std::endl;
    std::cout << "Wide Character: " << wideCharacter << std::endl;

    std::cout << "int8: " << static_cast<int>(int8) << std::endl;
    std::cout << "uint8: " << static_cast<unsigned int>(uint8) << std::endl;
    std::cout << "int16: " << int16 << std::endl;
    std::cout << "uint16: " << uint16 << std::endl;
    std::cout << "int32: " << int32 << std::endl;
    std::cout << "uint32: " << uint32 << std::endl;
    std::cout << "int64: " << int64 << std::endl;
    std::cout << "uint64: " << uint64 << std::endl;

    std::cout << "Pointer: " << pointer << std::endl;
    std::cout << "Reference: " << reference << std::endl;
    std::cout << "Array: " << array[0] << std::endl;
    std::cout << "String: " << string << std::endl;

    std::cout << "Vector: " << vector[0] << std::endl;
    std::cout << "Fixed Array: " << fixedArray[0] << std::endl;

    std::cout << "Person: " << person.name << ", " << person.age << std::endl;

    return 0;
}