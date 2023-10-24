#include "draw_visitor.h"
#include "../objects/model/frame_model.h"
#include "../objects/model/model.h"
#include "../objects/camera/camera.h"
#include "../objects/composite/composite.h"

#include "../transformer/transformer_factory.h"

#include <iostream>


DrawVisitor::DrawVisitor(const std::shared_ptr<BaseDrawer> &drawer_arg, const std::shared_ptr<Camera> &camera_arg) :
        drawer(drawer_arg), camera(camera_arg) {};


void DrawVisitor::visit(FrameModel &model) {
    auto points = model.getModelStructure()->getPoints();
    auto edges = model.getModelStructure()->getEdges();
    auto faces = model.getModelStructure()->getFaces();

    auto center = model.getCenter();


    for (const auto &face: faces) {
        // Получаем индексы точек, составляющих текущий полигон
        std::size_t pointIndex1 = face[0];
        std::size_t pointIndex2 = face[1];
        std::size_t pointIndex3 = face[2];

        // Рисуем полигон, используя три точки
        drawer->drawPolygon(
                                    projectPoint(points[pointIndex1], center),
                                    projectPoint(points[pointIndex2], center),
                                    projectPoint(points[pointIndex3], center)
                            );
    }


}


Point DrawVisitor::projectPoint(const Point &point, const Point &center) {
    Point resPoint(point);
    Point proj = {0, 0, 0};

    Point centerCam = camera->getCameraStructure()->getPosition();
    Point direction = camera->getCameraStructure()->getDirection();

    auto transformer = TransformerFactory(-direction, {1, 1, 1}, -centerCam).create();
    transformer->transform(resPoint, proj);

    return resPoint + center;
}

void DrawVisitor::visit(Camera &model) {}


DrawVisitorFactory::DrawVisitorFactory(std::shared_ptr<BaseDrawer> &drawer_arg,
                                       std::shared_ptr<Camera> &camera_arg) {
    drawer = drawer_arg;
    camera = camera_arg;
}

std::shared_ptr<Visitor> DrawVisitorFactory::create() {
    return std::make_unique<DrawVisitor>(drawer, camera);
}