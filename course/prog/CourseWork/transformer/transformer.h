//
// Created by User on 02.06.2023.
//

#ifndef LAB_03_TRANSFORMER_H
#define LAB_03_TRANSFORMER_H

#include "base_transformer.h"

class Transformer : public BaseTransformer {
public:
    Transformer(const Point &rotate, const Point &scale, const Point &shift) :
            rotateParams(rotate), scaleParams(scale), shiftParams(shift) {};

    ~Transformer() = default;

    void transform(Point &point, Point &center) override;

private:
    void move(Point &point, const Point &moveArg);

    void scale(Point &point, const Point &scaleArg);

    void rotate(Point &point, const Point &rotateArg);

    void rotateX(Point &point, double ox);

    void rotateY(Point &point, double oy);

    void rotateZ(Point &point, double oz);

    Point rotateParams;
    Point scaleParams;
    Point shiftParams;
};


#endif //LAB_03_TRANSFORMER_H
