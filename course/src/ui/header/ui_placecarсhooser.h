/********************************************************************************
** Form generated from reading UI file 'placecarсhooser.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLACECAR_441_HOOSER_H
#define UI_PLACECAR_441_HOOSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PlaceCarChooser
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PlaceCarChooser)
    {
        if (PlaceCarChooser->objectName().isEmpty())
            PlaceCarChooser->setObjectName(QString::fromUtf8("PlaceCarChooser"));
        PlaceCarChooser->resize(409, 233);
        verticalLayout_2 = new QVBoxLayout(PlaceCarChooser);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(PlaceCarChooser);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(PlaceCarChooser);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        label_3 = new QLabel(PlaceCarChooser);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(PlaceCarChooser);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        label_5 = new QLabel(PlaceCarChooser);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        radioButton = new QRadioButton(PlaceCarChooser);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setCheckable(true);
        radioButton->setChecked(true);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(PlaceCarChooser);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        buttonBox = new QDialogButtonBox(PlaceCarChooser);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(PlaceCarChooser);

        QMetaObject::connectSlotsByName(PlaceCarChooser);
    } // setupUi

    void retranslateUi(QDialog *PlaceCarChooser)
    {
        PlaceCarChooser->setWindowTitle(QCoreApplication::translate("PlaceCarChooser", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("PlaceCarChooser", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \321\217\321\207\320\265\320\271\320\272\320\270 (\320\277\320\276 \320\276\321\201\320\270 Ox)", nullptr));
        lineEdit->setText(QCoreApplication::translate("PlaceCarChooser", "4", nullptr));
        label_3->setText(QCoreApplication::translate("PlaceCarChooser", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \321\217\321\207\320\265\320\271\320\272\320\270 (\320\277\320\276 \320\276\321\201\320\270 Oy)", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("PlaceCarChooser", "7", nullptr));
        label_5->setText(QCoreApplication::translate("PlaceCarChooser", "\320\222\321\213\320\261\320\265\321\200\320\265\321\202\320\265 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\321\210\320\270\320\275\321\213", nullptr));
        radioButton->setText(QCoreApplication::translate("PlaceCarChooser", "\320\222\320\264\320\276\320\273\321\214 Ox", nullptr));
        radioButton_2->setText(QCoreApplication::translate("PlaceCarChooser", "\320\222\320\264\320\276\320\273\321\214 Oy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaceCarChooser: public Ui_PlaceCarChooser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLACECAR_441_HOOSER_H
