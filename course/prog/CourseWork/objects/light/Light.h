//
// Created by max on 29.10.23.
//

#ifndef COURSEWORK_LIGHT_H
#define COURSEWORK_LIGHT_H

#include "/usr/include/eigen3/Eigen/Dense"

#include "BaseLight.h"
#include "LightStructure.h"
#include "transform_visitor.h"
#include "draw_visitor.h"

class Light : public BaseLight {
    friend DrawVisitor;
    friend TransformVisitor;
public:
    Light() = default;

    explicit Light(std::shared_ptr<LightStructure> srcLightStructure) :
            lightStructure(srcLightStructure) {}

    Light(const Point &position_arg, const Point &direction_arg) {}

    ~Light() override = default;


    virtual Point getCenter() override;

    void accept(std::shared_ptr<Visitor> visitor, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW,
                size_t bufH) override;

    std::shared_ptr<LightStructure> getLightStructure() const;


private:
    std::shared_ptr<LightStructure> lightStructure;
};


class LightFactory : public BaseLightFactory {
public:
    LightFactory(const Point &positionArg, const Point &directionArg);

    ~LightFactory() override = default;

    std::shared_ptr<BaseLight> create() override;

private:
    Point position{};
    Point direction{0, 0, 0};
    //todo
    std::vector<std::vector<double>> shadowMap;
    Eigen::Matrix4f transMatrix;
};


#endif //COURSEWORK_LIGHT_H
