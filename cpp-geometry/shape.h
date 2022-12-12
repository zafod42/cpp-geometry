#pragma once
#include "base-types.h"
#include <string>

class Shape {
public:
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;

    virtual void move() = 0;
    virtual void scale() = 0;

    virtual std::string getName() = 0;

    virtual Shape* clone() = 0;
};