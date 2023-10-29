/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QLabel *label_7;
    QDoubleSpinBox *oxModelInput;
    QLabel *label_9;
    QDoubleSpinBox *oyModelInput;
    QLabel *label_8;
    QDoubleSpinBox *ozModelInput;
    QPushButton *rotateModelButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QDoubleSpinBox *dxModelInput;
    QLabel *label_2;
    QDoubleSpinBox *dyModelInput;
    QLabel *label_3;
    QDoubleSpinBox *dzModelInput;
    QPushButton *moveModelButton;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *kxModelInput;
    QLabel *label_6;
    QDoubleSpinBox *kyModelInput;
    QLabel *label_5;
    QDoubleSpinBox *kzModelInput;
    QPushButton *scaleModelButton;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QPushButton *loadModelButton;
    QPushButton *deleteAllModelsButton;
    QPushButton *deleteModelButton;
    QComboBox *modelsList;
    QWidget *tab_3;
    QGridLayout *gridLayout_12;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_13;
    QLabel *label_23;
    QDoubleSpinBox *deg_ox_illum;
    QDoubleSpinBox *deg_oy_Illim;
    QPushButton *add_illum;
    QLabel *label_18;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_9;
    QComboBox *camerasList;
    QPushButton *deleteCameraButton;
    QPushButton *loadCameraButton;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_8;
    QLabel *label_17;
    QDoubleSpinBox *xCameraInput;
    QLabel *label_20;
    QDoubleSpinBox *oxCameraInput_2;
    QLabel *label_16;
    QDoubleSpinBox *yCameraInput;
    QLabel *label_21;
    QDoubleSpinBox *oyCameraInput_2;
    QLabel *label_19;
    QDoubleSpinBox *ozCameraInput_2;
    QPushButton *addCameraButton;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_10;
    QLabel *label_10;
    QDoubleSpinBox *dxCameraInput;
    QLabel *label_11;
    QDoubleSpinBox *dyCameraInput;
    QPushButton *moveCameraButton;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_11;
    QLabel *label_13;
    QDoubleSpinBox *oxCameraInput;
    QLabel *label_15;
    QDoubleSpinBox *oyCameraInput;
    QLabel *label_14;
    QDoubleSpinBox *ozCameraInput;
    QPushButton *rotateCameraButton;
    QPushButton *clearSceneButton;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1082, 620);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMaximumSize(QSize(450, 16777215));
        QFont font;
        font.setPointSize(11);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QFont font1;
        font1.setPointSize(9);
        groupBox_5->setFont(font1);
        groupBox_5->setAlignment(Qt::AlignCenter);
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 0, 0, 1, 1);

        oxModelInput = new QDoubleSpinBox(groupBox_5);
        oxModelInput->setObjectName(QString::fromUtf8("oxModelInput"));
        oxModelInput->setMinimum(-1000.000000000000000);
        oxModelInput->setMaximum(1000.000000000000000);

        gridLayout_5->addWidget(oxModelInput, 0, 1, 1, 1);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_5->addWidget(label_9, 1, 0, 1, 1);

        oyModelInput = new QDoubleSpinBox(groupBox_5);
        oyModelInput->setObjectName(QString::fromUtf8("oyModelInput"));
        oyModelInput->setMinimum(-1000.000000000000000);
        oyModelInput->setMaximum(1000.000000000000000);

        gridLayout_5->addWidget(oyModelInput, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_5->addWidget(label_8, 2, 0, 1, 1);

        ozModelInput = new QDoubleSpinBox(groupBox_5);
        ozModelInput->setObjectName(QString::fromUtf8("ozModelInput"));
        ozModelInput->setMinimum(-1000.000000000000000);
        ozModelInput->setMaximum(1000.000000000000000);

        gridLayout_5->addWidget(ozModelInput, 2, 1, 1, 1);

        rotateModelButton = new QPushButton(groupBox_5);
        rotateModelButton->setObjectName(QString::fromUtf8("rotateModelButton"));

        gridLayout_5->addWidget(rotateModelButton, 3, 0, 1, 2);


        gridLayout_2->addWidget(groupBox_5, 1, 2, 1, 1);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFont(font1);
        groupBox_3->setAlignment(Qt::AlignCenter);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        dxModelInput = new QDoubleSpinBox(groupBox_3);
        dxModelInput->setObjectName(QString::fromUtf8("dxModelInput"));
        dxModelInput->setMinimum(-1000.000000000000000);
        dxModelInput->setMaximum(1000.000000000000000);

        gridLayout_3->addWidget(dxModelInput, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        dyModelInput = new QDoubleSpinBox(groupBox_3);
        dyModelInput->setObjectName(QString::fromUtf8("dyModelInput"));
        dyModelInput->setMinimum(-1000.000000000000000);
        dyModelInput->setMaximum(1000.000000000000000);

        gridLayout_3->addWidget(dyModelInput, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        dzModelInput = new QDoubleSpinBox(groupBox_3);
        dzModelInput->setObjectName(QString::fromUtf8("dzModelInput"));
        dzModelInput->setMinimum(-1000.000000000000000);
        dzModelInput->setMaximum(1000.000000000000000);

        gridLayout_3->addWidget(dzModelInput, 2, 1, 1, 1);

        moveModelButton = new QPushButton(groupBox_3);
        moveModelButton->setObjectName(QString::fromUtf8("moveModelButton"));

        gridLayout_3->addWidget(moveModelButton, 3, 0, 1, 2);


        gridLayout_2->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFont(font1);
        groupBox_4->setAlignment(Qt::AlignCenter);
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        kxModelInput = new QDoubleSpinBox(groupBox_4);
        kxModelInput->setObjectName(QString::fromUtf8("kxModelInput"));
        kxModelInput->setMinimum(-1000.000000000000000);
        kxModelInput->setMaximum(1000.000000000000000);
        kxModelInput->setValue(1.000000000000000);

        gridLayout_4->addWidget(kxModelInput, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 1, 0, 1, 1);

        kyModelInput = new QDoubleSpinBox(groupBox_4);
        kyModelInput->setObjectName(QString::fromUtf8("kyModelInput"));
        kyModelInput->setMinimum(-1000.000000000000000);
        kyModelInput->setMaximum(1000.000000000000000);
        kyModelInput->setValue(1.000000000000000);

        gridLayout_4->addWidget(kyModelInput, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 2, 0, 1, 1);

        kzModelInput = new QDoubleSpinBox(groupBox_4);
        kzModelInput->setObjectName(QString::fromUtf8("kzModelInput"));
        kzModelInput->setMinimum(-1000.000000000000000);
        kzModelInput->setMaximum(1000.000000000000000);
        kzModelInput->setValue(1.000000000000000);

        gridLayout_4->addWidget(kzModelInput, 2, 1, 1, 1);

        scaleModelButton = new QPushButton(groupBox_4);
        scaleModelButton->setObjectName(QString::fromUtf8("scaleModelButton"));

        gridLayout_4->addWidget(scaleModelButton, 3, 0, 1, 2);


        gridLayout_2->addWidget(groupBox_4, 1, 1, 1, 1);

        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setFont(font1);
        groupBox_6->setAlignment(Qt::AlignCenter);
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        loadModelButton = new QPushButton(groupBox_6);
        loadModelButton->setObjectName(QString::fromUtf8("loadModelButton"));

        gridLayout_6->addWidget(loadModelButton, 3, 0, 1, 1);

        deleteAllModelsButton = new QPushButton(groupBox_6);
        deleteAllModelsButton->setObjectName(QString::fromUtf8("deleteAllModelsButton"));

        gridLayout_6->addWidget(deleteAllModelsButton, 2, 0, 1, 1);

        deleteModelButton = new QPushButton(groupBox_6);
        deleteModelButton->setObjectName(QString::fromUtf8("deleteModelButton"));

        gridLayout_6->addWidget(deleteModelButton, 1, 0, 1, 1);

        modelsList = new QComboBox(groupBox_6);
        modelsList->setObjectName(QString::fromUtf8("modelsList"));

        gridLayout_6->addWidget(modelsList, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_6, 0, 0, 1, 3);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_12 = new QGridLayout(tab_3);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer, 0, 0, 1, 1);

        groupBox_11 = new QGroupBox(tab_3);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setFont(font1);
        groupBox_11->setAlignment(Qt::AlignCenter);
        gridLayout_13 = new QGridLayout(groupBox_11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        label_23 = new QLabel(groupBox_11);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_13->addWidget(label_23, 1, 0, 1, 1);

        deg_ox_illum = new QDoubleSpinBox(groupBox_11);
        deg_ox_illum->setObjectName(QString::fromUtf8("deg_ox_illum"));
        deg_ox_illum->setMinimum(-1000.000000000000000);
        deg_ox_illum->setMaximum(1000.000000000000000);

        gridLayout_13->addWidget(deg_ox_illum, 0, 1, 1, 1);

        deg_oy_Illim = new QDoubleSpinBox(groupBox_11);
        deg_oy_Illim->setObjectName(QString::fromUtf8("deg_oy_Illim"));
        deg_oy_Illim->setMinimum(-1000.000000000000000);
        deg_oy_Illim->setMaximum(1000.000000000000000);

        gridLayout_13->addWidget(deg_oy_Illim, 1, 1, 1, 1);

        add_illum = new QPushButton(groupBox_11);
        add_illum->setObjectName(QString::fromUtf8("add_illum"));

        gridLayout_13->addWidget(add_illum, 2, 0, 1, 2);

        label_18 = new QLabel(groupBox_11);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_13->addWidget(label_18, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer, 3, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_11, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_7 = new QGridLayout(tab_2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setFont(font1);
        groupBox_7->setAlignment(Qt::AlignCenter);
        gridLayout_9 = new QGridLayout(groupBox_7);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        camerasList = new QComboBox(groupBox_7);
        camerasList->setObjectName(QString::fromUtf8("camerasList"));

        gridLayout_9->addWidget(camerasList, 0, 0, 1, 1);

        deleteCameraButton = new QPushButton(groupBox_7);
        deleteCameraButton->setObjectName(QString::fromUtf8("deleteCameraButton"));

        gridLayout_9->addWidget(deleteCameraButton, 1, 0, 1, 1);

        loadCameraButton = new QPushButton(groupBox_7);
        loadCameraButton->setObjectName(QString::fromUtf8("loadCameraButton"));

        gridLayout_9->addWidget(loadCameraButton, 2, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_7, 0, 0, 1, 1);

        groupBox_10 = new QGroupBox(tab_2);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setFont(font1);
        groupBox_10->setAlignment(Qt::AlignCenter);
        gridLayout_8 = new QGridLayout(groupBox_10);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_17 = new QLabel(groupBox_10);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_8->addWidget(label_17, 0, 0, 1, 1);

        xCameraInput = new QDoubleSpinBox(groupBox_10);
        xCameraInput->setObjectName(QString::fromUtf8("xCameraInput"));
        xCameraInput->setMinimum(-1000.000000000000000);
        xCameraInput->setMaximum(1000.000000000000000);

        gridLayout_8->addWidget(xCameraInput, 0, 1, 1, 1);

        label_20 = new QLabel(groupBox_10);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_8->addWidget(label_20, 0, 2, 1, 1);

        oxCameraInput_2 = new QDoubleSpinBox(groupBox_10);
        oxCameraInput_2->setObjectName(QString::fromUtf8("oxCameraInput_2"));
        oxCameraInput_2->setMinimum(-1000.000000000000000);
        oxCameraInput_2->setMaximum(1000.000000000000000);

        gridLayout_8->addWidget(oxCameraInput_2, 0, 3, 1, 1);

        label_16 = new QLabel(groupBox_10);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_8->addWidget(label_16, 1, 0, 1, 1);

        yCameraInput = new QDoubleSpinBox(groupBox_10);
        yCameraInput->setObjectName(QString::fromUtf8("yCameraInput"));
        yCameraInput->setMinimum(-1000.000000000000000);
        yCameraInput->setMaximum(1000.000000000000000);

        gridLayout_8->addWidget(yCameraInput, 1, 1, 1, 1);

        label_21 = new QLabel(groupBox_10);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_8->addWidget(label_21, 1, 2, 1, 1);

        oyCameraInput_2 = new QDoubleSpinBox(groupBox_10);
        oyCameraInput_2->setObjectName(QString::fromUtf8("oyCameraInput_2"));
        oyCameraInput_2->setMinimum(-1000.000000000000000);
        oyCameraInput_2->setMaximum(1000.000000000000000);

        gridLayout_8->addWidget(oyCameraInput_2, 1, 3, 1, 1);

        label_19 = new QLabel(groupBox_10);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_8->addWidget(label_19, 2, 2, 1, 1);

        ozCameraInput_2 = new QDoubleSpinBox(groupBox_10);
        ozCameraInput_2->setObjectName(QString::fromUtf8("ozCameraInput_2"));
        ozCameraInput_2->setMinimum(-1000.000000000000000);
        ozCameraInput_2->setMaximum(1000.000000000000000);

        gridLayout_8->addWidget(ozCameraInput_2, 2, 3, 1, 1);

        addCameraButton = new QPushButton(groupBox_10);
        addCameraButton->setObjectName(QString::fromUtf8("addCameraButton"));

        gridLayout_8->addWidget(addCameraButton, 3, 0, 1, 4);


        gridLayout_7->addWidget(groupBox_10, 0, 1, 1, 1);

        groupBox_8 = new QGroupBox(tab_2);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setFont(font1);
        groupBox_8->setAlignment(Qt::AlignCenter);
        gridLayout_10 = new QGridLayout(groupBox_8);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_10 = new QLabel(groupBox_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_10->addWidget(label_10, 0, 0, 1, 1);

        dxCameraInput = new QDoubleSpinBox(groupBox_8);
        dxCameraInput->setObjectName(QString::fromUtf8("dxCameraInput"));
        dxCameraInput->setMinimum(-1000.000000000000000);
        dxCameraInput->setMaximum(1000.000000000000000);

        gridLayout_10->addWidget(dxCameraInput, 0, 1, 1, 1);

        label_11 = new QLabel(groupBox_8);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_10->addWidget(label_11, 1, 0, 1, 1);

        dyCameraInput = new QDoubleSpinBox(groupBox_8);
        dyCameraInput->setObjectName(QString::fromUtf8("dyCameraInput"));
        dyCameraInput->setMinimum(-1000.000000000000000);
        dyCameraInput->setMaximum(1000.000000000000000);

        gridLayout_10->addWidget(dyCameraInput, 1, 1, 1, 1);

        moveCameraButton = new QPushButton(groupBox_8);
        moveCameraButton->setObjectName(QString::fromUtf8("moveCameraButton"));

        gridLayout_10->addWidget(moveCameraButton, 2, 0, 1, 2);


        gridLayout_7->addWidget(groupBox_8, 1, 0, 1, 1);

        groupBox_9 = new QGroupBox(tab_2);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setFont(font1);
        groupBox_9->setAlignment(Qt::AlignCenter);
        gridLayout_11 = new QGridLayout(groupBox_9);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_13 = new QLabel(groupBox_9);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_11->addWidget(label_13, 0, 0, 1, 1);

        oxCameraInput = new QDoubleSpinBox(groupBox_9);
        oxCameraInput->setObjectName(QString::fromUtf8("oxCameraInput"));
        oxCameraInput->setMinimum(-1000.000000000000000);
        oxCameraInput->setMaximum(1000.000000000000000);

        gridLayout_11->addWidget(oxCameraInput, 0, 1, 1, 1);

        label_15 = new QLabel(groupBox_9);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_11->addWidget(label_15, 1, 0, 1, 1);

        oyCameraInput = new QDoubleSpinBox(groupBox_9);
        oyCameraInput->setObjectName(QString::fromUtf8("oyCameraInput"));
        oyCameraInput->setMinimum(-1000.000000000000000);
        oyCameraInput->setMaximum(1000.000000000000000);

        gridLayout_11->addWidget(oyCameraInput, 1, 1, 1, 1);

        label_14 = new QLabel(groupBox_9);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_11->addWidget(label_14, 2, 0, 1, 1);

        ozCameraInput = new QDoubleSpinBox(groupBox_9);
        ozCameraInput->setObjectName(QString::fromUtf8("ozCameraInput"));
        ozCameraInput->setMinimum(-1000.000000000000000);
        ozCameraInput->setMaximum(1000.000000000000000);

        gridLayout_11->addWidget(ozCameraInput, 2, 1, 1, 1);

        rotateCameraButton = new QPushButton(groupBox_9);
        rotateCameraButton->setObjectName(QString::fromUtf8("rotateCameraButton"));

        gridLayout_11->addWidget(rotateCameraButton, 3, 0, 1, 2);


        gridLayout_7->addWidget(groupBox_9, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        clearSceneButton = new QPushButton(centralwidget);
        clearSceneButton->setObjectName(QString::fromUtf8("clearSceneButton"));
        clearSceneButton->setFont(font1);

        gridLayout->addWidget(clearSceneButton, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 1, 2, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "ox:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "oy:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "oz:", nullptr));
        rotateModelButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "dx:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "dy:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "dz:", nullptr));
        moveModelButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "kx:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "ky:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "kz:", nullptr));
        scaleModelButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\274\320\276\320\264\320\265\320\273\320\270", nullptr));
        loadModelButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        deleteAllModelsButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\274\320\276\320\264\320\265\320\273\320\270", nullptr));
        deleteModelButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\203\321\216", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "\320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "oy:", nullptr));
        add_illum->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "ox:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\241\320\262\320\265\321\202", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\272\320\260\320\274\320\265\321\200\321\213", nullptr));
        deleteCameraButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\203\321\216", nullptr));
        loadCameraButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\321\203", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\321\213", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "x:", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "ox:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "y:", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "oy:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "oz:", nullptr));
        addCameraButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\321\203", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "dx:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "dy:", nullptr));
        moveCameraButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "ox:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "oy:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "oz:", nullptr));
        rotateCameraButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260", nullptr));
        clearSceneButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\201\321\206\320\265\320\275\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
