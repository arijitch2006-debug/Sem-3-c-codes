#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Parameterized & default constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // -------------------------------------------------------------
    // (a) Unary Operator Overloading: Increment and Decrement
    // -------------------------------------------------------------

    // Prefix increment (++c)
    Complex& operator++() {
        ++real;
        ++imag;
        return *this;
    }

    // Postfix increment (c++)
    Complex operator++(int) {
        Complex temp = *this;
        ++(*this); // Call prefix increment
        return temp;
    }

    // Prefix decrement (--c)
    Complex& operator--() {
        --real;
        --imag;
        return *this;
    }

    // Postfix decrement (c--)
    Complex operator--(int) {
        Complex temp = *this;
        --(*this); // Call prefix decrement
        return temp;
    }

    // -------------------------------------------------------------
    // (b) Binary Operator Overloading: Addition (+) and Subtraction (-)
    // -------------------------------------------------------------

    // Binary addition (c1 + c2)
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Binary subtraction (c1 - c2)
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Helper: Stream insertion operator for formatted printing
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0) {
            out << " + " << c.imag << "i";
        } else {
            out << " - " << -c.imag << "i";
        }
        return out;
    }
};

int main() {
    Complex c1(3.5, 2.5);
    Complex c2(1.2, 4.3);

    cout << "c1 = " << c1 << "\n";
    cout << "c2 = " << c2 << "\n\n";

    // Binary operations
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    cout << "c1 + c2 = " << sum << "\n";
    cout << "c1 - c2 = " << diff << "\n\n";

    // Unary operations (Prefix)
    cout << "Initial c1: " << c1 << "\n";
    cout << "++c1      : " << ++c1 << "\n";
    cout << "--c1      : " << --c1 << "\n\n";

    // Unary operations (Postfix)
    cout << "c1++ (returns old value): " << c1++ << "\n";
    cout << "After c1++              : " << c1 << "\n";
    cout << "c1-- (returns old value): " << c1-- << "\n";
    cout << "After c1--              : " << c1 << "\n";

    return 0;
}