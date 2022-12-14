#include "complex.h"

CompositeShape::CompositeShape(size_t mn, Shape* arr, size_t s) : maxNum(mn), size(s) {
    compositeShapeArr = new Shape*[maxNum];
    for (size_t i = 0; i < size; ++i) {
        compositeShapeArr[i] = arr[i].clone();
    }
}

CompositeShape::CompositeShape(const CompositeShape& compositeShape) : maxNum(compositeShape.maxNum), size(compositeShape.size){
    compositeShapeArr = new Shape * [maxNum];
    for (size_t i = 0; i < size; ++i) {
        compositeShapeArr[i] = compositeShape.compositeShapeArr[i]->clone();
    }
}

CompositeShape::~CompositeShape() {
    for (size_t i = 0; i < size; ++i) {
        delete compositeShapeArr[i];
    }
    delete[] compositeShapeArr;
}

//const double& CompositeShape::getArea() {
//
//}

const rectangle_t& CompositeShape::getFrameRect() {
    point_t leftBot(DBL_MAX, DBL_MAX) , rightTop(-DBL_MAX, -DBL_MAX);
    point_t tmp;
    for (size_t i = 0; i < size; ++i) {
        tmp = compositeShapeArr[i]->getFrameRect().pos;
        if (tmp.x < leftBot.x && tmp.y < leftBot.y) {
            leftBot = tmp;
        }
        if (tmp.x > rightTop.x && tmp.y > rightTop.y) {
            rightTop = tmp;
        }
    }
    double width = (rightTop.y - leftBot.y);
    double length = (rightTop.x - leftBot.x);
    point_t center(length / 2, width / 2);
    rectangle_t rect(width, length, center);
    return rect;
}

void CompositeShape::add(Shape& shape) {

}

void CompositeShape::move(point_t newPos) {

}

void CompositeShape::move(double x, double y) {

}

void CompositeShape::scale(double k) {

}

const std::string& CompositeShape::getName() {
    return name;
}

//Shape* CompositeShape::clone() {
//
//}