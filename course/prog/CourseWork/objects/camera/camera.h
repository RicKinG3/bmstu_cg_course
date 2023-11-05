#ifndef LAB_03_CAMERA_H
#define LAB_03_CAMERA_H

#include "base_camera.h"
#include "camera_structure.h"
#include "../../visitor/transform_visitor.h"

class Camera : public BaseCamera {
    friend DrawVisitor;
    friend TransformVisitor;
public:
    Camera() = default;

    explicit Camera(std::shared_ptr<CameraStructure> srcCameraStructure) :
            cameraStructure(srcCameraStructure) {}

    Camera(const Point &position_arg, const Point &direction_arg);

    ~Camera() override = default;

    virtual Point getCenter() override;

    void accept(std::shared_ptr<Visitor> visitor) override;

protected:
    std::shared_ptr<CameraStructure> getCameraStructure() const;

private:
    std::shared_ptr<CameraStructure> cameraStructure;
};


class CameraFactory : public BaseCameraFactory {
public:
    CameraFactory(const Point &positionArg, const Point &directionArg);

    ~CameraFactory() override = default;

    std::shared_ptr<BaseCamera> create() override;

private:
    Point position{};
    Point direction{0, 0, 0};
};


#endif //LAB_03_CAMERA_H
