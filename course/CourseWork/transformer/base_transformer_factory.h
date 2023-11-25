//
// Created by User on 02.06.2023.
//

#ifndef LAB_03_BASETRANSFORMERFACTORY_H
#define LAB_03_BASETRANSFORMERFACTORY_H

#include "base_transformer.h"

class BaseTransformerFactory {
public:
    virtual ~BaseTransformerFactory() = default;

    virtual std::shared_ptr<BaseTransformer> create() = 0;
};

#endif //LAB_03_BASETRANSFORMERFACTORY_H
