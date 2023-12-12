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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "SpecialGraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_2;
    QAction *action;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    SpecialGraphicsView *graphicsView;
    QTabWidget *mainMain;
    QWidget *scene_tab;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_sceneToInitianPosition;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_7;
    QLabel *label;
    QSpinBox *length_scene;
    QSpinBox *width_scene;
    QLabel *label_2;
    QPushButton *pushButton_createScene;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_distance;
    QPushButton *pushButton_zoom;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_right_scene;
    QPushButton *pushButton_up_scene;
    QPushButton *pushButton_left_scene;
    QPushButton *pushButton_down_scene;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_left;
    QPushButton *pushButton_down;
    QPushButton *pushButton_right;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_rightCircle;
    QPushButton *pushButton_up;
    QPushButton *pushButton_leftCircle;
    QWidget *obj;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_9;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *num_sq_ox;
    QSpinBox *num_sq_oy;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_12;
    QPushButton *pushButton_deleteModel;
    QPushButton *pushButton_moveModel;
    QListWidget *objListActiv;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_10;
    QRadioButton *objDirection_ox;
    QRadioButton *objDirection_oy;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_2;
    QComboBox *choose_obj;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_11;
    QLabel *label_6;
    QSpinBox *deg_oy;
    QSpinBox *deg_ox;
    QPushButton *pushButton_light_add;
    QLabel *label_5;
    QPushButton *pushButton_light_del;
    QPushButton *pushButton_addModel;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1191, 762);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(false);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("imgs/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new SpecialGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(500, 500));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));

        gridLayout->addWidget(graphicsView, 0, 1, 4, 1);

        mainMain = new QTabWidget(centralwidget);
        mainMain->setObjectName(QString::fromUtf8("mainMain"));
        mainMain->setMaximumSize(QSize(400, 16777215));
        scene_tab = new QWidget();
        scene_tab->setObjectName(QString::fromUtf8("scene_tab"));
        verticalLayout = new QVBoxLayout(scene_tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(scene_tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton_sceneToInitianPosition = new QPushButton(groupBox);
        pushButton_sceneToInitianPosition->setObjectName(QString::fromUtf8("pushButton_sceneToInitianPosition"));
        pushButton_sceneToInitianPosition->setFont(font);

        gridLayout_5->addWidget(pushButton_sceneToInitianPosition, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label, 0, 0, 1, 1);

        length_scene = new QSpinBox(groupBox_4);
        length_scene->setObjectName(QString::fromUtf8("length_scene"));
        length_scene->setMinimum(1);
        length_scene->setMaximum(100);
        length_scene->setValue(10);

        gridLayout_7->addWidget(length_scene, 1, 0, 1, 1);

        width_scene = new QSpinBox(groupBox_4);
        width_scene->setObjectName(QString::fromUtf8("width_scene"));
        width_scene->setMinimum(1);
        width_scene->setMaximum(100);
        width_scene->setValue(10);

        gridLayout_7->addWidget(width_scene, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_2, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_4, 0, 0, 1, 1);

        pushButton_createScene = new QPushButton(groupBox);
        pushButton_createScene->setObjectName(QString::fromUtf8("pushButton_createScene"));
        pushButton_createScene->setFont(font);

        gridLayout_5->addWidget(pushButton_createScene, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scene_tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_distance = new QPushButton(groupBox_2);
        pushButton_distance->setObjectName(QString::fromUtf8("pushButton_distance"));

        gridLayout_4->addWidget(pushButton_distance, 1, 0, 1, 1);

        pushButton_zoom = new QPushButton(groupBox_2);
        pushButton_zoom->setObjectName(QString::fromUtf8("pushButton_zoom"));

        gridLayout_4->addWidget(pushButton_zoom, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(scene_tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButton_right_scene = new QPushButton(groupBox_3);
        pushButton_right_scene->setObjectName(QString::fromUtf8("pushButton_right_scene"));

        gridLayout_6->addWidget(pushButton_right_scene, 1, 1, 1, 1);

        pushButton_up_scene = new QPushButton(groupBox_3);
        pushButton_up_scene->setObjectName(QString::fromUtf8("pushButton_up_scene"));

        gridLayout_6->addWidget(pushButton_up_scene, 0, 0, 1, 2);

        pushButton_left_scene = new QPushButton(groupBox_3);
        pushButton_left_scene->setObjectName(QString::fromUtf8("pushButton_left_scene"));

        gridLayout_6->addWidget(pushButton_left_scene, 1, 0, 1, 1);

        pushButton_down_scene = new QPushButton(groupBox_3);
        pushButton_down_scene->setObjectName(QString::fromUtf8("pushButton_down_scene"));

        gridLayout_6->addWidget(pushButton_down_scene, 2, 0, 1, 2);


        verticalLayout->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(scene_tab);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_8 = new QGridLayout(groupBox_5);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout = new QHBoxLayout(groupBox_6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_left = new QPushButton(groupBox_6);
        pushButton_left->setObjectName(QString::fromUtf8("pushButton_left"));

        horizontalLayout->addWidget(pushButton_left);

        pushButton_down = new QPushButton(groupBox_6);
        pushButton_down->setObjectName(QString::fromUtf8("pushButton_down"));

        horizontalLayout->addWidget(pushButton_down);

        pushButton_right = new QPushButton(groupBox_6);
        pushButton_right->setObjectName(QString::fromUtf8("pushButton_right"));

        horizontalLayout->addWidget(pushButton_right);


        gridLayout_8->addWidget(groupBox_6, 1, 1, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_5);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_rightCircle = new QPushButton(groupBox_7);
        pushButton_rightCircle->setObjectName(QString::fromUtf8("pushButton_rightCircle"));

        horizontalLayout_2->addWidget(pushButton_rightCircle);

        pushButton_up = new QPushButton(groupBox_7);
        pushButton_up->setObjectName(QString::fromUtf8("pushButton_up"));

        horizontalLayout_2->addWidget(pushButton_up);

        pushButton_leftCircle = new QPushButton(groupBox_7);
        pushButton_leftCircle->setObjectName(QString::fromUtf8("pushButton_leftCircle"));

        horizontalLayout_2->addWidget(pushButton_leftCircle);


        gridLayout_8->addWidget(groupBox_7, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox_5);

        mainMain->addTab(scene_tab, QString());
        obj = new QWidget();
        obj->setObjectName(QString::fromUtf8("obj"));
        gridLayout_2 = new QGridLayout(obj);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_9 = new QGroupBox(obj);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        gridLayout_9 = new QGridLayout(groupBox_9);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_3 = new QLabel(groupBox_9);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_9->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_9);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_9->addWidget(label_4, 0, 2, 1, 1);

        num_sq_ox = new QSpinBox(groupBox_9);
        num_sq_ox->setObjectName(QString::fromUtf8("num_sq_ox"));
        num_sq_ox->setMinimum(1);
        num_sq_ox->setMaximum(100);

        gridLayout_9->addWidget(num_sq_ox, 1, 1, 1, 1);

        num_sq_oy = new QSpinBox(groupBox_9);
        num_sq_oy->setObjectName(QString::fromUtf8("num_sq_oy"));
        num_sq_oy->setMinimum(1);
        num_sq_oy->setMaximum(100);

        gridLayout_9->addWidget(num_sq_oy, 1, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_9, 2, 0, 1, 1);

        groupBox_12 = new QGroupBox(obj);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        gridLayout_12 = new QGridLayout(groupBox_12);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        pushButton_deleteModel = new QPushButton(groupBox_12);
        pushButton_deleteModel->setObjectName(QString::fromUtf8("pushButton_deleteModel"));
        pushButton_deleteModel->setFont(font);

        gridLayout_12->addWidget(pushButton_deleteModel, 2, 0, 1, 1);

        pushButton_moveModel = new QPushButton(groupBox_12);
        pushButton_moveModel->setObjectName(QString::fromUtf8("pushButton_moveModel"));
        pushButton_moveModel->setFont(font);

        gridLayout_12->addWidget(pushButton_moveModel, 1, 0, 1, 1);

        objListActiv = new QListWidget(groupBox_12);
        objListActiv->setObjectName(QString::fromUtf8("objListActiv"));

        gridLayout_12->addWidget(objListActiv, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_12, 6, 0, 1, 1);

        groupBox_10 = new QGroupBox(obj);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        gridLayout_10 = new QGridLayout(groupBox_10);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        objDirection_ox = new QRadioButton(groupBox_10);
        objDirection_ox->setObjectName(QString::fromUtf8("objDirection_ox"));

        gridLayout_10->addWidget(objDirection_ox, 0, 0, 2, 2);

        objDirection_oy = new QRadioButton(groupBox_10);
        objDirection_oy->setObjectName(QString::fromUtf8("objDirection_oy"));

        gridLayout_10->addWidget(objDirection_oy, 2, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_10, 3, 0, 1, 1);

        groupBox_8 = new QGroupBox(obj);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        verticalLayout_2 = new QVBoxLayout(groupBox_8);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        choose_obj = new QComboBox(groupBox_8);
        choose_obj->addItem(QString());
        choose_obj->addItem(QString());
        choose_obj->addItem(QString());
        choose_obj->addItem(QString());
        choose_obj->addItem(QString());
        choose_obj->addItem(QString());
        choose_obj->setObjectName(QString::fromUtf8("choose_obj"));

        verticalLayout_2->addWidget(choose_obj);


        gridLayout_2->addWidget(groupBox_8, 0, 0, 1, 1);

        groupBox_11 = new QGroupBox(obj);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        gridLayout_11 = new QGridLayout(groupBox_11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_6 = new QLabel(groupBox_11);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_11->addWidget(label_6, 0, 1, 1, 1);

        deg_oy = new QSpinBox(groupBox_11);
        deg_oy->setObjectName(QString::fromUtf8("deg_oy"));
        deg_oy->setMinimum(-10000);
        deg_oy->setMaximum(10000);
        deg_oy->setValue(30);

        gridLayout_11->addWidget(deg_oy, 1, 1, 1, 1);

        deg_ox = new QSpinBox(groupBox_11);
        deg_ox->setObjectName(QString::fromUtf8("deg_ox"));
        deg_ox->setMinimum(-10000);
        deg_ox->setMaximum(10000);
        deg_ox->setValue(30);

        gridLayout_11->addWidget(deg_ox, 1, 0, 1, 1);

        pushButton_light_add = new QPushButton(groupBox_11);
        pushButton_light_add->setObjectName(QString::fromUtf8("pushButton_light_add"));

        gridLayout_11->addWidget(pushButton_light_add, 3, 0, 1, 2);

        label_5 = new QLabel(groupBox_11);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_11->addWidget(label_5, 0, 0, 1, 1);

        pushButton_light_del = new QPushButton(groupBox_11);
        pushButton_light_del->setObjectName(QString::fromUtf8("pushButton_light_del"));

        gridLayout_11->addWidget(pushButton_light_del, 4, 0, 1, 2);


        gridLayout_2->addWidget(groupBox_11, 5, 0, 1, 1);

        pushButton_addModel = new QPushButton(obj);
        pushButton_addModel->setObjectName(QString::fromUtf8("pushButton_addModel"));
        pushButton_addModel->setFont(font);

        gridLayout_2->addWidget(pushButton_addModel, 4, 0, 1, 1);

        mainMain->addTab(obj, QString());

        gridLayout->addWidget(mainMain, 0, 0, 4, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1191, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_3);

        retranslateUi(MainWindow);

        mainMain->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\320\265\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\270 \320\262\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\267\320\260\320\263\320\276\321\200\320\276\320\264\320\275\320\276\320\271 \320\274\320\265\321\201\321\202\320\275\320\276\321\201\321\202\320\270", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\240\321\203\320\272\320\276\320\262\320\276\320\264\321\201\321\202\320\262\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        groupBox->setTitle(QString());
        pushButton_sceneToInitianPosition->setText(QCoreApplication::translate("MainWindow", "\320\222 \320\275\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\277\320\273\320\260\321\202\321\204\320\276\321\200\320\274\321\203", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\273\320\260\321\202\321\204\320\276\321\200\320\274\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\276\320\262\n"
" \320\262 \320\264\320\273\320\270\320\275\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\276\320\262 \n"
"\320\262 \321\210\320\270\321\200\320\270\320\275\321\203", nullptr));
        pushButton_createScene->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\320\273\320\260\321\202\321\204\320\276\321\200\320\274\321\203", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\277\320\273\320\260\321\202\321\204\320\276\321\200\320\274\321\213", nullptr));
        pushButton_distance->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_zoom->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\277\320\273\320\260\321\202\321\204\320\276\321\200\320\274\321\213", nullptr));
        pushButton_right_scene->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        pushButton_up_scene->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        pushButton_left_scene->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        pushButton_down_scene->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\277\320\273\320\260\321\202\321\204\320\276\321\200\320\274\321\213 ", nullptr));
        groupBox_6->setTitle(QString());
        pushButton_left->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        pushButton_down->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        pushButton_right->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        groupBox_7->setTitle(QString());
        pushButton_rightCircle->setText(QCoreApplication::translate("MainWindow", "\342\206\273", nullptr));
        pushButton_up->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        pushButton_leftCircle->setText(QCoreApplication::translate("MainWindow", "\342\206\272", nullptr));
        mainMain->setTabText(mainMain->indexOf(scene_tab), QCoreApplication::translate("MainWindow", "\320\237\320\273\320\260\321\202\321\204\320\276\321\200\320\274\320\260", nullptr));
#if QT_CONFIG(tooltip)
        obj->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\276\320\261\321\212\320\265\320\272\321\202\321\213 \321\201\321\206\320\265\320\275\321\213 </p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        obj->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\276\320\261\321\212\320\265\320\272\321\202\321\213 \321\201\321\206\320\265\320\275\321\213 </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\200\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\276\320\261\321\212\320\265\320\272\321\202\320\260 ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\260 \320\277\320\276 \n"
"\320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\320\276\320\271 \320\276\321\201\320\270", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\260 \320\277\320\276 \n"
"\320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\271 \320\276\321\201\320\270", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262 \320\264\320\273\321\217 \320\277\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\321\217 \320\270\320\273\320\270 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\321\217 ", nullptr));
        pushButton_deleteModel->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        pushButton_moveModel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", nullptr));
        objDirection_ox->setText(QCoreApplication::translate("MainWindow", "\320\222\320\264\320\276\320\273\321\214 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\320\276\320\271 \320\276\321\201\320\270", nullptr));
        objDirection_oy->setText(QCoreApplication::translate("MainWindow", "\320\222\320\264\320\276\320\273\321\214 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\271 \320\276\321\201\320\270", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", nullptr));
        choose_obj->setItemText(0, QCoreApplication::translate("MainWindow", "\320\224\320\276\320\274", nullptr));
        choose_obj->setItemText(1, QCoreApplication::translate("MainWindow", "\320\224\320\276\321\200\320\276\320\263\320\260", nullptr));
        choose_obj->setItemText(2, QCoreApplication::translate("MainWindow", "\320\242\321\200\320\276\321\202\321\203\320\260\321\200", nullptr));
        choose_obj->setItemText(3, QCoreApplication::translate("MainWindow", "\320\234\320\260\321\210\320\270\320\275\320\260", nullptr));
        choose_obj->setItemText(4, QCoreApplication::translate("MainWindow", "\320\224\320\265\321\200\320\265\320\262\320\276", nullptr));
        choose_obj->setItemText(5, QCoreApplication::translate("MainWindow", "\320\232\321\203\321\201\321\202", nullptr));

        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\277\320\276 \n"
"\320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\271 \320\276\321\201\320\270 ", nullptr));
        pushButton_light_add->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\277\320\276 \n"
"\320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\320\276\320\271 \320\276\321\201\320\270", nullptr));
        pushButton_light_del->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260", nullptr));
        pushButton_addModel->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        mainMain->setTabText(mainMain->indexOf(obj), QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
