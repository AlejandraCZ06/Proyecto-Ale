#include <iostream>
#include <cmath>

class Point2d {
private:
    double x;
    double y;

public:
    // Constructores
    Point2d() : x(0), y(0) {}
    Point2d(double x, double y) : x(x), y(y) {}

    // Getters
    double getX() const { return x; }
    double getY() const { return y; }

    // Setters
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    // Sobrecarga de operadores aritméticos
    Point2d operator+(const Point2d& other) const {
        return Point2d(x + other.x, y + other.y);
    }

    Point2d operator-(const Point2d& other) const {
        return Point2d(x - other.x, y - other.y);
    }

    Point2d operator*(double scalar) const {
        return Point2d(x * scalar, y * scalar);
    }

    Point2d operator/(double scalar) const {
        if (scalar != 0) {
            return Point2d(x / scalar, y / scalar);
        } else {
            throw std::invalid_argument("Division by zero");
        }
    }

    // Métodos adicionales
    double distanceTo(const Point2d& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    double distanceToOrigin() const {
        return std::sqrt(x * x + y * y);
    }

    Point2d midpoint(const Point2d& other) const {
        return Point2d((x + other.x) / 2, (y + other.y) / 2);
    }

    Point2d unitVector() const {
        double magnitude = distanceToOrigin();
        if (magnitude != 0) {
            return Point2d(x / magnitude, y / magnitude);
        } else {
            throw std::invalid_argument("Zero vector has no unit vector");
        }
    }
};

int main() {
    double x1, y1, x2, y2;

    std::cout << "Ingrese las coordenadas del primer punto (x y) separe las coordenadas por un espacio: ";
    std::cin >> x1 >> y1;
    Point2d p1(x1, y1);

    std::cout << "Ingrese las coordenadas del segundo punto (x y)separe las coordenadas por un espacio: ";
    std::cin >> x2 >> y2;
    Point2d p2(x2, y2);

    std::cout << "Distancia de p1 a p2: " << p1.distanceTo(p2) << std::endl;
    std::cout << "Distancia de p1 al origen: " << p1.distanceToOrigin() << std::endl;

    Point2d midpoint = p1.midpoint(p2);
    std::cout << "Punto medio: (" << midpoint.getX() << ", " << midpoint.getY() << ")" << std::endl;

    Point2d unit = p1.unitVector();
    std::cout << "Vector unitario de p1: (" << unit.getX() << ", " << unit.getY() << ")" << std::endl;

    return 0;
}