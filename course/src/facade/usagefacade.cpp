#include "usagefacade.hpp"

#include "QDebug"
#include "QPen"

#include <limits>

#include "math.h"
#include "../config/config.hpp"

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

void Drawer::specBorderPut(int x, int y, double z) {
    if (x < 0 || x >= (int) depthBuffer.size() || \
        y < 0 || y >= (int) depthBuffer.at(0).size())
        return;
    if (std::fabs(z - depthBuffer.at(x).at(y)) < 1 || z > depthBuffer.at(x).at(y))
        if (x - MOVECOEF >= 0 && y - MOVECOEF >= 0)
            frameBuffer.at(x - MOVECOEF).at(y - MOVECOEF) = 3;
}

void Drawer::DDABordersForPolygon(
        int xStart, int yStart, double zStart, int xEnd, int yEnd, double zEnd) {
    if (xStart == xEnd && yStart == yEnd) {
        specBorderPut(xStart, yStart, zStart);
        return;
    }

    double deltaX = xEnd - xStart;
    double deltaY = yEnd - yStart;
    double deltaZ = zEnd - zStart;

    int trX = abs(deltaX);
    int trY = abs(deltaY);

    int length;
    if (trX > trY)
        length = trX;
    else
        length = trY;

    deltaX /= length;
    deltaY /= length;
    deltaZ /= length;

    double curX = xStart;
    double curY = yStart;
    double curZ = zStart;

    for (int i = 0; i < length; i++) {
        specBorderPut(round(curX), round(curY), curZ);
        curX += deltaX;
        curY += deltaY;
        curZ += deltaZ;
    }
}

void Drawer::interpolateRowIntoShadowMap(
        std::vector<std::vector<double>> *shadowMap, int xStart, int xEnd, double zStart, double zEnd, int curY) {
    for (int x = xStart; x <= xEnd; x++) {
        // Вычисляем значение Z для текущего X путем линейной интерполяции между zStart и zEnd
        double z = zStart + (zEnd - zStart) * (x - xStart) / (xEnd - xStart);

        // Проверяем, находится ли текущий пиксель в пределах карты теней
        if (x < 0 || x >= static_cast<int>(shadowMap->size()) ||
            curY < 0 || curY >= static_cast<int>(shadowMap->at(0).size()))
            continue;

        // Обновляем значение Z в карте теней, если оно больше текущего значения
        if (z > shadowMap->at(x).at(curY))
            shadowMap->at(x).at(curY) = z;
    }
}

// Функция для подготовки матриц трансформации
void Drawer::prepareTransformationMatrices(Eigen::Matrix4f &toCenter, Eigen::Matrix4f &backToStart) {
    // Задаем матрицу для перемещения объекта в центр координат
    toCenter << 1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            -CENTER_POINT_X, -CENTER_POINT_Y, -PLATFORM_START_Z - 5, 1;
    // Задаем матрицу для возврата объекта в исходное положение
    backToStart << 1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            CENTER_POINT_X, CENTER_POINT_Y, PLATFORM_START_Z + 5, 1;
}


// Функция для создания карты теней для 3D модели
void Drawer::generateShadowMap(std::vector<Polygon> &modelFacets, std::vector<Vertex> &modelVertices,
                               Eigen::Matrix4f &modelTransformationMatrix, Light *lightSource, size_t bufWidth,
                               size_t bufHeight) {
    // Подготовка матриц трансформации
    Eigen::Matrix4f toCenter, backToStart;
    prepareTransformationMatrices(toCenter, backToStart);
    // Массив для хранения преобразованных вершин
    std::array<Point, 3> dotsArr;
    // Получение карты теней и матрицы трансформации источника света
    std::vector<std::vector<double>> *shadowMap = &lightSource->getShadowMap();
    Eigen::Matrix4f illumMat = lightSource->getTransMtr();
    // Вычисление общей матрицы трансформации
    Eigen::Matrix4f dotTransMat = toCenter * modelTransformationMatrix * illumMat * backToStart;
    // Перебор всех граней модели
    for (size_t curFaceNum = 0; curFaceNum < modelFacets.size(); ++curFaceNum) {
        Eigen::MatrixXf coordinatesVec(3, 4);
        // Получение индексов вершин текущей грани и их преобразование
        std::vector<size_t> curDots = modelFacets.at(curFaceNum).getUsedVertices();
        for (size_t i = 0; i < 3; ++i) {
            Point vertex = modelVertices.at(curDots.at(i)).getPosition();
            dotsArr[i] = vertex;
            coordinatesVec.row(i) << vertex.getXCoord(), vertex.getYCoord(), vertex.getZCoord(), 1;
        }
        // Применение матрицы трансформации к вершинам
        coordinatesVec *= dotTransMat;
        for (size_t i = 0; i < 3; ++i) {
            dotsArr[i] = Point(coordinatesVec(i, 0), coordinatesVec(i, 1), coordinatesVec(i, 2));
        }
        // Сортировка вершин по Y-координате для последующего расчета теней
        if (dotsArr[0].getYCoord() > dotsArr[1].getYCoord())
            std::swap(dotsArr[0], dotsArr[1]);
        if (dotsArr[0].getYCoord() > dotsArr[2].getYCoord())
            std::swap(dotsArr[0], dotsArr[2]);
        if (dotsArr[1].getYCoord() > dotsArr[2].getYCoord())
            std::swap(dotsArr[1], dotsArr[2]);
        // Преобразование координат вершин в пиксели
        int x1 = round(dotsArr[0].getXCoord());
        int x2 = round(dotsArr[1].getXCoord());
        int x3 = round(dotsArr[2].getXCoord());
        // Получение Z-координат вершин
        double z1 = dotsArr[0].getZCoord();
        double z2 = dotsArr[1].getZCoord();
        double z3 = dotsArr[2].getZCoord();
        // Преобразование Y-координат вершин в пиксели
        int y1 = round(dotsArr[0].getYCoord());
        int y2 = round(dotsArr[1].getYCoord());
        int y3 = round(dotsArr[2].getYCoord());

#pragma omp parallel for
        // Используется OpenMP для распараллеливания цикла for по разным потокам, ускоряя вычисления
        for (int curY = (y1 < 0) ? 0 : y1;
             curY < ((y2 >= (int) bufHeight) ? (int) bufHeight - 1 : y2); curY++) {
            double aInc = 0;
            // Вычисление коэффициента для линейной интерполяции между y1 и y2
            if (y1 != y2)
                aInc = (double) (curY - y1) / (y2 - y1);

            double bInc = 0;
            // Вычисление коэффициента для линейной интерполяции между y1 и y3
            if (y1 != y3)
                bInc = (double) (curY - y1) / (y3 - y1);

            int xA = round(x1 + (x2 - x1) * aInc);
            int xB = round(x1 + (x3 - x1) * bInc);
            double zA = z1 + (z2 - z1) * aInc;
            double zB = z1 + (z3 - z1) * bInc;
            // Если xA больше xB, меняем их местами вместе с соответствующими значениями z
            if (xA > xB) {
                std::swap(xA, xB);
                std::swap(zA, zB);
            }
            // Ограничение значений xA и xB в пределах ширины буфера
            if (xA < 0)
                xA = 0;
            if (xB >= (int) bufWidth)
                xB = (int) bufWidth - 1;

            interpolateRowIntoShadowMap(shadowMap, xA, xB, zA, zB, curY);
        }

#pragma omp parallel for
        // Аналогичный параллельный цикл для обработки другого диапазона значений Y
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
    }
}


void Drawer::zBufForModel(std::vector<Polygon> &facets, std::vector<Vertex> &vertices,
                          Eigen::Matrix4f &transMat, size_t color, Platform *scene, size_t bufWidth,
                          size_t bufHeight) {
    std::array<Point, 3> dotsArr;

    // Подготовка матриц трансформации
    Eigen::Matrix4f toCenter, backToStart;
    prepareTransformationMatrices(toCenter, backToStart);


    // Общая матрица трансформации для точек
    Eigen::Matrix4f dotTransMat = toCenter * transMat * backToStart;
    // Массив матриц трансформации для всех источников света
    std::vector<Eigen::Matrix4f> illumDotMatrices;

    for (size_t i = 0; i < scene->getLightNum(); i++)
        // Заполнение массива матрицами трансформации источников света
        illumDotMatrices.push_back(
                toCenter * scene->getLight(i).getTransMtr() * backToStart);
    // Обработка всех граней модели
    for (size_t curFaceNum = 0; curFaceNum < facets.size(); curFaceNum++) {
        Eigen::MatrixXf coordinatesVec(3, 4);

        // Получение индексов вершин текущей грани
        std::vector<size_t> curDots = facets.at(curFaceNum).getUsedVertices();
        // Получение и трансформация координат вершин
        for (int i = 0; i < 3; i++) {
            dotsArr[i] = vertices.at(curDots.at(i)).getPosition();
            coordinatesVec.row(i)
                    << dotsArr[i].getXCoord(), dotsArr[i].getYCoord(), dotsArr[i].getZCoord(), 1;
        }
        // Применение матрицы трансформации
        coordinatesVec *= dotTransMat;
        // Обновление массива точек после трансформации
        for (int i = 0; i < 3; i++) {
            dotsArr[i] = Point(coordinatesVec(i, 0), coordinatesVec(i, 1), coordinatesVec(i, 2));
        }
//        // Сортировка точек по возрастанию Y-координаты для последующей обработки
//        std::sort(dotsArr.begin(), dotsArr.end(), [](const Point &a, const Point &b) {
//            return a.getYCoordinate() < b.getYCoord();
//        });
        if (dotsArr[0].getYCoord() > dotsArr[1].getYCoord())
            std::swap(dotsArr[0], dotsArr[1]);
        if (dotsArr[0].getYCoord() > dotsArr[2].getYCoord())
            std::swap(dotsArr[0], dotsArr[2]);
        if (dotsArr[1].getYCoord() > dotsArr[2].getYCoord())
            std::swap(dotsArr[1], dotsArr[2]);

        // Преобразование координат в пиксели и Z-координаты для рендеринга
        int x1 = round(dotsArr[0].getXCoord());
        int x2 = round(dotsArr[1].getXCoord());
        int x3 = round(dotsArr[2].getXCoord());

        double z1 = dotsArr[0].getZCoord();
        double z2 = dotsArr[1].getZCoord();
        double z3 = dotsArr[2].getZCoord();

        int y1 = round(dotsArr[0].getYCoord());
        int y2 = round(dotsArr[1].getYCoord());
        int y3 = round(dotsArr[2].getYCoord());
        // Параллельный цикл для обработки пикселей вдоль Y-координаты
#pragma omp parallel for
        for (int curY = (y1 < 0) ? 0 : y1;
             curY < ((y2 >= (int) bufHeight) ? (int) bufHeight - 1 : y2); curY++) {
            // Цикл обрабатывает строки сканирования от y1 до y2, учитывая границы буфера.

            // Переменная для хранения коэффициента интерполяции по первому ребру треугольника.
            double aInc = 0;

            if (y1 != y2)
                // Вычисление коэффициента интерполяции для первого ребра (от y1 до y2).
                aInc = (double) (curY - y1) / (y2 - y1);

            // Переменная для хранения коэффициента интерполяции по второму ребру треугольника.
            double bInc = 0;
            if (y1 != y3)
                bInc = (double) (curY - y1) / (y3 - y1);

            // Интерполяция x-координат для текущего значения y по обоим рёбрам.
            int xA = round(x1 + (x2 - x1) * aInc);
            int xB = round(x1 + (x3 - x1) * bInc);
            // Интерполяция z-координат (глубины) для текущего значения y по обоим рёбрам.
            double zA = z1 + (z2 - z1) * aInc;
            double zB = z1 + (z3 - z1) * bInc;

            if (xA > xB) {
                std::swap(xA, xB);
                std::swap(zA, zB);
            }
//             Ограничиваем координаты x горизонтальными границами буфера
            if (xA < 0) {
                xA = 0;
            }
            if (xB >= (int) bufWidth) {
                xB = (int) bufWidth - 1;

            }
            // Вложенный цикл 'for' обходит x-координаты текущей линии сканирования от xA до xB.
            for (int curX = xA; curX <= xB; curX++) {
                // Интерполяция z-координаты для текущего значения x между xA и xB.
                double curZ = zA + (zB - zA) * (curX - xA) / (xB - xA);
                // Если вычисленная z-координата больше или равна значению в буфере глубины, продолжаем проверку тени.
                if (curZ >= depthBuffer.at(curX).at(curY)) {
                    // Флаг для индикации видимости текущего пикселя после проверки тени.
                    short visible = 0;
                    // Создаём матрицу для хранения трансформированных координат.
                    Eigen::MatrixXf newCoordinates(1, 4);
                    // Перебираем каждый источник света, чтобы проверить, находится ли текущий пиксель в тени.
                    for (size_t i = 0; i < scene->getLightNum() && !visible; i++) {
                        // Присваиваем текущим координатам пикселя значения в матрицу.
                        newCoordinates << curX, curY, curZ, 1;
                        // Трансформируем координаты на основе матрицы трансформации источника света.
                        newCoordinates *= illumDotMatrices.at(i);
                        // Получаем карту теней для текущего источника света.
                        std::vector<std::vector<double>> *shadowMap =
                                &scene->getLight(i).getShadowMap();

                        // Округляем трансформированные координаты до целых значений.
                        int x = round(newCoordinates(0, 0));
                        int y = round(newCoordinates(0, 1));
                        // Проверяем, насколько близко трансформированная глубина к глубине в карте теней, чтобы считать пиксель видимым.
                        if (x < (int) shadowMap->size() && x >= 0 &&
                            y < (int) shadowMap->at(0).size() && y >= 0 &&
                            std::fabs(shadowMap->at(x).at(y) - newCoordinates(0, 2)) < 2)
                            visible = 1;
                    }
                    // Обновляем буфер глубины текущим значением z.
                    depthBuffer.at(curX).at(curY) = curZ;
                    if (scene->getLightNum()) {
                        if (curY - MOVECOEF >= 0 && curX - MOVECOEF >= 0)
                            // Если пиксель видим, обновляем буфер кадра соответствующим цветом и признаком видимости.
                            frameBuffer.at(curX - MOVECOEF).at(curY - MOVECOEF) = color + visible;
                    } else if (curY - MOVECOEF >= 0 && curX - MOVECOEF >= 0)
                        // Если нет источников света, обновляем буфер кадра цветом плюс 1.
                        frameBuffer.at(curX - MOVECOEF).at(curY - MOVECOEF) = color + 1;
                }

            }
        }
        // Аналогичные операции выполняются для следующей части треугольника (от y2 до y3)
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

            if (xA < 0) {
                xA = 0;
            }
            if (xB >= (int) bufWidth) {
                xB = (int) bufWidth - 1;

            }

            for (int curX = xA; curX <= xB; curX++) {
                double curZ = zA + (zB - zA) * (curX - xA) / (xB - xA);

                if (curZ >= depthBuffer.at(curX).at(curY)) {
                    short visible = 0;
                    Eigen::MatrixXf newCoordinates(1, 4);
                    for (size_t i = 0; i < scene->getLightNum() && !visible; i++) {
                        newCoordinates << curX, curY, curZ, 1;

                        newCoordinates *= illumDotMatrices.at(i);
                        std::vector<std::vector<double>> *shadowMap =
                                &scene->getLight(i).getShadowMap();
                        int x = round(newCoordinates(0, 0));
                        int y = round(newCoordinates(0, 1));

                        if (x < (int) shadowMap->size() && x >= 0 &&
                            y < (int) shadowMap->at(0).size() && y >= 0 &&
                            std::fabs(shadowMap->at(x).at(y) - newCoordinates(0, 2)) < 2)
                            visible = 1;
                    }
                    depthBuffer.at(curX).at(curY) = curZ;
                    if (scene->getLightNum()) {
                        if (curY - MOVECOEF >= 0 && curX - MOVECOEF >= 0)
                            frameBuffer.at(curX - MOVECOEF).at(curY - MOVECOEF) = color + visible;
                    } else if (curY - MOVECOEF >= 0 && curX - MOVECOEF >= 0)
                        frameBuffer.at(curX - MOVECOEF).at(curY - MOVECOEF) = color + 1;
                }
            }

        }
        DDABordersForPolygon(x1, y1, z1, x2, y2, z2);
        DDABordersForPolygon(x1, y1, z1, x3, y3, z3);
        DDABordersForPolygon(x2, y2, z2, x3, y3, z3);

    }
}

void Drawer::zBufferAlg(Platform *scene, size_t bufHeight, size_t bufWidth) {



    // Очищаем буферы глубины и кадров
    depthBuffer.clear();
    frameBuffer.clear();
    // Инициализируем буферы новыми пустыми значениями
    for (size_t i = 0; i < bufWidth; i++) {
        depthBuffer.push_back(std::vector<double>(bufHeight, 0));
        frameBuffer.push_back(std::vector<size_t>(bufHeight, 0));
    }


    Model model;
    std::vector<Polygon> facets;
    std::vector<Vertex> vertices;
    Model::model_t typeModel;
    // Генерируем карту теней для каждой модели в сцене
    for (size_t i = 0; i < scene->getModelsNum(); i++) {
        model = scene->getModel(i);
        facets = model.getPolygons();
        vertices = model.getVertices();



        // Для каждого источника света генерируем карту теней
        for (size_t j = 0; j < scene->getLightNum(); j++)
            generateShadowMap(facets, vertices, scene->getTransMtr(),
                              &scene->getLight(j), bufWidth, bufHeight);


    }
    // Обрабатываем базовую модель платформы
    model = scene->getPlateModel();
    facets = model.getPolygons();
    vertices = model.getVertices();


    for (size_t j = 0; j < scene->getLightNum(); j++)
        generateShadowMap(facets, vertices, scene->getTransMtr(),
                          &scene->getLight(j), bufWidth, bufHeight);


//     Выполняем z-буферизацию для всех моделей в сцене
    for (size_t i = 0; i < scene->getModelsNum(); i++) {
        model = scene->getModel(i);
        facets = model.getPolygons();
        vertices = model.getVertices();
        typeModel = model.getModelType();


        // Рассчитываем видимость каждой модели с учетом ее типа
        zBufForModel(
                facets, vertices, scene->getTransMtr(), 4 + typeModel * 2, scene, bufWidth, bufHeight);

    }

    model = scene->getPlateModel();
    facets = model.getPolygons();
    vertices = model.getVertices();


    zBufForModel(
            facets, vertices, scene->getTransMtr(), 1, scene, bufWidth, bufHeight);

    for (size_t i = 0; i < scene->getLightNum(); i++)


        scene->getLight(i).clearShadowMap();


}

QGraphicsScene *Drawer::drawScene(Platform *scene, QRectF rect) {


    size_t width = scene->getWidth() * SCALE_FACTOR;
    size_t height = scene->getHeight() * SCALE_FACTOR;
    qDebug() << "Сцена" << scene->getWidth() << " x " << scene->getHeight();

    scene->buildPlateModel(Point(PLATFORM_START), Point(width, height, PLATFORM_START_Z));

    using namespace std::chrono;
    nanoseconds start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    zBufferAlg(scene, rect.size().height() + MOVECOEF * 2, rect.size().width() + MOVECOEF * 2);
    nanoseconds end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());

    qDebug() << "Время выполнения z-буфера" << size_t((end - start).count() / 1000000);


    QGraphicsScene *outScene = new QGraphicsScene;
    outScene->setSceneRect(rect);

    QColor whiteBlue(135, 206, 235); // Пример смешения белого и синего


    QImage *image =
            new QImage(rect.size().width(), rect.size().height(), QImage::Format_RGB32);
    image->fill(whiteBlue.rgb());

    uint plateCol = qRgb(PLATFORM_COLOR);
    uint darkPlateCol = qRgb(PLATFORM_SHADOW_COLOR);
    uint blackCol = qRgb(BLACK_COLOR);

    uint houseCol = qRgb(HOME_COLOR);
    uint darkHouseCol = qRgb(HOME_SHADOW_COLOR);

    uint roofHouseCol = qRgb(HOME_ROOF_COLOR);
    uint darkRoofHouseCol = qRgb(HOME_ROOF_SHADOW_COLOR);

    uint windowsHouseCol = qRgb(HOME_WINDOW_COLOR);
    uint darkWindowsHouseCol = qRgb(HOME_WINDOW_SHADOW_COLOR);

    uint treeFoliageCol = qRgb(TREE_LEAVES_COLOR);
    uint darkTreeFoliageCol = qRgb(TREE_LEAVES_SHASOW_COLOR);

    uint treeTrunkCol = qRgb(TREE_TRUNK_COLOR);
    uint darkTreeTrunkCol = qRgb(TREE_TRUNK_SHADOW_COLOR);

    uint roadAsphaltCol = qRgb(ROAD_COLOR);
    uint darkRoadAsphaltCol = qRgb(ROAD_SHADOW_COLOR);

    uint roadStripeCol = qRgb(ROAD_STRIPE_COLOR);
    uint darkRoadStripeCol = qRgb(DARK_ROAD_STRIPE_COLOR);

    uint carCol = qRgb(CAR_GREY_COLOR);
    uint darkCarCol = qRgb(CAR_GREY_SHADOW_COLOR);

    uint wheelsCarCol = qRgb(CAR_WHEELS_COLOR);
    uint darkWheelsCarCol = qRgb(CAR_WHEELS_SHADOW_COLOR);

    uint glassCarCol = qRgb(CAR_GLASS_COLOR);
    uint darkGlassCarCol = qRgb(DARK_CAR_GLASS_COLOR);

    uint whiteCol = qRgb(WHITE_COLOR);

    nanoseconds start2 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());

    for (size_t i = 0; i < rect.size().width() - 1; i++)
        for (size_t j = 0; j < rect.size().height() - 1; j++) {
            if (frameBuffer.at(i).at(j) == 1) {
                image->setPixel(i, j, darkPlateCol);
            } else if (frameBuffer.at(i).at(j) == 2) {
                image->setPixel(i, j, plateCol);
            } else if (frameBuffer.at(i).at(j) == 3) {
                image->setPixel(i, j, blackCol);
            } else if (frameBuffer.at(i).at(j) == 4) {
                image->setPixel(i, j, darkHouseCol);
            } else if (frameBuffer.at(i).at(j) == 5) {
                image->setPixel(i, j, houseCol);
            } else if (frameBuffer.at(i).at(j) == 6) {
                image->setPixel(i, j, darkRoofHouseCol);
            } else if (frameBuffer.at(i).at(j) == 7) {
                image->setPixel(i, j, roofHouseCol);
            } else if (frameBuffer.at(i).at(j) == 8) {
                image->setPixel(i, j, darkWindowsHouseCol);
            } else if (frameBuffer.at(i).at(j) == 9) {
                image->setPixel(i, j, windowsHouseCol);
            } else if (frameBuffer.at(i).at(j) == 10) {
                image->setPixel(i, j, darkTreeFoliageCol);
            } else if (frameBuffer.at(i).at(j) == 11) {
                image->setPixel(i, j, treeFoliageCol);
            } else if (frameBuffer.at(i).at(j) == 12) {
                image->setPixel(i, j, darkTreeTrunkCol);
            } else if (frameBuffer.at(i).at(j) == 13) {
                image->setPixel(i, j, treeTrunkCol);
            } else if (frameBuffer.at(i).at(j) == 14) {
                image->setPixel(i, j, darkRoadAsphaltCol);
            } else if (frameBuffer.at(i).at(j) == 15) {
                image->setPixel(i, j, roadAsphaltCol);
            } else if (frameBuffer.at(i).at(j) == 16) {
                image->setPixel(i, j, darkRoadStripeCol);
            } else if (frameBuffer.at(i).at(j) == 17) {
                image->setPixel(i, j, roadStripeCol);
            } else if (frameBuffer.at(i).at(j) == 18) {
                image->setPixel(i, j, darkCarCol);
            } else if (frameBuffer.at(i).at(j) == 19) {
                image->setPixel(i, j, carCol);
            } else if (frameBuffer.at(i).at(j) == 20) {
                image->setPixel(i, j, darkWheelsCarCol);
            } else if (frameBuffer.at(i).at(j) == 21) {
                image->setPixel(i, j, wheelsCarCol);
            } else if (frameBuffer.at(i).at(j) == 22) {
                image->setPixel(i, j, darkGlassCarCol);
            } else if (frameBuffer.at(i).at(j) == 23) {
                image->setPixel(i, j, glassCarCol);
            } else if (frameBuffer.at(i).at(j) == 24) {
                image->setPixel(i, j, whiteCol);
            }
        }

    nanoseconds end2 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    qDebug() << "Время отрисовки" << size_t((end2 - start2).count() / 1000000);
    qDebug() << "Общее время" << size_t((end2 - start2).count() / 1000000) +
                                 size_t((end - start).count() / 1000000);


    outScene->addPixmap(QPixmap::fromImage(*image));
    delete image;
    for (size_t i = 0; i < scene->getLightNum(); i++)
        scene->getLight(i).clearShadowMap();

    return outScene;
}


bool UsageFacade::searchRoadsNearby(int xCell, int yCell, int widthModel, int heightModel) {
    for (int k = 0; k < 2; k++) {
        int i = yCell - 1 + k * (heightModel + 1);
        if (i < 0 || size_t(i) > scene->getHeight() - 1)
            continue;

        int j0 = xCell - 1;
        if (j0 >= 0) {
            if (scene->getUsedSquares()[i][j0] == 2 || scene->getUsedSquares()[i][j0] == 4) {
                qDebug() << "i = " << i << "j = " << j0 << "дорога рядом с домом";
                return true;
            }
        }

        j0 = xCell + widthModel;
        if (size_t(j0) <= scene->getWidth() - 1) {
            if (scene->getUsedSquares()[i][j0] == 2 || scene->getUsedSquares()[i][j0] == 4) {
                qDebug() << "i = " << i << "j = " << j0 << "дорога рядом с домом";
                return true;
            }
        }

        for (int j = xCell; j < xCell + widthModel; j++) {
            if (scene->getUsedSquares()[i][j] == 2 || scene->getUsedSquares()[i][j] == 4) {
                qDebug() << "i = " << i << "j = " << j << "дорога рядом с домом";
                return true;
            }
        }
    }

    for (int k = 0; k < 2; k++) {
        int j = xCell - 1 + k * (widthModel + 1);
        if (j < 0 || size_t(j) > scene->getWidth() - 1)
            continue;

        for (int i = yCell; i < yCell + heightModel; i++) {
            if (scene->getUsedSquares()[i][j] == 2 || scene->getUsedSquares()[i][j] == 4) {
                qDebug() << "i = " << i << "j = " << j << "дорога рядом с домом";
                return true;
            }
        }
    }

    return false;
}

int UsageFacade::addPickup(int xCell, int yCell, Direction direction, ColorCar color_car) {
    int modelLength, modelHeight;
    if (direction == Horizontal) {
        modelHeight = 1;
        modelLength = 3; // Увеличиваем длину для пикапа
    } else {
        modelHeight = 3; // Увеличиваем длину для пикапа
        modelLength = 1;
    }

    xCell -= 1;
    yCell -= 1;

    if (xCell + modelLength - 1 >= (int) scene->getWidth() ||
        yCell + modelHeight - 1 >= (int) scene->getHeight())
        return 2;

    for (int i = yCell; i < yCell + modelHeight; i++) {
        for (int j = xCell; j < xCell + modelLength; j++) {
            if (scene->getUsedSquares()[i][j] != 2) {
                qDebug() << "i = " << i << "j = " << j << "нет дороги (пикап)";
                return 3;
            }
        }
    }

    std::vector<Vertex> vertices;
    std::vector<Polygon> facets;

    int xFactor = xCell * SCALE_FACTOR + 10;
    int yFactor = yCell * SCALE_FACTOR + 10 - MOVECOEF * 2;
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
    pickupModel.setUsedSquare(xCell, yCell);
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


int UsageFacade::addHouse(int xCell, int yCell, int modelLength, int modelHeight, int countFloors) {
    xCell -= 1;
    yCell -= 1;

    if (xCell + modelLength - 1 >= (int) scene->getWidth() || \
        yCell + modelHeight - 1 >= (int) scene->getHeight())
        return 2;

    for (int i = yCell; i < yCell + modelHeight; i++) {
        for (int j = xCell; j < xCell + modelLength; j++) {
            if (scene->getUsedSquares()[i][j] != 0 && scene->getUsedSquares()[i][j] != 3) {
                qDebug() << "i = " << i << "j = " << j << "ячейка занята (дом)";
                return 1;
            }
        }
    }

    if (searchRoadsNearby(xCell, yCell, modelLength, modelHeight))
        return 4;

    std::vector<Vertex> vertices;
    std::vector<Polygon> facets;

    int xFactor = xCell * SCALE_FACTOR + 10;
    int yFactor = yCell * SCALE_FACTOR + 10;
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

            xFactor = xCell * SCALE_FACTOR + 10;
            yFactor += SCALE_FACTOR * modelHeight;
        }

        yFactor = yCell * SCALE_FACTOR + 10;


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

            yFactor = yCell * SCALE_FACTOR + 10;
            xFactor += SCALE_FACTOR * modelLength;
        }

        xFactor = xCell * SCALE_FACTOR + 10;

        zFactor += SCALE_FACTOR;
    }

    Model houseModel(vertices, facets, "Дом");
    houseModel.setUsedSquare(xCell, yCell);
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
    roofHouseModel.setUsedSquare(xCell, yCell);
    roofHouseModel.setHeightModel(modelHeight);
    roofHouseModel.setWidthModel(modelLength);
    roofHouseModel.setHouseHeight(countFloors);
    roofHouseModel.setModelType(Model::RoofHouse);
    roofHouseModel.setModelNum(scene->getRealModelsNum());
    scene->addModel(roofHouseModel);

    std::vector<Vertex> vertices3;
    std::vector<Polygon> facets3;

    xFactor = xCell * SCALE_FACTOR + 10;
    yFactor = yCell * SCALE_FACTOR + 10;
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

            xFactor = xCell * SCALE_FACTOR + 10;
            yFactor += SCALE_FACTOR * modelHeight;
        }

        yFactor = yCell * SCALE_FACTOR + 10;


        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < modelHeight; j++) {
                addQuad(vertices3, facets3,
                        xFactor, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR * 2 / 3,
                        xFactor, yFactor + SCALE_FACTOR * 2 / 3, zFactor + SCALE_FACTOR / 3,
                        xFactor, yFactor + SCALE_FACTOR / 3, zFactor + SCALE_FACTOR / 3);

                yFactor += SCALE_FACTOR;
            }

            yFactor = yCell * SCALE_FACTOR + 10;
            xFactor += SCALE_FACTOR * modelLength;
        }

        xFactor = xCell * SCALE_FACTOR + 10;

        zFactor += SCALE_FACTOR;
    }

    Model windowsHouseModel(vertices3, facets3, "Окна дома");
    windowsHouseModel.setUsedSquare(xCell, yCell);
    windowsHouseModel.setHeightModel(modelHeight);
    windowsHouseModel.setWidthModel(modelLength);
    windowsHouseModel.setHouseHeight(countFloors);
    windowsHouseModel.setModelType(Model::WindowsHouse);
    windowsHouseModel.setModelNum(scene->getRealModelsNum());
    scene->addModel(windowsHouseModel);

    return 0;
}


int UsageFacade::addTree(int xCell, int yCell) {
    xCell -= 1;
    yCell -= 1;

    if (xCell >= (int) scene->getWidth() || yCell >= (int) scene->getHeight())
        return 2;

    if (scene->getUsedSquares()[yCell][xCell] != 0 && scene->getUsedSquares()[yCell][xCell] != 3) {
        qDebug() << "i = " << xCell << "j = " << xCell << "ячейка занята (дерево)";
        return 1;
    }

    int xFactor = xCell * SCALE_FACTOR + 10;
    int yFactor = yCell * SCALE_FACTOR + 10;
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
    treeFoliageModel.setUsedSquare(xCell, yCell);
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
    treeTrunkModel.setUsedSquare(xCell, yCell);
    treeTrunkModel.setHeightModel(1);
    treeTrunkModel.setWidthModel(1);
    treeTrunkModel.setModelType(Model::TreeTrunk);
    treeTrunkModel.setModelNum(scene->getRealModelsNum());
    scene->addModel(treeTrunkModel);

    return 0;
}


int UsageFacade::addRoad(int xCell, int yCell, Direction direction) {
    xCell -= 1;
    yCell -= 1;

    if (xCell >= (int) scene->getWidth() || yCell >= (int) scene->getHeight())
        return 2;

    if (scene->getUsedSquares()[yCell][xCell] == 3) {
        qDebug() << "i = " << xCell << "j = " << xCell << "ячейка рядом с домом (дорога)";
        return 4;
    }
    if (scene->getUsedSquares()[yCell][xCell] != 0) {
        qDebug() << "i = " << xCell << "j = " << xCell << "ячейка занята (дорога)";
        return 1;
    }


    std::vector<Vertex> vertices;
    std::vector<Polygon> facets;

    int xFactor = xCell * SCALE_FACTOR + 10;
    int yFactor = yCell * SCALE_FACTOR + 10;
    int zFactor = PLATFORM_START_Z;

    //асфальт
    addQuad(vertices, facets,
            xFactor, yFactor, zFactor + 1,
            xFactor + SCALE_FACTOR, yFactor, zFactor + 1,
            xFactor + SCALE_FACTOR, yFactor + SCALE_FACTOR, zFactor + 1,
            xFactor, yFactor + SCALE_FACTOR, zFactor + 1);

    Model roadAsphaltModel(vertices, facets, "Дорога");
    roadAsphaltModel.setUsedSquare(xCell, yCell);
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
    } else {
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
    roadStripeModel.setUsedSquare(xCell, yCell);
    roadStripeModel.setHeightModel(1);
    roadStripeModel.setWidthModel(1);
    roadStripeModel.setDirectionRoad(direction);
    roadStripeModel.setModelType(Model::RoadStripe);
    roadStripeModel.setModelNum(scene->getRealModelsNum());
    scene->addModel(roadStripeModel);

    return 0;
}


int UsageFacade::addCar(int xCell, int yCell, Direction direction, ColorCar color_car) {
    int modelLength;
    int modelHeight;

    if (direction == Horizontal) {
        modelHeight = 1;
        modelLength = 2;
    } else {
        modelHeight = 2;
        modelLength = 1;
    }

    xCell -= 1;
    yCell -= 1;

    if (xCell + modelLength - 1 >= (int) scene->getWidth() || \
        yCell + modelHeight - 1 >= (int) scene->getHeight())
        return 2;

    for (int i = yCell; i < yCell + modelHeight; i++) {
        for (int j = xCell; j < xCell + modelLength; j++) {
            if (scene->getUsedSquares()[i][j] != 2) {
                qDebug() << "i = " << i << "j = " << j << "нет дороги (машина)";
                return 3;
            }
        }
    }


    std::vector<Vertex> vertices;
    std::vector<Polygon> facets;

    int xFactor = xCell * SCALE_FACTOR + 10;
    int yFactor = yCell * SCALE_FACTOR + 10 - MOVECOEF * 2;
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
    carModel.setUsedSquare(xCell, yCell);
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

    xFactor = xCell * SCALE_FACTOR + 10;
    yFactor = yCell * SCALE_FACTOR + 10 - MOVECOEF * 2;
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

        xFactor = xCell * SCALE_FACTOR + 10;
        yFactor = yCell * SCALE_FACTOR + 10 - MOVECOEF * 2;

        yFactor += SCALE_FACTOR / 2 + 4;
    }

    Model wheelsCarModel(vertices2, facets2, "Колёса машина");
    wheelsCarModel.setUsedSquare(xCell, yCell);
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

    xFactor = xCell * SCALE_FACTOR + 10;
    yFactor = yCell * SCALE_FACTOR + 10 - MOVECOEF * 2;
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
    glassCarModel.setUsedSquare(xCell, yCell);
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

