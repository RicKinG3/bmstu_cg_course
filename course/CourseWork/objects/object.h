//
// Created by User on 29.05.2023.
//

#ifndef LAB_03_OBJECT_H
#define LAB_03_OBJECT_H

#include "/usr/include/eigen3/Eigen/Dense"

#include <memory>
#include <vector>
#include "primitives/point.h"
#include "primitives/edge.h"
#include "../visitor/visitor.h"

class Object;

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;

class Object {
public:
    Object() = default;

    virtual ~Object() = default;

    virtual bool isVisible() { return false; };

    virtual bool add(const std::shared_ptr<Object> &) { return false; };

    virtual bool remove(const Iterator &) { return false; };


    virtual void accept(std::shared_ptr<Visitor> visitor, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW, size_t bufH) = 0;

    virtual Iterator begin() { return Iterator(); };

    virtual Iterator end() { return Iterator(); };

    virtual Point getCenter() = 0;
};

class VisibleObject : public Object {
public:
    VisibleObject() = default;

    virtual ~VisibleObject() override = default;

    bool isVisible() override { return true; }
};

class InvisibleObject : public Object {
public:
    InvisibleObject() = default;

    virtual ~InvisibleObject() override = default;

    bool isVisible() override { return false; }
};

#endif //LAB_03_OBJECT_H
