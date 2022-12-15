#pragma once
#include "base-types.h"
#include <iostream>

class Shape {
public:
    virtual const double& getArea() = 0;
    virtual const rectangle_t& getFrameRect() = 0;

    virtual void move(point_t) = 0;
    virtual void move(double, double) = 0;
    virtual void scale(double) = 0;

    virtual const std::string& getName() = 0;

    virtual Shape* clone() = 0;

    virtual ~Shape() = 0 {}

    bool operator<(Shape&);
    bool operator>(Shape&);
    bool operator==(Shape&);
    bool operator!=(Shape&);
    bool operator>=(Shape&);
    bool operator<=(Shape&);

};

std::ostream& operator<<(std::ostream& os, Shape& sh);

Shape** sortByArea(Shape** arr, size_t size);