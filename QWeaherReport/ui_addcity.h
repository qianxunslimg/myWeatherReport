/********************************************************************************
** Form generated from reading UI file 'addcity.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCITY_H
#define UI_ADDCITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddCity
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *plainTextEdit;

    void setupUi(QDialog *AddCity)
    {
        if (AddCity->objectName().isEmpty())
            AddCity->setObjectName(QString::fromUtf8("AddCity"));
        AddCity->resize(400, 300);
        AddCity->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);"));
        label = new QLabel(AddCity);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 60, 330, 41));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"color: rgb(41, 39, 40);"));
        pushButton = new QPushButton(AddCity);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 200, 171, 51));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8("font: 26pt \"Gigi\";\n"
"color: rgb(255, 0, 0);\n"
"background-color: rgb(255, 255, 0);"));
        plainTextEdit = new QLineEdit(AddCity);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(110, 130, 161, 51));
        plainTextEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"AcadEref\";\n"
"font: 26pt \"AcadEref\";\n"
"font: 14pt \"AcadEref\";\n"
"color: rgb(46, 47, 48);\n"
"background-color: rgb(152, 225, 101);"));

        retranslateUi(AddCity);

        QMetaObject::connectSlotsByName(AddCity);
    } // setupUi

    void retranslateUi(QDialog *AddCity)
    {
        AddCity->setWindowTitle(QCoreApplication::translate("AddCity", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddCity", "\350\257\267\350\276\223\345\205\245\346\202\250\346\203\263\346\267\273\345\212\240\347\232\204\345\237\216\345\270\202", nullptr));
        pushButton->setText(QCoreApplication::translate("AddCity", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCity: public Ui_AddCity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCITY_H
