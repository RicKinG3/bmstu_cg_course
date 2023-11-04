//
// Created by User on 29.05.2023.
//

#ifndef LAB_03_FRAME_MODEL_STRUCTURE_H
#define LAB_03_FRAME_MODEL_STRUCTURE_H
#include <QDebug>


#include <memory>
#include <vector>

#include "../primitives/point.h"
#include "../primitives/edge.h"
#include "../../visitor/draw_visitor.h"
#include "face.h"

class FrameModelStructure {
public:
    FrameModelStructure() = default;

    FrameModelStructure(const std::vector<Point> &srcPoints,
                        const std::vector<Edge> &srcEdges,
                        const std::vector<Face> &srcFaces,
                        const Point &srcCenter = {});

    ~FrameModelStructure() = default;

    const std::vector<Point> &getPoints();

    const std::vector<Edge> &getEdges();

    const std::vector<Face> &getFaces();

    void setPoints(const std::vector<Point> &points_);

    const Point &getCenter();

    void setCenter(const Point &srcCenter);

    void addPoint(const Point &point);

    void addEdge(const Edge &edge);

    void addFace(const Face &face);

    void printFaces() const;

    friend void DrawVisitor::visit(FrameModel &model);

private:
    Point center{};
    std::vector<Point> points;
    std::vector<Edge> edges;
    std::vector<Face> faces;
};


#endif //LAB_03_FRAME_MODEL_STRUCTURE_H
