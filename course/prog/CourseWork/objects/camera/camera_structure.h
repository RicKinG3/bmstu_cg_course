#ifndef LAB_03_CAMERA_STRUCTURE_H
#define LAB_03_CAMERA_STRUCTURE_H

#include <memory>
#include <vector>

#include "../primitives/point.h"
#include "../primitives/edge.h"

class CameraStructure {
public:
    CameraStructure() = default;

    CameraStructure(const Point &positionArg, const Point &directionArg);

    ~CameraStructure() = default;

    const Point getPosition();

    const Point getDirection();

    void setPosition(const Point &positionArg);

    void setDirection(const Point &directionArg);

private:
    Point position{};
    Point direction{0, 0, 0};
};


#endif //LAB_03_CAMERA_STRUCTURE_H
