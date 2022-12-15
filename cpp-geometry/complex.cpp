#include "complex.h"

CompositeShape::CompositeShape(size_t mn) : maxNum(mn) {
    compositeShapeArr = new Shape*[maxNum];
    for (size_t i = 0; i < maxNum; ++i) {
        compositeShapeArr[i] = nullptr;
    }
}

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
    delete compositeShapeArr;
}

const double& CompositeShape::getArea() {
    rectangle_t rect = getFrameRect();
    return rect.length * rect.width;
}

const rectangle_t& CompositeShape::getFrameRect() {
    point_t leftBot(DBL_MAX, DBL_MAX) , rightTop(-DBL_MAX, -DBL_MAX);
    rectangle_t tmpR;
    point_t tmp;
    for (size_t i = 0; i < size; ++i) {
        tmpR = compositeShapeArr[i]->getFrameRect();
        tmp = tmpR.pos;
        if (tmp.x - tmpR.length / 2 < leftBot.x || tmp.y - tmpR.width / 2 < leftBot.y) {
            leftBot = point_t(tmp.x - tmpR.length / 2, tmp.y - tmpR.width / 2);
        }
        if (tmp.x + tmpR.length / 2 > rightTop.x || tmp.y + tmpR.width / 2 > rightTop.y) {
            rightTop = point_t(tmp.x + tmpR.length / 2, tmp.y + tmpR.width / 2);
        }
    }
    double width = (rightTop.y - leftBot.y);
    double length = (rightTop.x - leftBot.x);
    point_t center(leftBot.x + length / 2, leftBot.y + width / 2);
    
    return rectangle_t(width, length, center);
}

void CompositeShape::add(Shape* shape) {
    Shape* tmp = shape->clone();
    if (size < maxNum) {
        compositeShapeArr[size] = tmp;
        ++size;
    }
}

void CompositeShape::move(point_t newPos) {
    for (size_t i = 0; i < size; ++i) {
        compositeShapeArr[i]->move(newPos);
    }
}

void CompositeShape::move(double x, double y) {
    for (size_t i = 0; i < size; ++i) {
        compositeShapeArr[i]->move(x, y);
    }
}

void CompositeShape::scale(double k) {
    for (size_t i = 0; i < size; ++i) {
        compositeShapeArr[i]->scale(k);
    }
}

const std::string& CompositeShape::getName() {
    return name;
}

Shape* CompositeShape::clone() {
    return (new CompositeShape(*this));
}