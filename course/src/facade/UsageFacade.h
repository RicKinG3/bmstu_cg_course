#ifndef SRC_USAGEFACADE_H
#define SRC_USAGEFACADE_H

#include <QGraphicsScene>
#include <QDebug>
#include <QPen>
#include <limits>

#include <math.h>

#include "/usr/include/eigen3/Eigen/Dense"
#include "Platform.h"
#include "config.h"
#include "Drawer.h"

//#include <omp.h>

//todo


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

#endif // SRC_USAGEFACADE_H
