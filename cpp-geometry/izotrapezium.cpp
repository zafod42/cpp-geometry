#include "izotrapezium.h"

Izotrapezium::Izotrapezium(point_t p, double lb, double lt, double h) : 
    leftBot(p), 
    lenBot(lb), 
    lenTop(lt), 
    height(h) 
{}

Izotrapezium::Izotrapezium(const Izotrapezium& izt) : 
    leftBot(izt.leftBot), 
    lenBot(izt.lenBot), 
    lenTop(izt.lenTop), 
    height(izt.height) 
{}

const double& Izotrapezium::getArea() {
    return height * (lenBot + lenTop) / 2;
}

const rectangle_t& Izotrapezium::getFrameRect() {
    rectangle_t rect;
    point_t p;

    rect.width = height;
    rect.length = std::max(lenBot, lenTop);
    rect.pos.x = leftBot.x + rect.length / 2;
    rect.pos.y = leftBot.y + rect.width / 2;

    return rect;
}

void Izotrapezium::move(point_t p) {
    point_t c;
    c.x = std::max(lenBot, lenTop);
    c.y = height / 2;
    leftBot.x += p.x - c.x;
    leftBot.y += p.y - c.y;
}

void Izotrapezium::move(double x, double y) {
    leftBot.x += x;
    leftBot.y += y;
}

void Izotrapezium::scale(double k) {
    //TODO: look to the python code, and make the same
    point_t center(std::max(lenBot, lenTop), height / 2);
    point_t newCenter(
        center.x + k * (leftBot.x - center.x),
        center.y + k * (leftBot.y - center.y)
    );
    leftBot = newCenter;
    height *= k;
    lenBot *= k;
    lenTop *= k;

}

const std::string& Izotrapezium::getName() {
    return name;
}

Shape* Izotrapezium::clone() {
    return (new Izotrapezium(*this));
}