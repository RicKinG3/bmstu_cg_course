#include "draw_manager.h"
#include <QDebug>


void DrawManager::draw(std::shared_ptr<BaseDrawer> &srcDrawer) {
    setDrawer(srcDrawer);

    auto sceneManager = SceneManagerCreator().getManager();
    auto scene = sceneManager->getScene();

    set_camera(sceneManager->getCamera());

    drawer->clearScene();


    std::shared_ptr<Visitor> visitor = DrawVisitorFactory(drawer, camera).create();

    zBufAlg(scene, visitor);
}

void DrawManager::updateSizePaint(std::shared_ptr<BaseDrawer> &srcDrawer) {
    setDrawer(srcDrawer);
    auto sceneManager = SceneManagerCreator().getManager();
    auto scene = sceneManager->getScene();
    scene->setHeight(srcDrawer->getHeight());
    scene->setWight(srcDrawer->getHeight());
}


void DrawManager::zBufAlg(std::shared_ptr<Scene> scene, std::shared_ptr<Visitor> visitor) {

    std::vector<std::vector<double>> depthBuffer;
    std::vector<std::vector<size_t>> frameBuffer;
    size_t bufWidth = scene->getWidth() ;
    size_t bufHeight = scene->getHeight();
    qDebug() << "its scene->getWidth()" << scene->getWidth() << "x" << scene->getHeight();

    for (size_t i = 0; i < bufWidth; i++) {
        depthBuffer.push_back(std::vector<double>(bufHeight, 0));
        frameBuffer.push_back(std::vector<size_t>(bufHeight, 0));
    }

    for (size_t i = 0; i < scene->getModelsNum(); i++)
    {
        model = scene->getModel(i);
        facets = model.getFacets();
        vertices = model.getVertices();
        for (size_t j = 0; j < scene->getIllumNum(); j++)
            shadowMapForModel(facets, vertices, scene->getTransMatrix(),
                              &scene->getIlluminant(j), bufWidth, bufHeight);
    }

    for (auto iterator = scene->begin(); iterator < scene->end(); iterator++) {
        auto object = *iterator;
        object->accept(visitor);
    }
}

void DrawManager::setDrawer(const std::shared_ptr<BaseDrawer> srcDrawer) {
    drawer = std::move(srcDrawer);
}

void DrawManager::set_camera(const std::shared_ptr<Camera> srcCamera) {
    camera = std::move(srcCamera);
}


std::shared_ptr<DrawManager> DrawManagerCreator::getManager() {
    if (manager == nullptr) {
        createInstance();
    }

    return manager;
}

void DrawManagerCreator::createInstance() {
    manager = std::make_shared<DrawManager>();
}
