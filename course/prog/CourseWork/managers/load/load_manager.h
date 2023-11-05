#ifndef LAB_03_LOAD_MANAGER_H
#define LAB_03_LOAD_MANAGER_H

#include <memory>

#include "../base_manager.h"
#include "../../director/base_load_director.h"
#include "../../objects/object.h"
#include "../../scene/scene.h"
#include "../../director/model/model_director.h"
#include "../../director/camera/camera_director.h"
#include "../scene/scene_manager.h"


class LoadManager : public BaseManager {
public:
    LoadManager() = default;

    LoadManager(const LoadManager &manager) = delete;

    ~LoadManager() override = default;

    void loadCamera(const std::string &fname);

    void loadModel(const std::string &fname);

    void setDirector(std::shared_ptr<BaseLoadDirector> srcDirector);

private:
    std::shared_ptr<BaseLoadDirector> director = nullptr;
};


class LoadManagerCreator {
public:
    std::shared_ptr<LoadManager> getManager();

private:
    void createInstance();

    std::shared_ptr<LoadManager> manager;
};

#endif //LAB_03_LOAD_MANAGER_H
