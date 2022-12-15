#pragma once
#include "shape.h"

class Rectangle : public Shape {
private:
    const std::string name = "RECTANGLE";
    point_t leftBot;
    point_t rightTop;
public:
    Rectangle(point_t leftBot, point_t rightTop);

    Rectangle(const Rectangle& rect) ;

    const double& getArea() override;


    const rectangle_t& getFrameRect() override;
    const std::string& getName() override;

    void move(point_t newPos) override;
    void move(double x, double y) override;
    void scale(double k) override;

    Shape* clone() override;

};