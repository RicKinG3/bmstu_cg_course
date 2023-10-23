#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "drawer/AbstractDrawerFactory.h"
#include "drawer/QtDrawerFactory.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupScene();

    facade = std::make_unique<Facade>();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupScene()
{
    scene = std::make_shared<QGraphicsScene>(this);
    ui->graphicsView->setScene(scene.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    scene->setSceneRect(-(ui->graphicsView->width()) / 2, -(ui->graphicsView->height()) / 2,
                        ui->graphicsView->width() / 2, ui->graphicsView->height() / 2);

    std::unique_ptr<AbstractDrawerFactory> factory = std::make_unique<QtDrawerFactory>(scene);
    drawer = factory->create();
}
