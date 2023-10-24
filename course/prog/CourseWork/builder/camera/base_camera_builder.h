#ifndef LAB_03_BASE_CAMERA_BUILDER_H
#define LAB_03_BASE_CAMERA_BUILDER_H

#include "../base_builder.h"


class BaseCameraBuilder : public BaseBuilder
{
public:
    BaseCameraBuilder() = default;
    ~BaseCameraBuilder() override = default;

    virtual void buildPosition(const Point &position) = 0;
    virtual void buildDirection(const Point &direction) = 0;

    virtual std::shared_ptr<Object> get() = 0;

protected:
    Point position, direction;
};


#endif //LAB_03_BASE_CAMERA_BUILDER_H
