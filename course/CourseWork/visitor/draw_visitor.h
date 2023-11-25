#ifndef LAB_03_DRAW_VISITOR_H
#define LAB_03_DRAW_VISITOR_H

#include "/usr/include/eigen3/Eigen/Dense"


#include <cmath>
#include "visitor.h"
#include "../drawer/base_drawer.h"

#include "face.h"

class DrawVisitor : public Visitor {
public:

    DrawVisitor(const std::shared_ptr<BaseDrawer> &drawer_arg, const std::shared_ptr<Camera> &camera_arg);

    ~DrawVisitor() override = default;

    void visit(FrameModel &model, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW, size_t bufH) override;

    void visit(Camera &model, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW, size_t bufH) override;

    void visit(Light &model, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW, size_t bufH) override;


    void interpolateRowIntoShadowMap(
            std::vector<std::vector<double>> *map, int xA, int xB, double zA, double zB, int curY);


    void shadowMapForModel(std::vector<Face> &facets, std::vector<Point> &vertices, std::shared_ptr<Light> illum, size_t bufWidth,
                                        size_t bufHeight);
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
