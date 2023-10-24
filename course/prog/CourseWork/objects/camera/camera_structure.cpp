#include "camera_structure.h"


CameraStructure::CameraStructure(const Point &positionArg, const Point &directionArg) :
        position(positionArg), direction(directionArg) {}


const Point CameraStructure::getPosition() {
    return position;
}

const Point CameraStructure::getDirection() {
    return direction;
}


void CameraStructure::setPosition(const Point &positionArg) {
    position = positionArg;
}

void CameraStructure::setDirection(const Point &directionArg) {
    direction = directionArg;
}