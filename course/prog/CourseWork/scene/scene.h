#ifndef LAB_03_SCENE_H
#define LAB_03_SCENE_H


#include <vector>
#include <memory>
#include <iostream>

#include "../objects/camera/camera.h"
#include "../objects/composite/composite.h"


class Scene
{
public:
    Scene(): objects(std::make_shared<Composite>()) {}
    ~Scene() = default;

    void addObject(const std::shared_ptr<Object> &object);
    void removeObject(size_t &id);

    Iterator begin();
    Iterator end();

    size_t getModelNum() const;
    size_t getCameraNum() const;

    Iterator getObjectIter(size_t &id);

protected:
    std::shared_ptr<Composite> objects;
    size_t modelNum = 0;
    size_t cameraNum = 0;
};


#endif //LAB_03_SCENE_H
