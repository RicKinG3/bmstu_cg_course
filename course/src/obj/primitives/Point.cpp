#include "Point.h"
//todo operation in matrix format

void Point::move(double x_dif, double y_dif, double z_dif) {
    x_coord += x_dif;
    y_coord += y_dif;
    z_coord += z_dif;
}

void Point::scale(double coef, double x_center, double y_center, double z_center) {
    x_coord -= x_center;
    y_coord -= y_center;
    z_coord -= z_center;

    Eigen::Matrix4f scaleMatrix;
    scaleMatrix << coef, 0, 0, 0,
            0, coef, 0, 0,
            0, 0, coef, 0,
            0, 0, 0, 1;

    Eigen::MatrixXf coordinates_vector(1, 4);
    coordinates_vector << x_coord, y_coord, z_coord, 1;

    coordinates_vector = coordinates_vector * scaleMatrix;

    x_coord = coordinates_vector(0, 0) + x_center;
    y_coord = coordinates_vector(0, 1) + y_center;
    z_coord = coordinates_vector(0, 2) + z_center;
}

void Point::rotateX(double angle, double x_center, double y_center, double z_center) {
    x_coord -= x_center;
    y_coord -= y_center;
    z_coord -= z_center;

    Eigen::Matrix4f rotateMatrix;
    rotateMatrix << 1, 0, 0, 0,
            0, cos(angle), -sin(angle), 0,
            0, sin(angle), cos(angle), 0,
            0, 0, 0, 1;

    Eigen::MatrixXf coordinates_vector(1, 4);
    coordinates_vector << x_coord, y_coord, z_coord, 1;

    coordinates_vector = coordinates_vector * rotateMatrix;

    x_coord = coordinates_vector(0, 0) + x_center;
    y_coord = coordinates_vector(0, 1) + y_center;
    z_coord = coordinates_vector(0, 2) + z_center;
}

void Point::rotateY(double angle, double x_center, double y_center, double z_center) {
    x_coord -= x_center;
    y_coord -= y_center;
    z_coord -= z_center;

    Eigen::Matrix4f rotateMatrix;
    rotateMatrix << cos(angle), 0, sin(angle), 0,
            0, 1, 0, 0,
            -sin(angle), 0, cos(angle), 0,
            0, 0, 0, 1;

    Eigen::MatrixXf coordinates_vector(1, 4);
    coordinates_vector << x_coord, y_coord, z_coord, 1;

    coordinates_vector = coordinates_vector * rotateMatrix;
    x_coord = coordinates_vector(0, 0) + x_center;
    y_coord = coordinates_vector(0, 1) + y_center;
    z_coord = coordinates_vector(0, 2) + z_center;
}

void Point::rotateZ(double angle, double x_center, double y_center, double z_center) {
    x_coord -= x_center;
    y_coord -= y_center;
    z_coord -= z_center;

    Eigen::Matrix4f rotateMatrix;
    rotateMatrix << cos(angle), -sin(angle), 0, 0,
            sin(angle), cos(angle), 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1;

    Eigen::MatrixXf coordinates_vector(1, 4);
    coordinates_vector << x_coord, y_coord, z_coord, 1;

    coordinates_vector = coordinates_vector * rotateMatrix;
    x_coord = coordinates_vector(0, 0) + x_center;
    y_coord = coordinates_vector(0, 1) + y_center;
    z_coord = coordinates_vector(0, 2) + z_center;
}


bool Point::operator==(const Point &second_point) const noexcept {
    return (x_coord == second_point.getXCoord()) &&
           (y_coord == second_point.getYCoord()) &&
           (z_coord == second_point.getZCoord());
}

bool Point::operator!=(const Point &second_point) const noexcept {
    return !(*this == second_point);
}

Point Point::operator+(const Point &second_point) {
    Point result{};

    result.x_coord = this->x_coord + second_point.getXCoord();
    result.y_coord = this->y_coord + second_point.getYCoord();
    result.z_coord = this->z_coord + second_point.getZCoord();

    return result;
}

Point Point::operator-(const Point &second_point) {
    Point result{};

    result.x_coord = this->x_coord - second_point.getXCoord();
    result.y_coord = this->y_coord - second_point.getYCoord();
    result.z_coord = this->z_coord - second_point.getZCoord();

    return result;
}

Point Point::operator*(const Point &second_point) {
    Point result{};

    result.x_coord = this->x_coord * second_point.getXCoord();
    result.y_coord = this->y_coord * second_point.getYCoord();
    result.z_coord = this->z_coord * second_point.getZCoord();

    return result;
}

Point Point::operator-() const {
    Point result{};

    result.x_coord = -x_coord;
    result.y_coord = -y_coord;
    result.z_coord = -z_coord;

    return result;
}

std::ostream &operator<<(std::ostream &os, const Point &dot) {
    os << "Point: (" << dot.x_coord << "; " << dot.y_coord << "; "
       << dot.z_coord << ")\n";
    return os;
}

QDebug operator<<(QDebug deb, const Point &point) {
    deb << "Point: (" << point.getXCoord() << "; " << point.getYCoord() << "; "
        << point.getZCoord() << ")\n";
    return deb;
}

double Point::getXCoord() const { return x_coord; }

void Point::setXCoord(double value) { x_coord = value; }

double Point::getYCoord() const { return y_coord; }

void Point::setYCoord(double value) { y_coord = value; }

double Point::getZCoord() const { return z_coord; }

void Point::setZCoord(double value) { z_coord = value; }

