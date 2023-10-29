//
// Created by User on 29.05.2023.
//

#ifndef LAB_03_DRAWER_FACTORY_H
#define LAB_03_DRAWER_FACTORY_H


#include "abstract_drawer_factory.h"
#include "qt_drawer.h"


class QtDrawerFactory : public AbstractDrawerFactory {
public:
    QtDrawerFactory() = delete;

    explicit QtDrawerFactory(std::shared_ptr<QGraphicsScene> &src_scene);

    std::unique_ptr<BaseDrawer> create() override;



private:
    std::shared_ptr<QGraphicsScene> scene;

};

#endif //LAB_03_DRAWER_FACTORY_H
