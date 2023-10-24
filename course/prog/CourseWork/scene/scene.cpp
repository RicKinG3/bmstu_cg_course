#include <iterator>
#include "scene.h"


void Scene::addObject(const std::shared_ptr<Object> &object)
{
    if (object->isVisible())
        modelNum += 1;
    else
        cameraNum += 1;

    objects->add(object);
}

void Scene::removeObject(size_t &id)
{
    auto iterator = getObjectIter(id);
    objects->remove(iterator);
}


Iterator Scene::begin()
{
    return objects->begin();
}

Iterator Scene::end()
{
    return objects->end();
}


size_t Scene::getModelNum() const
{
    return modelNum;
}

size_t Scene::getCameraNum() const
{
    return cameraNum;
}


Iterator Scene::getObjectIter(size_t &id)
{
    auto iterator = begin();

    for (size_t cur = 0; cur < id; cur++)
        iterator++;

    return iterator;
}
