#ifndef OBJS_HPP
#define OBJS_HPP

#define MOVECOEF 500

#include <iostream>
#include <vector>
#include "/usr/include/eigen3/Eigen/Dense"

#include "config.hpp"
#include "Point.h"
#include "Vertex.h"
#include "Model.h"
#include "Light.h"


class Platform {
public:
    Platform();

    Platform(size_t width_, size_t height_);

    operator bool() const;

    size_t getWidth();

    size_t getHeight();

    void buildPlateModel(Point start_platform, Point end_platform);

    Model &getPlateModel();

    void changeSize(size_t new_width, size_t new_height);

    void moveUp(double value);

    void moveDown(double value);

    void moveLeft(double value);

    void moveRight(double value);

    void scale(double value);

    void rotateX(double angle);

    void rotateY(double angle);

    void rotateZ(double angle);

    void toCenter();

    size_t getRealModelsNum();

    size_t getModelsNum();

    Model &getModel(size_t num);

    void setModel(size_t num, Model &new_model);

    void addModel(Model &model);

    void deleteModel(size_t num);

    size_t getLightNum();

    Light &getLight(size_t num);

    void setLight(Light &light, size_t i);

    void addLight(Light &light);

    void delLight(size_t num);

    Eigen::Matrix4f &getTransMtr();

    void multToTrans(Eigen::Matrix4f &new_trans_mtr);

    std::vector<std::vector<size_t>> &getUsedSquares();

    void initUsedSquares();

    void markUsedSquares(size_t num);

    void clearUsedSquares(size_t num);

    void printUsedSquares();

private:
    void markSquareNearHouse(int xCell, int yCell, int widthModel, int heightModel);

    void clearSquareNearHouse(int xCell, int yCell, int widthModel, int heightModel);

    void addQuad(std::vector<Vertex> &vertices, std::vector<Polygon> &facets,
                 int x1, int y1, int z1,
                 int x2, int y2, int z2,
                 int x3, int y3, int z3,
                 int x4, int y4, int z4);

    size_t width, height;

    Model *platform_model = nullptr;

    Eigen::Matrix4f trans_mtr;

    size_t real_model_num = 0;
    size_t models_um = 0;
    std::vector<Model> models;

    size_t light_num = 0;
    std::vector<Light> lights;

    Point point_center;

    std::vector<std::vector<size_t>> used_squares;
};

#endif // OBJS_HPP
