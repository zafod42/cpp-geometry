#pragma once
#include "shape.h"

class Rectangle : public Shape {
private:
    point_t leftBot;
    point_t rightTop;
public:
    Rectangle(point_t, point_t);
    Rectangle(double, double, double, double);

    Rectangle(const Rectangle&);

    double getArea() override;


    rectangle_t getFrameRect() override;
    std::string getName() override;

    void move() override;
    void scale() override;


};