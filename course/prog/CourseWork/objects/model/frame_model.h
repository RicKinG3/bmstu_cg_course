#ifndef LAB_03_FRAME_MODEL_H
#define LAB_03_FRAME_MODEL_H

#include <memory>
#include "model.h"
#include "model_structure.h"
#include "../../visitor/draw_visitor.h"
#include "../../visitor/transform_visitor.h"

class FrameModel : public Model {
    friend void
    DrawVisitor::visit(FrameModel &model, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW, size_t bufH);

    friend void
    TransformVisitor::visit(FrameModel &model, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW,
                            size_t bufH);

public:
    FrameModel() = default;

    explicit FrameModel(std::shared_ptr<FrameModelStructure> srcModelStructure) :
            modelStructure(srcModelStructure) {}

    ~FrameModel() override = default;

    virtual Point getCenter() override;


    void accept(std::shared_ptr<Visitor> visitor, Eigen::Matrix4f mtr, std::shared_ptr<Light> light,
                size_t bufW, size_t bufH);

    std::shared_ptr<FrameModelStructure> getModelStructure() const;


private:
    //массив со всеми нашими объектами
    std::shared_ptr<FrameModelStructure> modelStructure;
};

#endif //LAB_03_FRAME_MODEL_H
