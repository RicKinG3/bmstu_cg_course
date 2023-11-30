#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QShortcut>
#include <QTimer>
#include <QMessageBox>
#include <QErrorMessage>

#include "config.h"

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

void MainWindow::drawThisShit() {
    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());
    delScene();
    ui->graphicsView->setScene(setScene);
}

Direction MainWindow::getDeirection() {
    if (ui->objDirection_ox->isChecked()) {
//        qDebug() << "objDirection_ox 1 is checked";
        return Horizontal;
    } else if (ui->objDirection_oy->isChecked()) {
        return Vertical;
//        qDebug() << "objDirection_oy 2 is checked";
    } else {
//        qDebug() << "No RadioButton is checked";
        return Nodirection;
    }
    return Nodirection;
}

//todo check add 1 light
//need fors go back
void MainWindow::on_pushButton_light_add_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    int deg_ox = ui->deg_ox->value();
    int deg_oy = ui->deg_oy->value();
//    qDebug() << "deg_ox = " << deg_ox;
//    qDebug() << "deg_oy= " << deg_oy;
    facade->addLight(deg_ox, deg_oy);

    drawThisShit();
}

void MainWindow::showErrorAddModel(RetCodeAddObjToScene rc) {

    switch (rc) {
        case sq_full:
            showErrorMessage("Некоторые из выбранных квадратов заняты");
            return;
        case obj_over_range:
            showErrorMessage("Объект полностью не помещается на платформу");
            return;
        case car_only_on_road:
            showErrorMessage("Машину можно поставить только на дорогу");
            return;
        case road_home:
            //todo del this shit
            showErrorMessage("Дороги не должны прилегать к дому");
            return;
        default:
            break;
    }

}

void MainWindow::printListObj() {
    Platform *scene = facade->getScene();
    Model model;
    Model::model_t modelType_;
    int count = 0;
    ui->objListActiv->clear();

    for (size_t i = 0; i < scene->getModelsNum(); i++) {
        model = scene->getModel(i);
        modelType_ = model.getModelType();

        if (modelType_ == Model::model_t::House || \
            modelType_ == Model::model_t::TreeFoliage || \
            modelType_ == Model::model_t::RoadAsphalt || \
            modelType_ == Model::model_t::Car||
            modelType_ == Model::model_t::Bush) {
            count++;
            ui->objListActiv->addItem(
                    QString::number(count) + ". " +
                    scene->getModel(i).getName() + " - (" +
                    QString::number(scene->getModel(i).getUsedXSq() + 1) + "; " +
                    QString::number(scene->getModel(i).getUsedYSq() + 1) + ")");
        }
    }
}


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
//            qDebug() << "choose base home";
            rc = static_cast<RetCodeAddObjToScene>(facade->addHouse(sq_num_ox, sq_num_oy, BASE_LENX_HOUSE,
                                                                    BASE_LENY_HOUSE, BASE_LENZ_HOUSE));
            break;
        case premiumHome:
            //todo add garaj
//            qDebug() << "choose premiumHome";
            rc = static_cast<RetCodeAddObjToScene>(facade->addHouse(sq_num_ox, sq_num_oy, PREMIUM_LENX_HOUSE,
                                                                    PREMIUM_LENY_HOUSE, PREMIUM_LENZ_HOUSE));
            break;
        case road:
            rc = static_cast<RetCodeAddObjToScene>(facade->addRoad(sq_num_ox, sq_num_oy, objDirection));
//            qDebug() << "choose road";
            break;
        case tratuaru:
            qDebug() << "choose tratuaru";
            break;
        case carGrey:
//            qDebug() << "choose carGrey";
            color_car = grey;
            rc = static_cast<RetCodeAddObjToScene>(facade->addCar(sq_num_ox, sq_num_oy, objDirection, color_car));
            break;
        case carRed:
            //todo
            qDebug() << "choose carRed";
            rc = static_cast<RetCodeAddObjToScene>(facade->addPickup(sq_num_ox, sq_num_oy, objDirection, color_car));
            break;
        case tree:
//            qDebug() << "choose tree";
            rc = static_cast<RetCodeAddObjToScene>(facade->addTree(sq_num_ox, sq_num_oy));
            break;
        case bush:
            qDebug() << "choose bush";
            rc = static_cast<RetCodeAddObjToScene>(facade->addBush(sq_num_ox, sq_num_oy));
            break;
        default:
            qDebug() << "error choose";
            showErrorMessage("Некорректный выбор объекта");
            return;
    }
    showErrorAddModel(rc);
    printListObj();
    drawThisShit();
}
//  todo optimus ptime 3
void MainWindow::on_pushButton_deleteModel_clicked() {
    if (!facade->isSceneSet()) {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }
    Platform *scene = facade->getScene();
    size_t curRow = size_t(this->ui->objListActiv->currentRow());

    if (curRow < 0)
        return;

    size_t modelsNum = scene->getModelsNum();
    size_t realModelsNum = scene->getRealModelsNum();
    bool flag = false;
    Model model;
    Model::model_t modelType_;

    if (curRow < realModelsNum) {
        for (size_t i = 0; i < modelsNum; i++) {
            model = scene->getModel(i);

            if (model.getModelNum() == curRow) {
                modelType_ = model.getModelType();

                if ((modelType_ == Model::model_t::RoadAsphalt || \
                      modelType_ == Model::model_t::RoadStripe) && \
                      scene->getUsedSquares()[model.getUsedYSq()][model.getUsedXSq()] == 4) {
                    close();
                    QErrorMessage *err = new QErrorMessage();
                    err->showMessage("Нельзя удалить дорогу, так как на ней расположена машина");
                    return;
                } else {
                    scene->deleteModel(i);

                    flag = true;
                    modelsNum--;
                    i--;
                }
            } else if (flag) {
                break;
            }
        }

        recalculationModelsNum();
        printListObj();
    } else {
        scene->delLight(curRow - realModelsNum);
    }

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}


int MainWindow::changeModel(Model &model, int newXCell, int newYCell) {
    int resultCode = 0;

    switch (model.getModelType()) {
        case Model::House:
            resultCode = facade->addHouse(newXCell, newYCell,
                                          model.getWidthModel(),
                                          model.getHeightModel(),
                                          model.getHouseHeight());
            break;
        case Model::TreeFoliage:
            resultCode = facade->addTree(newXCell, newYCell);
            break;
        case Model::RoadAsphalt:
            resultCode = facade->addRoad(newXCell, newYCell,
                                         model.getDirectionRoad());
            break;
        case Model::Car:
            resultCode = facade->addCar(newXCell, newYCell,
                                        model.getDirectionCar(), model.getColorCar());
            break;
        default:
            // Обработка неизвестного типа модели, если это необходимо
            break;
    }
    return resultCode;
}

//todo
void MainWindow::recalculationModelsNum() {
    Platform *scene = facade->getScene();
    size_t realModelsNum = scene->getRealModelsNum();
    Model model;
    int cur = 0;

    for (size_t i = 0; i < realModelsNum; i++) {
        model = scene->getModel(cur);
        int border = (model.getModelType() == Model::House || model.getModelType() == Model::Car) ? 3 : 2;

        for (int j = 0; j < border; j++) {
            scene->getModel(cur++).setModelNum(i);
        }
    }
}

void MainWindow::on_pushButton_moveModel_clicked() {
    if (!isSetPlatformErrMSG())
        return;

    size_t curRow = size_t(this->ui->objListActiv->currentRow());
    if (curRow >= facade->getScene()->getModelsNum()) {
        qDebug() << "cur row > model num ";
        return;
    }

    Platform *scene = facade->getScene();
    size_t modelsNum = scene->getModelsNum();
    Model model;
    Model::model_t modelType_;
    bool flag = false;

    int sq_num_ox = ui->num_sq_ox->value();
    int sq_num_oy = ui->num_sq_oy->value();

    RetCodeAddObjToScene rc = pass;
    for (size_t i = 0; i < modelsNum; i++) {
        model = scene->getModel(i);

        if (model.getModelNum() == curRow) {
            modelType_ = model.getModelType();

            if ((modelType_ == Model::model_t::RoadAsphalt || \
                      modelType_ == Model::model_t::RoadStripe) && \
                      scene->getUsedSquares()[model.getUsedYSq()][model.getUsedXSq()] == 4) {
                //    close();
                showErrorMessage("Нельзя переместить дорогу, так как на ней расположена машина");
                return;
            } else {
                scene->clearUsedSquares(i);
                rc = static_cast<RetCodeAddObjToScene>( changeModel(scene->getModel(i),
                                                                    sq_num_ox,
                                                                    sq_num_oy));
                if (rc != pass) {
                    showErrorAddModel(rc);
                    return;
                }

                scene->deleteModel(i);
                scene->markUsedSquares(scene->getModelsNum() - 1);
                scene->printUsedSquares();


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
    if (!isSetPlatformErrMSG())
        return;
    delScene();
    ui->graphicsView->setScene(facade->toCenter(ui->graphicsView->rect()));
}


void MainWindow::on_pushButton_up_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    pictureRotateXLeft();
}

void MainWindow::on_pushButton_down_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    pictureRotateXRight();
}

void MainWindow::on_pushButton_left_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    pictureRotateYRight();
}

void MainWindow::on_pushButton_right_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    pictureRotateYLeft();
}

void MainWindow::on_pushButton_leftCircle_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    pictureRotateZRight();
}

void MainWindow::on_pushButton_rightCircle_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    pictureRotateZLeft();
}


void MainWindow::on_pushButton_up_scene_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    pictureUp();
}

void MainWindow::on_pushButton_down_scene_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    pictureDown();
}

void MainWindow::on_pushButton_left_scene_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    pictureLeft();
}

void MainWindow::on_pushButton_right_scene_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    pictureRight();
}


void MainWindow::on_pushButton_zoom_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    pictureScaleUp();
}

void MainWindow::on_pushButton_distance_clicked() {
    if (!isSetPlatformErrMSG())
        return;
    pictureScaleDown();
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