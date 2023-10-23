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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_1;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QToolBox *toolBox;
    QWidget *page_7;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_9;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *x_set_obj;
    QPushButton *pushButton;
    QComboBox *chose_obj;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_10;
    QLabel *label_2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer;
    QWidget *page_8;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_7;
    QDoubleSpinBox *doubleSpinBox_7;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_8;
    QComboBox *comboBox_3;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QLineEdit *lineEdit_9;
    QWidget *page_9;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_7;
    QLineEdit *lineEdit_10;
    QDoubleSpinBox *doubleSpinBox_10;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_11;
    QComboBox *comboBox_4;
    QDoubleSpinBox *doubleSpinBox_11;
    QDoubleSpinBox *doubleSpinBox_12;
    QLineEdit *lineEdit_12;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        MainWindow->setFont(font);
        action_1 = new QAction(MainWindow);
        action_1->setObjectName(QString::fromUtf8("action_1"));
        action_1->setFont(font);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_2->setFont(font);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(350, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolBox = new QToolBox(groupBox);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        page_7->setGeometry(QRect(0, 0, 324, 418));
        gridLayout_3 = new QGridLayout(page_7);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(page_7);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_9 = new QGridLayout(groupBox_5);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        spinBox_2 = new QSpinBox(groupBox_5);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        gridLayout_9->addWidget(spinBox_2, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_9->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_9->addWidget(label_4, 1, 1, 1, 1);

        x_set_obj = new QSpinBox(groupBox_5);
        x_set_obj->setObjectName(QString::fromUtf8("x_set_obj"));

        gridLayout_9->addWidget(x_set_obj, 2, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_5, 1, 0, 1, 2);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 2, 0, 1, 2);

        chose_obj = new QComboBox(groupBox_2);
        chose_obj->addItem(QString());
        chose_obj->addItem(QString());
        chose_obj->addItem(QString());
        chose_obj->addItem(QString());
        chose_obj->addItem(QString());
        chose_obj->addItem(QString());
        chose_obj->addItem(QString());
        chose_obj->setObjectName(QString::fromUtf8("chose_obj"));

        gridLayout_2->addWidget(chose_obj, 0, 0, 1, 2);

        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_10 = new QGridLayout(groupBox_6);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_10->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(groupBox_6);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_10->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout_10->addWidget(doubleSpinBox, 1, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        gridLayout_10->addWidget(doubleSpinBox_2, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_6, 4, 0, 1, 2);

        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_2->addWidget(pushButton_5, 7, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        toolBox->addItem(page_7, QString::fromUtf8("\320\236\320\261\321\212\320\265\320\272\321\202\321\213 \321\201\321\206\320\265\320\275\321\213"));
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        page_8->setGeometry(QRect(0, 0, 324, 418));
        gridLayout_6 = new QGridLayout(page_8);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox_3 = new QGroupBox(page_8);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        lineEdit_7 = new QLineEdit(groupBox_3);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        gridLayout_5->addWidget(lineEdit_7, 1, 1, 1, 1);

        doubleSpinBox_7 = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));

        gridLayout_5->addWidget(doubleSpinBox_7, 2, 2, 1, 1);

        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_5->addWidget(pushButton_3, 3, 0, 1, 3);

        lineEdit_8 = new QLineEdit(groupBox_3);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        gridLayout_5->addWidget(lineEdit_8, 1, 0, 1, 1);

        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        gridLayout_5->addWidget(comboBox_3, 0, 0, 1, 3);

        doubleSpinBox_8 = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));

        gridLayout_5->addWidget(doubleSpinBox_8, 2, 0, 1, 1);

        doubleSpinBox_9 = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));

        gridLayout_5->addWidget(doubleSpinBox_9, 2, 1, 1, 1);

        lineEdit_9 = new QLineEdit(groupBox_3);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        gridLayout_5->addWidget(lineEdit_9, 1, 2, 1, 1);


        gridLayout_6->addWidget(groupBox_3, 0, 0, 1, 1);

        toolBox->addItem(page_8, QString::fromUtf8("\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\236\320\261\321\212\320\265\320\272\321\202\320\276\320\262"));
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        page_9->setGeometry(QRect(0, 0, 324, 418));
        gridLayout_8 = new QGridLayout(page_9);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        groupBox_4 = new QGroupBox(page_9);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        lineEdit_10 = new QLineEdit(groupBox_4);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        gridLayout_7->addWidget(lineEdit_10, 1, 1, 1, 1);

        doubleSpinBox_10 = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));

        gridLayout_7->addWidget(doubleSpinBox_10, 2, 2, 1, 1);

        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_7->addWidget(pushButton_4, 3, 0, 1, 3);

        lineEdit_11 = new QLineEdit(groupBox_4);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        gridLayout_7->addWidget(lineEdit_11, 1, 0, 1, 1);

        comboBox_4 = new QComboBox(groupBox_4);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        gridLayout_7->addWidget(comboBox_4, 0, 0, 1, 3);

        doubleSpinBox_11 = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));

        gridLayout_7->addWidget(doubleSpinBox_11, 2, 0, 1, 1);

        doubleSpinBox_12 = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_12->setObjectName(QString::fromUtf8("doubleSpinBox_12"));

        gridLayout_7->addWidget(doubleSpinBox_12, 2, 1, 1, 1);

        lineEdit_12 = new QLineEdit(groupBox_4);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        gridLayout_7->addWidget(lineEdit_12, 1, 2, 1, 1);


        gridLayout_8->addWidget(groupBox_4, 0, 0, 1, 1);

        toolBox->addItem(page_9, QString::fromUtf8("\320\230\320\267\320\274\320\265\320\275\320\270\320\265 \320\241\321\206\320\265\320\275\321\213"));

        verticalLayout->addWidget(toolBox);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setFont(font);
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action_1);
        menu->addAction(action_2);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_1->setText(QCoreApplication::translate("MainWindow", "\321\207\321\202\320\276 - \321\202\320\276 1", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\321\207\321\202\320\276 - \321\202\320\276 2", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\321\207\321\202\320\276 - \321\202\320\276 3", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", " - \321\202\320\276 3", nullptr));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\276\320\261\321\212\320\265\320\272\321\202\320\260 \320\275\320\260 \321\201\321\206\320\265\320\275\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202 \320\275\320\260 \321\201\321\206\320\265\320\275\321\203", nullptr));
        chose_obj->setItemText(0, QCoreApplication::translate("MainWindow", "\320\224\320\276\320\274 \302\253\321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\213\320\271\302\273", nullptr));
        chose_obj->setItemText(1, QCoreApplication::translate("MainWindow", "\320\224\320\276\320\274 \302\253\320\277\321\200\320\265\320\274\320\270\320\260\320\273\321\214\320\275\321\213\320\271\302\273", nullptr));
        chose_obj->setItemText(2, QCoreApplication::translate("MainWindow", "\320\224\320\276\321\200\320\276\320\263\320\260", nullptr));
        chose_obj->setItemText(3, QCoreApplication::translate("MainWindow", "\320\234\320\260\321\210\320\270\320\275\320\260 (\321\201\320\265\321\200\320\260\321\217)", nullptr));
        chose_obj->setItemText(4, QCoreApplication::translate("MainWindow", "\320\234\320\260\321\210\320\270\320\275\320\260 (\320\272\321\200\320\260\321\201\320\275\320\260\321\217)", nullptr));
        chose_obj->setItemText(5, QCoreApplication::translate("MainWindow", "\320\224\320\265\321\200\320\265\320\262\320\276", nullptr));
        chose_obj->setItemText(6, QCoreApplication::translate("MainWindow", "\320\232\321\203\321\201\321\202", nullptr));

#if QT_CONFIG(whatsthis)
        chose_obj->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\276\320\264\320\270\320\275 \320\270\320\267 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262 \321\201\321\206\320\265\320\275\321\213 \320\264\320\273\321\217 \320\265\320\263\320\276 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217 \320\275\320\260  \321\201\321\206\320\265\320\275\320\265</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260 \321\201\320\262\320\265\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 Y", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 X", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_7), QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213 \321\201\321\206\320\265\320\275\321\213", nullptr));
        groupBox_3->setTitle(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_8), QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\236\320\261\321\212\320\265\320\272\321\202\320\276\320\262", nullptr));
        groupBox_4->setTitle(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_9), QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\320\265 \320\241\321\206\320\265\320\275\321\213", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
