#include "rectangle.h"

Rectangle::Rectangle(point_t leftBot, point_t rightTop, std::string name) {
    this->leftBot = leftBot;
    this->rightTop = rightTop;
    this->name = name;
}

Rectangle::Rectangle(const Rectangle& rect) {
    leftBot = rect.leftBot;
    rightTop = rect.rightTop;
    name = rect.name;
}

const double& Rectangle::getArea() {
    double length = abs(leftBot.x - rightTop.x);
    double width = abs(leftBot.y - rightTop.y);
    return length * width;
}

const rectangle_t& Rectangle::getFrameRect() {
    double length = abs(leftBot.x - rightTop.x);
    double width = abs(leftBot.y - rightTop.y);
    rectangle_t rect;
    rect.width = width;
    rect.length = length;
    rect.pos.x = leftBot.x + length / 2;
    rect.pos.y = leftBot.y + width / 2;
    return rect;
}

void Rectangle::move(point_t p) {
    double length = abs(leftBot.x - rightTop.x);
    double width = abs(leftBot.y - rightTop.y);
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