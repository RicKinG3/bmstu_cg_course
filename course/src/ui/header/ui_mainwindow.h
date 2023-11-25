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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "specialgraphicsview.hpp"

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
    QTabWidget *menu_3;
    QWidget *obj;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_deleteModel;
    QPushButton *pushButton_addModel;
    QPushButton *pushButton_moveModel;
    QListWidget *listWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QPushButton *pushButton_rightCircle;
    QPushButton *pushButton_up;
    QPushButton *pushButton_leftCircle;
    QPushButton *pushButton_left;
    QPushButton *pushButton_down;
    QPushButton *pushButton_right;
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
    QPushButton *pushButton_left_scene;
    QPushButton *pushButton_right_scene;
    QPushButton *pushButton_up_scene;
    QPushButton *pushButton_down_scene;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

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
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));

        gridLayout->addWidget(graphicsView, 0, 1, 4, 1);

        menu_3 = new QTabWidget(centralwidget);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        obj = new QWidget();
        obj->setObjectName(QString::fromUtf8("obj"));
        gridLayout_2 = new QGridLayout(obj);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_deleteModel = new QPushButton(obj);
        pushButton_deleteModel->setObjectName(QString::fromUtf8("pushButton_deleteModel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        pushButton_deleteModel->setFont(font1);

        gridLayout_2->addWidget(pushButton_deleteModel, 3, 0, 1, 1);

        pushButton_addModel = new QPushButton(obj);
        pushButton_addModel->setObjectName(QString::fromUtf8("pushButton_addModel"));
        pushButton_addModel->setFont(font1);

        gridLayout_2->addWidget(pushButton_addModel, 1, 0, 1, 1);

        pushButton_moveModel = new QPushButton(obj);
        pushButton_moveModel->setObjectName(QString::fromUtf8("pushButton_moveModel"));
        pushButton_moveModel->setFont(font1);

        gridLayout_2->addWidget(pushButton_moveModel, 2, 0, 1, 1);

        listWidget = new QListWidget(obj);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Consolas"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(false);
        listWidget->setFont(font2);
        listWidget->setIconSize(QSize(100, 100));

        gridLayout_2->addWidget(listWidget, 0, 0, 1, 1);

        menu_3->addTab(obj, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_3, 0, 0, 1, 3);

        pushButton_rightCircle = new QPushButton(tab);
        pushButton_rightCircle->setObjectName(QString::fromUtf8("pushButton_rightCircle"));

        gridLayout_3->addWidget(pushButton_rightCircle, 1, 0, 1, 1);

        pushButton_up = new QPushButton(tab);
        pushButton_up->setObjectName(QString::fromUtf8("pushButton_up"));

        gridLayout_3->addWidget(pushButton_up, 1, 1, 1, 1);

        pushButton_leftCircle = new QPushButton(tab);
        pushButton_leftCircle->setObjectName(QString::fromUtf8("pushButton_leftCircle"));

        gridLayout_3->addWidget(pushButton_leftCircle, 1, 2, 1, 1);

        pushButton_left = new QPushButton(tab);
        pushButton_left->setObjectName(QString::fromUtf8("pushButton_left"));

        gridLayout_3->addWidget(pushButton_left, 2, 0, 1, 1);

        pushButton_down = new QPushButton(tab);
        pushButton_down->setObjectName(QString::fromUtf8("pushButton_down"));

        gridLayout_3->addWidget(pushButton_down, 2, 1, 1, 1);

        pushButton_right = new QPushButton(tab);
        pushButton_right->setObjectName(QString::fromUtf8("pushButton_right"));

        gridLayout_3->addWidget(pushButton_right, 2, 2, 1, 1);

        menu_3->addTab(tab, QString());
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
        pushButton_sceneToInitianPosition->setFont(font1);

        gridLayout_5->addWidget(pushButton_sceneToInitianPosition, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));

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

        gridLayout_7->addWidget(label_2, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_4, 0, 0, 1, 1);

        pushButton_createScene = new QPushButton(groupBox);
        pushButton_createScene->setObjectName(QString::fromUtf8("pushButton_createScene"));
        pushButton_createScene->setFont(font1);

        gridLayout_5->addWidget(pushButton_createScene, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scene_tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_distance = new QPushButton(groupBox_2);
        pushButton_distance->setObjectName(QString::fromUtf8("pushButton_distance"));

        gridLayout_4->addWidget(pushButton_distance, 0, 0, 1, 1);

        pushButton_zoom = new QPushButton(groupBox_2);
        pushButton_zoom->setObjectName(QString::fromUtf8("pushButton_zoom"));

        gridLayout_4->addWidget(pushButton_zoom, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(scene_tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButton_left_scene = new QPushButton(groupBox_3);
        pushButton_left_scene->setObjectName(QString::fromUtf8("pushButton_left_scene"));

        gridLayout_6->addWidget(pushButton_left_scene, 3, 0, 1, 1);

        pushButton_right_scene = new QPushButton(groupBox_3);
        pushButton_right_scene->setObjectName(QString::fromUtf8("pushButton_right_scene"));

        gridLayout_6->addWidget(pushButton_right_scene, 3, 1, 1, 1);

        pushButton_up_scene = new QPushButton(groupBox_3);
        pushButton_up_scene->setObjectName(QString::fromUtf8("pushButton_up_scene"));

        gridLayout_6->addWidget(pushButton_up_scene, 2, 0, 1, 2);

        pushButton_down_scene = new QPushButton(groupBox_3);
        pushButton_down_scene->setObjectName(QString::fromUtf8("pushButton_down_scene"));

        gridLayout_6->addWidget(pushButton_down_scene, 4, 0, 1, 2);


        verticalLayout->addWidget(groupBox_3);

        menu_3->addTab(scene_tab, QString());

        gridLayout->addWidget(menu_3, 0, 0, 4, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1191, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu->addAction(action_3);
        menu_2->addAction(action_4);

        retranslateUi(MainWindow);

        menu_3->setCurrentIndex(2);
        listWidget->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\321\203\321\200\321\201\320\276\320\262\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260, \320\232\320\276\320\262\320\260\320\273\320\265\321\206", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\240\321\203\320\272\320\276\320\262\320\276\320\264\321\201\321\202\320\262\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\230\320\235\320\244\320\236", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\247\320\242\320\236-\320\242\320\236", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\245\320\243\320\231", nullptr));
#if QT_CONFIG(tooltip)
        obj->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\276\320\261\321\212\320\265\320\272\321\202\321\213 \321\201\321\206\320\265\320\275\321\213 </p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        obj->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\276\320\261\321\212\320\265\320\272\321\202\321\213 \321\201\321\206\320\265\320\275\321\213 </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_deleteModel->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        pushButton_addModel->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        pushButton_moveModel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        menu_3->setTabText(menu_3->indexOf(obj), QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213 \321\201\321\206\320\265\320\275\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\240\320\220\320\251\320\225\320\235\320\230\320\225 \320\236\320\221\320\252\320\225\320\232\320\242\320\236\320\222", nullptr));
        pushButton_rightCircle->setText(QCoreApplication::translate("MainWindow", "\342\206\273", nullptr));
        pushButton_up->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        pushButton_leftCircle->setText(QCoreApplication::translate("MainWindow", "\342\206\272", nullptr));
        pushButton_left->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        pushButton_down->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        pushButton_right->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        menu_3->setTabText(menu_3->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        groupBox->setTitle(QString());
        pushButton_sceneToInitianPosition->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\265\n"
" \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\201\321\206\320\265\320\275\321\213", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \321\201\321\206\320\265\320\275\321\213", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\276\320\262 \320\262 \320\264\320\273\320\270\320\275\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\276\320\262 \320\262 \321\210\320\270\321\200\320\270\320\275\321\203", nullptr));
        pushButton_createScene->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\201\321\206\320\265\320\275\321\203", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\201\321\206\320\265\320\275\321\213", nullptr));
        pushButton_distance->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_zoom->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\261\320\273\320\270\320\267\320\270\321\202\321\214", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \321\201\321\206\320\265\320\275\321\213", nullptr));
        pushButton_left_scene->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        pushButton_right_scene->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        pushButton_up_scene->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        pushButton_down_scene->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        menu_3->setTabText(menu_3->indexOf(scene_tab), QCoreApplication::translate("MainWindow", "\320\241\321\206\320\265\320\275\320\260", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\220\320\237\320\240\320\220\320\222\320\232\320\220 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
