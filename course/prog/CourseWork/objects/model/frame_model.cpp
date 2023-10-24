#include "frame_model.h"

void FrameModel::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}


std::shared_ptr<FrameModelStructure> FrameModel::getModelStructure() const {
    return modelStructure;
}

Point FrameModel::getCenter() {
    return modelStructure->getCenter();
}
