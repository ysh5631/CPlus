#ifndef ASSIGMENT_CIRCLE_H
#define ASSIGMENT_CIRCLE_H
#include "IShape.h"

class Circle final : public IShape {
public:
    Circle() = default;
    Circle(const Point& c, size_t r);
    explicit Circle(const std::vector<Point>& points);
    virtual ~Circle() noexcept {
        std::cout << "Circle is destructed!" << std::endl;
    }

    double getArea() const override;
    double getPerimeter() const override;
    virtual std::unique_ptr<IShape> clone() const;

protected:
    std::string toString() const override;

private:
    Point center = {0 , 0};
    size_t radius = 0;
};
#endif //ASSIGMENT_CIRCLE_H
