#include <QPainter>
#include <QGraphicsPolygonItem>
#include "qt_drawer.h"


QtDrawer::QtDrawer(std::shared_ptr<QGraphicsScene> &srcScene) {
    scene = srcScene;
}

QtDrawer::QtDrawer(const QtDrawer &srcDrawer) {
    scene = srcDrawer.scene;
}


void QtDrawer::drawLine(const Point &point1, const Point &point2) {
    QPen pen(Qt::white);  // Создаем перо с красным цветом
    scene->addLine(point1.getX(), -point1.getY(), point2.getX(), -point2.getY(), pen);
}

//TODO need algos
void QtDrawer::drawPolygon(const Point &point1, const Point &point2, const Point &point3) {
    // Получаем указатель на QGraphicsScene из shared_ptr
    QGraphicsScene* scenePtr = scene.get();

    // Проверка на nullptr (по желанию)
    if (!scenePtr) {
        // Обработка ошибки или возврат
        return;
    }

    // Создаем полигон из трех точек
    QPolygon poly;
    poly << QPoint(point1.getX(), -point1.getY()) << QPoint(point2.getX(), -point2.getY())
         << QPoint(point3.getX(), -point3.getY());

    // Создаем кисть с белым цветом
    QBrush brush(Qt::red);

    // Создаем графический элемент (полигон) в сцене
    QGraphicsPolygonItem* polygonItem = new QGraphicsPolygonItem(poly);
    polygonItem->setBrush(brush);

    // Добавляем полигон к сцене
    scenePtr->addItem(polygonItem);
}



void QtDrawer::clearScene() {
    scene->clear();
}
