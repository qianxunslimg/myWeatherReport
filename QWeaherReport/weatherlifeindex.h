#ifndef WEATHERLIFEINDEX_H
#define WEATHERLIFEINDEX_H

#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>


#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace Ui {
class WeatherLifeIndex;
}

class WeatherLifeIndex : public QDialog
{
    Q_OBJECT

public:
    explicit WeatherLifeIndex(QWidget *parent = nullptr);
    ~WeatherLifeIndex();

private slots:
    void on_pushButton_clicked();
    void replyFinished_GetLifeIndex(QNetworkReply*);

private:
    Ui::WeatherLifeIndex *ui;
    QNetworkAccessManager *manager_GetLifeIndex;
    QString cityCodeIn_LifeIndex;
    void dispaly(QString );
};

#endif // WEATHERLIFEINDEX_H
