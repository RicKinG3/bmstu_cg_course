#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDebug"
#include <QErrorMessage>
#include <QShortcut>
#include <QTimer>

#include "../config/config.hpp"

#include "illuminantplacechooser.hpp"
#include "objecthangman.hpp"
#include "objectchanger.hpp"
#include "placechooser.h"
#include "../headers/specialgraphicsview.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    facade = new UsageFacade;

//    ui->listWidget->setStyleSheet("QListWidget::item {background-color: white;}");
//
//    QListWidgetItem *hourse = new QListWidgetItem("      Дом");
//    ui->listWidget->addItem(hourse);
//
//    QListWidgetItem *tree = new QListWidgetItem("      Дерево");
//    ui->listWidget->addItem(tree);
//
//    QListWidgetItem *road = new QListWidgetItem("      Дорога");
//    ui->listWidget->addItem(road);
//
//    QListWidgetItem *car = new QListWidgetItem("      Машина");
//    ui->listWidget->addItem(car);
//
//    QListWidgetItem *flashlight = new QListWidgetItem("      Источник света");
//    ui->listWidget->addItem(flashlight);
//    ui->listWidget->addItem(flashlight);


    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QShortcut *shortcutDown = new QShortcut(QKeySequence("down"), this);
    QObject::connect(shortcutDown, SIGNAL(activated()), this, SLOT(pictureDown()));

    QShortcut *shortcutUp = new QShortcut(QKeySequence("up"), this);
    QObject::connect(shortcutUp, SIGNAL(activated()), this, SLOT(pictureUp()));

    QShortcut *shortcutLeft = new QShortcut(QKeySequence("left"), this);
    QObject::connect(shortcutLeft, SIGNAL(activated()), this, SLOT(pictureLeft()));

    QShortcut *shortcutRight = new QShortcut(QKeySequence("right"), this);
    QObject::connect(shortcutRight, SIGNAL(activated()), this, SLOT(pictureRight()));

    QShortcut *shortcutScaleUp = new QShortcut(QKeySequence("z"), this);
    QObject::connect(shortcutScaleUp, SIGNAL(activated()), this, SLOT(pictureScaleUp()));

    QShortcut *shortcutScaleDown = new QShortcut(QKeySequence("x"), this);
    QObject::connect(
            shortcutScaleDown, SIGNAL(activated()), this, SLOT(pictureScaleDown()));

    QShortcut *shortcutRotateXRight = new QShortcut(QKeySequence("s"), this);
    QObject::connect(
            shortcutRotateXRight, SIGNAL(activated()), this, SLOT(pictureRotateXRight()));

    QShortcut *shortcutRotateXLeft = new QShortcut(QKeySequence("w"), this);
    QObject::connect(
            shortcutRotateXLeft, SIGNAL(activated()), this, SLOT(pictureRotateXLeft()));

    QShortcut *shortcutRotateYRight = new QShortcut(QKeySequence("a"), this);
    QObject::connect(
            shortcutRotateYRight, SIGNAL(activated()), this, SLOT(pictureRotateYRight()));

    QShortcut *shortcutRotateYLeft = new QShortcut(QKeySequence("d"), this);
    QObject::connect(
            shortcutRotateYLeft, SIGNAL(activated()), this, SLOT(pictureRotateYLeft()));

    QShortcut *shortcutRotateZLeft = new QShortcut(QKeySequence("q"), this);
    QObject::connect(
            shortcutRotateZLeft, SIGNAL(activated()), this, SLOT(pictureRotateZLeft()));

    QShortcut *shortcutRotateZRight = new QShortcut(QKeySequence("e"), this);
    QObject::connect(
            shortcutRotateZRight, SIGNAL(activated()), this, SLOT(pictureRotateZRight()));
}

MainWindow::~MainWindow() { delete ui; }


void MainWindow::pictureDown() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->moveDownScene(MOVE_FACTOR, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureUp() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->moveUpScene(MOVE_FACTOR, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureLeft() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->moveLeftScene(MOVE_FACTOR, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRight() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->moveRightScene(MOVE_FACTOR, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureScaleUp() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->scaleScene(SCALE_COEF + 1, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureScaleDown() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->scaleScene(1 - SCALE_COEF, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRotateXRight() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->rotateXScene(ROTATE_COEF, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRotateXLeft() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->rotateXScene(-ROTATE_COEF, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRotateYRight() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->rotateYScene(ROTATE_COEF, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRotateYLeft() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->rotateYScene(-ROTATE_COEF, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRotateZRight() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->rotateZScene(ROTATE_COEF, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRotateZLeft() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->rotateZScene(-ROTATE_COEF, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureToCenter() {
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->toCenter(ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

#include <QMessageBox>


void MainWindow::on_pushButton_createScene_clicked() {

    if (ui->graphicsView->scene()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Предупреждение",
                                     "При создании новой сцены предыдущая будет удалена. Продолжить?",
                                     QMessageBox::Yes | QMessageBox::No);
        // Проверка ответа пользователя
        if (reply == QMessageBox::Yes) {
            delete ui->graphicsView->scene();
        } else {
            return;
        }

    }
    int h = ui->length_scene->value();
    int w = ui->width_scene->value();


    facade->setCellScene(w, h);
    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());


    ui->graphicsView->setScene(setScene);
}

enum ObjIndex {
    baseHome,
    premiumHome,
    road,
    tratuaru,
    carGrey,
    carRed,
    tree,
    bush
};


enum RetCodeAddObjToScene {
    pass,
    sq_full,
    obj_over_range,
    car_only_on_road,
    road_home,
    err
};

bool MainWindow::isSetScene() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return false;
    }
    return true;
}

void MainWindow::drawThisShit() {
    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}

Direction MainWindow::getDeirection() {
    if (ui->objDirection_ox->isChecked()) {
        qDebug() << "objDirection_ox 1 is checked";
        return Horizontal;
    } else if (ui->objDirection_oy->isChecked()) {
        return Vertical;
        qDebug() << "objDirection_oy 2 is checked";
    } else {
        qDebug() << "No RadioButton is checked";
        return Nodirection;
    }
    return Nodirection;
}

void MainWindow::on_pushButton_light_add_clicked() {
    if (!isSetScene())
        return;
    int deg_ox = ui->deg_ox->value();
    int deg_oy = ui->deg_oy->value();
    qDebug() << "deg_ox = " << deg_ox;
    qDebug() << "deg_oy= " << deg_oy;
    facade->addLight(deg_ox, deg_oy);

    drawThisShit();
}

#define BASE_LENX_HOUSE 3
#define BASE_LENY_HOUSE 2
#define BASE_LENZ_HOUSE 1

#define PREMIUM_LENX_HOUSE 3
#define PREMIUM_LENY_HOUSE 3
#define PREMIUM_LENZ_HOUSE 2


//todo del cast (
void MainWindow::on_pushButton_addModel_clicked() {
    if (!isSetScene())
        return;

    ObjIndex cur_obj = static_cast<ObjIndex>(ui->choose_obj->currentIndex());
    qDebug() << "index = " << cur_obj;

    int sq_num_ox = ui->num_sq_ox->value();
    int sq_num_oy = ui->num_sq_oy->value();
    qDebug() << "sq_num_ox = " << sq_num_ox;
    qDebug() << "sq_num_oy = " << sq_num_oy;

    Direction objDirection = getDeirection();

    RetCodeAddObjToScene rc = pass;
    ColorCar color_car;

    switch (cur_obj) {
        case baseHome:
            qDebug() << "choose base home";
            //todo recode
            rc = static_cast<RetCodeAddObjToScene>(facade->addHouse(sq_num_ox, sq_num_oy, BASE_LENX_HOUSE, BASE_LENY_HOUSE, BASE_LENZ_HOUSE));
            break;
        case premiumHome:
        //todo add garag
            qDebug() << "choose premiumHome";
            rc = static_cast<RetCodeAddObjToScene>(facade->addHouse(sq_num_ox, sq_num_oy, PREMIUM_LENX_HOUSE, PREMIUM_LENY_HOUSE, PREMIUM_LENZ_HOUSE));
            break;
        case road:
            rc = static_cast<RetCodeAddObjToScene>(facade->addRoad(sq_num_ox, sq_num_oy, objDirection));
            qDebug() << "choose road";
            break;
        case tratuaru:
            qDebug() << "choose tratuaru";
            break;
        case carGrey:
            qDebug() << "choose carGrey";
            color_car =  grey;
            rc = static_cast<RetCodeAddObjToScene>(facade->addCar(sq_num_ox, sq_num_oy, objDirection, color_car));
            break;
        case carRed:
            qDebug() << "choose carRed";
            rc = static_cast<RetCodeAddObjToScene>(facade->addPickup(sq_num_ox, sq_num_oy, objDirection, color_car));
            break;
        case tree:
            qDebug() << "choose tree";
            rc = static_cast<RetCodeAddObjToScene>(facade->addTree(sq_num_ox, sq_num_oy));
            break;
        case bush:
            qDebug() << "choose bush";
            break;
        default:
            qDebug() << "error choose";
            QErrorMessage *err = new QErrorMessage();
            err->showMessage("Некорректный выбор объекта");
            return;
    }
    //todo msg only one
    QErrorMessage *err = new QErrorMessage();
    switch (rc) {
        case sq_full:
            err->showMessage("Некоторые из выбранных ячеек заняты");
            return;
        case obj_over_range:
            err->showMessage("Объект не влезает в сцену");
            return;
        case car_only_on_road:
            err->showMessage("Машины разрешено ставить только на доргах");
            return;
        case road_home:
            err->showMessage("Дороги не должны прилегать к дому");
            return;
        default:
            break;
    }

    drawThisShit();


//    todo dell listWidget
//    int curRow = this->ui->listWidget->currentRow();
//    if (curRow < 0)
//        return;
//
//    if (curRow >= 0 && curRow < 4) {
//        int retCode = 0;
//
//        if (curRow == 0) {
//            PlaceHouseChooser placeHouseChooserWindow(nullptr);
//            placeHouseChooserWindow.setModal(true);
//            placeHouseChooserWindow.exec();
//
//            if (placeHouseChooserWindow.status == PlaceHouseChooser::OK)
//                retCode = facade->addHouse(
//                        placeHouseChooserWindow.getXCell(),
//                        placeHouseChooserWindow.getYCell(),
//                        placeHouseChooserWindow.getModelLength(),
//                        placeHouseChooserWindow.getModelHeight(),
//                        placeHouseChooserWindow.getHouseHeight());
//            else
//                return;
//        } else if (curRow == 1) {
//            PlaceTreeChooser PlaceTreeChooserWindow(nullptr);
//            PlaceTreeChooserWindow.setModal(true);
//            PlaceTreeChooserWindow.exec();
//
//            if (PlaceTreeChooserWindow.status == PlaceTreeChooser::OK)
//                retCode = facade->addTree(
//                        PlaceTreeChooserWindow.getXCell(),
//                        PlaceTreeChooserWindow.getYCell());
//            else
//                return;
//}
//
//else if (curRow == 2) {
//PlaceRoadChooser PlaceRoadChooserWindow(nullptr);
//PlaceRoadChooserWindow.setModal(true);
//PlaceRoadChooserWindow.
//
//exec();
//
//if (PlaceRoadChooserWindow.status == PlaceRoadChooser::OK)
//retCode = facade->addRoad(
//        PlaceRoadChooserWindow.getXCell(),
//        PlaceRoadChooserWindow.getYCell(),
//        PlaceRoadChooserWindow.getDirection());
//else
//return;
//        } else if (curRow == 3) {
//            PlaceCarChooser PlaceCarChooserWindow(nullptr);
//            PlaceCarChooserWindow.setModal(true);
//            PlaceCarChooserWindow.exec();
//
//            if (PlaceCarChooserWindow.status == PlaceCarChooser::OK)
//                retCode = facade->addCar(
//                        PlaceCarChooserWindow.getXCell(),
//                        PlaceCarChooserWindow.getYCell(),
//                        PlaceCarChooserWindow.getDirection());
//            else
//                return;
//        }
//
//
//        if (retCode == 1) {
//            QErrorMessage *err = new QErrorMessage();
//            err->showMessage("Некоторые из выбранных ячеек заняты");
//            return;
//        } else if (retCode == 2) {
//            QErrorMessage *err = new QErrorMessage();
//            err->showMessage("Объект не влезает в сцену");
//            return;
//        } else if (retCode == 3) {
//            QErrorMessage *err = new QErrorMessage();
//            err->showMessage("Машины разрешено ставить только на доргах");
//            return;
//        } else if (retCode == 4) {
//            QErrorMessage *err = new QErrorMessage();
//            err->showMessage("Дороги не должны прилегать к дому");
//            return;
//        }
//    } else {
//        IlluminantPlaceChooser placeIlluminantChooserWindow(nullptr);
//        placeIlluminantChooserWindow.setModal(true);
//        placeIlluminantChooserWindow.exec();
//
//        if (placeIlluminantChooserWindow.status == IlluminantPlaceChooser::OK)
//            facade->addLight(
//                    placeIlluminantChooserWindow.getXAngle(),
//                    placeIlluminantChooserWindow.getYAngle());
//        else
//            return;
//    }


}


void MainWindow::on_pushButton_deleteModel_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    ObjectHangman objectHangmanWindow(facade->getScene(), nullptr);
    objectHangmanWindow.setModal(true);
    objectHangmanWindow.exec();

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}


void MainWindow::on_pushButton_moveModel_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    ObjectChanger objectChangerWindow(facade, nullptr);
    objectChangerWindow.setModal(true);
    objectChangerWindow.exec();

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}

void MainWindow::on_pushButton_sceneToInitianPosition_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    QGraphicsScene *setScene = facade->toCenter(ui->graphicsView->rect());

    ui->graphicsView->setScene(setScene);
}


void MainWindow::on_pushButton_up_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureRotateXLeft();
}

void MainWindow::on_pushButton_down_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureRotateXRight();
}

void MainWindow::on_pushButton_left_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureRotateYRight();
}

void MainWindow::on_pushButton_right_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureRotateYLeft();
}

void MainWindow::on_pushButton_leftCircle_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureRotateZRight();
}

void MainWindow::on_pushButton_rightCircle_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureRotateZLeft();
}


void MainWindow::on_pushButton_up_scene_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureUp();
}

void MainWindow::on_pushButton_down_scene_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureDown();
}

void MainWindow::on_pushButton_left_scene_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureLeft();
}

void MainWindow::on_pushButton_right_scene_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureRight();
}


void MainWindow::on_pushButton_zoom_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureScaleUp();
}

void MainWindow::on_pushButton_distance_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureScaleDown();
}
