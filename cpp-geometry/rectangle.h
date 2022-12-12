#pragma once
#include "shape.h"

class Rectangle : public Shape {
private:
    point_t leftBot;
    point_t rightTop;
    std::string name;
public:
    Rectangle(point_t, point_t, std::string);

    Rectangle(const Rectangle&);

    const double& getArea() override;


    const rectangle_t& getFrameRect() override;
    const std::string& getName() override;

    void move(point_t) override;
    void move(double, double) override;
    void scale(double) override;

    Shape* clone() override;

};