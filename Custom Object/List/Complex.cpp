#include "Complex.h"
using namespace std;

Complex::Complex(double _r, double _i){
    r = _r; i=_i;
}
Complex Complex::add(const Complex& c) {
    return {r+c.r, i+c.i};
}

ostream& operator<<(std::ostream& os, const Complex& c){
    os << c.r << " + " << c.i << "i";
    return os;
}

bool Complex::operator == (const Complex& c) const{
    return i == c.i && r == c.r;
}