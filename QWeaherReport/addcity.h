#ifndef ADDCITY_H
#define ADDCITY_H

#include <QDialog>
#include <QKeyEvent>
//#include <widget.h>
namespace Ui {
class AddCity;
}

class AddCity : public QDialog
{
    Q_OBJECT

public:
    explicit AddCity(QWidget *parent = nullptr);
    ~AddCity();
    QString newCityName;


signals:
    void tomainWidget(QString);

private slots:
    void on_pushButton_clicked();
    void slotEditClicked();
    void fromMainWidget();
private:
    Ui::AddCity *ui;

};

#endif // ADDCITY_H
