#include <iostream>
#include "BAI_10.hpp"

using namespace std;

class Complex{
    private:
        int real;
        int img;
    public:
        Complex(int real = 0, int img = 0) {
            this->real = real;
            this->img = img;
        }

        Complex operator+(Complex &b) {
            Complex c;
            c.real = real + b.real;
            c.img = img + b.img;
            return c;
        }

        Complex operator-(Complex &b) {
            Complex c;
            c.real = real - b.real;
            c.img = img - b.img;
            return c;
        }

        Complex operator*(Complex &b) {
            Complex c;
            c.real = real * b.real - img * b.img;
            c.img = real * b.img + img * b.real;
            return c;
        }

        Complex operator/(Complex &b) {
            Complex c;
            c.real = (real * b.real + img * b.img) / (b.real * b.real + b.img * b.img);
            c.img = (img * b.real - real * b.img) / (b.real * b.real + b.img * b.img);
            return c;
        }

        bool operator==(Complex &b) {
            return (real == b.real && img == b.img);
        }

        void print() {
            cout << real << " + " << img << "i" << endl;
        }
};

class Complex_float : public Complex{
    private:
        float real;
        float img;
    public:
        Complex_float(float real = 0, float img = 0) {
            this->real = real;
            this->img = img;
        }

        void print() {
            cout << real << " + " << img << "i" << endl;
        }
};

void complexClass(void) {
    Complex c0, c1(1, 2), c2(3, 4);
    Complex c3 = c1 + c2;
    Complex c4 = c1 + c0;
    Complex_float c5(1.1, 2.2);
    if (c1 == c4) {
        cout << "c1 == c4" << endl;
    }

    if (c1 == c2) {
        cout << "c1 == c2" << endl;
    }
    else {
        cout << "c1 != c2" << endl;
    }

    c3.print();
    c5.print();
}