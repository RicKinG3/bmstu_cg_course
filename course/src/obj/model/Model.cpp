#include "Model.h"


const std::vector<Vertex> Model::getVertices() { return vertices; }

void Model::setVertices(std::vector<Vertex> &vertices_) { vertices = vertices_; }



QString Model::getName() { return model_name; }

void Model::setName(QString model_name_) { model_name = model_name_; }


void Model::setWidthModel(int width_model_) { width_model = width_model_; }

int Model::getWidthModel() { return width_model; }

void Model::setHeightModel(int height_model_) { height_model = height_model_; }

int Model::getHeightModel() { return height_model; }


void Model::setHouseHeight(int house_height_) { house_height = house_height_; }

int Model::getHouseHeight() { return house_height; }


Direction Model::getDirectionRoad() { return direction_road; }

void Model::setDirectionRoad(Direction direction_road_) { direction_road = direction_road_; }


Direction Model::getDirectionCar() { return direction_car; }

void Model::setDirectionCar(Direction direction_car_) { direction_car = direction_car_; }

ColorCar Model::getColorCar() { return color_car; }

void Model::setColorCar(ColorCar color) { color_car = color; }


void Model::setModelNum(size_t model_num_) { model_num = model_num_; }

size_t Model::getModelNum() { return model_num; }


void Model::setUsedSquare(int x_sq, int y_sq) {
    x_square = x_sq;
    y_square = y_sq;
}

int Model::getUsedXSq() { return x_square; }

int Model::getUsedYSq() { return y_square; }


void Model::setModelType(model_t model_type_) { model_type = model_type_; }

Model::model_t Model::getModelType() { return model_type; }


void Model::rotateZ(int angle) {
    double radianAngle = (double) angle * M_PI / 180.0;

    Point start(PLATFORM_START);
    double x_center = start.getXCoord() + x_square * SCALE_FACTOR + SCALE_FACTOR / 2;
    double y_center = start.getYCoord() + y_square * SCALE_FACTOR + SCALE_FACTOR / 2;

    for (size_t i = 0; i < vertices.size(); i++) {
        Point curDot = vertices.at(i).getPosition();
        curDot.rotateZ(radianAngle, x_center, y_center, 0);
        vertices.at(i).setPosition(curDot);
    }
}

void Model::moveTo(int new_x_sq, int new_y_sq) {
    Point start(PLATFORM_START);

    int xInc = SCALE_FACTOR * new_x_sq - SCALE_FACTOR * x_square;
    int yInc = SCALE_FACTOR * new_y_sq - SCALE_FACTOR * y_square;

    for (size_t i = 0; i < vertices.size(); i++) {
        Point curDot = vertices.at(i).getPosition();
        curDot.move(xInc, yInc, 0);
        vertices.at(i).setPosition(curDot);
    }

    x_square = new_x_sq;
    y_square = new_y_sq;
}
