//
// Created by max on 23.10.23.
//

#ifndef COURSEWORK_QTDRAWER_H
#define COURSEWORK_QTDRAWER_H

#include <QGraphicsScene>
#include "BaseDrawer.h"


class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = delete;
    explicit QtDrawer(std::shared_ptr<QGraphicsScene> &srcScene);
    QtDrawer(const QtDrawer &srcDrawer);
    ~QtDrawer() override = default;

    void drawLine(const Point &point1, const Point &point2) override;
    void clearScene() override;

private:
    std::shared_ptr<QGraphicsScene> scene;
};



#endif //COURSEWORK_QTDRAWER_H
