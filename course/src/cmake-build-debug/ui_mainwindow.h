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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "specialgraphicsview.hpp"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_2;
    QAction *action;
    QAction *action_3;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_left;
    QPushButton *pushButton_up;
    QPushButton *pushButton_down_scene;
    QPushButton *pushButton_distance;
    QPushButton *pushButton_up_scene;
    QLabel *label_3;
    QLabel *label_2;
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *pushButton_rightCircle;
    QPushButton *pushButton_sceneToInitianPosition;
    QPushButton *pushButton_down;
    QPushButton *pushButton_left_scene;
    QPushButton *pushButton_right_scene;
    QPushButton *pushButton_right;
    QPushButton *pushButton_createScene;
    QPushButton *pushButton_zoom;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_moveModel;
    QPushButton *pushButton_deleteModel;
    SpecialGraphicsView *graphicsView;
    QPushButton *pushButton_addModel;
    QPushButton *pushButton_leftCircle;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1191, 762);
        QIcon icon;
        icon.addFile(QString::fromUtf8("imgs/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_left = new QPushButton(centralwidget);
        pushButton_left->setObjectName(QString::fromUtf8("pushButton_left"));

        gridLayout->addWidget(pushButton_left, 6, 1, 1, 1);

        pushButton_up = new QPushButton(centralwidget);
        pushButton_up->setObjectName(QString::fromUtf8("pushButton_up"));

        gridLayout->addWidget(pushButton_up, 5, 2, 1, 2);

        pushButton_down_scene = new QPushButton(centralwidget);
        pushButton_down_scene->setObjectName(QString::fromUtf8("pushButton_down_scene"));

        gridLayout->addWidget(pushButton_down_scene, 13, 2, 1, 2);

        pushButton_distance = new QPushButton(centralwidget);
        pushButton_distance->setObjectName(QString::fromUtf8("pushButton_distance"));

        gridLayout->addWidget(pushButton_distance, 10, 3, 1, 2);

        pushButton_up_scene = new QPushButton(centralwidget);
        pushButton_up_scene->setObjectName(QString::fromUtf8("pushButton_up_scene"));

        gridLayout->addWidget(pushButton_up_scene, 12, 2, 1, 2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 4, 1, 1, 4);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 4);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(16);
        listWidget->setFont(font1);
        listWidget->setIconSize(QSize(100, 100));

        gridLayout->addWidget(listWidget, 1, 1, 1, 4);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 7, 1, 1, 4);

        pushButton_rightCircle = new QPushButton(centralwidget);
        pushButton_rightCircle->setObjectName(QString::fromUtf8("pushButton_rightCircle"));

        gridLayout->addWidget(pushButton_rightCircle, 5, 1, 1, 1);

        pushButton_sceneToInitianPosition = new QPushButton(centralwidget);
        pushButton_sceneToInitianPosition->setObjectName(QString::fromUtf8("pushButton_sceneToInitianPosition"));
        QFont font2;
        font2.setPointSize(12);
        pushButton_sceneToInitianPosition->setFont(font2);

        gridLayout->addWidget(pushButton_sceneToInitianPosition, 8, 3, 1, 2);

        pushButton_down = new QPushButton(centralwidget);
        pushButton_down->setObjectName(QString::fromUtf8("pushButton_down"));

        gridLayout->addWidget(pushButton_down, 6, 2, 1, 2);

        pushButton_left_scene = new QPushButton(centralwidget);
        pushButton_left_scene->setObjectName(QString::fromUtf8("pushButton_left_scene"));

        gridLayout->addWidget(pushButton_left_scene, 12, 1, 2, 1);

        pushButton_right_scene = new QPushButton(centralwidget);
        pushButton_right_scene->setObjectName(QString::fromUtf8("pushButton_right_scene"));

        gridLayout->addWidget(pushButton_right_scene, 12, 4, 2, 1);

        pushButton_right = new QPushButton(centralwidget);
        pushButton_right->setObjectName(QString::fromUtf8("pushButton_right"));

        gridLayout->addWidget(pushButton_right, 6, 4, 1, 1);

        pushButton_createScene = new QPushButton(centralwidget);
        pushButton_createScene->setObjectName(QString::fromUtf8("pushButton_createScene"));
        pushButton_createScene->setFont(font2);

        gridLayout->addWidget(pushButton_createScene, 8, 1, 1, 2);

        pushButton_zoom = new QPushButton(centralwidget);
        pushButton_zoom->setObjectName(QString::fromUtf8("pushButton_zoom"));

        gridLayout->addWidget(pushButton_zoom, 10, 1, 1, 2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 9, 1, 1, 4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 11, 1, 1, 4);

        pushButton_moveModel = new QPushButton(centralwidget);
        pushButton_moveModel->setObjectName(QString::fromUtf8("pushButton_moveModel"));
        pushButton_moveModel->setFont(font2);

        gridLayout->addWidget(pushButton_moveModel, 3, 3, 1, 2);

        pushButton_deleteModel = new QPushButton(centralwidget);
        pushButton_deleteModel->setObjectName(QString::fromUtf8("pushButton_deleteModel"));
        pushButton_deleteModel->setFont(font2);

        gridLayout->addWidget(pushButton_deleteModel, 3, 1, 1, 2);

        graphicsView = new SpecialGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));

        gridLayout->addWidget(graphicsView, 0, 5, 14, 1);

        pushButton_addModel = new QPushButton(centralwidget);
        pushButton_addModel->setObjectName(QString::fromUtf8("pushButton_addModel"));
        pushButton_addModel->setFont(font2);

        gridLayout->addWidget(pushButton_addModel, 2, 1, 1, 4);

        pushButton_leftCircle = new QPushButton(centralwidget);
        pushButton_leftCircle->setObjectName(QString::fromUtf8("pushButton_leftCircle"));

        gridLayout->addWidget(pushButton_leftCircle, 5, 4, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1191, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_3);

        retranslateUi(MainWindow);

        listWidget->setCurrentRow(-1);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\321\203\321\200\321\201\320\276\320\262\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260, \320\232\320\276\320\262\320\260\320\273\320\265\321\206", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\240\321\203\320\272\320\276\320\262\320\276\320\264\321\201\321\202\320\262\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", " \321\206\321\203\320\260\321\200\321\203\321\206", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\321\206\321\203\320\272\321\206\321\203", nullptr));
        pushButton_left->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        pushButton_up->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        pushButton_down_scene->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        pushButton_distance->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_up_scene->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\240\320\220\320\251\320\225\320\235\320\230\320\225 \320\236\320\221\320\252\320\225\320\232\320\242\320\236\320\222", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "GBPlffffF", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\246\320\225\320\235\320\220", nullptr));
        pushButton_rightCircle->setText(QCoreApplication::translate("MainWindow", "\342\206\273", nullptr));
        pushButton_sceneToInitianPosition->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\265\n"
" \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\201\321\206\320\265\320\275\321\213", nullptr));
        pushButton_down->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        pushButton_left_scene->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        pushButton_right_scene->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        pushButton_right->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        pushButton_createScene->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\201\321\206\320\265\320\275\321\203", nullptr));
        pushButton_zoom->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\261\320\273\320\270\320\267\320\270\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\234\320\220\320\241\320\250\320\242\320\220\320\221\320\230\320\240\320\236\320\222\320\220\320\235\320\230\320\225 \320\241\320\246\320\225\320\235\320\253", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\237\320\225\320\240\320\225\320\234\320\225\320\251\320\225\320\235\320\230\320\225 \320\241\320\246\320\225\320\235\320\253", nullptr));
        pushButton_moveModel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        pushButton_deleteModel->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        pushButton_addModel->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        pushButton_leftCircle->setText(QCoreApplication::translate("MainWindow", "\342\206\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
