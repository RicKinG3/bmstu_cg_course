#include "draw_manager.h"
#include <QDebug>
#include "/usr/include/eigen3/Eigen/Dense"

#include "frame_model.h"

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
//  todo короче нужно получить здесь список всего объекта камер и всего и уже передать в алгос просто чтоб не ебться
//void DrawManager::shadowMapForModel(std::shared_ptr<Object> obj,
//                                    Eigen::Matrix4f &transMat, Light *illum, size_t bufWidth, size_t bufHeight) {
//    std::array<Point, 3> dotsArr;
//    Eigen::Matrix4f toCenter;
//
//    toCenter << 1, 0, 0, 0,
//            0, 1, 0, 0,
//            0, 0, 1, 0,
//            -X_CENTER, -Y_CENTER, -PLATE_Z - 5, 1;
//
//    Eigen::Matrix4f backToStart;
//
//    backToStart << 1, 0, 0, 0,
//            0, 1, 0, 0,
//            0, 0, 1, 0,
//            X_CENTER, Y_CENTER, PLATE_Z + 5, 1;
//
//    std::vector<std::vector<double>> *shadowMap = &illum->getShadowMap();
//    Eigen::Matrix4f illumMat = illum->getTransMat();
//
//    Eigen::Matrix4f dotTransMat = toCenter * transMat * illumMat * backToStart;
//
//    for (size_t curFaceNum = 0; curFaceNum < facets.size(); curFaceNum++) {
//        Eigen::MatrixXf coordinatesVec(3, 4);
//
//        std::vector<size_t> curDots = facets.at(curFaceNum).getUsedVertices();
//        dotsArr[0] = vertices.at(curDots.at(0)).getPosition();
//        dotsArr[1] = vertices.at(curDots.at(1)).getPosition();
//        dotsArr[2] = vertices.at(curDots.at(2)).getPosition();
//
//        coordinatesVec <<
//                       dotsArr[0].getXCoordinate(), dotsArr[0].getYCoordinate(), dotsArr[0].getZCoordinate(), 1,
//                dotsArr[1].getXCoordinate(), dotsArr[1].getYCoordinate(), dotsArr[1].getZCoordinate(), 1,
//                dotsArr[2].getXCoordinate(), dotsArr[2].getYCoordinate(), dotsArr[2].getZCoordinate(), 1;
//
//        coordinatesVec *= dotTransMat;
//        dotsArr[0] =
//                Dot3D(coordinatesVec(0, 0), coordinatesVec(0, 1), coordinatesVec(0, 2));
//        dotsArr[1] =
//                Dot3D(coordinatesVec(1, 0), coordinatesVec(1, 1), coordinatesVec(1, 2));
//        dotsArr[2] =
//                Dot3D(coordinatesVec(2, 0), coordinatesVec(2, 1), coordinatesVec(2, 2));
//
//        if (dotsArr[0].getYCoordinate() > dotsArr[1].getYCoordinate())
//            std::swap(dotsArr[0], dotsArr[1]);
//        if (dotsArr[0].getYCoordinate() > dotsArr[2].getYCoordinate())
//            std::swap(dotsArr[0], dotsArr[2]);
//        if (dotsArr[1].getYCoordinate() > dotsArr[2].getYCoordinate())
//            std::swap(dotsArr[1], dotsArr[2]);
//
//        int x1 = round(dotsArr[0].getXCoordinate());
//        int x2 = round(dotsArr[1].getXCoordinate());
//        int x3 = round(dotsArr[2].getXCoordinate());
//
//        double z1 = dotsArr[0].getZCoordinate();
//        double z2 = dotsArr[1].getZCoordinate();
//        double z3 = dotsArr[2].getZCoordinate();
//
//        int y1 = round(dotsArr[0].getYCoordinate());
//        int y2 = round(dotsArr[1].getYCoordinate());
//        int y3 = round(dotsArr[2].getYCoordinate());
//
//#pragma omp parallel for
//        for (int curY = (y1 < 0) ? 0 : y1;
//             curY < ((y2 >= (int) bufHeight) ? (int) bufHeight - 1 : y2); curY++) {
//            double aInc = 0;
//            if (y1 != y2)
//                aInc = (double) (curY - y1) / (y2 - y1);
//
//            double bInc = 0;
//            if (y1 != y3)
//                bInc = (double) (curY - y1) / (y3 - y1);
//
//            int xA = round(x1 + (x2 - x1) * aInc);
//            int xB = round(x1 + (x3 - x1) * bInc);
//            double zA = z1 + (z2 - z1) * aInc;
//            double zB = z1 + (z3 - z1) * bInc;
//
//            if (xA > xB) {
//                std::swap(xA, xB);
//                std::swap(zA, zB);
//            }
//
//            if (xA < 0)
//                xA = 0;
//            if (xB >= (int) bufWidth)
//                xB = (int) bufWidth - 1;
//
//            interpolateRowIntoShadowMap(shadowMap, xA, xB, zA, zB, curY);
//        }
//
//#pragma omp parallel for
//        for (int curY = (y2 < 0) ? 0 : y2;
//             curY <= ((y3 >= (int) bufHeight) ? (int) bufHeight - 1 : y3); curY++) {
//            double aInc = 0;
//            if (y2 != y3)
//                aInc = (double) (curY - y2) / (y3 - y2);
//
//            double bInc = 0;
//            if (y1 != y3)
//                bInc = (double) (curY - y1) / (y3 - y1);
//
//            int xA = round(x2 + (x3 - x2) * aInc);
//            int xB = round(x1 + (x3 - x1) * bInc);
//            double zA = z2 + (z3 - z2) * aInc;
//            double zB = z1 + (z3 - z1) * bInc;
//
//            if (xA > xB) {
//                std::swap(xA, xB);
//                std::swap(zA, zB);
//            }
//
//            if (xA < 0)
//                xA = 0;
//            if (xB >= (int) bufWidth)
//                xB = (int) bufWidth - 1;
//
//            interpolateRowIntoShadowMap(shadowMap, xA, xB, zA, zB, curY);
//        }
//    }
//}


void DrawManager::zBufAlg(std::shared_ptr<Scene> scene, std::shared_ptr<Visitor> visitor) {

    std::vector<std::vector<double>> depthBuffer;
    std::vector<std::vector<size_t>> frameBuffer;
    size_t bufWidth = scene->getWidth();
    size_t bufHeight = scene->getHeight();
    qDebug() << "its scene->getWidth()" << scene->getWidth() << "x" << scene->getHeight();

    for (size_t i = 0; i < bufWidth; i++) {
        depthBuffer.push_back(std::vector<double>(bufHeight, 0));
        frameBuffer.push_back(std::vector<size_t>(bufHeight, 0));
    }
    // для каждого из объектов
    for (auto iterator = scene->begin(); iterator != scene->end(); ++iterator) {
        auto object = *iterator;
        if (object->isVisible()) {
            object->accept(visitor);
//            // Assuming the object is of type FrameModel
//            std::shared_ptr<FrameModel> frameModel = std::dynamic_pointer_cast<FrameModel>(object);
//            std::shared_ptr<FrameModelStructure> frameModelStructure = frameModel->getModelStructure();
//             frameModelStructure->getFaces();
//             frameModelStructure->getPoints();
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
