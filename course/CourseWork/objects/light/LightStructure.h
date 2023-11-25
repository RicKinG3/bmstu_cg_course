//
// Created by max on 29.10.23.
//

#ifndef COURSEWORK_LIGHTSTRUCTURE_H
#define COURSEWORK_LIGHTSTRUCTURE_H

#include "/usr/include/eigen3/Eigen/Dense"

#include "point.h"

#include <memory>
#include <vector>

class LightStructure {
public:
    LightStructure() = default;

    LightStructure(const Point &positionArg, const Point &directionArg, Eigen::Matrix4f &transMatrix_);

    ~LightStructure() = default;

    const Point getDirection();

    void setPosition(const Point &positionArg);

    void setDirection(const Point &directionArg);

    const Point getPosition();


    //todo
    void setShadowMap(std::vector<std::vector<double>> &setShadowMap);

    std::vector<std::vector<double>> &getShadowMap();

    void clearShadowMap();


    void setTransMat(Eigen::Matrix4f &mat);

    Eigen::Matrix4f &getTransMat();

private:
    Point position{};
    Point direction{0, 0, 0};
    //todo
    std::vector<std::vector<double>> shadowMap;
    Eigen::Matrix4f transMatrix;
};


#endif //COURSEWORK_LIGHTSTRUCTURE_H
