#include "IShape.h"
#include <sstream>
#include <iostream>
#include <typeinfo>
using namespace std;

IShape::IShape(const std::vector<Point> &points) : points(points){}
IShape::~IShape() noexcept {
    std::cout << "IShape is destructed!" << std::endl;
}
std::ostream& operator << (std::ostream& os, const IShape& shape) {
    os << "type: " << typeid(shape).name() << ", points: ";
    for(auto& v : shape.points)
        os << "(" << v.x << ", " << v.y << "), ";
    os << "area: " << shape.getArea() << ", perimeter: " << shape.getPerimeter();
    return os;
}
double _round( double v, int place ) {
    const int adj = std::pow(10, place);
    return std::floor( v*(adj) + 0.5 )/adj;
};
double _dist(const Point p1, const Point p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
};

string IShape::toString() const{
    return "";
}