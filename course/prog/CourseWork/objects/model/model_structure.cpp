#include "model_structure.h"
#include <iostream>

FrameModelStructure::FrameModelStructure(const std::vector<Point> &srcPoints,
                                         const std::vector<Edge> &srcEdges,
                                         const std::vector<Face> &srcFaces,
                                         const Point &srcCenter) :
        points(srcPoints), edges(srcEdges), faces(srcFaces), center(srcCenter) {
}


const std::vector<Point> &FrameModelStructure::getPoints() {
    return points;
}

const std::vector<Edge> &FrameModelStructure::getEdges() {
    return edges;
}

const Point &FrameModelStructure::getCenter() {
    return center;
}


const std::vector<Face> &FrameModelStructure::getFaces() {
    return faces;
}


void FrameModelStructure::addPoint(const Point &point) {
    points.push_back(-(center - point));
}

void FrameModelStructure::addEdge(const Edge &edge) {
    edges.push_back(edge);

}

void FrameModelStructure::addFace(const Face &face) {
    faces.push_back(face);
}


void FrameModelStructure::setCenter(const Point &srcCenter) {
    center = srcCenter;
}

void FrameModelStructure::setPoints(const std::vector<Point> &points_) {
    points = points_;
}


void FrameModelStructure::printFaces() const {
    for (const auto &face: faces) {
        std::cout << face << std::endl;
    }
}

