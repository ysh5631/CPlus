#include "Circle.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
const double PI = 3.141592;

Circle::Circle(const Point& c, size_t r) : center(c), radius(r) {}

Circle::Circle(const std::vector<Point>& points){
    this->points = points;
}
double Circle::getArea() const{
    return round(PI*radius*radius);
}
double Circle::getPerimeter() const {
    return _round(2*PI*radius,3);
}

unique_ptr<IShape> Circle::clone() const{
    return unique_ptr<Circle>(new Circle(*this));
}

string Circle::toString() const{
    return "";
}