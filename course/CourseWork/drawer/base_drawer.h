#ifndef LAB_03_DRAWER_H
#define LAB_03_DRAWER_H

#include "../objects/primitives/point.h"

class BaseDrawer {
public:
    BaseDrawer() = default;

    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Point &point1, const Point &point2) = 0;

    virtual void clearScene() = 0;

    virtual void drawPolygon(const Point &point1, const Point &point2, const Point &point3) = 0;


    //todo may be not this but i dont now where
    virtual void setHeight(size_t height_) = 0;

    virtual void setWight(size_t width_) = 0;

    virtual size_t getHeight() = 0;

    virtual size_t getWidth() = 0;
};

#endif //LAB_03_DRAWER_H
