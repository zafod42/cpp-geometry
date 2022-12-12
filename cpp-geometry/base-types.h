#pragma once

struct point_t {
    double x;
    double y;
    point_t(double x_, double y_) : x(x_), y(y_) {}
};

struct rectangle_t {
    double width;
    double length;
    double pos;
    rectangle_t(double w, double l, double p) : width(w), length(l), pos(p) {}
};