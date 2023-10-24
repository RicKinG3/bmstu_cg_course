#ifndef LAB_03_TRANSFORM_VISITOR_H
#define LAB_03_TRANSFORM_VISITOR_H


#include "visitor.h"
#include "../transformer/base_transformer.h"

#include <iostream>

class TransformVisitor : public Visitor {
public:
    TransformVisitor(const std::shared_ptr<BaseTransformer> &transformer_);

    ~TransformVisitor() override = default;

    void visit(FrameModel &model) override;

    void visit(Camera &model) override;

private:
    std::shared_ptr<BaseTransformer> transformer;
};


class TransformVisitorFactory : public VisitorFactory {
public:
    TransformVisitorFactory(std::shared_ptr<BaseTransformer> &transformer_);

    ~TransformVisitorFactory() override = default;

    std::shared_ptr<Visitor> create() override;

private:
    std::shared_ptr<BaseTransformer> transformer;
};


#endif //LAB_03_TRANSFORM_VISITOR_H
