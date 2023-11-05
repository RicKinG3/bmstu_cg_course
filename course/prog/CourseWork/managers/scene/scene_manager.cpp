#include "scene_manager.h"
#include "../../exceptions/manager_exceptions.h"


SceneManager::SceneManager() : scene(std::make_shared<Scene>()) {}


std::shared_ptr<Scene> SceneManager::getScene() {
    return scene;
}

std::shared_ptr<Camera> SceneManager::getCamera() {
    if (camera.lock() == nullptr) {
        time_t cur_time = time(NULL);
        throw NoMainCameraException(__FILE__, __func__, __LINE__,
                                    ctime(&cur_time));
    }

    return camera.lock();
}

void SceneManager::setScene(std::shared_ptr<Scene> &sceneArg) {
    scene = sceneArg;
}

void SceneManager::setCamera(size_t &id) {
    auto iterator = scene->getObjectIter(id);
    camera = std::dynamic_pointer_cast<Camera>(*iterator);
}


void SceneManager::addCamera(const Point &position, const Point &direction) {
    auto camera = CameraFactory(position, direction).create();
    scene->addObject(camera);
}

void SceneManager::addLight(const Point &position, const Point &direction) {
    auto light = LightFactory(position, direction).create();
    scene->addObject(light);
}

std::shared_ptr<SceneManager> SceneManagerCreator::getManager() {
    if (manager == nullptr) {
        createInstance();
    }

    return manager;
}

void SceneManagerCreator::createInstance() {
    static auto _manager = std::make_shared<SceneManager>();
    manager = _manager;
}
