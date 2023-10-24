//
// Created by User on 29.05.2023.
//

#ifndef LAB_03_POINT_H
#define LAB_03_POINT_H


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

#endif //LAB_03_POINT_H
