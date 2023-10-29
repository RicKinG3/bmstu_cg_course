//
// Created by max on 29.10.23.
//

#include "LightStructure.h"

LightStructure::LightStructure(const Point &positionArg, const Point &directionArg) :
        position(positionArg), direction(directionArg) {}

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
