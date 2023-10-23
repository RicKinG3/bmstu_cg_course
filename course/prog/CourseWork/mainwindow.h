#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "facade/Facade.h"
#include "drawer/BaseDrawer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void setupScene();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<Facade>         facade;
    std::shared_ptr<BaseDrawer>     drawer;



};
#endif // MAINWINDOW_H
