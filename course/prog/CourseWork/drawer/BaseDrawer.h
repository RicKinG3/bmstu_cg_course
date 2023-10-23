//
// Created by max on 23.10.23.
//

#ifndef COURSEWORK_BASEDRAWER_H
#define COURSEWORK_BASEDRAWER_H
#include "../objects/primitives/point.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Point &point1, const Point &point2) = 0;
    virtual void clearScene() = 0;
};

#endif //COURSEWORK_BASEDRAWER_H
