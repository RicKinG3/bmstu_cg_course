#ifndef LAB_03_DRAW_MANAGER_H
#define LAB_03_DRAW_MANAGER_H

#include "../base_manager.h"
#include "../../drawer/base_drawer.h"
#include "../../objects/camera/camera.h"
#include "../../scene/scene.h"
#include "../../managers/scene/scene_manager.h"


class DrawManager : public BaseManager {
public:
    DrawManager() = default;

    DrawManager(const DrawManager &manager) = delete;

    ~DrawManager() override = default;

    void draw(std::shared_ptr<BaseDrawer> &srcDrawer);

    void setDrawer(const std::shared_ptr<BaseDrawer> srcDrawer);

    void set_camera(const std::shared_ptr<Camera> srcCamera);

    void zBufAlg(std::shared_ptr<Scene> scene, std::shared_ptr<Visitor> visitor, std:: shared_ptr<Light> );

    void updateSizePaint(std::shared_ptr<BaseDrawer> &srcDrawer);

private:
    std::shared_ptr<BaseDrawer> drawer;
    std::shared_ptr<Camera> camera;


};


class DrawManagerCreator {
public:
    std::shared_ptr<DrawManager> getManager();

private:
    void createInstance();

    std::shared_ptr<DrawManager> manager;
};


#endif //LAB_03_DRAW_MANAGER_H
