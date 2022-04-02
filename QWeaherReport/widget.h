#ifndef WIDGET_H
#define WIDGET_H
#pragma execution_character_set("utf-8")
#include <QWidget>
#include <QTextCodec>
#include <QTextStream>
#include <QFile>
#include <QIODevice>
#include "addcity.h"
#include "weatherlifeindex.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>


#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void display(QString);
    void findPyFromZh(QString);
    void writeByLine(QString);
    //    void showIcon(QString);
    QStringList iconIndex;
private:
    Ui::Widget *ui;
    QNetworkAccessManager *manager_GetWearherInfo;
    QNetworkAccessManager *manager_GetCityZh;
    QNetworkAccessManager *manager_GetvCityCode;
    QString nowDiqu;

    AddCity *newCity;
    WeatherLifeIndex *weatherlifeindex;
private slots:
    void replyFinished_GetWeatherInfo(QNetworkReply *);
    void replyFinished_GetCityZh(QNetworkReply *);
    void replyFinished_GetCityCode(QNetworkReply *);
    void on_comboBox_CityNow_currentIndexChanged(int index);
    void on_btn_addCity_clicked();

    void fromNewCity(QString);
    void on_btn_toLife_clicked();

signals:
    void toSubDialog();
};

struct Weather{
    QString temp, windDir,humidity,feelsLike,windSpeed,windScale;
    QString  city, obsTime, text, wind360, icon;

    QString nowIp;
    QString city_py, city_zh;
    QString city_code;

    int temp_begin, windDir_begin,humidity_begin,feelsLike_begin,
    windSpeed_begin,windScale_begin,
    obsTime_begin, text_begin, wind360_begin,icon_begin;

    int temp_end, windDir_end,humidity_end,feelsLike_end,
    windSpeed_end,windScale_end,
    obsTime_end, text_end, wind360_end,icon_end;

};

#endif // WIDGET_H
