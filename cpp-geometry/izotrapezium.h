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
    Izotrapezium(point_t leftBot, double lenBot, double lenTop, double height);
    Izotrapezium(const Izotrapezium& izot);
    const double& getArea() override;
    const rectangle_t getFrameRect() override;

    void move(point_t newPos) override;
    void move(double x, double y) override;
    void scale(double k) override;

    const std::string& getName() override;

    Shape* clone() override;
};