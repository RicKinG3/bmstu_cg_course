#ifndef SRC_DRAWER_H
#define SRC_DRAWER_H

#include <QDebug>
#include <QGraphicsScene>
#include <vector>

#include "Platform.h"
#include "/usr/include/eigen3/Eigen/Dense"


class Drawer {
public:
    void zBufferAlg(Platform *scene, size_t bufheight, size_t bufWidth);

    void zBufForModel(std::vector<Polygon> &facets, std::vector<Vertex> &vertices,
                      Eigen::Matrix4f &transMat, size_t color, Platform *scene, size_t bufWidth, size_t bufHeight);

    void generateShadowMap(std::vector<Polygon> &modelFacets, std::vector<Vertex> &modelVertices,
                           Eigen::Matrix4f &modelTransformationMatrix, Light *lightSource, size_t bufWidth,
                           size_t bufHeight);

    void prepareTransformationMatrices(Eigen::Matrix4f &toCenter, Eigen::Matrix4f &backToStart);

    std::array<Point, 3> transformFacetVertices(Polygon &facet,
                                                const std::vector<Vertex> &modelVertices,
                                                const Eigen::Matrix4f &modelTransformationMatrix,
                                                const Eigen::Matrix4f &lightSourceMatrix,
                                                const Eigen::Matrix4f &toCenter,
                                                const Eigen::Matrix4f &backToStart);

    void rasterizeFacet(const std::array<Point, 3> &vertices,
                        std::vector<std::vector<double>> *shadowMap,
                        size_t bufferWidth, size_t bufferHeight);

    QGraphicsScene *drawScene(Platform *scene, QRectF rect);

private:
    void interpolateColIntoShadowMap();

    void interpolateRowIntoShadowMap(std::vector<std::vector<double>> *shadowMap, int xStart, int xEnd, double zStart,
                                     double zEnd, int curY);

    void specBorderPut(int x, int y, double z);

    void DDABordersForPolygon(
            int xStart, int yStart, double zStart, int xEnd, int yEnd, double zEnd);

    void drawSquareBorders(int x1, int y1, double z1, int x2, int y2, double z2, int x3, int y3, double z3);

    std::vector<std::vector<double>> depthBuffer;
    std::vector<std::vector<size_t>> frameBuffer;
};


#endif //SRC_DRAWER_H
