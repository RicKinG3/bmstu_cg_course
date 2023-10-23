//
// Created by max on 24.10.23.
//

#ifndef COURSEWORK_POINT_H
#define COURSEWORK_POINT_H



#include <cmath>
#include <memory>


class Point {
public:
    Point() = default;

    Point(double srcX, double srcY, double srcZ);

    Point(const Point &srcPoint) = default;

    Point(const Point &&srcPoint) noexcept;

    ~Point() = default;

    Point &operator=(const Point &srcPoint) = default;

    Point &operator=(Point &&srcPoint) noexcept;

    double getX() const;

    double getY() const;

    double getZ() const;

    void setX(double srcX);

    void setY(double srcY);

    void setZ(double srcZ);

    bool operator==(const Point &secondPoint) const noexcept;

    bool operator!=(const Point &secondPoint) const noexcept;

    Point operator+(const Point &secondPoint);

    Point operator-(const Point &secondPoint);

    Point operator*(const Point &secondPoint);

    Point operator-() const;

private:
    double x, y, z;
};

#endif //COURSEWORK_POINT_H
