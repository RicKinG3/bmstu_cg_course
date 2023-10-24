#ifndef LAB_03_MODEL_BUILDER_H
#define LAB_03_MODEL_BUILDER_H

#include "base_model_builder.h"
#include "../../objects/model/frame_model.h"
#include "../../objects/model/model_structure.h"
#include "../../objects/primitives/point.h"
#include "../../objects/primitives/edge.h"


class ModelBuilder : public BaseModelBuilder
{
public:
    ModelBuilder() = default;
    ~ModelBuilder() override = default;

    bool isBuilt() override;
    void reset() override;
    void build() override;

    void buildCenter(const Point &center) override;
    void buildPoint(const Point &point) override;
    void buildEdge(const Edge &edge) override;

    void buildFace(const Face &face) override;

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<FrameModelStructure> modelStruct;
};


class ModelBuilderCreator : public BuilderCreator
{
public:
    ModelBuilderCreator() = default;
    ~ModelBuilderCreator() override = default;

    std::shared_ptr<BaseBuilder> createBuilder() override;
};


#endif //LAB_03_MODEL_BUILDER_H
