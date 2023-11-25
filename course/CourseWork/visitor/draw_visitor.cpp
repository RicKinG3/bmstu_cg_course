#include "draw_visitor.h"

#include "../objects/camera/camera.h"
#include "../objects/composite/composite.h"

#include "../transformer/transformer_factory.h"
#include "../objects/model/frame_model.h"
#include "../objects/model/model.h"
#include "Light.h"
#include <iostream>
//todo
#define PLATE_Z                 10000
#define PLATE_START             10, 10, PLATE_Z

#define X_CENTER                450
#define Y_CENTER                380


void DrawVisitor::interpolateRowIntoShadowMap(
        std::vector<std::vector<double>> *map, int xA, int xB, double zA, double zB, int curY)
{
    for (int curX = xA; curX <= xB; curX++)
    {
        double curZ = zA + (zB - zA) * (curX - xA) / (xB - xA);
        if (curX >= (int) map->size() || curX < 0 || curY >= (int) map->at(0).size() ||
            curY < 0)
            continue;

        if (curZ > map->at(curX).at(curY))
            map->at(curX).at(curY) = curZ;
    }
}


////todo вынести на верх

void DrawVisitor::shadowMapForModel(std::vector<Face> &facets, std::vector<Point> &vertices, std::shared_ptr<Light> illum, size_t bufWidth,
                                    size_t bufHeight) {
    std::array<Point, 3> dotsArr;
    Eigen::Matrix4f toCenter;

    toCenter << 1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            -X_CENTER, -Y_CENTER, -PLATE_Z - 5, 1;

    Eigen::Matrix4f backToStart;

    backToStart << 1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            X_CENTER, Y_CENTER, PLATE_Z + 5, 1;

    std::vector<std::vector<double>> *shadowMap = &(illum->getLightStructure())->getShadowMap();
    Eigen::Matrix4f illumMat = illum->getLightStructure()->getTransMat();
    //todo  * transMat
    Eigen::Matrix4f dotTransMat = toCenter  * illumMat * backToStart;


    size_t curFaceNum = 0;
    for (const auto &face: facets) {
        Eigen::MatrixXf coordinatesVec(3, 4);

        // Получаем индексы точек, составляющих текущий полигон
        std::size_t pointIndex1 = face[0];
        std::size_t pointIndex2 = face[1];
        std::size_t pointIndex3 = face[2];

        dotsArr[0] = vertices[pointIndex1];
        dotsArr[2] = vertices[pointIndex2];
        dotsArr[3] = vertices[pointIndex3];

        coordinatesVec <<
                       dotsArr[0].getX(), dotsArr[0].getY(), dotsArr[0].getZ(), 1,
                dotsArr[1].getX(), dotsArr[1].getY(), dotsArr[1].getZ(), 1,
                dotsArr[2].getX(), dotsArr[2].getY(), dotsArr[2].getZ(), 1;

        coordinatesVec *= dotTransMat;
        dotsArr[0] =
                Point(coordinatesVec(0, 0), coordinatesVec(0, 1), coordinatesVec(0, 2));
        dotsArr[1] =
                Point(coordinatesVec(1, 0), coordinatesVec(1, 1), coordinatesVec(1, 2));
        dotsArr[2] =
                Point(coordinatesVec(2, 0), coordinatesVec(2, 1), coordinatesVec(2, 2));

        if (dotsArr[0].getY() > dotsArr[1].getY())
            std::swap(dotsArr[0], dotsArr[1]);
        if (dotsArr[0].getY() > dotsArr[2].getY())
            std::swap(dotsArr[0], dotsArr[2]);
        if (dotsArr[1].getY() > dotsArr[2].getY())
            std::swap(dotsArr[1], dotsArr[2]);

        int x1 = round(dotsArr[0].getX());
        int x2 = round(dotsArr[1].getX());
        int x3 = round(dotsArr[2].getX());

        double z1 = dotsArr[0].getZ();
        double z2 = dotsArr[1].getZ();
        double z3 = dotsArr[2].getZ();

        int y1 = round(dotsArr[0].getY());
        int y2 = round(dotsArr[1].getY());
        int y3 = round(dotsArr[2].getY());

#pragma omp parallel for
        for (int curY = (y1 < 0) ? 0 : y1;
             curY < ((y2 >= (int) bufHeight) ? (int) bufHeight - 1 : y2); curY++) {
            double aInc = 0;
            if (y1 != y2)
                aInc = (double) (curY - y1) / (y2 - y1);

            double bInc = 0;
            if (y1 != y3)
                bInc = (double) (curY - y1) / (y3 - y1);

            int xA = round(x1 + (x2 - x1) * aInc);
            int xB = round(x1 + (x3 - x1) * bInc);
            double zA = z1 + (z2 - z1) * aInc;
            double zB = z1 + (z3 - z1) * bInc;

            if (xA > xB) {
                std::swap(xA, xB);
                std::swap(zA, zB);
            }

            if (xA < 0)
                xA = 0;
            if (xB >= (int) bufWidth)
                xB = (int) bufWidth - 1;

            interpolateRowIntoShadowMap(shadowMap, xA, xB, zA, zB, curY);
        }

#pragma omp parallel for
        for (int curY = (y2 < 0) ? 0 : y2;
             curY <= ((y3 >= (int) bufHeight) ? (int) bufHeight - 1 : y3); curY++) {
            double aInc = 0;
            if (y2 != y3)
                aInc = (double) (curY - y2) / (y3 - y2);

            double bInc = 0;
            if (y1 != y3)
                bInc = (double) (curY - y1) / (y3 - y1);

            int xA = round(x2 + (x3 - x2) * aInc);
            int xB = round(x1 + (x3 - x1) * bInc);
            double zA = z2 + (z3 - z2) * aInc;
            double zB = z1 + (z3 - z1) * bInc;

            if (xA > xB) {
                std::swap(xA, xB);
                std::swap(zA, zB);
            }

            if (xA < 0)
                xA = 0;
            if (xB >= (int) bufWidth)
                xB = (int) bufWidth - 1;

            interpolateRowIntoShadowMap(shadowMap, xA, xB, zA, zB, curY);
        }
        curFaceNum++;
    }
}
DrawVisitor::DrawVisitor(const std::shared_ptr<BaseDrawer> &drawer_arg, const std::shared_ptr<Camera> &camera_arg) :
        drawer(drawer_arg), camera(camera_arg) {};

//TODO del edges
// почему то передается нулевуой Light

void
DrawVisitor::visit(FrameModel &model, Eigen::Matrix4f mtr, std::shared_ptr<Light> lights, size_t bufW, size_t bufH) {

    auto points = model.getModelStructure()->getPoints();
    auto edges = model.getModelStructure()->getEdges();
    auto faces = model.getModelStructure()->getFaces();

    auto center = model.getCenter();
    //todo сделать это как в объект
//    Eigen::Matrix4f transMatrix;

    shadowMapForModel(faces, points, lights, bufW, bufH);


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

void DrawVisitor::visit(Camera &model, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW, size_t bufH) {}

void DrawVisitor::visit(Light &model, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW, size_t bufH) {}

DrawVisitorFactory::DrawVisitorFactory(std::shared_ptr<BaseDrawer> &drawer_arg,
                                       std::shared_ptr<Camera> &camera_arg) {
    drawer = drawer_arg;
    camera = camera_arg;
}

std::shared_ptr<Visitor> DrawVisitorFactory::create() {
    return std::make_unique<DrawVisitor>(drawer, camera);
}