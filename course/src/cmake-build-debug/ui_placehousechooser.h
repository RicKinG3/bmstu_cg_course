/********************************************************************************
** Form generated from reading UI file 'placehousechooser.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLACEHOUSECHOOSER_H
#define UI_PLACEHOUSECHOOSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PlaceHouseChooser
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PlaceHouseChooser)
    {
        if (PlaceHouseChooser->objectName().isEmpty())
            PlaceHouseChooser->setObjectName(QString::fromUtf8("PlaceHouseChooser"));
        PlaceHouseChooser->resize(406, 308);
        verticalLayout_2 = new QVBoxLayout(PlaceHouseChooser);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(PlaceHouseChooser);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(PlaceHouseChooser);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        label_3 = new QLabel(PlaceHouseChooser);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(PlaceHouseChooser);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        label = new QLabel(PlaceHouseChooser);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit_3 = new QLineEdit(PlaceHouseChooser);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        label_4 = new QLabel(PlaceHouseChooser);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        lineEdit_4 = new QLineEdit(PlaceHouseChooser);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout->addWidget(lineEdit_4);

        label_5 = new QLabel(PlaceHouseChooser);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        lineEdit_5 = new QLineEdit(PlaceHouseChooser);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout->addWidget(lineEdit_5);

        buttonBox = new QDialogButtonBox(PlaceHouseChooser);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(PlaceHouseChooser);

        QMetaObject::connectSlotsByName(PlaceHouseChooser);
    } // setupUi

    void retranslateUi(QDialog *PlaceHouseChooser)
    {
        PlaceHouseChooser->setWindowTitle(QCoreApplication::translate("PlaceHouseChooser", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("PlaceHouseChooser", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \321\217\321\207\320\265\320\271\320\272\320\270 (\320\277\320\276 \320\276\321\201\320\270 Ox)", nullptr));
        lineEdit->setText(QCoreApplication::translate("PlaceHouseChooser", "2", nullptr));
        label_3->setText(QCoreApplication::translate("PlaceHouseChooser", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \321\217\321\207\320\265\320\271\320\272\320\270 (\320\277\320\276 \320\276\321\201\320\270 Oy)", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("PlaceHouseChooser", "2", nullptr));
        label->setText(QCoreApplication::translate("PlaceHouseChooser", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\210\320\270\321\200\320\270\320\275\321\203 \320\264\320\276\320\274\320\260 (\320\272\320\276\320\273-\320\262\320\276 \321\217\321\207\320\265\320\265\320\272 \320\277\320\276 \320\276\321\201\320\270 Ox):", nullptr));
        lineEdit_3->setInputMask(QString());
        lineEdit_3->setText(QCoreApplication::translate("PlaceHouseChooser", "3", nullptr));
        label_4->setText(QCoreApplication::translate("PlaceHouseChooser", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\273\320\270\320\275\321\203 \320\264\320\276\320\274\320\260 (\320\272\320\276\320\273-\320\262\320\276 \321\217\321\207\320\265\320\265\320\272 \320\277\320\276 \320\276\321\201\320\270 Oy):", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("PlaceHouseChooser", "2", nullptr));
        label_5->setText(QCoreApplication::translate("PlaceHouseChooser", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\321\213\321\201\320\276\321\202\321\203  \320\264\320\276\320\274\320\260 (\320\272\320\276\320\273-\320\262\320\276 \321\217\321\207\320\265\320\265\320\272)", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("PlaceHouseChooser", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaceHouseChooser: public Ui_PlaceHouseChooser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLACEHOUSECHOOSER_H
