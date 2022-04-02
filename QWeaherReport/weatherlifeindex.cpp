#include "weatherlifeindex.h"
#include "ui_weatherlifeindex.h"
#include<QIcon>
#include <QDebug>
#include <QTextCodec>
extern QString city_code_toAll;
#pragma execution_character_set("utf-8")
WeatherLifeIndex::WeatherLifeIndex(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WeatherLifeIndex)
{
    ui->setupUi(this);
    setWindowTitle("生活指数");
    QIcon icon(":/new/image/life.png");
    setWindowIcon(icon);

    manager_GetLifeIndex = new QNetworkAccessManager;
    connect(manager_GetLifeIndex, SIGNAL(finished(QNetworkReply*)),
            this,SLOT(replyFinished_GetLifeIndex(QNetworkReply*)));


}

WeatherLifeIndex::~WeatherLifeIndex()
{
    delete ui;
}

void WeatherLifeIndex::on_pushButton_clicked()
{
    qDebug()<<"the fucking city code is "<<city_code_toAll<<endl;
    QString url = "https://devapi.qweather.com/v7/indices/1d?type=1,2&location=%1&key=af50a832027844f692de411f1ad9655d";
    QString final_url = url.arg(city_code_toAll);

    manager_GetLifeIndex->get(QNetworkRequest(
                                  QUrl(final_url)));

}

void WeatherLifeIndex::replyFinished_GetLifeIndex(QNetworkReply *reply)
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QString all = codec->toUnicode(reply->readAll());
    qDebug()<<all<<endl;
    //ui->textBrowser->setText(all);

    //display(all);
    reply->deleteLater();
}

void WeatherLifeIndex::dispaly(QString all)
{

}
