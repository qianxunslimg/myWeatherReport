/********************************************************************************
** Form generated from reading UI file 'weatherlifeindex.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERLIFEINDEX_H
#define UI_WEATHERLIFEINDEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WeatherLifeIndex
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *WeatherLifeIndex)
    {
        if (WeatherLifeIndex->objectName().isEmpty())
            WeatherLifeIndex->setObjectName(QString::fromUtf8("WeatherLifeIndex"));
        WeatherLifeIndex->resize(400, 300);
        label = new QLabel(WeatherLifeIndex);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 72, 16));
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(WeatherLifeIndex);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 130, 89, 24));

        retranslateUi(WeatherLifeIndex);

        QMetaObject::connectSlotsByName(WeatherLifeIndex);
    } // setupUi

    void retranslateUi(QDialog *WeatherLifeIndex)
    {
        WeatherLifeIndex->setWindowTitle(QCoreApplication::translate("WeatherLifeIndex", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("WeatherLifeIndex", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("WeatherLifeIndex", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeatherLifeIndex: public Ui_WeatherLifeIndex {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERLIFEINDEX_H
