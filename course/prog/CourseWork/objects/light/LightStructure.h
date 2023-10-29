//
// Created by max on 29.10.23.
//

#ifndef COURSEWORK_LIGHTSTRUCTURE_H
#define COURSEWORK_LIGHTSTRUCTURE_H

#include "point.h"

#include <memory>
#include <vector>

class LightStructure {
public:
    LightStructure() = default;

    LightStructure(const Point &positionArg, const Point &directionArg);

    ~LightStructure() = default;

    const Point getDirection();

    void setPosition(const Point &positionArg);

    void setDirection(const Point &directionArg);

    const Point getPosition();

private:
    Point position{};
    Point direction{0, 0, 0};
};



#endif //COURSEWORK_LIGHTSTRUCTURE_H
