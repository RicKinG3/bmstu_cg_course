#ifndef LAB_03_DRAW_VISITOR_H
#define LAB_03_DRAW_VISITOR_H


#include <cmath>
#include "visitor.h"
#include "../drawer/base_drawer.h"


class DrawVisitor : public Visitor {
public:
    DrawVisitor(const std::shared_ptr<BaseDrawer> &drawer_arg, const std::shared_ptr<Camera> &camera_arg);

    ~DrawVisitor() override = default;

    void visit(FrameModel &model) override;

    void visit(Camera &model) override;

    void visit(Light &model) override;

private:

    std::shared_ptr<BaseDrawer> drawer;
    std::shared_ptr<Camera> camera;
    std::shared_ptr<Light> light;

    Point projectPoint(const Point &point, const Point &center);
};


class DrawVisitorFactory : public VisitorFactory {
public:
    DrawVisitorFactory(std::shared_ptr<BaseDrawer> &drawer_arg, std::shared_ptr<Camera> &camera_arg);

    ~DrawVisitorFactory() override = default;

    std::shared_ptr<Visitor> create() override;

private:
    std::shared_ptr<BaseDrawer> drawer;
    std::shared_ptr<Camera> camera;
    std::shared_ptr<Light> light;

};

#endif //LAB_03_DRAW_VISITOR_H
