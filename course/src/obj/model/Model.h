#ifndef SRC_MODEL_H
#define SRC_MODEL_H

#include <iostream>
#include <vector>

#include "Polygon.h"
#include "Vertex.h"
#include "config.h"

enum Direction {
    Horizontal,
    Vertical,
    Nodirection
};

enum ColorCar {
    grey,
    red
};


class Model {
public:
    Model() {}

    Model(std::vector<Vertex> vertices_, std::vector<Polygon> polygons_)
            : vertices{vertices_}, polygons{polygons_} {}

    Model(std::vector<Vertex> vertices_, std::vector<Polygon> polygons, QString name_)
            : vertices{vertices_}, polygons{polygons}, model_name{name_} {}

    ~Model() {}

    const std::vector<Vertex> getVertices();

    void setVertices(std::vector<Vertex> &vertices_);

    const std::vector<Polygon> getPolygons();

    void setPolygons(std::vector<Polygon> polygons_);

    void moveTo(int new_x_sq, int new_y_sq);

    void rotateZ(int angle);

    void setUsedSquare(int x_sq, int y_sq);

    int getUsedXSq();

    int getUsedYSq();

    void setWidthModel(int width_model_);

    int getWidthModel();

    void setHeightModel(int height_model_);

    int getHeightModel();

    void setHouseHeight(int house_height_);

    int getHouseHeight();

    void setModelNum(size_t model_num_);

    size_t getModelNum();

    QString getName();

    void setName(QString model_name_);

    enum model_t {
        House,
        RoofHouse,
        WindowsHouse,
        TreeFoliage,
        TreeTrunk,
        RoadAsphalt,
        RoadStripe,
        Car,
        WheelsCar,
        GlassCar,
        Pickup
    };

    Direction getDirectionRoad();

    void setDirectionRoad(Direction direction_road_);

    Direction getDirectionCar();

    void setDirectionCar(Direction direction_car_);


    ColorCar getColorCar();

    void setColorCar(ColorCar color);


    void setModelType(model_t model_type_);

    model_t getModelType();

private:
    std::vector<Vertex> vertices;
    std::vector<Polygon> polygons;
    QString model_name;

    int x_square, y_square;
    int width_model, height_model;
    int house_height = -1;

    Direction direction_road = Horizontal;
    Direction direction_car = Horizontal;

    size_t model_num;
    model_t model_type;

    ColorCar color_car = grey;
};


#endif //SRC_MODEL_H
