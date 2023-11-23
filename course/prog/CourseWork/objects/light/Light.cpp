//
// Created by max on 29.10.23.
//

#include "Light.h"

std::shared_ptr<LightStructure> Light::getLightStructure() const {
    return lightStructure;
}

Point Light::getCenter() {
    return lightStructure->getPosition();
}

//todo ???
void Light::accept(std::shared_ptr<Visitor> visitor, Eigen::Matrix4f mtr, std::shared_ptr<Light> light,
                   size_t bufW, size_t bufH) {
    visitor->visit(*this, mtr, light, bufW, bufH);
}


LightFactory::LightFactory(const Point &positionArg, const Point &directionArg) {
    position = positionArg;
    direction = directionArg;
    //todo
    Eigen::Matrix4f transMat;
    //todo
    double radianXAngle = (double) directionArg.getX() * M_PI / 180.0;
    double radianYAngle = (double) directionArg.getY() * M_PI / 180.0;

    transMat << 1, 0, 0, 0,
            0, cos(radianXAngle), -sin(radianXAngle), 0,
            0, sin(radianXAngle), cos(radianXAngle), 0,
            0, 0, 0, 1;

    Eigen::Matrix4f prodMat;
    prodMat << cos(radianYAngle), 0, sin(radianYAngle), 0,
            0, 1, 0, 0,
            -sin(radianYAngle), 0, cos(radianYAngle), 0,
            0, 0, 0, 1;

    transMat *= prodMat;

    transMatrix =  transMat;

}

std::shared_ptr<BaseLight> LightFactory::create() {
    return std::make_shared<Light>(std::make_shared<LightStructure>(position, direction, transMatrix));
}
