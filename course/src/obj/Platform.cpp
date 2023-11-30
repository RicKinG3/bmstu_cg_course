#include "Platform.h"
#include <QDebug>

//todo reform

Platform::Platform() {}

Platform::Platform(size_t width_, size_t height_) {
    width = width_;
    height = height_;

    models_um = 0;
    light_num = 0;

    initUsedSquares();
    toCenter();
}

void movePointQuad(int &x1, int &x2, int &x3, int &x4, int &y1, int &y2, int &y3, int &y4) {
    x1 += MOVECOEF;
    x2 += MOVECOEF;
    x3 += MOVECOEF;
    x4 += MOVECOEF;

    y1 += MOVECOEF;
    y2 += MOVECOEF;
    y3 += MOVECOEF;
    y4 += MOVECOEF;
}

void Platform::addQuad(std::vector<Vertex> &vertices, std::vector<Polygon> &facets, int x1,
                       int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4) {
    Point dot;
    std::vector<size_t> vec;
    // перенос точек для того чтоб потом работал з алгоритм
    movePointQuad(x1, x2, x3, x4, y1, y2, y3, y4);


    size_t size = facets.size();

    dot = Point(x1, y1, z1);
    vec = {size, size + 1};
    vertices.push_back(Vertex(dot, vec));

    dot = Point(x2, y2, z2);
    vec = {size};
    vertices.push_back(Vertex(dot, vec));

    dot = Point(x3, y3, z3);
    vec = {size, size + 1};
    vertices.push_back(Vertex(dot, vec));

    dot = Point(x4, y4, z4);
    vec = {size + 1};
    vertices.push_back(Vertex(dot, vec));

    size = vertices.size();
    vec = {size - 4, size - 3, size - 2};
    facets.push_back(vec);
    vec = {size - 4, size - 2, size - 1};
    facets.push_back(vec);
}

size_t Platform::getWidth() { return width; }

size_t Platform::getHeight() { return height; }

Platform::operator bool() const { return this->platform_model; }


void Platform::markUsedSquares(size_t num) {
    int xCell = models[num].getUsedXSq();
    int yCell = models[num].getUsedYSq();
    int widthModel = models[num].getWidthModel();
    int heightModel = models[num].getHeightModel();
    Model::model_t modelType_ = models[num].getModelType();

    int key;
    // 1 - стоит модель
    // 2 - стоит дорога
    // 3 - ячейка прилегает к дому
    // 4 - стоит машина на дороге

    if (modelType_ == Model::model_t::RoadStripe)
        key = 2;
    else if (modelType_ == Model::model_t::GlassCar)
        key = 4;
    else
        key = 1;

    if (modelType_ == Model::model_t::WindowsHouse)
        markSquareNearHouse(xCell, yCell, widthModel, heightModel);


    for (int i = yCell; i < yCell + heightModel; i++) {
        for (int j = xCell; j < xCell + widthModel; j++) {
            getUsedSquares()[i][j] = key;
            qDebug() << "i = " << i << "j = " << j << "занята моделью";
        }
    }
}

void Platform::markSquareNearHouse(int xCell, int yCell, int widthModel, int heightModel) {
    for (int k = 0; k < 2; k++) {
        int i = yCell - 1 + k * (heightModel + 1);
        if (i < 0 || size_t(i) > getHeight() - 1)
            continue;

        int j0 = xCell - 1;
        if (j0 >= 0) {
            if (getUsedSquares()[i][j0] == 0)
                getUsedSquares()[i][j0] = 3;
            qDebug() << "i = " << i << "j = " << j0 << "отмечена как прилегающая к дому";
        }

        j0 = xCell + widthModel;
        if (size_t(j0) <= getWidth() - 1) {
            if (getUsedSquares()[i][j0] == 0)
                getUsedSquares()[i][j0] = 3;
            qDebug() << "i = " << i << "j = " << j0 << "отмечена как прилегающая к дому";
        }

        for (int j = xCell; j < xCell + widthModel; j++) {
            if (getUsedSquares()[i][j] == 0)
                getUsedSquares()[i][j] = 3;
            qDebug() << "i = " << i << "j = " << j << "отмечена как прилегающая к дому";
        }
    }

    for (int k = 0; k < 2; k++) {
        int j = xCell - 1 + k * (widthModel + 1);
        if (j < 0 || size_t(j) > getWidth() - 1)
            continue;

        for (int i = yCell; i < yCell + heightModel; i++) {
            if (getUsedSquares()[i][j] == 0)
                getUsedSquares()[i][j] = 3;
            qDebug() << "i = " << i << "j = " << j << "отмечена как прилегающая к дому";
        }
    }
}

void Platform::clearUsedSquares(size_t num) {
    int xCell = models[num].getUsedXSq();
    int yCell = models[num].getUsedYSq();
    int widthModel = models[num].getWidthModel();
    int heightModel = models[num].getHeightModel();
    Model::model_t modelType_ = models[num].getModelType();

    int key;
    if (modelType_ == Model::model_t::GlassCar)
        key = 2;
    else
        key = 0;

    if (modelType_ == Model::model_t::WindowsHouse)
        clearSquareNearHouse(xCell, yCell, widthModel, heightModel);


    for (int i = yCell; i < yCell + heightModel; i++) {
        for (int j = xCell; j < xCell + widthModel; j++) {
            getUsedSquares()[i][j] = key;
            qDebug() << "i = " << i << "j = " << j << "освобождена после удаления модели";
        }
    }
}


void Platform::clearSquareNearHouse(int xCell, int yCell, int widthModel, int heightModel) {
    for (int k = 0; k < 2; k++) {
        int i = yCell - 1 + k * (heightModel + 1);
        if (i < 0 || size_t(i) > getHeight() - 1)
            continue;

        int j0 = xCell - 1;
        if (j0 >= 0) {
            if (getUsedSquares()[i][j0] == 3)
                getUsedSquares()[i][j0] = 0;
            qDebug() << "i = " << i << "j = " << j0 << "отмечена как не прилегающая к дому";
        }

        j0 = xCell + widthModel;
        if (size_t(j0) <= getWidth() - 1) {
            if (getUsedSquares()[i][j0] == 3)
                getUsedSquares()[i][j0] = 0;
            qDebug() << "i = " << i << "j = " << j0 << "отмечена как не прилегающая к дому";
        }

        for (int j = xCell; j < xCell + widthModel; j++) {
            if (getUsedSquares()[i][j] == 3)
                getUsedSquares()[i][j] = 0;
            qDebug() << "i = " << i << "j = " << j << "отмечена как не прилегающая к дому";
        }
    }

    for (int k = 0; k < 2; k++) {
        int j = xCell - 1 + k * (widthModel + 1);
        if (j < 0 || size_t(j) > getWidth() - 1)
            continue;

        for (int i = yCell; i < yCell + heightModel; i++) {
            if (getUsedSquares()[i][j] == 3)
                getUsedSquares()[i][j] = 0;
            qDebug() << "i = " << i << "j = " << j << "отмечена как не прилегающая к дому";
        }
    }
}


void Platform::moveUp(double value) {
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, -value, 0, 1;

    trans_mtr *= moveMat;
}

void Platform::moveDown(double value) {
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, value, 0, 1;

    trans_mtr *= moveMat;
}

void Platform::moveLeft(double value) {
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            -value, 0, 0, 1;

    trans_mtr *= moveMat;
}

void Platform::moveRight(double value) {
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            value, 0, 0, 1;

    trans_mtr *= moveMat;
}

void Platform::scale(double value) {
    Eigen::Matrix4f scaleMatrix;
    scaleMatrix << value, 0, 0, 0,
            0, value, 0, 0,
            0, 0, value, 0,
            0, 0, 0, 1;

    trans_mtr *= scaleMatrix;
}

void Platform::rotateX(double angle) {
    Eigen::Matrix4f rotateMatrix;
    rotateMatrix << 1, 0, 0, 0,
            0, cos(angle), -sin(angle), 0,
            0, sin(angle), cos(angle), 0,
            0, 0, 0, 1;

    trans_mtr *= rotateMatrix;
}

void Platform::rotateY(double angle) {
    Eigen::Matrix4f rotateMatrix;
    rotateMatrix << cos(angle), 0, sin(angle), 0,
            0, 1, 0, 0,
            -sin(angle), 0, cos(angle), 0,
            0, 0, 0, 1;

    trans_mtr *= rotateMatrix;
}

void Platform::rotateZ(double angle) {

    Eigen::Matrix4f rotateMatrix;
    rotateMatrix << cos(angle), -sin(angle), 0, 0,
            sin(angle), cos(angle), 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1;

    trans_mtr *= rotateMatrix;
}

void Platform::toCenter() {
    Point start(PLATFORM_START);

    Eigen::Matrix4f newMat;

    newMat << 1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1;
    newMat(3, 0) = CENTER_POINT_X - start.getXCoord() - getWidth() * SCALE_FACTOR / 2 - MOVECOEF;
    newMat(3, 1) = CENTER_POINT_Y - start.getYCoord() - getHeight() * SCALE_FACTOR / 2 - MOVECOEF;
    newMat(3, 2) = 0;

    trans_mtr = newMat;
}


size_t Platform::getRealModelsNum() { return real_model_num; }

size_t Platform::getModelsNum() { return models_um; }

Model &Platform::getModel(size_t num) { return models.at(num); }


const std::vector<Polygon> Model::getPolygons() { return polygons; }

void Model::setPolygons(std::vector<Polygon> polygons_) { polygons = polygons_; }

void Platform::setModel(size_t num, Model &new_model) { models.at(num) = new_model; }


void Platform::addModel(Model &model) {
    models_um++;
    models.push_back(model);

    Model::model_t modelType_ = models[models_um - 1].getModelType();

    if (modelType_ == Model::model_t::WindowsHouse ||
        modelType_ == Model::model_t::TreeTrunk ||
        modelType_ == Model::model_t::RoadStripe ||
        modelType_ == Model::model_t::GlassCar) {
        markUsedSquares(models_um - 1);
        real_model_num++;
        printUsedSquares();
    }
}

size_t Platform::getLightNum() { return light_num; }

Light &Platform::getLight(size_t num) { return lights.at(num); }

void Platform::setLight(Light &light, size_t i) { lights.at(i) = light; }

void Platform::addLight(Light &light) {
    light_num++;
    lights.push_back(light);
}

void Platform::delLight(size_t num) {
    if (num < lights.size()) {
        light_num--;
        lights.erase(lights.begin() + num);
    }
}

void Platform::deleteModel(size_t num) {
    if (num < models.size()) {
        Model::model_t modelType_ = models[num].getModelType();

        if (modelType_ == Model::model_t::WindowsHouse || \
            modelType_ == Model::model_t::TreeTrunk || \
            modelType_ == Model::model_t::RoadStripe || \
            modelType_ == Model::model_t::GlassCar) {
            clearUsedSquares(num);
            real_model_num--;
        }

        models_um--;
        models.erase(models.begin() + num);
        printUsedSquares();
    }
}


void Platform::printUsedSquares() {
    for (size_t i = 0; i < height; i++) {
        qDebug() << getUsedSquares()[i];
    }
}


Model &Platform::getPlateModel() { return *platform_model; }

void Platform::buildPlateModel(Point start_platform, Point end_platform) {
//    if (platform_model)
//        return;

    std::vector<Vertex> vertices;
    std::vector<Polygon> facets;

    for (size_t y = start_platform.getYCoord(); y < end_platform.getYCoord();
         y += SCALE_FACTOR)
        for (size_t x = start_platform.getXCoord(); x < end_platform.getXCoord();
             x += SCALE_FACTOR)
            addQuad(vertices, facets, x, y, PLATFORM_START_Z, x + SCALE_FACTOR, y, PLATFORM_START_Z,
                    x + SCALE_FACTOR, y + SCALE_FACTOR, PLATFORM_START_Z, x, y + SCALE_FACTOR, PLATFORM_START_Z);

    addQuad(vertices, facets, start_platform.getXCoord(),
            start_platform.getYCoord(), PLATFORM_START_Z - 10, start_platform.getXCoord(),
            end_platform.getYCoord() + 10, PLATFORM_START_Z - 10, end_platform.getXCoord() + 10,
            end_platform.getYCoord() + 10, PLATFORM_START_Z - 10, end_platform.getXCoord() + 10,
            start_platform.getYCoord(), PLATFORM_START_Z - 10);

    addQuad(vertices, facets, start_platform.getXCoord(),
            start_platform.getYCoord(), PLATFORM_START_Z - 10, start_platform.getXCoord(),
            end_platform.getYCoord() + 10, PLATFORM_START_Z - 10, start_platform.getXCoord(),
            end_platform.getYCoord() + 10, PLATFORM_START_Z, start_platform.getXCoord(),
            start_platform.getYCoord(), PLATFORM_START_Z);

    addQuad(vertices, facets, start_platform.getXCoord(),
            end_platform.getYCoord() + 10, PLATFORM_START_Z - 10, end_platform.getXCoord() + 10,
            end_platform.getYCoord() + 10, PLATFORM_START_Z - 10, end_platform.getXCoord() + 10,
            end_platform.getYCoord() + 10, PLATFORM_START_Z, start_platform.getXCoord(),
            end_platform.getYCoord() + 10, PLATFORM_START_Z);

    addQuad(vertices, facets, end_platform.getXCoord() + 10,
            end_platform.getYCoord() + 10, PLATFORM_START_Z - 10, end_platform.getXCoord() + 10,
            start_platform.getYCoord(), PLATFORM_START_Z - 10, end_platform.getXCoord() + 10,
            start_platform.getYCoord(), PLATFORM_START_Z, end_platform.getXCoord() + 10,
            end_platform.getYCoord() + 10, PLATFORM_START_Z);

    addQuad(vertices, facets, end_platform.getXCoord() + 10,
            start_platform.getYCoord(), PLATFORM_START_Z - 10, start_platform.getXCoord(),
            start_platform.getYCoord(), PLATFORM_START_Z - 10, start_platform.getXCoord(),
            start_platform.getYCoord(), PLATFORM_START_Z, end_platform.getXCoord() + 10,
            start_platform.getYCoord(), PLATFORM_START_Z);
    if (platform_model)
        delete platform_model;
    platform_model = new Model(vertices, facets);
}

void Platform::changeSize(size_t new_width, size_t new_height) {
    if (new_width) {
        if (new_width < width) {
            for (size_t i = 0; i < models_um; i++) {
                if (getModel(i).getUsedXSq() >= (int) new_width) {
                    deleteModel(i);
                    i--;
                }
            }
        }

        width = new_width;
    }


    if (new_height) {
        if (new_height < height) {
            for (size_t i = 0; i < models_um; i++) {
                if (getModel(i).getUsedYSq() >= (int) new_height) {
                    deleteModel(i);
                    i--;
                }
            }
        }

        height = new_height;
    }
}

Eigen::Matrix4f &Platform::getTransMtr() { return trans_mtr; }


void Platform::initUsedSquares() {
    used_squares.resize(getHeight());

    for (size_t i = 0; i < getHeight(); i++) {
        used_squares[i].resize(getWidth(), 0);
    }
}


std::vector<std::vector<size_t>> &Platform::getUsedSquares() { return used_squares; }
