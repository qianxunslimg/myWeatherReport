#include "addcity.h"
#include "ui_addcity.h"
#include <QDebug>


AddCity::AddCity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCity)
{
    ui->setupUi(this);
    //    connect(newCity,SIGNAL(tomainWidget(QString)),this,SLOT(fromNewCity(QString)));
    //connect(Widget,SIGNAL(toSubDialog()), this, SLOT(fromMainWidget()));
    connect(ui->plainTextEdit, SIGNAL(returnPressed()), this, SLOT(slotEditClicked()));
}

AddCity::~AddCity()
{
    delete ui;
}

void AddCity::on_pushButton_clicked()
{
    newCityName = ui->plainTextEdit->text();
    qDebug()<<"the new city is "<< newCityName<<endl;
    emit tomainWidget(newCityName);
    this->hide();
}

void AddCity::fromMainWidget(){
    ui->plainTextEdit->clear();
}

void AddCity::slotEditClicked()
{
    newCityName = ui->plainTextEdit->text();
    qDebug()<<"the new city is "<< newCityName<<endl;
    emit tomainWidget(newCityName);
    this->hide();
}

//void AddCity::`(QString){
//    emit
//}
