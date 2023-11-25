#ifndef LAB_03_VISITOR_H
#define LAB_03_VISITOR_H

#include <memory>

#include "/usr/include/eigen3/Eigen/Dense"

class FrameModel;

class Camera;

class Composite;

class Scene;

class Light;

class Visitor {
public:
    Visitor() = default;

    virtual ~Visitor() = default;

    virtual void visit(FrameModel &model, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW, size_t bufH ) = 0;

    virtual void visit(Camera &model, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW, size_t bufH ) = 0;

    virtual void visit(Light &model, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW, size_t bufH ) = 0;


    // TODO : delete
    // todo need add light
};


class VisitorFactory {
public:
    VisitorFactory() = default;

    virtual ~VisitorFactory() = default;

    virtual std::shared_ptr<Visitor> create() = 0;
};

#endif //LAB_03_VISITOR_H
