#pragma once
#include "shape.h"

class CompositeShape : public Shape {
private:
    const size_t maxNum;
    size_t size;
    const std::string name = "COMPLEX";
    Shape** compositeShapeArr;
public:

    CompositeShape(size_t maxNum);
    CompositeShape(size_t maxNum, Shape* arr, size_t size);
    CompositeShape(const CompositeShape& izot);

    ~CompositeShape();

    const double& getArea() override;
    const rectangle_t& getFrameRect() override;

    void add(Shape *shape);

    void move(point_t newPos) override;
    void move(double x, double y) override;
    void scale(double k) override;

    const std::string& getName() override;

    Shape* clone() override;
};