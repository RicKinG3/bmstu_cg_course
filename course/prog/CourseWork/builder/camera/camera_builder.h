#ifndef LAB_03_CAMERA_BUILDER_H
#define LAB_03_CAMERA_BUILDER_H


#include "base_camera_builder.h"
#include "../../objects/camera/camera.h"


class CameraBuilder : public BaseCameraBuilder
{
public:
    CameraBuilder() = default;
    ~CameraBuilder() override = default;

    bool isBuilt() override;
    void reset() override;
    void build() override;

    virtual void buildPosition(const Point &position) override;
    virtual void buildDirection(const Point &direction) override;

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<Camera> camera;
};


class CameraBuilderCreator : public BuilderCreator
{
public:
    CameraBuilderCreator() = default;
    ~CameraBuilderCreator() override = default;

    std::shared_ptr<BaseBuilder> createBuilder() override;
};



#endif //LAB_03_CAMERA_BUILDER_H
