#include "draw_manager.h"


void DrawManager::draw(std::shared_ptr<BaseDrawer> &srcDrawer)
{
    setDrawer(srcDrawer);

    auto sceneManager = SceneManagerCreator().getManager();
    auto scene = sceneManager->getScene();

    set_camera(sceneManager->getCamera());

    drawer->clearScene();

    std::shared_ptr<Visitor> visitor = DrawVisitorFactory(drawer, camera).create();

    for (auto iterator = scene->begin(); iterator < scene->end(); iterator++)
    {
        auto object = *iterator;
        object->accept(visitor);
    }
}

void DrawManager::setDrawer(const std::shared_ptr<BaseDrawer> srcDrawer)
{
    drawer = std::move(srcDrawer);
}

void DrawManager::set_camera(const std::shared_ptr<Camera> srcCamera)
{
    camera = std::move(srcCamera);
}


std::shared_ptr<DrawManager> DrawManagerCreator::getManager()
{
    if (manager == nullptr)
    {
        createInstance();
    }

    return manager;
}

void DrawManagerCreator::createInstance()
{
    manager = std::make_shared<DrawManager>();
}
