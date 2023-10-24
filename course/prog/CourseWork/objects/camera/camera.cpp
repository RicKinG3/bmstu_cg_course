#include "camera.h"
#include "camera_structure.h"


std::shared_ptr<CameraStructure> Camera::getCameraStructure() const {
    return cameraStructure;
}


Point Camera::getCenter() {
    return cameraStructure->getPosition();
}

void Camera::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}


CameraFactory::CameraFactory(const Point &positionArg, const Point &directionArg) {
    position = positionArg;
    direction = directionArg;
}

std::shared_ptr<BaseCamera> CameraFactory::create() {
    return std::make_shared<Camera>(std::make_shared<CameraStructure>(position, direction));
}
