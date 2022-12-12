#include <iostream>
#include "rectangle.h"

int main() {
    point_t lb, rt;
    lb.x = 1;
    lb.y = 1;
    rt.x = 6;
    rt.y = 5;
    Rectangle rect(lb, rt, "RECTANGLE");
    Shape* rectptr = nullptr;
    rectptr = rect.clone();
    double area = rectptr->getArea();
    std::cout << area << '\n';
    delete rectptr;
    std::cout << rect.getName() << '\n';
    rectangle_t frame = rect.getFrameRect();
    std::cout << (frame.length * frame.width) << ' ' << rect.getArea() << '\n';
    std::cout << "Center: " << '(' << frame.pos.x << "; " << frame.pos.y << ')' << '\n';
    
    return 0;
}