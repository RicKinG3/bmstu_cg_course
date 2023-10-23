//
// Created by max on 24.10.23.
//

#include "point.h"


Point::Point(const double srcX, const double srcY, const double srcZ) {
    x = srcX;
    y = srcY;
    z = srcZ;
}

Point::Point(const Point &&srcPoint) noexcept {
    x = srcPoint.getX();
    y = srcPoint.getY();
    z = srcPoint.getZ();

    srcPoint.~Point();
}


Point &Point::operator=(Point &&srcPoint) noexcept {
    x = srcPoint.getX();
    y = srcPoint.getY();
    z = srcPoint.getZ();

    srcPoint.~Point();

    return *this;
}


double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::getZ() const {
    return z;
}


void Point::setX(double srcX) {
    x = srcX;
}

void Point::setY(double srcY) {
    y = srcY;
}

void Point::setZ(double srcZ) {
    z = srcZ;
}


bool Point::operator==(const Point &secondPoint) const noexcept {
    return (x == secondPoint.getX()) &&
           (y == secondPoint.getY()) &&
           (z == secondPoint.getZ());
}

bool Point::operator!=(const Point &secondPoint) const noexcept {
    return !(*this == secondPoint);
}

Point Point::operator+(const Point &secondPoint) {
    Point result{};

    result.x = this->x + secondPoint.getX();
    result.y = this->y + secondPoint.getY();
    result.z = this->z + secondPoint.getZ();

    return result;
}

Point Point::operator-(const Point &secondPoint) {
    Point result{};

    result.x = this->x - secondPoint.getX();
    result.y = this->y - secondPoint.getY();
    result.z = this->z - secondPoint.getZ();

    return result;
}

Point Point::operator*(const Point &secondPoint) {
    Point result{};

    result.x = this->x * secondPoint.getX();
    result.y = this->y * secondPoint.getY();
    result.z = this->z * secondPoint.getZ();

    return result;
}

Point Point::operator-() const {
    Point result{};

    result.x = -x;
    result.y = -y;
    result.z = -z;

    return result;
}