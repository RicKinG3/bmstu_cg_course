#include "frame_model.h"


void FrameModel::accept(std::shared_ptr<Visitor> visitor, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW, size_t bufH  ) {
    visitor->visit(*this, mtr, light, bufW, bufH);
}

std::shared_ptr<FrameModelStructure> FrameModel::getModelStructure() const {
    return modelStructure;
}

Point FrameModel::getCenter() {
    return modelStructure->getCenter();
}
