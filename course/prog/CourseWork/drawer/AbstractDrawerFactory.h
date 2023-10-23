//
// Created by max on 23.10.23.
//

#ifndef COURSEWORK_ABSTRACTDRAWERFACTORY_H
#define COURSEWORK_ABSTRACTDRAWERFACTORY_H

#include "BaseDrawer.h"
#include <memory>


class AbstractDrawerFactory
{
public:
    AbstractDrawerFactory() = default;
    // virtual гарантирует, что деструктор будет вызван правильно,
    // даже если указатель на базовый класс будет использоваться
    // для удаления объекта производного класса
    virtual ~AbstractDrawerFactory() = default ;

    virtual std::unique_ptr<BaseDrawer> create() = 0;
};


#endif //COURSEWORK_ABSTRACTDRAWERFACTORY_H
