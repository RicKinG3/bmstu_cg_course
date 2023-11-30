//
// Created by max on 30.11.23.
//

#ifndef SRC_POINT_H
#define SRC_POINT_H

#include "QDebug"
#include "/usr/include/eigen3/Eigen/Dense"

class Point {
public:
    Point() {};

    Point(double x_coord_, double y_coord_, double z_coord_)
            : x_coord{x_coord_}, y_coord{y_coord_}, z_coord{z_coord_} {
    }

    void scale(double coef, double x_center, double y_center, double z_center);

    void move(double x_dif, double y_dif, double z_dif);

    void rotateX(double angle, double x_center, double y_center, double z_center);

    void rotateY(double angle, double x_center, double y_center, double z_center);

    void rotateZ(double angle, double x_center, double y_center, double z_center);

    bool operator==(const Point &second_point) const noexcept;

    Point operator*(const Point &second_point);

    Point operator-(const Point &second_point);

    Point operator+(const Point &second_point);

    bool operator!=(const Point &second_point) const noexcept;

    Point operator-() const;


    friend std::ostream &operator<<(std::ostream &os, const Point &dot);

    friend QDebug operator<<(QDebug deb, const Point &point);

    double getXCoord() const;

    void setXCoord(double value);

    double getYCoord() const;

    void setYCoord(double value);

    double getZCoord() const;

    void setZCoord(double value);

private:
    double x_coord, y_coord, z_coord;

};


#endif //SRC_POINT_H
