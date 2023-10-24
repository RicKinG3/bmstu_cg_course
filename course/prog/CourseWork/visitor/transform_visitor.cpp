//
// Created by User on 02.06.2023.
//

#include "transform_visitor.h"
#include "../objects/model/frame_model.h"
#include "../objects/camera/camera.h"

TransformVisitor::TransformVisitor(const std::shared_ptr<BaseTransformer> &transformer_) :
        transformer(transformer_) {}

void TransformVisitor::visit(FrameModel &model) {
    auto points = model.getModelStructure()->getPoints();
    auto center = model.getCenter();

    for (auto &point: points)
        transformer->transform(point, center);

    model.getModelStructure()->setPoints(points);
    model.getModelStructure()->setCenter(center);
}

void TransformVisitor::visit(Camera &model) {
    auto direction = model.getCameraStructure()->getDirection();
    auto position = model.getCameraStructure()->getPosition();

    transformer->transform(direction, position);
    //transformer->transform(position, position);

    model.getCameraStructure()->setDirection(direction);
    model.getCameraStructure()->setPosition(position);
}

TransformVisitorFactory::TransformVisitorFactory(std::shared_ptr<BaseTransformer> &transformer_) :
        transformer(transformer_) {
}

std::shared_ptr<Visitor> TransformVisitorFactory::create() {
    return std::make_unique<TransformVisitor>(transformer);
}
