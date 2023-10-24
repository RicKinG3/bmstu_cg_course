#ifndef LAB_03_BASE_TRANSFORMER_H
#define LAB_03_BASE_TRANSFORMER_H

#include "../objects/primitives/point.h"

class BaseTransformer {
public:
    virtual ~BaseTransformer() = default;

    virtual void transform(Point &point, Point &center) = 0;
};

#endif //LAB_03_BASE_TRANSFORMER_H
