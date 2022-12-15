#include "shape.h"

bool Shape::operator<(Shape& shape) {
    double eps = 1e-11;
    return getArea() + eps < shape.getArea();
}

bool Shape::operator>(Shape& shape) {
    return shape < *this;
}

bool Shape::operator==(Shape& shape) {
    return !(*this < shape || shape < *this);
}

bool Shape::operator!=(Shape& shape) {
    return !(*this == shape);
}

bool Shape::operator>=(Shape& shape) {
    return !(*this < shape);
}

bool Shape::operator<=(Shape& shape) {
    return !(shape < *this);
}




std::ostream& operator<<(std::ostream& os, Shape& sh) {
    rectangle_t rect = sh.getFrameRect();
    point_t center = rect.pos;
    double width = rect.width;
    double length = rect.length;
    return os
        << "Name: " << sh.getName() << '\n'
        << "Area: " << sh.getArea() << '\n'
        << "Left bottom: (" << center.x - length / 2 << "; " << center.y - width / 2 << ")\n"
        << "Right top: (" << center.x + length / 2 << "; " << center.y + width / 2 << ")\n";
}