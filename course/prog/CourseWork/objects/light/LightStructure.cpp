//
// Created by max on 29.10.23.
//

#include "LightStructure.h"

//todo
#define ILLUM_VIS_X             1000
#define ILLUM_VIS_Y             1000

LightStructure::LightStructure(const Point &positionArg, const Point &directionArg, Eigen::Matrix4f &transMatrix_) :
        position(positionArg), direction(directionArg) {
    transMatrix = transMatrix_;
    for (size_t i = 0; i < ILLUM_VIS_X; i++) { shadowMap.push_back(std::vector<double>(ILLUM_VIS_Y, 0)); }
}

const Point LightStructure::getPosition() {
    return position;
}

const Point LightStructure::getDirection() {
    return direction;
}


void LightStructure::setPosition(const Point &positionArg) {
    position = positionArg;
}

void LightStructure::setDirection(const Point &directionArg) {
    direction = directionArg;
}

Eigen::Matrix4f &LightStructure::getTransMat() { return transMatrix; }
std::vector<std::vector<double>> &LightStructure::getShadowMap() { return shadowMap; }

void LightStructure::setShadowMap(std::vector<std::vector<double>> &setShadowMap) {
    shadowMap = setShadowMap;
}
//todo
void LightStructure::clearShadowMap() {
    for (size_t i = 0; i < shadowMap.size(); i++) {
        for (size_t j = 0; j < shadowMap.at(0).size(); j++)
            shadowMap.at(i).at(j) = 0;
    }
}