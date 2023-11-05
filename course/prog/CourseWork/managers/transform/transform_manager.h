#ifndef LAB_03_TRANSFORM_MANAGER_H
#define LAB_03_TRANSFORM_MANAGER_H


#include "../base_manager.h"
#include "../../objects/object.h"
#include "../../managers/scene/scene_manager.h"


class TransformManager : public BaseManager
{
public:
    TransformManager() = default;
    TransformManager(const TransformManager &manager) = delete;
    TransformManager &operator = (const TransformManager &manager) = delete;
    ~TransformManager() override = default;

    void transform(size_t, const Point &, const Point &, const Point &);
};


class TransformManagerCreator
{
public:
    std::shared_ptr<TransformManager> getManager();

private:
    void createInstance();
    std::shared_ptr<TransformManager> manager;
};


#endif //LAB_03_TRANSFORM_MANAGER_H
