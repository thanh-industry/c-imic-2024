#include <iostream>
#include <cmath> // for fabs
using namespace std;

// Template class for Complex numbers
template <typename T>
class Complex {
private:
    T real;
    T imag;

public:
    // Constructor to initialize values
    Complex(T r = 0, T i = 0) : real(r), imag(i) {}

    // Function to input values from the keyboard
    void input() {
        cout << "  Enter the real and imaginary parts: ";
        cin >> real >> imag;
    }

    // Function to display the complex number
    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") << fabs(imag) << "i";
    }

    // Addition of two complex numbers (returns Complex<float>)
    Complex<float> operator + (const Complex<T>& other) const {
        return Complex<float>(static_cast<float>(real) + static_cast<float>(other.real),
                               static_cast<float>(imag) + static_cast<float>(other.imag));
    }

    // Subtraction of two complex numbers (returns Complex<float>)
    Complex<float> operator - (const Complex<T>& other) const {
        return Complex<float>(static_cast<float>(real) - static_cast<float>(other.real),
                               static_cast<float>(imag) - static_cast<float>(other.imag));
    }

    // Multiplication of two complex numbers (returns Complex<float>)
    Complex<float> operator * (const Complex<T>& other) const {
        return Complex<float>(static_cast<float>(real) * static_cast<float>(other.real) -
                               static_cast<float>(imag) * static_cast<float>(other.imag),
                               static_cast<float>(real) * static_cast<float>(other.imag) +
                               static_cast<float>(imag) * static_cast<float>(other.real));
    }

    // Division of two complex numbers (returns Complex<float>)
    Complex<float> operator / (const Complex<T>& other) const {
        float denominator = static_cast<float>(other.real) * static_cast<float>(other.real) +
                            static_cast<float>(other.imag) * static_cast<float>(other.imag);
        return Complex<float>((static_cast<float>(real) * static_cast<float>(other.real) +
                               static_cast<float>(imag) * static_cast<float>(other.imag)) / denominator,
                               (static_cast<float>(imag) * static_cast<float>(other.real) -
                                static_cast<float>(real) * static_cast<float>(other.imag)) / denominator);
    }
};

int main() {
    Complex<int> c1;     // First complex number with type int
    Complex<float> c2;   // Second complex number with type float

    // Input the two complex numbers
    cout << "Enter the first complex number (type integer):\n";
    c1.input();
    cout << "Enter the second complex number (type float):\n";
    c2.input();

    // Display the entered complex numbers
    cout << "\nFirst complex number: ";
    c1.display();
    cout << "\nSecond complex number: ";
    c2.display();

    // Perform and display the operations (results will be Complex<float>)
    Complex<float> sum = c1 + c2;
    Complex<float> difference = c1 - c2;
    Complex<float> product = c1 * c2;
    Complex<float> quotient = c1 / c2;

    cout << "\n\nAddition result: ";
    sum.display();

    cout << "\nSubtraction result: ";
    difference.display();

    cout << "\nMultiplication result: ";
    product.display();

    cout << "\nDivision result: ";
    quotient.display();

    return 0;
}
