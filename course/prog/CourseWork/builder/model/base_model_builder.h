#ifndef LAB_03_BASE_MODEL_BUILDER_H
#define LAB_03_BASE_MODEL_BUILDER_H

#include "../base_builder.h"

class BaseModelBuilder : public BaseBuilder
{
public:
    BaseModelBuilder() = default;
    ~BaseModelBuilder() override = default;

    virtual void buildCenter(const Point &center) = 0;
    virtual void buildPoint(const Point &point) = 0;
    virtual void buildEdge(const Edge &edge) = 0;
    virtual void buildFace(const Face &face) = 0;


    virtual std::shared_ptr<Object> get() = 0;
};

#endif //LAB_03_BASE_MODEL_BUILDER_H
