#ifndef ASSIGMENT_RECTANGLE_H
#define ASSIGMENT_RECTANGLE_H
#include "IShape.h"
#include <memory>
using namespace std;

class Rectangle final : public IShape {
public:
    Rectangle() = default;
    Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    Rectangle(std::vector<Point>& points);
    virtual ~Rectangle() noexcept {
        std::cout << "Rectangle is destructed!" << std::endl;
    }

    double getPerimeter() const override;
    double getArea() const override;
    unique_ptr<IShape> clone() const  override ;

};
#endif //ASSIGMENT_RECTANGLE_H
