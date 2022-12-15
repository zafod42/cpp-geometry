#include "rectangle.h"

Rectangle::Rectangle(point_t lb, point_t rt) : leftBot(lb), rightTop(rt) {}

Rectangle::Rectangle(const Rectangle& rect) : leftBot(rect.leftBot), rightTop(rect.rightTop) {}

const double& Rectangle::getArea() {
    double length = rightTop.x - leftBot.x;
    double width = rightTop.y - leftBot.y;
    return length * width;
}

const rectangle_t& Rectangle::getFrameRect() {
    double length = rightTop.x - leftBot.x;
    double width = rightTop.y - leftBot.y;

    point_t center(leftBot.x + length / 2, leftBot.y + width / 2);

    return rectangle_t(width, length, center);
}

void Rectangle::move(point_t p) {
    double length = rightTop.x - leftBot.x;
    double width = rightTop.y - leftBot.y;
    double ax = 0, ay = 0;
    ax = p.x - length / 2;
    ay = p.y - width / 2;
    leftBot.x += ax;
    leftBot.y += ay;
    rightTop.x += ax;
    rightTop.y += ay;
}

void Rectangle::move(double ax, double ay) {
    leftBot.x += ax;
    leftBot.y += ay;
    rightTop.x += ax;
    rightTop.y += ay;
}

const std::string& Rectangle::getName() {
    return name;
}

void Rectangle::scale(double k) {
    leftBot.x *= k;
    leftBot.y *= k;
    rightTop.x *= k;
    rightTop.y *= k;
}

Shape* Rectangle::clone() {
    return (new Rectangle(*this));
}