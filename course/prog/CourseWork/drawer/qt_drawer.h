#ifndef LAB_03_QT_DRAWER_H
#define LAB_03_QT_DRAWER_H
#include <QGraphicsScene>
#include "base_drawer.h"


class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = delete;
    explicit QtDrawer(std::shared_ptr<QGraphicsScene> &srcScene);
    QtDrawer(const QtDrawer &srcDrawer);
    ~QtDrawer() override = default;

    void drawLine(const Point &point1, const Point &point2) override;
    void clearScene() override;
    void drawPolygon(const Point &point1, const Point &point2,  const Point &point3);
    float interpolate(int y1, int y2, float x1, float x2, int y) ;

        private:
    std::shared_ptr<QGraphicsScene> scene;
};


#endif //LAB_03_QT_DRAWER_H
