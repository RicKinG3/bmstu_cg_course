#include "load_manager.h"


void LoadManager::setDirector(std::shared_ptr<BaseLoadDirector> srcDirector) {
    director = srcDirector;
}


void LoadManager::loadCamera(const std::string &fname) {
    auto new_director = CameraDirectorCreator().getDirector(fname);
    setDirector(new_director);
    auto object = director->create();
    SceneManagerCreator().getManager()->getScene()->addObject(object);
}

void LoadManager::loadModel(const std::string &fname) {
    auto new_director = ModelDirectorCreator().getDirector(fname);
    setDirector(new_director);
    auto object = director->create();
    SceneManagerCreator().getManager()->getScene()->addObject(object);
}


std::shared_ptr<LoadManager> LoadManagerCreator::getManager() {
    if (manager == nullptr) {
        createInstance();
    }

    return manager;
}

void LoadManagerCreator::createInstance() {
    manager = std::make_shared<LoadManager>();
}
