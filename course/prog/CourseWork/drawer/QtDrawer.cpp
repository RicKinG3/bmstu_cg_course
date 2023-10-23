//
// Created by max on 23.10.23.
//

#include "QtDrawer.h"
#include "../objects/primitives/point.h"

QtDrawer::QtDrawer(std::shared_ptr<QGraphicsScene> &srcScene)
{
    scene = srcScene;
}

QtDrawer::QtDrawer(const QtDrawer &srcDrawer)
{
    scene = srcDrawer.scene;
}


void QtDrawer::drawLine(const Point &point1, const Point &point2)
{
    QPen pen(Qt::white);  // Создаем перо с красным цветом
    scene->addLine(point1.getX(), -point1.getY(), point2.getX(), -point2.getY(), pen);
}

void QtDrawer::clearScene()
{
    scene->clear();
}