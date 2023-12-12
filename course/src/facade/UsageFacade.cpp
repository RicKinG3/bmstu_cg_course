#include "UsageFacade.h"

UsageFacade::UsageFacade() { drawer = new Drawer; }

void UsageFacade::setCellScene(size_t width_, size_t height_) {
    if (scene)
        delete scene;

    scene = new Platform(width_, height_);
}

void UsageFacade::changeCellScene(size_t newWidth, size_t newheight) {
    scene->changeSize(newWidth, newheight);
}

bool UsageFacade::isSceneSet() { return scene; }

QGraphicsScene *UsageFacade::drawScene(QRectF rect) {
    QGraphicsScene *retScene = nullptr;
    if (isSceneSet())
        retScene = drawer->drawScene(scene, rect);

    return retScene;
}

QGraphicsScene *UsageFacade::moveUpScene(double value, QRectF rect) {
    scene->moveUp(value);

    return drawScene(rect);
}

QGraphicsScene *UsageFacade::moveDownScene(double value, QRectF rect) {
    scene->moveDown(value);

    return drawScene(rect);
}

QGraphicsScene *UsageFacade::moveRightScene(double value, QRectF rect) {
    scene->moveRight(value);

    return drawScene(rect);
}

QGraphicsScene *UsageFacade::moveLeftScene(double value, QRectF rect) {
    scene->moveLeft(value);

    return drawScene(rect);
}

QGraphicsScene *UsageFacade::scaleScene(double value, QRectF rect) {
    scene->scale(value);

    return drawScene(rect);
}

QGraphicsScene *UsageFacade::rotateXScene(double angle, QRectF rect) {
    scene->rotateX(angle);

    return drawScene(rect);
}

QGraphicsScene *UsageFacade::rotateYScene(double angle, QRectF rect) {
    scene->rotateY(angle);

    return drawScene(rect);
}

QGraphicsScene *UsageFacade::rotateZScene(double angle, QRectF rect) {
    scene->rotateZ(angle);

    return drawScene(rect);
}

QGraphicsScene *UsageFacade::toCenter(QRectF rect) {
    scene->toCenter();

    return drawScene(rect);
}

Platform *UsageFacade::getScene() { return scene; }


void movePointQua(int &x1, int &x2, int &x3, int &x4, int &y1, int &y2, int &y3, int &y4) {
    x1 += MOVECOEF;
    x2 += MOVECOEF;
    x3 += MOVECOEF;
    x4 += MOVECOEF;

    y1 += MOVECOEF;
    y2 += MOVECOEF;
    y3 += MOVECOEF;
    y4 += MOVECOEF;
}


void UsageFacade::addQuad(std::vector<Vertex> &vertices, std::vector<Polygon> &facets,
                          int x1, int y1, int z1, int x2, int y2, int z2,
                          int x3, int y3, int z3, int x4, int y4, int z4) {
    // перенос точек для того чтоб потом работал з алгоритм
    movePointQua(x1, x2, x3, x4, y1, y2, y3, y4);


    Point dot;
    std::vector<size_t> vec;

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


void movePointTriangle(int &x1, int &x2, int &x3, int &y1, int &y2, int &y3) {
    x1 += MOVECOEF;
    x2 += MOVECOEF;
    x3 += MOVECOEF;
    y1 += MOVECOEF;
    y2 += MOVECOEF;
    y3 += MOVECOEF;
}


void UsageFacade::addTriangle(std::vector<Vertex> &vertices, std::vector<Polygon> &facets,
                              int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3) {
    Point dot;
    std::vector<size_t> vec;

    movePointTriangle(x1, x2, x3, y1, y2, y3);

    size_t size = facets.size();

    dot = Point(x1, y1, z1);
    vec = {size};
    vertices.push_back(Vertex(dot, vec));

    dot = Point(x2, y2, z2);
    vec = {size};
    vertices.push_back(Vertex(dot, vec));

    dot = Point(x3, y3, z3);
    vec = {size};
    vertices.push_back(Vertex(dot, vec));

    size = vertices.size();
    vec = {size - 3, size - 2, size - 1};
    facets.push_back(vec);
}

void UsageFacade::addLight(int xAngle, int yAngle) {
    // Создание матрицы трансформации для поворота вокруг оси X
    Eigen::Matrix4f transMatX;
    // из град в радианы
    double radianXAngle = (double) xAngle * M_PI / 180.0;
    transMatX << 1, 0, 0, 0,
            0, cos(radianXAngle), -sin(radianXAngle), 0,
            0, sin(radianXAngle), cos(radianXAngle), 0,
            0, 0, 0, 1;

    // Создание матрицы трансформации для поворота вокруг оси Y
    Eigen::Matrix4f transMatY;
    double radianYAngle = (double) yAngle * M_PI / 180.0;
    transMatY << cos(radianYAngle), 0, sin(radianYAngle), 0,
            0, 1, 0, 0,
            -sin(radianYAngle), 0, cos(radianYAngle), 0,
            0, 0, 0, 1;

    // Умножение матриц трансформации
    Eigen::Matrix4f transMat = transMatX * transMatY;

    // Создание объекта light с использованием полученной матрицы трансформации
    Light illum(transMat);
    illum.setAngles(xAngle, yAngle);

    // Добавление источника света в сцену
    scene->addLight(illum);
}


bool UsageFacade::searchRoadsNearby(int x_sq, int y_sq, int widthModel, int heightModel) {
    for (int k = 0; k < 2; k++) {
        int i = y_sq - 1 + k * (heightModel + 1);
        if (i < 0 || size_t(i) > scene->getHeight() - 1)
            continue;

        int j0 = x_sq - 1;
        if (j0 >= 0) {
            if (scene->getUsedSquares()[i][j0] == 2 || scene->getUsedSquares()[i][j0] == 4) {
                qDebug() << "i = " << i << "j = " << j0 << "дорога рядом с домом";
                return true;
            }
        }

        j0 = x_sq + widthModel;
        if (size_t(j0) <= scene->getWidth() - 1) {
            if (scene->getUsedSquares()[i][j0] == 2 || scene->getUsedSquares()[i][j0] == 4) {
                qDebug() << "i = " << i << "j = " << j0 << "дорога рядом с домом";
                return true;
            }
        }

        for (int j = x_sq; j < x_sq + widthModel; j++) {
            if (scene->getUsedSquares()[i][j] == 2 || scene->getUsedSquares()[i][j] == 4) {
                qDebug() << "i = " << i << "j = " << j << "дорога рядом с домом";
                return true;
            }
        }
    }

    for (int k = 0; k < 2; k++) {
        int j = x_sq - 1 + k * (widthModel + 1);
        if (j < 0 || size_t(j) > scene->getWidth() - 1)
            continue;

        for (int i = y_sq; i < y_sq + heightModel; i++) {
            if (scene->getUsedSquares()[i][j] == 2 || scene->getUsedSquares()[i][j] == 4) {
                qDebug() << "i = " << i << "j = " << j << "дорога рядом с домом";
                return true;
            }
        }
    }

    return false;
}

int UsageFacade::addPickup(int x_sq, int y_sq, Direction direction, ColorCar color_car) {
    int modelLength, modelHeight;
    if (direction == Horizontal) {
        modelHeight = 1;
        modelLength = 3; // Увеличиваем длину для пикапа
    }
    else {
        modelHeight = 3; // Увеличиваем длину для пикапа
        modelLength = 1;
    }

    x_sq -= 1;
    y_sq -= 1;

    if (x_sq + modelLength - 1 >= (int) scene->getWidth() ||
        y_sq + modelHeight - 1 >= (int) scene->getHeight())
        return 2;

    for (int i = y_sq; i < y_sq + modelHeight; i++) {
        for (int j = x_sq; j < x_sq + modelLength; j++) {
            if (scene->getUsedSquares()[i][j] != 2) {
                qDebug() << "i = " << i << "j = " << j << "нет дороги (пикап)";
                return 3;
            }
        }
    }

    std::vector<Vertex> vertices;
    std::vector<Polygon> facets;

    int xFactor = x_sq * SCALE_FACTOR + 10;
    int yFactor = y_sq * SCALE_FACTOR + 10 - MOVECOEF * 2;
    int zFactor = PLATFORM_START_Z + SCALE_FACTOR / 16;

    // Передняя часть кабины
    addQuad(vertices, facets,
            xFactor, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor, yFactor + SCALE_FACTOR * 5 / 6, zFactor);

// Задняя часть кабины
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR * 5 / 6, zFactor);

// Боковые стороны кабины
    addQuad(vertices, facets,
            xFactor, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 2,
            xFactor, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 2,
            xFactor, yFactor + SCALE_FACTOR * 5 / 6, zFactor);

    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 2,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 2,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR * 5 / 6, zFactor);

// Верх кабины
    addQuad(vertices, facets,
            xFactor, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 2,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 2,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 2,
            xFactor, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 2);

    // Грузовая платформа
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 2.5, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 2.5, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR * 5 / 6, zFactor);

    // Бампер
    addQuad(vertices, facets,
            xFactor, yFactor, zFactor,
            xFactor + SCALE_FACTOR * 1.5, yFactor, zFactor,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor, yFactor + SCALE_FACTOR / 6, zFactor);

// Задний бампер
    addQuad(vertices, facets,
            xFactor, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR * 1.5, yFactor + SCALE_FACTOR, zFactor,
            xFactor, yFactor + SCALE_FACTOR, zFactor);

// Ручки дверей
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR / 2, zFactor + SCALE_FACTOR / 4,
            xFactor + SCALE_FACTOR / 3, yFactor + SCALE_FACTOR / 2, zFactor + SCALE_FACTOR / 4,
            xFactor + SCALE_FACTOR / 3, yFactor + SCALE_FACTOR / 2, zFactor + SCALE_FACTOR / 3,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR / 2, zFactor + SCALE_FACTOR / 3);

// Окна
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR / 8, yFactor + SCALE_FACTOR / 4, zFactor + SCALE_FACTOR / 3,
            xFactor + SCALE_FACTOR * 3 / 8, yFactor + SCALE_FACTOR / 4, zFactor + SCALE_FACTOR / 3,
            xFactor + SCALE_FACTOR * 3 / 8, yFactor + SCALE_FACTOR * 3 / 4, zFactor + SCALE_FACTOR / 3,
            xFactor + SCALE_FACTOR / 8, yFactor + SCALE_FACTOR * 3 / 4, zFactor + SCALE_FACTOR / 3);


    Model pickupModel(vertices, facets, "Пикап");
    pickupModel.setUsedSquare(x_sq, y_sq);
    pickupModel.setHeightModel(modelHeight);
    pickupModel.setWidthModel(modelLength);
    pickupModel.setDirectionCar(direction);
    pickupModel.setModelType(Model::Pickup);
    pickupModel.setModelNum(scene->getRealModelsNum());

    if (modelLength == 1)
        pickupModel.rotateZ(-90);

    scene->addModel(pickupModel);

    // Добавление колёс и стёкол
    // ...

    return 0;
}


int UsageFacade::addHouse(int x_sq, int y_sq, int modelLength, int modelHeight, int countFloors) {
    x_sq -= 1;
    y_sq -= 1;

    if (x_sq + modelLength - 1 >= (int) scene->getWidth() || \
        y_sq + modelHeight - 1 >= (int) scene->getHeight())
        return 2;

    for (int i = y_sq; i < y_sq + modelHeight; i++) {
        for (int j = x_sq; j < x_sq + modelLength; j++) {
            if (scene->getUsedSquares()[i][j] != 0 && scene->getUsedSquares()[i][j] != 3) {
                qDebug() << "i = " << i << "j = " << j << "ячейка занята (дом)";
                return 1;
            }
        }
    }

//    if (searchRoadsNearby(x_sq, y_sq, modelLength, modelHeight))
//        return 4;

    std::vector<Vertex> vertices;
    std::vector<Polygon> facets;

    int xFactor = x_sq * SCALE_FACTOR + 10;
    int yFactor = y_sq * SCALE_FACTOR + 10;
    int zFactor = PLATFORM_START_Z;

    //стены дома
    for (int i = 0; i < countFloors; i++) {
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < modelLength; j++) {
                addQuad(vertices, facets,
                        xFactor, yFactor, zFactor,
                        xFactor + SCALE_FACTOR, yFactor, zFactor,
                        xFactor + SCALE_FACTOR, yFactor, zFactor + SCALE_FACTOR / 3,
                        xFactor, yFactor, zFactor + SCALE_FACTOR / 3);
                addQuad(vertices, facets,
                        xFactor, yFactor, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor + SCALE_FACTOR, yFactor, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor + SCALE_FACTOR, yFactor, zFactor + SCALE_FACTOR,
                        xFactor, yFactor, zFactor + SCALE_FACTOR);
                addQuad(vertices, facets,
                        xFactor, yFactor, zFactor + SCALE_FACTOR / 3,
                        xFactor + SCALE_FACTOR / 3, yFactor, zFactor + SCALE_FACTOR / 3,
                        xFactor + SCALE_FACTOR / 3, yFactor, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor, yFactor, zFactor + SCALE_FACTOR * 2 / 3);
                addQuad(vertices, facets,
                        xFactor + SCALE_FACTOR * 2 / 3, yFactor, zFactor + SCALE_FACTOR / 3,
                        xFactor + SCALE_FACTOR, yFactor, zFactor + SCALE_FACTOR / 3,
                        xFactor + SCALE_FACTOR, yFactor, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor + SCALE_FACTOR * 2 / 3, yFactor, zFactor + SCALE_FACTOR * 2 / 3);

                xFactor += SCALE_FACTOR;
            }

            xFactor = x_sq * SCALE_FACTOR + 10;
            yFactor += SCALE_FACTOR * modelHeight;
        }

        yFactor = y_sq * SCALE_FACTOR + 10;


        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < modelHeight; j++) {
                addQuad(vertices, facets,
                        xFactor, yFactor, zFactor,
                        xFactor, yFactor + SCALE_FACTOR, zFactor,
                        xFactor, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR / 3,
                        xFactor, yFactor, zFactor + SCALE_FACTOR / 3);
                addQuad(vertices, facets,
                        xFactor, yFactor, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR,
                        xFactor, yFactor, zFactor + SCALE_FACTOR);
                addQuad(vertices, facets,
                        xFactor, yFactor, zFactor + SCALE_FACTOR / 3,
                        xFactor, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR / 3,
                        xFactor, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor, yFactor, zFactor + SCALE_FACTOR * 2 / 3);
                addQuad(vertices, facets,
                        xFactor, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR / 3,
                        xFactor, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR / 3,
                        xFactor, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 2 / 3);

                yFactor += SCALE_FACTOR;
            }

            yFactor = y_sq * SCALE_FACTOR + 10;
            xFactor += SCALE_FACTOR * modelLength;
        }

        xFactor = x_sq * SCALE_FACTOR + 10;

        zFactor += SCALE_FACTOR;
    }

    Model houseModel(vertices, facets, "Дом");
    houseModel.setUsedSquare(x_sq, y_sq);
    houseModel.setHeightModel(modelHeight);
    houseModel.setWidthModel(modelLength);
    houseModel.setHouseHeight(countFloors);
    houseModel.setModelType(Model::House);
    houseModel.setModelNum(scene->getRealModelsNum());
    scene->addModel(houseModel);

    std::vector<Vertex> vertices2;
    std::vector<Polygon> facets2;

    //крыша дома
    addTriangle(vertices2, facets2,
                xFactor + modelLength * SCALE_FACTOR, yFactor + modelHeight * SCALE_FACTOR, zFactor,
                xFactor + modelLength * SCALE_FACTOR, yFactor, zFactor,
                xFactor + modelLength * SCALE_FACTOR * 2 / 3, yFactor + modelHeight * SCALE_FACTOR / 2,
                zFactor + SCALE_FACTOR);
    addTriangle(vertices2, facets2,
                xFactor, yFactor + modelHeight * SCALE_FACTOR, zFactor,
                xFactor, yFactor, zFactor,
                xFactor + modelLength * SCALE_FACTOR / 3, yFactor + modelHeight * SCALE_FACTOR / 2,
                zFactor + SCALE_FACTOR);
    addTriangle(vertices2, facets2,
                xFactor + modelLength * SCALE_FACTOR * 2 / 3, yFactor, zFactor,
                xFactor + modelLength * SCALE_FACTOR, yFactor, zFactor,
                xFactor + modelLength * SCALE_FACTOR * 2 / 3, yFactor + modelHeight * SCALE_FACTOR / 2,
                zFactor + SCALE_FACTOR);
    addTriangle(vertices2, facets2,
                xFactor + modelLength * SCALE_FACTOR, yFactor + modelHeight * SCALE_FACTOR, zFactor,
                xFactor + modelLength * SCALE_FACTOR * 2 / 3, yFactor + modelHeight * SCALE_FACTOR, zFactor,
                xFactor + modelLength * SCALE_FACTOR * 2 / 3, yFactor + modelHeight * SCALE_FACTOR / 2,
                zFactor + SCALE_FACTOR);
    addTriangle(vertices2, facets2,
                xFactor + modelLength * SCALE_FACTOR / 3, yFactor, zFactor,
                xFactor, yFactor, zFactor,
                xFactor + modelLength * SCALE_FACTOR / 3, yFactor + modelHeight * SCALE_FACTOR / 2,
                zFactor + SCALE_FACTOR);
    addTriangle(vertices2, facets2,
                xFactor, yFactor + modelHeight * SCALE_FACTOR, zFactor,
                xFactor + modelLength * SCALE_FACTOR / 3, yFactor + modelHeight * SCALE_FACTOR, zFactor,
                xFactor + modelLength * SCALE_FACTOR / 3, yFactor + modelHeight * SCALE_FACTOR / 2,
                zFactor + SCALE_FACTOR);


    addQuad(vertices2, facets2,
            xFactor + modelLength * SCALE_FACTOR / 3, yFactor, zFactor,
            xFactor + modelLength * SCALE_FACTOR * 2 / 3, yFactor, zFactor,
            xFactor + modelLength * SCALE_FACTOR * 2 / 3, yFactor + modelHeight * SCALE_FACTOR / 2,
            zFactor + SCALE_FACTOR,
            xFactor + modelLength * SCALE_FACTOR / 3, yFactor + modelHeight * SCALE_FACTOR / 2, zFactor + SCALE_FACTOR);
    addQuad(vertices2, facets2,
            xFactor + modelLength * SCALE_FACTOR / 3, yFactor + modelHeight * SCALE_FACTOR / 2, zFactor + SCALE_FACTOR,
            xFactor + modelLength * SCALE_FACTOR * 2 / 3, yFactor + modelHeight * SCALE_FACTOR / 2,
            zFactor + SCALE_FACTOR,
            xFactor + modelLength * SCALE_FACTOR * 2 / 3, yFactor + modelHeight * SCALE_FACTOR, zFactor,
            xFactor + modelLength * SCALE_FACTOR / 3, yFactor + modelHeight * SCALE_FACTOR, zFactor);


    Model roofHouseModel(vertices2, facets2, "Крыша дома");
    roofHouseModel.setUsedSquare(x_sq, y_sq);
    roofHouseModel.setHeightModel(modelHeight);
    roofHouseModel.setWidthModel(modelLength);
    roofHouseModel.setHouseHeight(countFloors);
    roofHouseModel.setModelType(Model::RoofHouse);
    roofHouseModel.setModelNum(scene->getRealModelsNum());
    scene->addModel(roofHouseModel);

    std::vector<Vertex> vertices3;
    std::vector<Polygon> facets3;

    xFactor = x_sq * SCALE_FACTOR + 10;
    yFactor = y_sq * SCALE_FACTOR + 10;
    zFactor = PLATFORM_START_Z;

    //окна дома
    for (int i = 0; i < countFloors; i++) {
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < modelLength; j++) {
                addQuad(vertices3, facets3,
                        xFactor + SCALE_FACTOR / 3, yFactor, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor + SCALE_FACTOR * 2 / 3, yFactor, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor + SCALE_FACTOR * 2 / 3, yFactor, zFactor + SCALE_FACTOR / 3,
                        xFactor + SCALE_FACTOR / 3, yFactor, zFactor + SCALE_FACTOR / 3);

                xFactor += SCALE_FACTOR;
            }

            xFactor = x_sq * SCALE_FACTOR + 10;
            yFactor += SCALE_FACTOR * modelHeight;
        }

        yFactor = y_sq * SCALE_FACTOR + 10;


        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < modelHeight; j++) {
                addQuad(vertices3, facets3,
                        xFactor, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR / 3,
                        xFactor, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR / 3);

                yFactor += SCALE_FACTOR;
            }

            yFactor = y_sq * SCALE_FACTOR + 10;
            xFactor += SCALE_FACTOR * modelLength;
        }

        xFactor = x_sq * SCALE_FACTOR + 10;

        zFactor += SCALE_FACTOR;
    }

    Model windowsHouseModel(vertices3, facets3, "Окна дома");
    windowsHouseModel.setUsedSquare(x_sq, y_sq);
    windowsHouseModel.setHeightModel(modelHeight);
    windowsHouseModel.setWidthModel(modelLength);
    windowsHouseModel.setHouseHeight(countFloors);
    windowsHouseModel.setModelType(Model::WindowsHouse);
    windowsHouseModel.setModelNum(scene->getRealModelsNum());
    scene->addModel(windowsHouseModel);

    return 0;
}

//todo return code 
//todo finish tut
int UsageFacade::addBush(int x_sq, int y_sq) {
    x_sq -= 1;
    y_sq -= 1;

    if (x_sq >= (int) scene->getWidth() || y_sq >= (int) scene->getHeight())
        return 2;

    if (scene->getUsedSquares()[y_sq][x_sq] != 0 && scene->getUsedSquares()[y_sq][x_sq] != 3) {
        qDebug() << "i = " << x_sq << "j = " << x_sq << "ячейка занята (куст)";
        return 1;
    }

    int xFactor = x_sq * SCALE_FACTOR + 10;
    int yFactor = y_sq * SCALE_FACTOR + 10;
    int zFactor = PLATFORM_START_Z;

    std::vector<Vertex> vertices;
    std::vector<Polygon> facets;

    int under_platform = 1;
    int up = 30;

    int second_fl = up / 2;
    int tree_fl = second_fl / 2;
    int second_up = up * 1.4;
    int tree_up = second_up * 1.4;

    // Нижняя часть куста
    addQuad(vertices, facets,
            xFactor, yFactor, zFactor + under_platform, // a
            xFactor + SCALE_FACTOR, yFactor, zFactor + under_platform, //b
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + under_platform,//c
            xFactor, yFactor + SCALE_FACTOR, zFactor + under_platform);//d
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + under_platform, //c
            xFactor, yFactor + SCALE_FACTOR, zFactor + under_platform, //d
            xFactor, yFactor + SCALE_FACTOR, (zFactor + under_platform * up),
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + under_platform * up);
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR, yFactor, zFactor + under_platform, //b
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + under_platform, //c
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + under_platform * up,
            xFactor + SCALE_FACTOR, yFactor, zFactor + under_platform * up);
    addQuad(vertices, facets,
            xFactor, yFactor, zFactor + under_platform, // a
            xFactor + SCALE_FACTOR, yFactor, zFactor + under_platform,//b
            xFactor + SCALE_FACTOR, yFactor, zFactor + under_platform * up,
            xFactor, yFactor, zFactor + under_platform * up);
    addQuad(vertices, facets,
            xFactor, yFactor + SCALE_FACTOR, zFactor + under_platform, // d
            xFactor, yFactor, zFactor + under_platform, // a
            xFactor, yFactor, zFactor + under_platform * up,
            xFactor, yFactor + SCALE_FACTOR, zFactor + under_platform * up
    );
    addQuad(vertices, facets,
            xFactor, yFactor, zFactor + under_platform * up, // a
            xFactor + SCALE_FACTOR, yFactor, zFactor + under_platform * up, //b
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + under_platform * up,//c
            xFactor, yFactor + SCALE_FACTOR, zFactor + under_platform * up);//d
    // вторая часть куста
    addQuad(vertices, facets,
            xFactor + second_fl, yFactor + second_fl, zFactor + under_platform * up, // a
            xFactor + SCALE_FACTOR - second_fl, yFactor + second_fl, zFactor + under_platform * up, //b
            xFactor + SCALE_FACTOR - second_fl, yFactor - second_fl + SCALE_FACTOR, zFactor + under_platform * up,//c
            xFactor + second_fl, yFactor + SCALE_FACTOR - second_fl, zFactor + under_platform * up);//d

    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR - second_fl, yFactor + SCALE_FACTOR - second_fl, zFactor + under_platform * up, //c
            xFactor + second_fl, yFactor + SCALE_FACTOR - second_fl, zFactor + under_platform * up, //d
            xFactor + second_fl, yFactor + SCALE_FACTOR - second_fl, (zFactor + under_platform * second_up),
            xFactor + SCALE_FACTOR - second_fl, yFactor + SCALE_FACTOR - second_fl,
            zFactor + under_platform * second_up);
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR - second_fl, yFactor + second_fl, zFactor + under_platform * up, //b
            xFactor + SCALE_FACTOR - second_fl, yFactor + SCALE_FACTOR - second_fl, zFactor + under_platform * up, //c
            xFactor + SCALE_FACTOR - second_fl, yFactor + SCALE_FACTOR - second_fl,
            zFactor + under_platform * second_up,
            xFactor + SCALE_FACTOR - second_fl, yFactor + second_fl, zFactor + under_platform * second_up);
    addQuad(vertices, facets,
            xFactor + second_fl, yFactor + second_fl, zFactor + under_platform * up, // a
            xFactor + SCALE_FACTOR - second_fl, yFactor + second_fl, zFactor + under_platform * up,//b
            xFactor + SCALE_FACTOR - second_fl, yFactor + second_fl, zFactor + under_platform * second_up,
            xFactor + second_fl, yFactor + second_fl, zFactor + under_platform * second_up);
    addQuad(vertices, facets,
            xFactor + second_fl, yFactor - second_fl + SCALE_FACTOR, zFactor + under_platform * up, // d
            xFactor + second_fl, yFactor + second_fl, zFactor + under_platform * up, // a
            xFactor + second_fl, yFactor + second_fl, zFactor + under_platform * second_up,
            xFactor + second_fl, yFactor + SCALE_FACTOR - second_fl, zFactor + under_platform * second_up
    );
    addQuad(vertices, facets,
            xFactor + second_fl, yFactor + second_fl, zFactor + under_platform * second_up, // a
            xFactor + SCALE_FACTOR - second_fl, yFactor + second_fl, zFactor + under_platform * second_up, //b
            xFactor + SCALE_FACTOR - second_fl, yFactor - second_fl + SCALE_FACTOR,
            zFactor + under_platform * second_up,//c
            xFactor + second_fl, yFactor + SCALE_FACTOR - second_fl, zFactor + under_platform * second_up);//d
    // третья часть куста
    addQuad(vertices, facets,
            xFactor + tree_up, yFactor + tree_up, zFactor + under_platform * second_up, // a
            xFactor + SCALE_FACTOR - tree_up, yFactor + tree_up, zFactor + under_platform * second_up, //b
            xFactor + SCALE_FACTOR - tree_up, yFactor - tree_up + SCALE_FACTOR, zFactor + under_platform * second_up,//c
            xFactor + tree_up, yFactor + SCALE_FACTOR - tree_up, zFactor + under_platform * second_up);//d

    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR - tree_up, yFactor + SCALE_FACTOR - tree_up,
            zFactor + under_platform * second_up, //c
            xFactor + tree_up, yFactor + SCALE_FACTOR - tree_up, zFactor + under_platform * second_up, //d
            xFactor + tree_up, yFactor + SCALE_FACTOR - tree_up, (zFactor + under_platform * tree_up),
            xFactor + SCALE_FACTOR - tree_up, yFactor + SCALE_FACTOR - tree_up,
            zFactor + under_platform * tree_up);
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR - tree_up, yFactor + tree_up, zFactor + under_platform * second_up, //b
            xFactor + SCALE_FACTOR - tree_up, yFactor + SCALE_FACTOR - tree_up,
            zFactor + under_platform * second_up, //c
            xFactor + SCALE_FACTOR - tree_up, yFactor + SCALE_FACTOR - tree_up,
            zFactor + under_platform * tree_up,
            xFactor + SCALE_FACTOR - tree_up, yFactor + tree_up, zFactor + under_platform * tree_up);
    addQuad(vertices, facets,
            xFactor + tree_up, yFactor + tree_up, zFactor + under_platform * second_up, // a
            xFactor + SCALE_FACTOR - tree_up, yFactor + tree_up, zFactor + under_platform * second_up,//b
            xFactor + SCALE_FACTOR - tree_up, yFactor + tree_up, zFactor + under_platform * tree_up,
            xFactor + tree_up, yFactor + tree_up, zFactor + under_platform * tree_up);
    addQuad(vertices, facets,
            xFactor + tree_up, yFactor - tree_up + SCALE_FACTOR, zFactor + under_platform * second_up, // d
            xFactor + tree_up, yFactor + tree_up, zFactor + under_platform * second_up, // a
            xFactor + tree_up, yFactor + tree_up, zFactor + under_platform * tree_up,
            xFactor + tree_up, yFactor + SCALE_FACTOR - tree_up, zFactor + under_platform * tree_up
    );
    addQuad(vertices, facets,
            xFactor + tree_up, yFactor + tree_up, zFactor + under_platform * tree_up, // a
            xFactor + SCALE_FACTOR - tree_up, yFactor + tree_up, zFactor + under_platform * tree_up, //b
            xFactor + SCALE_FACTOR - tree_up, yFactor - tree_up + SCALE_FACTOR, zFactor + under_platform * tree_up,//c
            xFactor + tree_up, yFactor + SCALE_FACTOR - tree_up, zFactor + under_platform * tree_up);//d

    Model bush_model(vertices, facets, "Куст");
    bush_model.setUsedSquare(x_sq, y_sq);
    bush_model.setHeightModel(1);
    bush_model.setWidthModel(1);
    bush_model.setModelType(Model::Bush);
    bush_model.setModelNum(scene->getRealModelsNum());
    scene->addModel(bush_model);

    return 0;
}

int UsageFacade::addTree(int x_sq, int y_sq) {
    x_sq -= 1;
    y_sq -= 1;

    if (x_sq >= (int) scene->getWidth() || y_sq >= (int) scene->getHeight())
        return 2;

    if (scene->getUsedSquares()[y_sq][x_sq] != 0 && scene->getUsedSquares()[y_sq][x_sq] != 3) {
        qDebug() << "i = " << x_sq << "j = " << x_sq << "ячейка занята (дерево)";
        return 1;
    }

    int xFactor = x_sq * SCALE_FACTOR + 10;
    int yFactor = y_sq * SCALE_FACTOR + 10;
    int zFactor = PLATFORM_START_Z;

    std::vector<Vertex> vertices2;
    std::vector<Polygon> facets2;

    //нижняя часть листвы дерева
    addQuad(vertices2, facets2,
            xFactor, yFactor, zFactor + SCALE_FACTOR,
            xFactor + SCALE_FACTOR, yFactor, zFactor + SCALE_FACTOR,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR,
            xFactor, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR);

    addQuad(vertices2, facets2,
            xFactor, yFactor, zFactor + SCALE_FACTOR,
            xFactor + SCALE_FACTOR, yFactor, zFactor + SCALE_FACTOR,
            xFactor + SCALE_FACTOR, yFactor, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor, yFactor, zFactor + SCALE_FACTOR * 3 / 2);
    addQuad(vertices2, facets2,
            xFactor, yFactor, zFactor + SCALE_FACTOR,
            xFactor, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR,
            xFactor, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor, yFactor, zFactor + SCALE_FACTOR * 3 / 2);
    addQuad(vertices2, facets2,
            xFactor + SCALE_FACTOR, yFactor, zFactor + SCALE_FACTOR,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR, yFactor, zFactor + SCALE_FACTOR * 3 / 2);
    addQuad(vertices2, facets2,
            xFactor, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 3 / 2);

    addQuad(vertices2, facets2,
            xFactor, yFactor, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR, yFactor, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 3 / 2);

    //верхняя часть листвы дерева (вдоль Ox)
    addQuad(vertices2, facets2,
            xFactor, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 2,
            xFactor, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 2);
    addQuad(vertices2, facets2,
            xFactor, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 2,
            xFactor, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 2);
    addQuad(vertices2, facets2,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 2,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 2);
    addQuad(vertices2, facets2,
            xFactor, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 2,
            xFactor, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 2);

    addQuad(vertices2, facets2,
            xFactor, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 2,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 2,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 2,
            xFactor, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 2);

    //верхняя часть листвы дерева (вдоль Oy)
    addQuad(vertices2, facets2,
            xFactor + SCALE_FACTOR / 3, yFactor, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR * 2 / 3, yFactor, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR * 2 / 3, yFactor, zFactor + SCALE_FACTOR * 2,
            xFactor + SCALE_FACTOR / 3, yFactor, zFactor + SCALE_FACTOR * 2);
    addQuad(vertices2, facets2,
            xFactor + SCALE_FACTOR / 3, yFactor, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR / 3, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR / 3, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 2,
            xFactor + SCALE_FACTOR / 3, yFactor, zFactor + SCALE_FACTOR * 2);
    addQuad(vertices2, facets2,
            xFactor + SCALE_FACTOR * 2 / 3, yFactor, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR * 2 / 3, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR * 2 / 3, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 2,
            xFactor + SCALE_FACTOR * 2 / 3, yFactor, zFactor + SCALE_FACTOR * 2);
    addQuad(vertices2, facets2,
            xFactor + SCALE_FACTOR / 3, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR * 2 / 3, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 3 / 2,
            xFactor + SCALE_FACTOR * 2 / 3, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 2,
            xFactor + SCALE_FACTOR / 3, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 2);

    addQuad(vertices2, facets2,
            xFactor + SCALE_FACTOR / 3, yFactor, zFactor + SCALE_FACTOR * 2,
            xFactor + SCALE_FACTOR * 2 / 3, yFactor, zFactor + SCALE_FACTOR * 2,
            xFactor + SCALE_FACTOR * 2 / 3, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 2,
            xFactor + SCALE_FACTOR / 3, yFactor + SCALE_FACTOR, zFactor + SCALE_FACTOR * 2);

    Model treeFoliageModel(vertices2, facets2, "Дерево");
    treeFoliageModel.setUsedSquare(x_sq, y_sq);
    treeFoliageModel.setHeightModel(1);
    treeFoliageModel.setWidthModel(1);
    treeFoliageModel.setModelType(Model::TreeFoliage);
    treeFoliageModel.setModelNum(scene->getRealModelsNum());
    scene->addModel(treeFoliageModel);


    std::vector<Vertex> vertices;
    std::vector<Polygon> facets;


    //ствол дерева
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR * 2 / 5, yFactor + SCALE_FACTOR * 2 / 5, zFactor,
            xFactor + SCALE_FACTOR * 3 / 5, yFactor + SCALE_FACTOR * 2 / 5, zFactor,
            xFactor + SCALE_FACTOR * 3 / 5, yFactor + SCALE_FACTOR * 2 / 5, zFactor + SCALE_FACTOR,
            xFactor + SCALE_FACTOR * 2 / 5, yFactor + SCALE_FACTOR * 2 / 5, zFactor + SCALE_FACTOR);
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR * 2 / 5, yFactor + SCALE_FACTOR * 2 / 5, zFactor,
            xFactor + SCALE_FACTOR * 2 / 5, yFactor + SCALE_FACTOR * 3 / 5, zFactor,
            xFactor + SCALE_FACTOR * 2 / 5, yFactor + SCALE_FACTOR * 3 / 5, zFactor + SCALE_FACTOR,
            xFactor + SCALE_FACTOR * 2 / 5, yFactor + SCALE_FACTOR * 2 / 5, zFactor + SCALE_FACTOR);
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR * 3 / 5, yFactor + SCALE_FACTOR * 2 / 5, zFactor,
            xFactor + SCALE_FACTOR * 3 / 5, yFactor + SCALE_FACTOR * 3 / 5, zFactor,
            xFactor + SCALE_FACTOR * 3 / 5, yFactor + SCALE_FACTOR * 3 / 5, zFactor + SCALE_FACTOR,
            xFactor + SCALE_FACTOR * 3 / 5, yFactor + SCALE_FACTOR * 2 / 5, zFactor + SCALE_FACTOR);
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR * 2 / 5, yFactor + SCALE_FACTOR * 3 / 5, zFactor,
            xFactor + SCALE_FACTOR * 3 / 5, yFactor + SCALE_FACTOR * 3 / 5, zFactor,
            xFactor + SCALE_FACTOR * 3 / 5, yFactor + SCALE_FACTOR * 3 / 5, zFactor + SCALE_FACTOR,
            xFactor + SCALE_FACTOR * 2 / 5, yFactor + SCALE_FACTOR * 3 / 5, zFactor + SCALE_FACTOR);

    Model treeTrunkModel(vertices, facets, "Ствол дерева");
    treeTrunkModel.setUsedSquare(x_sq, y_sq);
    treeTrunkModel.setHeightModel(1);
    treeTrunkModel.setWidthModel(1);
    treeTrunkModel.setModelType(Model::TreeTrunk);
    treeTrunkModel.setModelNum(scene->getRealModelsNum());
    scene->addModel(treeTrunkModel);

    return 0;
}


int UsageFacade::addRoad(int x_sq, int y_sq, Direction direction) {
    x_sq -= 1;
    y_sq -= 1;

    if (x_sq >= (int) scene->getWidth() || y_sq >= (int) scene->getHeight())
        return obj_over_range;

//    if (scene->getUsedSquares()[y_sq][x_sq] == 3) {
//        qDebug() << "i = " << x_sq << "j = " << x_sq << "ячейка рядом с домом (дорога)";
//        return 4;
//    }
    if (scene->getUsedSquares()[y_sq][x_sq] != 0) {
        qDebug() << "i = " << x_sq << "j = " << x_sq << "ячейка занята (дорога)";
        return sq_full;
    }


    std::vector<Vertex> vertices;
    std::vector<Polygon> facets;

    int xFactor = x_sq * SCALE_FACTOR + 10;
    int yFactor = y_sq * SCALE_FACTOR + 10;
    int zFactor = PLATFORM_START_Z;

    //асфальт
    int up = 1;
    addQuad(vertices, facets,
            xFactor, yFactor, zFactor + up,
            xFactor + SCALE_FACTOR, yFactor, zFactor + up,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + up,
            xFactor, yFactor + SCALE_FACTOR, zFactor + up);

    Model roadAsphaltModel(vertices, facets, "Дорога");
    roadAsphaltModel.setUsedSquare(x_sq, y_sq);
    roadAsphaltModel.setHeightModel(1);
    roadAsphaltModel.setWidthModel(1);
    roadAsphaltModel.setDirectionRoad(direction);
    roadAsphaltModel.setModelType(Model::RoadAsphalt);
    roadAsphaltModel.setModelNum(scene->getRealModelsNum());
    scene->addModel(roadAsphaltModel);

    std::vector<Vertex> vertices2;
    std::vector<Polygon> facets2;

    // Полосы дороги
    if (direction == Horizontal) {
        // Добавляем полосы по обеим сторонам горизонтальной дороги
        for (int i = 0; i < 2; ++i) {
            double yOffset = (i == 0) ? SCALE_FACTOR / 10 : SCALE_FACTOR * 9 / 10;
            addQuad(vertices2, facets2,
                    xFactor, yFactor + yOffset, zFactor + 2,
                    xFactor + SCALE_FACTOR, yFactor + yOffset, zFactor + 2,
                    xFactor + SCALE_FACTOR, yFactor + yOffset + SCALE_FACTOR / 20, zFactor + 2,
                    xFactor, yFactor + yOffset + SCALE_FACTOR / 20, zFactor + 2);
        }
    }
    else {
        // Добавляем полосы по обеим сторонам вертикальной дороги
        for (int i = 0; i < 2; ++i) {
            double xOffset = (i == 0) ? SCALE_FACTOR / 10 : SCALE_FACTOR * 9 / 10;
            addQuad(vertices2, facets2,
                    xFactor + xOffset, yFactor, zFactor + 2,
                    xFactor + xOffset + SCALE_FACTOR / 20, yFactor, zFactor + 2,
                    xFactor + xOffset + SCALE_FACTOR / 20, yFactor + SCALE_FACTOR, zFactor + 2,
                    xFactor + xOffset, yFactor + SCALE_FACTOR, zFactor + 2);
        }
    }

    Model roadStripeModel(vertices2, facets2, "Полоса дороги");
    roadStripeModel.setUsedSquare(x_sq, y_sq);
    roadStripeModel.setHeightModel(1);
    roadStripeModel.setWidthModel(1);
    roadStripeModel.setDirectionRoad(direction);
    roadStripeModel.setModelType(Model::RoadStripe);
    roadStripeModel.setModelNum(scene->getRealModelsNum());
    scene->addModel(roadStripeModel);

    return 0;
}


int UsageFacade::addSidewalk(int x_sq, int y_sq, Direction direction) {
    x_sq -= 1;
    y_sq -= 1;

    if (x_sq >= (int) scene->getWidth() || y_sq >= (int) scene->getHeight())
        return obj_over_range;

//    if (scene->getUsedSquares()[y_sq][x_sq] == 3) {
//    if (scene->getUsedSquares()[y_sq][x_sq] == 3) {
//        qDebug() << "i = " << x_sq << "j = " << x_sq << "ячейка рядом с домом (дорога)";
//        return 4;
//    }
    if (scene->getUsedSquares()[y_sq][x_sq] != 0) {
        qDebug() << "i = " << x_sq << "j = " << x_sq << "ячейка занята (дорога)";
        return sq_full;
    }


    std::vector<Vertex> vertices;
    std::vector<Polygon> facets;

    int xFactor = x_sq * SCALE_FACTOR + 10;
    int yFactor = y_sq * SCALE_FACTOR + 10;
    int zFactor = PLATFORM_START_Z;

    //асфальт

    int up = 1;
    addQuad(vertices, facets,
            xFactor, yFactor, zFactor + up,
            xFactor + SCALE_FACTOR, yFactor, zFactor + up,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + up,
            xFactor, yFactor + SCALE_FACTOR, zFactor + up);


    Model sidewalk_model(vertices, facets, "Тротуар");
    sidewalk_model.setUsedSquare(x_sq, y_sq);
    sidewalk_model.setHeightModel(1);
    sidewalk_model.setWidthModel(1);
    sidewalk_model.setDirectionSidewalk(direction);
    sidewalk_model.setModelType(Model::Sidewalk);
    sidewalk_model.setModelNum(scene->getRealModelsNum());
    scene->addModel(sidewalk_model);


    std::vector<Vertex> vertices2;
    std::vector<Polygon> facets2;
    float y_offset_far = 0.25;
    int koef_blizko = 20;
    float y_offset_near = SCALE_FACTOR - SCALE_FACTOR / koef_blizko;

    int under = 2;
    float up_under = under + 2;

    // бардюры
    if (direction == Horizontal) {
        for (int i = 0; i < 2; ++i) {
            double yOffset = (i == 0) ? y_offset_far : y_offset_near;

            addQuad(vertices2, facets2,
                    xFactor, yFactor + yOffset, zFactor + under, //a
                    xFactor + SCALE_FACTOR, yFactor + yOffset, zFactor + under,//b
                    xFactor + SCALE_FACTOR, yFactor + yOffset + SCALE_FACTOR / koef_blizko, zFactor + under,//c
                    xFactor, yFactor + yOffset + SCALE_FACTOR / koef_blizko, zFactor + under); // d
            addQuad(vertices2, facets2,
                    xFactor, yFactor + yOffset, zFactor + under, // a
                    xFactor + SCALE_FACTOR, yFactor + yOffset, zFactor + under, // b
                    xFactor + SCALE_FACTOR, yFactor + yOffset, zFactor + up_under,
                    xFactor, yFactor + yOffset, zFactor + up_under);
            addQuad(vertices2, facets2,
                    xFactor + SCALE_FACTOR, yFactor + yOffset + SCALE_FACTOR / koef_blizko, zFactor + under, //c
                    xFactor, yFactor + yOffset + SCALE_FACTOR / koef_blizko, zFactor + under, // d
                    xFactor, yFactor + yOffset + SCALE_FACTOR / koef_blizko, zFactor + up_under,
                    xFactor + SCALE_FACTOR, yFactor + yOffset + SCALE_FACTOR / koef_blizko, zFactor + up_under);
            addQuad(vertices2, facets2,
                    xFactor, yFactor + yOffset, zFactor + under, // a
                    xFactor, yFactor + yOffset + SCALE_FACTOR / koef_blizko, zFactor + under, //d
                    xFactor, yFactor + yOffset + SCALE_FACTOR / koef_blizko, zFactor + up_under,
                    xFactor, yFactor + yOffset, zFactor + up_under); //
            addQuad(vertices2, facets2,
                    xFactor + SCALE_FACTOR, yFactor + yOffset, zFactor + under,//b
                    xFactor + SCALE_FACTOR, yFactor + yOffset + SCALE_FACTOR / koef_blizko, zFactor + under,//c
                    xFactor + SCALE_FACTOR, yFactor + yOffset + SCALE_FACTOR / koef_blizko, zFactor + up_under,
                    xFactor + SCALE_FACTOR, yFactor + yOffset, zFactor + up_under);
            addQuad(vertices2, facets2,
                    xFactor, yFactor + yOffset, zFactor + up_under, //a
                    xFactor + SCALE_FACTOR, yFactor + yOffset, zFactor + up_under,//b
                    xFactor + SCALE_FACTOR, yFactor + yOffset + SCALE_FACTOR / koef_blizko, zFactor + up_under,//c
                    xFactor, yFactor + yOffset + SCALE_FACTOR / koef_blizko, zFactor + up_under); // d
        }
    }
    else {
        // Добавляем полосы по обеим сторонам вертикальной дороги
        for (int i = 0; i < 2; ++i) {
            double xOffset = (i == 0) ? y_offset_far : y_offset_near;


            addQuad(vertices2, facets2,
                    xFactor + xOffset, yFactor, zFactor + under, //a
                    xFactor + SCALE_FACTOR / koef_blizko + xOffset, yFactor, zFactor + under,//b
                    xFactor + SCALE_FACTOR / koef_blizko + xOffset, yFactor + SCALE_FACTOR, zFactor + under,//c
                    xFactor + xOffset, yFactor + SCALE_FACTOR, zFactor + under); // d
            addQuad(vertices2, facets2,
                    xFactor + xOffset, yFactor, zFactor + under, //a
                    xFactor + SCALE_FACTOR / koef_blizko + xOffset, yFactor, zFactor + under,//b
                    xFactor + xOffset, yFactor, zFactor + up_under, //a
                    xFactor + SCALE_FACTOR / koef_blizko + xOffset, yFactor, zFactor + up_under);
            addQuad(vertices2, facets2,
                    xFactor + SCALE_FACTOR / koef_blizko + xOffset, yFactor + SCALE_FACTOR, zFactor + under,//c
                    xFactor + xOffset, yFactor + SCALE_FACTOR, zFactor + under, // d
                    xFactor + SCALE_FACTOR / koef_blizko + xOffset, yFactor + SCALE_FACTOR, zFactor + up_under,//c
                    xFactor + xOffset, yFactor + SCALE_FACTOR, zFactor + up_under); // d
            addQuad(vertices2, facets2,
                    xFactor + xOffset, yFactor, zFactor + under, //a
                    xFactor + xOffset, yFactor + SCALE_FACTOR, zFactor + under,// d
                    xFactor + xOffset, yFactor + SCALE_FACTOR, zFactor + up_under,// d
                    xFactor + xOffset, yFactor, zFactor + up_under); //a
            addQuad(vertices2, facets2,
                    xFactor + SCALE_FACTOR / koef_blizko + xOffset, yFactor, zFactor + under,//b
                    xFactor + SCALE_FACTOR / koef_blizko + xOffset, yFactor + SCALE_FACTOR, zFactor + under,//c
                    xFactor + SCALE_FACTOR / koef_blizko + xOffset, yFactor + SCALE_FACTOR, zFactor + up_under,//c
                    xFactor + SCALE_FACTOR / koef_blizko + xOffset, yFactor, zFactor + up_under);
            addQuad(vertices2, facets2,
                    xFactor + xOffset, yFactor, zFactor + up_under, //a
                    xFactor + SCALE_FACTOR / koef_blizko + xOffset, yFactor, zFactor + up_under,//b
                    xFactor + SCALE_FACTOR / koef_blizko + xOffset, yFactor + SCALE_FACTOR, zFactor + up_under,//c
                    xFactor + xOffset, yFactor + SCALE_FACTOR, zFactor + up_under); // d
        }
    }

    Model border_model(vertices2, facets2, "Бордюр");
    border_model.setUsedSquare(x_sq, y_sq);
    border_model.setHeightModel(1);
    border_model.setWidthModel(1);
    border_model.setDirectionSidewalk(direction);
    border_model.setModelType(Model::Baborder);
    border_model.setModelNum(scene->getRealModelsNum());
    scene->addModel(border_model);

    return 0;
}


int UsageFacade::addCar(int x_sq, int y_sq, Direction direction, ColorCar color_car) {
    int modelLength;
    int modelHeight;

    if (direction == Horizontal) {
        modelHeight = 1;
        modelLength = 2;
    }
    else {
        modelHeight = 2;
        modelLength = 1;
    }

    x_sq -= 1;
    y_sq -= 1;

    if (x_sq + modelLength - 1 >= (int) scene->getWidth() || \
        y_sq + modelHeight - 1 >= (int) scene->getHeight())
        return 2;

    for (int i = y_sq; i < y_sq + modelHeight; i++) {
        for (int j = x_sq; j < x_sq + modelLength; j++) {
            if (scene->getUsedSquares()[i][j] != 2) {
                qDebug() << "i = " << i << "j = " << j << "нет дороги (машина)";
                return 3;
            }
        }
    }


    std::vector<Vertex> vertices;
    std::vector<Polygon> facets;

    int xFactor = x_sq * SCALE_FACTOR + 10;

    int yFactor = y_sq * SCALE_FACTOR + 10;
    if (direction != Horizontal) yFactor = yFactor - MOVECOEF * 2;

    int zFactor = PLATFORM_START_Z + SCALE_FACTOR / 16;

    //рама машины
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 4, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 4, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR * 5 / 6, zFactor);
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 3,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 3,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR * 5 / 6, zFactor);
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR * 7 / 4, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 4, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 3,
            xFactor + SCALE_FACTOR * 7 / 4, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 3,
            xFactor + SCALE_FACTOR * 7 / 4, yFactor + SCALE_FACTOR * 5 / 6, zFactor);
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 4, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 4, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 3,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 3);
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 4, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 4, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 3,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 3);

    zFactor += SCALE_FACTOR / 3;

    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 4, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 4, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR / 4, yFactor + SCALE_FACTOR * 5 / 6, zFactor);

    //кузов машины
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 5,
            xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 5);
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 5,
            xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 5);

    //лобовое стекло
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 5,
            xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 5,
            xFactor + SCALE_FACTOR * 3 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR * 3 / 6, yFactor + SCALE_FACTOR / 6, zFactor);
    //заднее стекло
    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 5,
            xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 5,
            xFactor + SCALE_FACTOR * 9 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR * 9 / 6, yFactor + SCALE_FACTOR / 6, zFactor);

    // стёкла водителя
    addTriangle(vertices, facets,
                xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 5,
                xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR / 6, zFactor,
                xFactor + SCALE_FACTOR * 3 / 6, yFactor + SCALE_FACTOR / 6, zFactor);
    addTriangle(vertices, facets,
                xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 5,
                xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
                xFactor + SCALE_FACTOR * 3 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor);

    // стёкла пассажира
    addTriangle(vertices, facets,
                xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 5,
                xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR / 6, zFactor,
                xFactor + SCALE_FACTOR * 9 / 6, yFactor + SCALE_FACTOR / 6, zFactor);
    addTriangle(vertices, facets,
                xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor + SCALE_FACTOR / 5,
                xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
                xFactor + SCALE_FACTOR * 9 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor);

    //крыша машины
    zFactor += SCALE_FACTOR / 5;

    addQuad(vertices, facets,
            xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR / 6, zFactor,
            xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor,
            xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR * 5 / 6, zFactor);


    Model carModel(vertices, facets, "Машина");
    carModel.setUsedSquare(x_sq, y_sq);
    carModel.setHeightModel(modelHeight);
    carModel.setWidthModel(modelLength);
    carModel.setDirectionCar(direction);
    carModel.setModelNum(scene->getRealModelsNum());
    carModel.setModelType(Model::Car);

    if (modelLength == 1)
        carModel.rotateZ(-90);

    scene->addModel(carModel);

    std::vector<Vertex> vertices2;
    std::vector<Polygon> facets2;

    xFactor = x_sq * SCALE_FACTOR + 10;
    yFactor = y_sq * SCALE_FACTOR + 10 ;
    if (direction != Horizontal) yFactor = yFactor - MOVECOEF * 2;
    zFactor = PLATFORM_START_Z;

    //колёса машины
    for (int i = 0; i < 2; i++) {
        yFactor -= 2;

        for (int j = 0; j < 2; j++) {
            addQuad(vertices2, facets2,
                    xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR / 6, zFactor,
                    xFactor + SCALE_FACTOR * 3 / 4, yFactor + SCALE_FACTOR / 6, zFactor,
                    xFactor + SCALE_FACTOR * 3 / 4, yFactor + SCALE_FACTOR * 2 / 6, zFactor,
                    xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR * 2 / 6, zFactor);
            addQuad(vertices2, facets2,
                    xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR / 6, zFactor,
                    xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 4,
                    xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR * 2 / 6, zFactor + SCALE_FACTOR / 4,
                    xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR * 2 / 6, zFactor);
            addQuad(vertices2, facets2,
                    xFactor + SCALE_FACTOR * 3 / 4, yFactor + SCALE_FACTOR / 6, zFactor,
                    xFactor + SCALE_FACTOR * 3 / 4, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 4,
                    xFactor + SCALE_FACTOR * 3 / 4, yFactor + SCALE_FACTOR * 2 / 6, zFactor + SCALE_FACTOR / 4,
                    xFactor + SCALE_FACTOR * 3 / 4, yFactor + SCALE_FACTOR * 2 / 6, zFactor);
            addQuad(vertices2, facets2,
                    xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR / 6, zFactor,
                    xFactor + SCALE_FACTOR * 3 / 4, yFactor + SCALE_FACTOR / 6, zFactor,
                    xFactor + SCALE_FACTOR * 3 / 4, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 4,
                    xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR / 6, zFactor + SCALE_FACTOR / 4);
            addQuad(vertices2, facets2,
                    xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR * 2 / 6, zFactor,
                    xFactor + SCALE_FACTOR * 3 / 4, yFactor + SCALE_FACTOR * 2 / 6, zFactor,
                    xFactor + SCALE_FACTOR * 3 / 4, yFactor + SCALE_FACTOR * 2 / 6, zFactor + SCALE_FACTOR / 4,
                    xFactor + SCALE_FACTOR / 2, yFactor + SCALE_FACTOR * 2 / 6, zFactor + SCALE_FACTOR / 4);

            xFactor += SCALE_FACTOR * 3 / 4;
        }

        xFactor = x_sq * SCALE_FACTOR + 10;

        yFactor = y_sq * SCALE_FACTOR + 10 ;

        if (direction != Horizontal) yFactor = yFactor - MOVECOEF * 2;
        yFactor += SCALE_FACTOR / 2 + 4;
    }

    Model wheelsCarModel(vertices2, facets2, "Колёса машина");
    wheelsCarModel.setUsedSquare(x_sq, y_sq);
    wheelsCarModel.setHeightModel(modelHeight);
    wheelsCarModel.setWidthModel(modelLength);
    wheelsCarModel.setDirectionCar(direction);
    wheelsCarModel.setModelType(Model::WheelsCar);
    wheelsCarModel.setModelNum(scene->getRealModelsNum());

    if (modelLength == 1)
        wheelsCarModel.rotateZ(-90);

    scene->addModel(wheelsCarModel);

    std::vector<Vertex> vertices3;
    std::vector<Polygon> facets3;

    xFactor = x_sq * SCALE_FACTOR + 10;
    yFactor = y_sq * SCALE_FACTOR + 10;
    if (direction != Horizontal) yFactor = yFactor - MOVECOEF * 2;
    zFactor = PLATFORM_START_Z + SCALE_FACTOR * 19 / 48;

    //лобовое стекло
    addQuad(vertices3, facets3,
            xFactor + SCALE_FACTOR * 5 / 6 - 3, yFactor + SCALE_FACTOR / 6 + 5, zFactor + SCALE_FACTOR / 5 - 7 / 5,
            xFactor + SCALE_FACTOR * 5 / 6 - 3, yFactor + SCALE_FACTOR * 5 / 6 - 5, zFactor + SCALE_FACTOR / 5 - 7 / 5,
            xFactor + SCALE_FACTOR * 3 / 6 + 3, yFactor + SCALE_FACTOR * 5 / 6 - 5, zFactor + 17 / 5,
            xFactor + SCALE_FACTOR * 3 / 6 + 3, yFactor + SCALE_FACTOR / 6 + 5, zFactor + 17 / 5);
    //заднее стекло
    addQuad(vertices3, facets3,
            xFactor + SCALE_FACTOR * 7 / 6 + 3, yFactor + SCALE_FACTOR / 6 + 5, zFactor + SCALE_FACTOR / 5 - 7 / 5,
            xFactor + SCALE_FACTOR * 7 / 6 + 3, yFactor + SCALE_FACTOR * 5 / 6 - 5, zFactor + SCALE_FACTOR / 5 - 7 / 5,
            xFactor + SCALE_FACTOR * 9 / 6 - 3, yFactor + SCALE_FACTOR * 5 / 6 - 5, zFactor + 17 / 5,
            xFactor + SCALE_FACTOR * 9 / 6 - 3, yFactor + SCALE_FACTOR / 6 + 5, zFactor + 17 / 5);

    zFactor -= SCALE_FACTOR / 15;
    xFactor += SCALE_FACTOR / 15;

    // стёкла водителя
    addTriangle(vertices3, facets3,
                xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR / 6 - 1, zFactor + SCALE_FACTOR / 5,
                xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR / 6 - 1, zFactor,
                xFactor + SCALE_FACTOR * 3 / 6, yFactor + SCALE_FACTOR / 6 - 1, zFactor);
    addTriangle(vertices3, facets3,
                xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR * 5 / 6 + 1, zFactor + SCALE_FACTOR / 5,
                xFactor + SCALE_FACTOR * 5 / 6, yFactor + SCALE_FACTOR * 5 / 6 + 1, zFactor,
                xFactor + SCALE_FACTOR * 3 / 6, yFactor + SCALE_FACTOR * 5 / 6 + 1, zFactor);

    xFactor -= SCALE_FACTOR * 2 / 15;

    // стёкла пассажира
    addTriangle(vertices3, facets3,
                xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR / 6 - 1, zFactor + SCALE_FACTOR / 5,
                xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR / 6 - 1, zFactor,
                xFactor + SCALE_FACTOR * 9 / 6, yFactor + SCALE_FACTOR / 6 - 1, zFactor);
    addTriangle(vertices3, facets3,
                xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR * 5 / 6 + 1, zFactor + SCALE_FACTOR / 5,
                xFactor + SCALE_FACTOR * 7 / 6, yFactor + SCALE_FACTOR * 5 / 6 + 1, zFactor,
                xFactor + SCALE_FACTOR * 9 / 6, yFactor + SCALE_FACTOR * 5 / 6 + 1, zFactor);

    Model glassCarModel(vertices3, facets3, "Стёкла машины");
    glassCarModel.setUsedSquare(x_sq, y_sq);
    glassCarModel.setHeightModel(modelHeight);
    glassCarModel.setWidthModel(modelLength);
    glassCarModel.setDirectionCar(direction);
    glassCarModel.setModelType(Model::GlassCar);
    glassCarModel.setModelNum(scene->getRealModelsNum());

    if (modelLength == 1)
        glassCarModel.rotateZ(-90);

    scene->addModel(glassCarModel);

    return 0;
}

