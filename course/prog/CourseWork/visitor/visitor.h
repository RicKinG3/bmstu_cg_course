#ifndef LAB_03_VISITOR_H
#define LAB_03_VISITOR_H

#include <memory>


class FrameModel;

class Camera;

class Composite;

class Scene;

class Visitor {
public:
    Visitor() = default;

    virtual ~Visitor() = default;

    virtual void visit(FrameModel &model) = 0;

    virtual void visit(Camera &model) = 0;

    // TODO : delete
};


class VisitorFactory {
public:
    VisitorFactory() = default;

    virtual ~VisitorFactory() = default;

    virtual std::shared_ptr<Visitor> create() = 0;
};

#endif //LAB_03_VISITOR_H
