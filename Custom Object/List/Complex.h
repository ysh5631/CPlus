#ifndef ASSIGMENT_COMPLEX_H
#define ASSIGMENT_COMPLEX_H
#include <iostream>
class Complex {
public:
    Complex(double _r=0, double _i=0);
    Complex add(const Complex& c);
    bool operator == (const Complex& c) const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
private:
    double r{0}, i{0};
};
#endif //ASSIGMENT_COMPLEX_H
