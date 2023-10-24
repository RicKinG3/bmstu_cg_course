/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *clearSceneButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_6;
    QComboBox *modelsList;
    QPushButton *deleteModelButton;
    QPushButton *deleteAllModelsButton;
    QPushButton *loadModelButton;
    QGroupBox *groupBox_3;
    QDoubleSpinBox *dxModelInput;
    QDoubleSpinBox *dyModelInput;
    QDoubleSpinBox *dzModelInput;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *moveModelButton;
    QGroupBox *groupBox_4;
    QDoubleSpinBox *kzModelInput;
    QLabel *label_4;
    QDoubleSpinBox *kxModelInput;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *kyModelInput;
    QPushButton *scaleModelButton;
    QGroupBox *groupBox_5;
    QDoubleSpinBox *ozModelInput;
    QLabel *label_7;
    QDoubleSpinBox *oxModelInput;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *oyModelInput;
    QPushButton *rotateModelButton;
    QWidget *tab_2;
    QGroupBox *groupBox_9;
    QDoubleSpinBox *ozCameraInput;
    QLabel *label_13;
    QDoubleSpinBox *oxCameraInput;
    QLabel *label_14;
    QLabel *label_15;
    QDoubleSpinBox *oyCameraInput;
    QPushButton *rotateCameraButton;
    QGroupBox *groupBox_8;
    QDoubleSpinBox *dxCameraInput;
    QDoubleSpinBox *dyCameraInput;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *moveCameraButton;
    QGroupBox *groupBox_10;
    QPushButton *addCameraButton;
    QLabel *label_16;
    QLabel *label_17;
    QDoubleSpinBox *xCameraInput;
    QDoubleSpinBox *yCameraInput;
    QLabel *label_19;
    QDoubleSpinBox *oxCameraInput_2;
    QDoubleSpinBox *oyCameraInput_2;
    QLabel *label_20;
    QLabel *label_21;
    QDoubleSpinBox *ozCameraInput_2;
    QGroupBox *groupBox_7;
    QComboBox *camerasList;
    QPushButton *deleteCameraButton;
    QPushButton *loadCameraButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1082, 620);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(480, 10, 600, 600));
        clearSceneButton = new QPushButton(centralwidget);
        clearSceneButton->setObjectName(QStringLiteral("clearSceneButton"));
        clearSceneButton->setGeometry(QRect(20, 520, 441, 40));
        QFont font;
        font.setPointSize(9);
        clearSceneButton->setFont(font);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 441, 451));
        QFont font1;
        font1.setPointSize(11);
        tabWidget->setFont(font1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 10, 421, 181));
        groupBox_6->setFont(font);
        groupBox_6->setAlignment(Qt::AlignCenter);
        modelsList = new QComboBox(groupBox_6);
        modelsList->setObjectName(QStringLiteral("modelsList"));
        modelsList->setGeometry(QRect(10, 30, 401, 28));
        deleteModelButton = new QPushButton(groupBox_6);
        deleteModelButton->setObjectName(QStringLiteral("deleteModelButton"));
        deleteModelButton->setGeometry(QRect(10, 70, 401, 29));
        deleteAllModelsButton = new QPushButton(groupBox_6);
        deleteAllModelsButton->setObjectName(QStringLiteral("deleteAllModelsButton"));
        deleteAllModelsButton->setGeometry(QRect(10, 100, 401, 29));
        loadModelButton = new QPushButton(groupBox_6);
        loadModelButton->setObjectName(QStringLiteral("loadModelButton"));
        loadModelButton->setGeometry(QRect(10, 140, 401, 29));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 200, 111, 181));
        groupBox_3->setFont(font);
        groupBox_3->setAlignment(Qt::AlignCenter);
        dxModelInput = new QDoubleSpinBox(groupBox_3);
        dxModelInput->setObjectName(QStringLiteral("dxModelInput"));
        dxModelInput->setGeometry(QRect(38, 34, 67, 21));
        dxModelInput->setMinimum(-1000);
        dxModelInput->setMaximum(1000);
        dyModelInput = new QDoubleSpinBox(groupBox_3);
        dyModelInput->setObjectName(QStringLiteral("dyModelInput"));
        dyModelInput->setGeometry(QRect(38, 64, 67, 21));
        dyModelInput->setMinimum(-1000);
        dyModelInput->setMaximum(1000);
        dzModelInput = new QDoubleSpinBox(groupBox_3);
        dzModelInput->setObjectName(QStringLiteral("dzModelInput"));
        dzModelInput->setGeometry(QRect(38, 94, 67, 21));
        dzModelInput->setMinimum(-1000);
        dzModelInput->setMaximum(1000);
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 34, 21, 20));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 64, 21, 20));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 94, 21, 20));
        moveModelButton = new QPushButton(groupBox_3);
        moveModelButton->setObjectName(QStringLiteral("moveModelButton"));
        moveModelButton->setGeometry(QRect(2, 140, 107, 31));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(165, 200, 111, 181));
        groupBox_4->setFont(font);
        groupBox_4->setAlignment(Qt::AlignCenter);
        kzModelInput = new QDoubleSpinBox(groupBox_4);
        kzModelInput->setObjectName(QStringLiteral("kzModelInput"));
        kzModelInput->setGeometry(QRect(38, 94, 67, 21));
        kzModelInput->setMinimum(-1000);
        kzModelInput->setMaximum(1000);
        kzModelInput->setValue(1);
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 34, 21, 20));
        kxModelInput = new QDoubleSpinBox(groupBox_4);
        kxModelInput->setObjectName(QStringLiteral("kxModelInput"));
        kxModelInput->setGeometry(QRect(38, 34, 67, 21));
        kxModelInput->setMinimum(-1000);
        kxModelInput->setMaximum(1000);
        kxModelInput->setValue(1);
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 94, 21, 20));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 64, 21, 20));
        kyModelInput = new QDoubleSpinBox(groupBox_4);
        kyModelInput->setObjectName(QStringLiteral("kyModelInput"));
        kyModelInput->setGeometry(QRect(38, 64, 67, 21));
        kyModelInput->setMinimum(-1000);
        kyModelInput->setMaximum(1000);
        kyModelInput->setValue(1);
        scaleModelButton = new QPushButton(groupBox_4);
        scaleModelButton->setObjectName(QStringLiteral("scaleModelButton"));
        scaleModelButton->setGeometry(QRect(2, 140, 107, 31));
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(320, 200, 111, 181));
        groupBox_5->setFont(font);
        groupBox_5->setAlignment(Qt::AlignCenter);
        ozModelInput = new QDoubleSpinBox(groupBox_5);
        ozModelInput->setObjectName(QStringLiteral("ozModelInput"));
        ozModelInput->setGeometry(QRect(38, 94, 67, 21));
        ozModelInput->setMinimum(-1000);
        ozModelInput->setMaximum(1000);
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 34, 21, 20));
        oxModelInput = new QDoubleSpinBox(groupBox_5);
        oxModelInput->setObjectName(QStringLiteral("oxModelInput"));
        oxModelInput->setGeometry(QRect(38, 34, 67, 21));
        oxModelInput->setMinimum(-1000);
        oxModelInput->setMaximum(1000);
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 94, 21, 20));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 64, 21, 20));
        oyModelInput = new QDoubleSpinBox(groupBox_5);
        oyModelInput->setObjectName(QStringLiteral("oyModelInput"));
        oyModelInput->setGeometry(QRect(38, 64, 67, 21));
        oyModelInput->setMinimum(-1000);
        oyModelInput->setMaximum(1000);
        rotateModelButton = new QPushButton(groupBox_5);
        rotateModelButton->setObjectName(QStringLiteral("rotateModelButton"));
        rotateModelButton->setGeometry(QRect(2, 140, 107, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_9 = new QGroupBox(tab_2);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(250, 200, 171, 181));
        groupBox_9->setFont(font);
        groupBox_9->setAlignment(Qt::AlignCenter);
        ozCameraInput = new QDoubleSpinBox(groupBox_9);
        ozCameraInput->setObjectName(QStringLiteral("ozCameraInput"));
        ozCameraInput->setGeometry(QRect(90, 94, 67, 21));
        ozCameraInput->setMinimum(-1000);
        ozCameraInput->setMaximum(1000);
        label_13 = new QLabel(groupBox_9);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 34, 21, 20));
        oxCameraInput = new QDoubleSpinBox(groupBox_9);
        oxCameraInput->setObjectName(QStringLiteral("oxCameraInput"));
        oxCameraInput->setGeometry(QRect(90, 34, 67, 21));
        oxCameraInput->setMinimum(-1000);
        oxCameraInput->setMaximum(1000);
        label_14 = new QLabel(groupBox_9);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 94, 21, 20));
        label_15 = new QLabel(groupBox_9);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 64, 21, 20));
        oyCameraInput = new QDoubleSpinBox(groupBox_9);
        oyCameraInput->setObjectName(QStringLiteral("oyCameraInput"));
        oyCameraInput->setGeometry(QRect(90, 64, 67, 21));
        oyCameraInput->setMinimum(-1000);
        oyCameraInput->setMaximum(1000);
        rotateCameraButton = new QPushButton(groupBox_9);
        rotateCameraButton->setObjectName(QStringLiteral("rotateCameraButton"));
        rotateCameraButton->setGeometry(QRect(5, 140, 161, 31));
        groupBox_8 = new QGroupBox(tab_2);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 200, 171, 181));
        groupBox_8->setFont(font);
        groupBox_8->setAlignment(Qt::AlignCenter);
        dxCameraInput = new QDoubleSpinBox(groupBox_8);
        dxCameraInput->setObjectName(QStringLiteral("dxCameraInput"));
        dxCameraInput->setGeometry(QRect(90, 34, 67, 21));
        dxCameraInput->setMinimum(-1000);
        dxCameraInput->setMaximum(1000);
        dyCameraInput = new QDoubleSpinBox(groupBox_8);
        dyCameraInput->setObjectName(QStringLiteral("dyCameraInput"));
        dyCameraInput->setGeometry(QRect(90, 64, 67, 21));
        dyCameraInput->setMinimum(-1000);
        dyCameraInput->setMaximum(1000);
        label_10 = new QLabel(groupBox_8);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 34, 21, 20));
        label_11 = new QLabel(groupBox_8);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 64, 21, 20));
        moveCameraButton = new QPushButton(groupBox_8);
        moveCameraButton->setObjectName(QStringLiteral("moveCameraButton"));
        moveCameraButton->setGeometry(QRect(5, 140, 161, 31));
        groupBox_10 = new QGroupBox(tab_2);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(210, 10, 211, 181));
        groupBox_10->setFont(font);
        groupBox_10->setAlignment(Qt::AlignCenter);
        addCameraButton = new QPushButton(groupBox_10);
        addCameraButton->setObjectName(QStringLiteral("addCameraButton"));
        addCameraButton->setGeometry(QRect(10, 140, 191, 29));
        label_16 = new QLabel(groupBox_10);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(12, 70, 21, 20));
        label_17 = new QLabel(groupBox_10);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(12, 40, 21, 20));
        xCameraInput = new QDoubleSpinBox(groupBox_10);
        xCameraInput->setObjectName(QStringLiteral("xCameraInput"));
        xCameraInput->setGeometry(QRect(28, 40, 67, 21));
        xCameraInput->setMinimum(-1000);
        xCameraInput->setMaximum(1000);
        yCameraInput = new QDoubleSpinBox(groupBox_10);
        yCameraInput->setObjectName(QStringLiteral("yCameraInput"));
        yCameraInput->setGeometry(QRect(28, 70, 67, 21));
        yCameraInput->setMinimum(-1000);
        yCameraInput->setMaximum(1000);
        label_19 = new QLabel(groupBox_10);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(108, 100, 21, 20));
        oxCameraInput_2 = new QDoubleSpinBox(groupBox_10);
        oxCameraInput_2->setObjectName(QStringLiteral("oxCameraInput_2"));
        oxCameraInput_2->setGeometry(QRect(134, 40, 67, 21));
        oxCameraInput_2->setMinimum(-1000);
        oxCameraInput_2->setMaximum(1000);
        oyCameraInput_2 = new QDoubleSpinBox(groupBox_10);
        oyCameraInput_2->setObjectName(QStringLiteral("oyCameraInput_2"));
        oyCameraInput_2->setGeometry(QRect(134, 70, 67, 21));
        oyCameraInput_2->setMinimum(-1000);
        oyCameraInput_2->setMaximum(1000);
        label_20 = new QLabel(groupBox_10);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(108, 40, 21, 20));
        label_21 = new QLabel(groupBox_10);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(108, 70, 21, 20));
        ozCameraInput_2 = new QDoubleSpinBox(groupBox_10);
        ozCameraInput_2->setObjectName(QStringLiteral("ozCameraInput_2"));
        ozCameraInput_2->setGeometry(QRect(134, 100, 67, 21));
        ozCameraInput_2->setMinimum(-1000);
        ozCameraInput_2->setMaximum(1000);
        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 10, 191, 181));
        groupBox_7->setFont(font);
        groupBox_7->setAlignment(Qt::AlignCenter);
        camerasList = new QComboBox(groupBox_7);
        camerasList->setObjectName(QStringLiteral("camerasList"));
        camerasList->setGeometry(QRect(10, 30, 171, 28));
        deleteCameraButton = new QPushButton(groupBox_7);
        deleteCameraButton->setObjectName(QStringLiteral("deleteCameraButton"));
        deleteCameraButton->setGeometry(QRect(10, 70, 171, 29));
        loadCameraButton = new QPushButton(groupBox_7);
        loadCameraButton->setObjectName(QStringLiteral("loadCameraButton"));
        loadCameraButton->setGeometry(QRect(10, 140, 171, 29));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        clearSceneButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\201\321\206\320\265\320\275\321\203", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\274\320\276\320\264\320\265\320\273\320\270", Q_NULLPTR));
        deleteModelButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\203\321\216", Q_NULLPTR));
        deleteAllModelsButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\274\320\276\320\264\320\265\320\273\320\270", Q_NULLPTR));
        loadModelButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "dx:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "dy:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "dz:", Q_NULLPTR));
        moveModelButton->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "kx:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "kz:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "ky:", Q_NULLPTR));
        scaleModelButton->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "ox:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "oz:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "oy:", Q_NULLPTR));
        rotateModelButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "ox:", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "oz:", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "oy:", Q_NULLPTR));
        rotateCameraButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "dx:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "dy:", Q_NULLPTR));
        moveCameraButton->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\321\213", Q_NULLPTR));
        addCameraButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\321\203", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "y:", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "x:", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "oz:", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "ox:", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "oy:", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\272\320\260\320\274\320\265\321\200\321\213", Q_NULLPTR));
        deleteCameraButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\203\321\216", Q_NULLPTR));
        loadCameraButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\321\203", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
