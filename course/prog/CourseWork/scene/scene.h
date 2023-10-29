#ifndef LAB_03_SCENE_H
#define LAB_03_SCENE_H


#include <vector>
#include <memory>
#include <iostream>

#include "../objects/camera/camera.h"
#include "../objects/composite/composite.h"


class Scene {
public:
    Scene() : objects(std::make_shared<Composite>()) {}

    ~Scene() = default;

    void addObject(const std::shared_ptr<Object> &object);

    void removeObject(size_t &id);

    Iterator begin();

    Iterator end();

    size_t getModelNum() const;

    size_t getCameraNum() const;


    Iterator getObjectIter(size_t &id);

    void setHeight(size_t height_) { height = height_; }

    void setWight(size_t width_) { width = width_; }

    double getHeight() { return height; }

    double getWidth() { return width; }

protected:
    std::shared_ptr<Composite> objects;
    size_t modelNum = 0;
    size_t cameraNum = 0;

    size_t height = 0;
    size_t width = 0;
};


#endif //LAB_03_SCENE_H
