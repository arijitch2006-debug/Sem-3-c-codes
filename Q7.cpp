#include <iostream>
#include <cmath>
using namespace std;

// 1. Overloaded function to find the area of a Circle (1 parameter: radius)
double AREA(double radius) {
    return 3.14159 * radius * radius;
}

// 2. Overloaded function to find the area of a Rectangle (2 parameters: length, breadth)
double AREA(double length, double breadth) {
    return length * breadth;
}

// 3. Overloaded function to find the area of a Triangle (3 parameters: sides a, b, c using Heron's Formula)
double AREA(double a, double b, double c) {
    double s = (a + b + c) / 2.0; // Semi-perimeter
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Alternative overloaded function for Triangle (using float base and height to differentiate from Rectangle)
float AREA(float base, float height) {
    return 0.5f * base * height;
}

int main() {
    double r, l, b, side1, side2, side3;
    float base, height;

    // Circle
    cout << "Enter radius of the circle: ";
    cin >> r;
    cout << "Area of Circle = " << AREA(r) << "\n\n";

    // Rectangle
    cout << "Enter length and breadth of the rectangle: ";
    cin >> l >> b;
    cout << "Area of Rectangle = " << AREA(l, b) << "\n\n";

    // Triangle (Base and Height)
    cout << "Enter base and height of the triangle: ";
    cin >> base >> height;
    cout << "Area of Triangle (using base & height) = " << AREA(base, height) << "\n\n";

    // Triangle (3 sides)
    cout << "Enter three sides of the triangle: ";
    cin >> side1 >> side2 >> side3;
    cout << "Area of Triangle (using Heron's formula) = " << AREA(side1, side2, side3) << "\n";

    return 0;
}