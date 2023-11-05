//
// Created by User on 02.06.2023.
//

#ifndef LAB_03_TRANSFORMER_FACTORY_H
#define LAB_03_TRANSFORMER_FACTORY_H

#include "base_transformer_factory.h"

class TransformerFactory : public BaseTransformerFactory {
public:
    TransformerFactory(const Point &rotate, const Point &scale, const Point &shift);

    std::shared_ptr<BaseTransformer> create() override;

private:
    Point rotateParams;
    Point scaleParams;
    Point shiftParams;
};


#endif //LAB_03_TRANSFORMER_FACTORY_H
