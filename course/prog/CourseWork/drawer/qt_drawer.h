#ifndef LAB_03_QT_DRAWER_H
#define LAB_03_QT_DRAWER_H

#include <QGraphicsScene>
#include "base_drawer.h"


class QtDrawer : public BaseDrawer {
public:
    QtDrawer() = delete;

    explicit QtDrawer(std::shared_ptr<QGraphicsScene> &srcScene);

    QtDrawer(const QtDrawer &srcDrawer);

    ~QtDrawer() override = default;

    void drawLine(const Point &point1, const Point &point2) override;

    void clearScene() override;

    void drawPolygon(const Point &point1, const Point &point2, const Point &point3);

    void setHeight(size_t height_) override{ h = height_; }

    void setWight(size_t width_) override{ w = width_; }

    size_t getHeight() override { return h; }

    size_t getWidth() override{ return w; }

private:
    std::shared_ptr<QGraphicsScene> scene;
    size_t w = 0;
    size_t h = 0;
};


#endif //LAB_03_QT_DRAWER_H
