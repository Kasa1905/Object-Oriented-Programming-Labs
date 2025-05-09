#include <iostream>
#include <stdexcept>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overloaded operators
    Complex operator + (const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator - (const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator * (const Complex& other) const {
        return Complex((real * other.real) - (imag * other.imag),
                       (real * other.imag) + (imag * other.real));
    }

    Complex operator / (const Complex& other) const {
        if (other.real == 0 && other.imag == 0) {
            throw runtime_error("Division by zero");
        }
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    // Comparison operators
    bool operator == (const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator != (const Complex& other) const {
        return !(*this == other);
    }

    // Input and output stream operators
    friend istream& operator >> (istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    friend ostream& operator << (ostream& out, const Complex& c) {
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
    try {
        Complex c1, c2, sum, difference, product, quotient;

        // Input two complex numbers
        cout << "Enter first complex number:\n";
        cin >> c1;

        cout << "Enter second complex number:\n";
        cin >> c2;

        // Perform operations
        sum = c1 + c2;
        difference = c1 - c2;
        product = c1 * c2;
        quotient = c1 / c2;

        // Display results
        cout << "Sum: " << sum << endl;
        cout << "Difference: " << difference << endl;
        cout << "Product: " << product << endl;
        cout << "Quotient: " << quotient << endl;

        // Compare the two complex numbers
        if (c1 == c2) {
            cout << "The two complex numbers are equal." << endl;
        } else {
            cout << "The two complex numbers are not equal." << endl;
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}