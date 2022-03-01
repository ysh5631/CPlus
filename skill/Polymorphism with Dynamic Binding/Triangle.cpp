#include "Triangle.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
using namespace std;

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3){
    points.push_back(p1); points.push_back(p2); points.push_back(p3);
}
Triangle::Triangle(std::vector<Point>& points){
    this->points = points;
}
double Triangle::getPerimeter() const {
    double len1 = _dist(points[0],points[1]);
    double len2 = _dist(points[0],points[2]);
    double len3 = _dist(points[1],points[2]);
    return _round(len1 + len2 + len3, 5);
}
double Triangle::getArea() const {
    double len1 = _dist(points[0],points[1]);
    double len2 = _dist(points[0],points[2]);
    double len3 = _dist(points[1],points[2]);
    double s = (len1 + len2 + len3) / 2;
    return _round(sqrt(s*(s-len1)*(s-len2)*(s-len3)), 5);
}

unique_ptr<IShape> Triangle::clone() const {
    return unique_ptr<IShape>(new Triangle(*this));
}