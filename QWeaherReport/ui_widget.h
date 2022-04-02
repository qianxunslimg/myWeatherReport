/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_CityNow;
    QPushButton *btn_addCity;
    QLabel *label_image;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *text;
    QLabel *temp;
    QHBoxLayout *horizontalLayout_2;
    QLabel *windScale;
    QLabel *windDir;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_toLife;
    QLabel *humidity;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setEnabled(true);
        Widget->resize(328, 424);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(310, 170));
        widget_2->setMaximumSize(QSize(310, 170));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        comboBox_CityNow = new QComboBox(widget);
        comboBox_CityNow->setObjectName(QString::fromUtf8("comboBox_CityNow"));
        sizePolicy.setHeightForWidth(comboBox_CityNow->sizePolicy().hasHeightForWidth());
        comboBox_CityNow->setSizePolicy(sizePolicy);
        comboBox_CityNow->setMinimumSize(QSize(128, 64));
        comboBox_CityNow->setMaximumSize(QSize(128, 64));

        verticalLayout->addWidget(comboBox_CityNow);

        btn_addCity = new QPushButton(widget);
        btn_addCity->setObjectName(QString::fromUtf8("btn_addCity"));
        sizePolicy.setHeightForWidth(btn_addCity->sizePolicy().hasHeightForWidth());
        btn_addCity->setSizePolicy(sizePolicy);
        btn_addCity->setMinimumSize(QSize(128, 64));
        btn_addCity->setMaximumSize(QSize(128, 64));
        btn_addCity->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 128, 254);\n"
"font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(btn_addCity);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        label_image = new QLabel(widget_2);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(25);
        sizePolicy1.setVerticalStretch(25);
        sizePolicy1.setHeightForWidth(label_image->sizePolicy().hasHeightForWidth());
        label_image->setSizePolicy(sizePolicy1);
        label_image->setMinimumSize(QSize(128, 128));
        label_image->setMaximumSize(QSize(128, 128));
        label_image->setSizeIncrement(QSize(200, 200));
        label_image->setBaseSize(QSize(200, 200));

        gridLayout->addWidget(label_image, 0, 1, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 0, 1, 1);

        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setMinimumSize(QSize(310, 230));
        widget_3->setMaximumSize(QSize(310, 230));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        text = new QLabel(widget_3);
        text->setObjectName(QString::fromUtf8("text"));
        sizePolicy.setHeightForWidth(text->sizePolicy().hasHeightForWidth());
        text->setSizePolicy(sizePolicy);
        text->setMinimumSize(QSize(128, 64));
        text->setMaximumSize(QSize(128, 64));
        text->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        text->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(text);

        temp = new QLabel(widget_3);
        temp->setObjectName(QString::fromUtf8("temp"));
        sizePolicy.setHeightForWidth(temp->sizePolicy().hasHeightForWidth());
        temp->setSizePolicy(sizePolicy);
        temp->setMinimumSize(QSize(128, 64));
        temp->setMaximumSize(QSize(128, 64));
        temp->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        temp->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(temp);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        windScale = new QLabel(widget_3);
        windScale->setObjectName(QString::fromUtf8("windScale"));
        sizePolicy.setHeightForWidth(windScale->sizePolicy().hasHeightForWidth());
        windScale->setSizePolicy(sizePolicy);
        windScale->setMinimumSize(QSize(128, 64));
        windScale->setMaximumSize(QSize(128, 64));
        windScale->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        windScale->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(windScale);

        windDir = new QLabel(widget_3);
        windDir->setObjectName(QString::fromUtf8("windDir"));
        sizePolicy.setHeightForWidth(windDir->sizePolicy().hasHeightForWidth());
        windDir->setSizePolicy(sizePolicy);
        windDir->setMinimumSize(QSize(128, 64));
        windDir->setMaximumSize(QSize(128, 64));
        windDir->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        windDir->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(windDir);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btn_toLife = new QPushButton(widget_3);
        btn_toLife->setObjectName(QString::fromUtf8("btn_toLife"));
        sizePolicy.setHeightForWidth(btn_toLife->sizePolicy().hasHeightForWidth());
        btn_toLife->setSizePolicy(sizePolicy);
        btn_toLife->setMinimumSize(QSize(128, 64));
        btn_toLife->setMaximumSize(QSize(128, 64));
        btn_toLife->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_4->addWidget(btn_toLife);

        humidity = new QLabel(widget_3);
        humidity->setObjectName(QString::fromUtf8("humidity"));
        sizePolicy.setHeightForWidth(humidity->sizePolicy().hasHeightForWidth());
        humidity->setSizePolicy(sizePolicy);
        humidity->setMinimumSize(QSize(128, 64));
        humidity->setMaximumSize(QSize(128, 64));
        humidity->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        humidity->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(humidity);


        verticalLayout_3->addLayout(horizontalLayout_4);


        gridLayout_2->addWidget(widget_3, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btn_addCity->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\345\237\216\345\270\202", nullptr));
        label_image->setText(QString());
        text->setText(QString());
        temp->setText(QString());
        windScale->setText(QString());
        windDir->setText(QString());
        btn_toLife->setText(QCoreApplication::translate("Widget", "\347\224\237\346\264\273\346\214\207\346\225\260", nullptr));
        humidity->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
