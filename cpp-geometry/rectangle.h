#pragma once
#include "shape.h"

class Rectangle : public Shape {
private:
    const std::string name = "RECTANGLE";
    point_t leftBot;
    point_t rightTop;
public:
    Rectangle(point_t, point_t);

    Rectangle(const Rectangle&);

    const double& getArea() override;


    const rectangle_t getFrameRect() override;
    const std::string& getName() override;

    void move(point_t) override;
    void move(double, double) override;
    void scale(double) override;

    Shape* clone() override;

};