#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QMainWindow>
#include <QMouseEvent>

#include "usagefacade.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

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

#define BASE_LENX_HOUSE 3
#define BASE_LENY_HOUSE 2
#define BASE_LENZ_HOUSE 1

#define PREMIUM_LENX_HOUSE 3
#define PREMIUM_LENY_HOUSE 3
#define PREMIUM_LENZ_HOUSE 2

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_pushButton_light_add_clicked();

    void on_pushButton_createScene_clicked();

    void on_pushButton_sceneToInitianPosition_clicked();

    void on_pushButton_addModel_clicked();

    void on_pushButton_deleteModel_clicked();

    void on_pushButton_moveModel_clicked();

    void pictureDown();

    void pictureUp();

    void pictureLeft();

    void pictureRight();

    void pictureScaleUp();

    void pictureScaleDown();

    void pictureRotateXRight();

    void pictureRotateXLeft();

    void pictureRotateYRight();

    void pictureRotateYLeft();

    void pictureRotateZRight();

    void pictureRotateZLeft();

    void pictureToCenter();

    void on_pushButton_up_clicked();

    void on_pushButton_down_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_leftCircle_clicked();

    void on_pushButton_rightCircle_clicked();

    void on_pushButton_up_scene_clicked();

    void on_pushButton_down_scene_clicked();

    void on_pushButton_left_scene_clicked();

    void on_pushButton_right_scene_clicked();

    void on_pushButton_zoom_clicked();

    void on_pushButton_distance_clicked();

private:
    int changeModel(Model &model, int newXCell, int newYCell);

    void recalculationModelsNum();

    void showErrorMessage(const QString &message);

    bool isSetPlatformErrMSG();

    void drawThisShit();

    void delScene();

    Direction getDeirection();

    void showErrorAddModel(RetCodeAddObjToScene rc);
    void printListObj();

    Ui::MainWindow *ui;
    UsageFacade *facade;
};

#endif // MAINWINDOW_H
