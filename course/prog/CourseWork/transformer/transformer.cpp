//
// Created by User on 02.06.2023.
//

#include "transformer.h"

#include "matrix.h"

static double toRadians(const double &angle) {
    return angle * (M_PI / 180);
}

void Transformer::transform(Point &point, Point &center) {
    scale(point, scaleParams);
    rotate(point, rotateParams);

    move(center, shiftParams);
}

void Transformer::move(Point &point, const Point &moveArg) {
    point = point + moveArg;
}

void Transformer::scale(Point &point, const Point &scaleArg) {
    point = point * scaleArg;

}

void Transformer::rotate(Point &point, const Point &rotateArg) {
    rotateX(point, rotateArg.getX());
    rotateY(point, rotateArg.getY());
    rotateZ(point, rotateArg.getZ());

}

void Transformer::rotateX(Point &point, double ox) {
    ox = toRadians(ox);

    Matrix mtr = {{1, 0,       0,        0},

                  {0, cos(ox), -sin(ox), 0},

                  {0, sin(ox), cos(ox),  0},

                  {0, 0,       0,        1}};

    Matrix cur_location = {{point.getX(), point.getY(), point.getZ(), 1}};

    Matrix new_location = cur_location * mtr;

    double x = new_location[0][0];

    double y = new_location[0][1];

    double z = new_location[0][2];

    point.setX(x);
    point.setY(y);
    point.setZ(z);
}

void Transformer::rotateY(Point &point, double oy) {
    oy = toRadians(oy);

    Matrix mtr = {{cos(oy),  0, sin(oy), 0},

                  {0,        1, 0,       0},

                  {-sin(oy), 0, cos(oy), 0},

                  {0,        0, 0,       1}};

    Matrix cur_location = {{point.getX(), point.getY(), point.getZ(), 1}};

    Matrix new_location = cur_location * mtr;

    double x = new_location[0][0];

    double y = new_location[0][1];

    double z = new_location[0][2];

    point.setX(x);
    point.setY(y);
    point.setZ(z);
}

void Transformer::rotateZ(Point &point, double oz) {
    oz = toRadians(oz);

    Matrix mtr = {{cos(oz), -sin(oz), 0, 0},

                  {sin(oz), cos(oz),  0, 0},

                  {0,       0,        1, 0},

                  {0,       0,        0, 1}};

    Matrix cur_location = {{point.getX(), point.getY(), point.getZ(), 1}};

    Matrix new_location = cur_location * mtr;

    double x = new_location[0][0];

    double y = new_location[0][1];

    double z = new_location[0][2];

    point.setX(x);
    point.setY(y);
    point.setZ(z);
}
