#ifndef USAGEFACADE_HPP
#define USAGEFACADE_HPP

#include "/usr/include/eigen3/Eigen/Dense"
#include "Platform.h"
#include <QGraphicsScene>


//#include <omp.h>




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

class UsageFacade {
public:
    UsageFacade();

    void setCellScene(size_t width_, size_t height_);

    void changeCellScene(size_t newWidth, size_t newheight);

    bool isSceneSet();

    QGraphicsScene *drawScene(QRectF rect);

    int addHouse(int xCell, int yCell, int modelLength, int modelHeight, int countFloors);

    int addPickup(int xCell, int yCell, Direction direction, ColorCar color_car);


    int addTree(int xCell, int yCell);

    int addRoad(int xCell, int yCell, Direction direction);

    int addCar(int xCell, int yCell, Direction direction, ColorCar color_car);

    void addLight(int xAngle, int yAngle);

    QGraphicsScene *moveUpScene(double value, QRectF rect);

    QGraphicsScene *moveDownScene(double value, QRectF rect);

    QGraphicsScene *moveLeftScene(double value, QRectF rect);

    QGraphicsScene *moveRightScene(double value, QRectF rect);

    QGraphicsScene *scaleScene(double value, QRectF rect);

    QGraphicsScene *rotateXScene(double angle, QRectF rect);

    QGraphicsScene *rotateYScene(double angle, QRectF rect);

    QGraphicsScene *rotateZScene(double angle, QRectF rect);

    QGraphicsScene *toCenter(QRectF rect);

    Platform *getScene();

private:
    Platform *scene = nullptr;
    Drawer *drawer;

    void addQuad(std::vector<Vertex> &vertices, std::vector<Polygon> &facets,
                 int x1, int y1, int z1,
                 int x2, int y2, int z2,
                 int x3, int y3, int z3,
                 int x4, int y4, int z4);

    void addTriangle(std::vector<Vertex> &vertices, std::vector<Polygon> &facets,
                     int x1, int y1, int z1,
                     int x2, int y2, int z2,
                     int x3, int y3, int z3);

    bool searchRoadsNearby(int xCell, int yCell, int widthModel, int heightModel);
    };

#endif // USAGEFACADE_HPP
