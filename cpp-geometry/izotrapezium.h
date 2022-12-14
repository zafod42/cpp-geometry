#pragma once
#include "shape.h"

class Izotrapezium : public Shape {
private:
    const std::string name = "IZOTRAPEZIUM";
    point_t leftBot;
    double lenBot;
    double lenTop;
    double height;
public:

    const double& getArea() override;
    const rectangle_t getFrameRect() override;

    void move(point_t) override;
    void move(double, double) override;
    void scale(double) override;

    const std::string& getName() override;

    Shape* clone() override;
};