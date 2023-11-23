#ifndef LAB_03_SCENE_MANAGER_H
#define LAB_03_SCENE_MANAGER_H


#include <memory>
#include "../base_manager.h"
#include "../../scene/scene.h"
#include "../../objects/camera/camera.h"
#include "Light.h"

class SceneManager : public BaseManager
{
public:
    SceneManager();
    SceneManager(const SceneManager&) = delete;
    SceneManager &operator = (const SceneManager&) = delete;
    ~SceneManager() override = default;

    void setScene(std::shared_ptr<Scene> &sceneArg);
    void setCamera(size_t &id);

    void addCamera(const Point &position, const Point &direction);
    void addLight(const Point &position, const Point &direction);


    void removeObject(size_t &id) { scene->removeObject(id);}

    size_t countCamera() {return scene->getCameraNum();}
    size_t countModel() {return scene->getModelNum();}

    std::shared_ptr<Scene>  getScene();
    std::shared_ptr<Camera> getCamera();
    std::shared_ptr<Light> getLight();


private:
    std::shared_ptr<Scene>  scene;
    std::weak_ptr<Light>  light;

    std::weak_ptr<Camera>  camera;
};


class SceneManagerCreator
{
public:
    std::shared_ptr<SceneManager> getManager();

private:
    void createInstance();
    std::shared_ptr<SceneManager> manager;
};


#endif //LAB_03_SCENE_MANAGER_H
