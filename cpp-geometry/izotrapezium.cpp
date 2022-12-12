#include "izotrapezium.h"

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

void Izotrapezium::move(point_t) {

}

void Izotrapezium::move(double, double) {

}

void Izotrapezium::scale(double) {

}

const std::string& Izotrapezium::getName() {

}

Shape* Izotrapezium::clone() {

}