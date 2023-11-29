#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QShortcut>
#include <QTimer>
#include <QMessageBox>
#include <QErrorMessage>

#include "config.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    facade = new UsageFacade;

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

void MainWindow::showErrorMessage(const QString &message) {
    QErrorMessage *err = new QErrorMessage(this);
    err->showMessage(message);
}

bool MainWindow::isSetPlatformErrMSG() {
    if (!facade->isSceneSet()) {
        showErrorMessage("Сцена ещё не была задана.");
        return false;
    }
    return true;
}

void MainWindow::delScene() {
    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
}

void MainWindow::pictureDown() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->moveDownScene(MOVE_FACTOR, ui->graphicsView->rect()));
}

void MainWindow::pictureUp() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->moveUpScene(MOVE_FACTOR, ui->graphicsView->rect()));
}

void MainWindow::pictureLeft() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->moveLeftScene(MOVE_FACTOR, ui->graphicsView->rect()));
}

void MainWindow::pictureRight() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->moveRightScene(MOVE_FACTOR, ui->graphicsView->rect()));
}

void MainWindow::pictureScaleUp() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->scaleScene(SCALE_COEF + 1, ui->graphicsView->rect()));
}

void MainWindow::pictureScaleDown() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->scaleScene(1 - SCALE_COEF, ui->graphicsView->rect()));
}

void MainWindow::pictureRotateXRight() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->rotateXScene(ROTATE_COEF, ui->graphicsView->rect()));
}

void MainWindow::pictureRotateXLeft() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->rotateXScene(-ROTATE_COEF, ui->graphicsView->rect()));
}

void MainWindow::pictureRotateYRight() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->rotateYScene(ROTATE_COEF, ui->graphicsView->rect()));
}

void MainWindow::pictureRotateYLeft() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->rotateYScene(-ROTATE_COEF, ui->graphicsView->rect()));
}

void MainWindow::pictureRotateZRight() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->rotateZScene(ROTATE_COEF, ui->graphicsView->rect()));
}

void MainWindow::pictureRotateZLeft() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->rotateZScene(-ROTATE_COEF, ui->graphicsView->rect()));
}

void MainWindow::pictureToCenter() {
    if (!facade->isSceneSet())
        return;
    delScene();
    ui->graphicsView->setScene(facade->toCenter(ui->graphicsView->rect()));
}


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
    ui->graphicsView->setScene(facade->drawScene(ui->graphicsView->rect()));
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
    if (!isSetPlatformErrMSG())
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
    if (!isSetPlatformErrMSG())
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
            rc = static_cast<RetCodeAddObjToScene>(facade->addHouse(sq_num_ox, sq_num_oy, BASE_LENX_HOUSE,
                                                                    BASE_LENY_HOUSE, BASE_LENZ_HOUSE));
            break;
        case premiumHome:
            //todo add garag
            qDebug() << "choose premiumHome";
            rc = static_cast<RetCodeAddObjToScene>(facade->addHouse(sq_num_ox, sq_num_oy, PREMIUM_LENX_HOUSE,
                                                                    PREMIUM_LENY_HOUSE, PREMIUM_LENZ_HOUSE));
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
            color_car = grey;
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

    CellScene *scene = facade->getScene();
    PolModel model;
    PolModel::model_t modelType_;
    int count = 0;
    ui->objListActiv->clear();

    for (size_t i = 0; i < scene->getModelsNum(); i++) {
        model = scene->getModel(i);
        modelType_ = model.getModelType();

        if (modelType_ == PolModel::model_t::House || \
            modelType_ == PolModel::model_t::treeFoliage || \
            modelType_ == PolModel::model_t::roadAsphalt || \
            modelType_ == PolModel::model_t::Car) {
            count++;
            ui->objListActiv->addItem(
                    QString::number(count) + ". " +
                    scene->getModel(i).getName() + " - (" +
                    QString::number(scene->getModel(i).getUsedXCell() + 1) + "; " +
                    QString::number(scene->getModel(i).getUsedYCell() + 1) + ")");
        }
    }


    drawThisShit();


}

//todo
//
void MainWindow::on_pushButton_deleteModel_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

//    ObjectHangman objectHangmanWindow(facade->getScene(), nullptr);
//    objectHangmanWindow.setModal(true);
//    objectHangmanWindow.exec();

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}


int MainWindow::changeModel(PolModel &model, int newXCell, int newYCell) {
    int retCode = 0;

    PolModel::model_t modelType_ = model.getModelType();

    if (modelType_ == PolModel::model_t::House) {
        retCode = facade->addHouse(newXCell, newYCell,
                                   model.getWidthModel(),
                                   model.getHeightModel(),
                                   model.getHouseHeight());
    } else if (modelType_ == PolModel::model_t::treeFoliage) {
        retCode = facade->addTree(newXCell, newYCell);
    } else if (modelType_ == PolModel::model_t::roadAsphalt) {
        retCode = facade->addRoad(newXCell, newYCell,
                                  model.getDirectionRoad());
    } else if (modelType_ == PolModel::model_t::Car) {
        retCode = facade->addCar(newXCell, newYCell,
                                 model.getDirectionCar(), model.getColorCar());
    }

    return retCode;
}

void MainWindow::recalculationModelsNum() {
    CellScene *scene = facade->getScene();
    size_t realModelsNum = scene->getRealModelsNum();
    PolModel model;
    PolModel::model_t modelType_;
    int cur = 0, border = 0;

    for (size_t i = 0; i < realModelsNum; i++) {
        model = scene->getModel(cur);
        modelType_ = model.getModelType();

        if (modelType_ == PolModel::model_t::House || \
            modelType_ == PolModel::model_t::Car) {
            border = 3;
        } else {
            border = 2;
        }

        for (int j = 0; j < border; j++) {
            scene->getModel(cur).setModelNum(i);
            cur++;
        }
    }
}


void MainWindow::on_pushButton_moveModel_clicked() {
    if (!isSetPlatformErrMSG())
        return;

    size_t curRow = size_t(this->ui->objListActiv->currentRow());

    CellScene *scene = facade->getScene();
    size_t modelsNum = scene->getModelsNum();
    PolModel model;
    PolModel::model_t modelType_;
    bool flag = false;

    int sq_num_ox = ui->num_sq_ox->value();
    int sq_num_oy = ui->num_sq_oy->value();


    for (size_t i = 0; i < modelsNum; i++) {
        model = scene->getModel(i);

        if (model.getModelNum() == curRow) {
            modelType_ = model.getModelType();

            if ((modelType_ == PolModel::model_t::roadAsphalt || \
                      modelType_ == PolModel::model_t::roadStripe) && \
                      scene->getUsedCells()[model.getUsedYCell()][model.getUsedXCell()] == 4) {
                close();
                QErrorMessage *err = new QErrorMessage();
                err->showMessage("Нельзя переместить дорогу, так как на ней расположена машина");
                return;
            } else {
                scene->clearUsedCells(i);
                int retCode = changeModel(scene->getModel(i),
                                          sq_num_ox,
                                          sq_num_oy);

                if (retCode == 1) {
                    close();
                    scene->markUsedCells(i);
                    QErrorMessage *err = new QErrorMessage();
                    err->showMessage("Некоторые из выбранных ячеек заняты");
                    return;
                } else if (retCode == 2) {
                    close();
                    scene->markUsedCells(i);
                    QErrorMessage *err = new QErrorMessage();
                    err->showMessage("Объект не влезает в сцену");
                    return;
                } else if (retCode == 3) {
                    close();
                    scene->markUsedCells(i);
                    QErrorMessage *err = new QErrorMessage();
                    err->showMessage("Машины разрешено ставить только на доргах");
                    return;
                } else if (retCode == 4) {
                    close();
                    scene->markUsedCells(i);
                    QErrorMessage *err = new QErrorMessage();
                    err->showMessage("Дороги не должны прилегать к дому");
                    return;
                } else {
                    scene->deleteModel(i);
                    scene->markUsedCells(scene->getModelsNum() - 1);
                    scene->printUsedCells();
                }

                flag = true;
                modelsNum--;
                i--;
            }
        } else if (flag) {
            break;
        }
    }
    recalculationModelsNum();

    drawThisShit();
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
