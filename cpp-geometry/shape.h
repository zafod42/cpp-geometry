#pragma once
#include "base-types.h"
#include <string>

class Shape {
public:
    virtual const double& getArea() = 0;
    virtual const rectangle_t& getFrameRect() = 0;

    virtual void move(point_t) = 0;
    virtual void move(double, double) = 0;
    virtual void scale(double) = 0;

    virtual const std::string& getName() = 0;

    virtual Shape* clone() = 0;
};