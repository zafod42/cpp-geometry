#pragma once

struct point_t {
    double x;
    double y;
    point_t() :x(0), y(0) {};
    point_t(double x_, double y_) : x(x_), y(y_) {}
    point_t(const point_t& p) : x(p.x), y(p.y) {}
};

struct rectangle_t {
    double width;
    double length;
    point_t pos;
    rectangle_t(double w, double l, point_t p) : width(w), length(l), pos(p) {};
};