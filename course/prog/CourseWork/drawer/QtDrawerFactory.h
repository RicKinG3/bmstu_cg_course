//
// Created by max on 23.10.23.
//

#ifndef COURSEWORK_QTDRAWERFACTORY_H
#define COURSEWORK_QTDRAWERFACTORY_H

#include "AbstractDrawerFactory.h"
#include <QGraphicsScene>
class QtDrawerFactory : AbstractDrawerFactory {
public:
    QtDrawerFactory() = default;
    explicit QtDrawerFactory(std::shared_ptr<QGraphicsScene> &src_scene);

    std::unique_ptr<BaseDrawer> create() override;
private:
    std::shared_ptr<QGraphicsScene> scene;

};


#endif //COURSEWORK_QTDRAWERFACTORY_H
