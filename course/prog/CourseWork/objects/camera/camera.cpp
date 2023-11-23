#include "camera.h"
#include "camera_structure.h"


std::shared_ptr<CameraStructure> Camera::getCameraStructure() const {
    return cameraStructure;
}

void
Camera::accept(std::shared_ptr<Visitor> visitor, Eigen::Matrix4f mtr, std::shared_ptr<Light> light,
               size_t bufW, size_t bufH) {
    visitor->visit(*this, mtr, light, bufW, bufH);
}


Point Camera::getCenter() {
    return cameraStructure->getPosition();
}


CameraFactory::CameraFactory(const Point &positionArg, const Point &directionArg) {
    position = positionArg;
    direction = directionArg;
}

std::shared_ptr<BaseCamera> CameraFactory::create() {
    return std::make_shared<Camera>(std::make_shared<CameraStructure>(position, direction));
}
