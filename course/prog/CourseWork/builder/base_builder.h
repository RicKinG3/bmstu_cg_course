#ifndef LAB_03_BASE_BUILDER_H
#define LAB_03_BASE_BUILDER_H

#include "../objects/object.h"

#include "face.h"

class BaseBuilder
{
public:
    BaseBuilder() = default;
    virtual ~BaseBuilder() = default;

    virtual bool isBuilt() = 0;
    virtual void reset() = 0;
    virtual void build() = 0;
};


class BuilderCreator
{
public:
    BuilderCreator() = default;
    virtual ~BuilderCreator() = default;

    virtual std::shared_ptr<BaseBuilder> createBuilder() = 0;
};


#endif //LAB_03_BASE_BUILDER_H
