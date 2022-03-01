#include "Rectangle.h"
#include <iostream>
#include <vector>
using namespace std;

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4){
    points.push_back(p1); points.push_back(p2);
    points.push_back(p3); points.push_back(p4);
}
Rectangle::Rectangle(std::vector<Point>& points) {
    this->points = points;
}
double Rectangle::getPerimeter() const {
    double len = _dist(points[0],points[1]);
    return (len  * 4);
}

double Rectangle::getArea() const {
    double len = _dist(points[0],points[1]);
    return _round(len*len, 2);
}

unique_ptr<IShape> Rectangle::clone() const {
    return unique_ptr<IShape>(new Rectangle(*this));
}