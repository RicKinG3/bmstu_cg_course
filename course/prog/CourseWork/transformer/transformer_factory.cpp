//
// Created by User on 02.06.2023.
//

#include "transformer_factory.h"
#include "transformer.h"

TransformerFactory::TransformerFactory(const Point &rotate, const Point &scale, const Point &shift) :
        rotateParams(rotate), scaleParams(scale), shiftParams(shift) {

}

std::shared_ptr<BaseTransformer> TransformerFactory::create() {
    return std::make_shared<Transformer>(rotateParams, scaleParams, shiftParams);
}