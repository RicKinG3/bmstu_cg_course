#include "Drawer.h"
//todo

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
        qDebug() << typeModel;

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
            } else if (frameBuffer.at(i).at(j) == 25) {
                image->setPixel(i, j, blackCol);
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
