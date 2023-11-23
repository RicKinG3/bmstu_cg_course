#include "draw_manager.h"
#include <QDebug>
#include "/usr/include/eigen3/Eigen/Dense"

#include "frame_model.h"

void DrawManager::draw(std::shared_ptr<BaseDrawer> &srcDrawer) {
    setDrawer(srcDrawer);

    auto sceneManager = SceneManagerCreator().getManager();
    auto scene = sceneManager->getScene();
    set_camera(sceneManager->getCamera());
    std::shared_ptr<Light> lights = sceneManager->getLight();

    drawer->clearScene();

    std::shared_ptr<Visitor> visitor = DrawVisitorFactory(drawer, camera).create();

    zBufAlg(scene, visitor, lights);
}

void DrawManager::updateSizePaint(std::shared_ptr<BaseDrawer> &srcDrawer) {
    setDrawer(srcDrawer);
    auto sceneManager = SceneManagerCreator().getManager();
    auto scene = sceneManager->getScene();
    scene->setHeight(srcDrawer->getHeight());
    scene->setWight(srcDrawer->getHeight());
}



void DrawManager::zBufAlg(std::shared_ptr<Scene> scene, std::shared_ptr<Visitor> visitor, std::shared_ptr<Light> lights) {

    std::vector<std::vector<double>> depthBuffer;
    std::vector<std::vector<size_t>> frameBuffer;
    size_t bufWidth = scene->getWidth();
    size_t bufHeight = scene->getHeight();
    qDebug() << "its scene->getWidth()" << scene->getWidth() << "x" << scene->getHeight();

    for (size_t i = 0; i < bufWidth; i++) {
        depthBuffer.push_back(std::vector<double>(bufHeight, 0));
        frameBuffer.push_back(std::vector<size_t>(bufHeight, 0));
    }
    Eigen::Matrix4f transMatrix; // todo up in obj
    // для каждого из объектов
    for (auto iterator = scene->begin(); iterator != scene->end(); ++iterator) {
        auto object = *iterator;
        if (object->isVisible()) {
           // object->accept(visitor);
           // для каждого

            object->accept(visitor, transMatrix, lights, bufWidth, bufHeight);
        }
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
