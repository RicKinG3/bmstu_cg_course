#ifndef LAB_03_ABSTRACT_DRAWER_FACTORY_H
#define LAB_03_ABSTRACT_DRAWER_FACTORY_H

#include <memory>
#include "base_drawer.h"


class AbstractDrawerFactory
{
public:
    AbstractDrawerFactory() = default;
    virtual ~AbstractDrawerFactory() = default;

    virtual std::unique_ptr<BaseDrawer> create() = 0;
};


#endif //LAB_03_ABSTRACT_DRAWER_FACTORY_H
