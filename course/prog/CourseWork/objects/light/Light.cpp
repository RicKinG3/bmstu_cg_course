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
void Light::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}



LightFactory::LightFactory(const Point &positionArg, const Point &directionArg) {
    position = positionArg;
    direction = directionArg;
}

std::shared_ptr<BaseLight> LightFactory::create() {
    return std::make_shared<Light>(std::make_shared<LightStructure>(position, direction));
}
