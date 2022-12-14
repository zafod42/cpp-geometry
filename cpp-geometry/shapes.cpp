#include "shape.h"


std::ostream& operator<<(std::ostream& os, Shape& sh) {
    point_t center = sh.getFrameRect().pos;
    double width = sh.getFrameRect().width;
    double length = sh.getFrameRect().length;
    return os
        << "Name: " << sh.getName() << '\n'
        << "Area: " << sh.getArea() << '\n'
        << "Left bottom: (" << center.x - length / 2 << "; " << center.y - width / 2 << ")\n"
        << "Right top: (" << center.x + length / 2 << "; " << center.y + width / 2 << ")\n";
}