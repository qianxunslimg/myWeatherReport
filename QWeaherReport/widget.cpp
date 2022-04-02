#include "widget.h"
#include "ui_widget.h"
extern QString city_code_toAll;
//    QIcon icon(":/new/image/city.png");
int Parse_HeWeather_Now_Json(void);
Weather weather;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QFont font = QFont ("Courier");
    font.setStyleHint (QFont::Monospace);
    font.setPointSize (20);
    //    ui->textBrowser->setFont(font);
    ui->comboBox_CityNow->setFont(font);
    //    ui->textBrowser_chuli->setFont(font);

    //ui->comboBox_CityNow->setItemIcon(0,icon);


    //配置文件
    QFile file("./config.txt");
    if(!file.exists()){
        qDebug() << ("未找到文件夹路径");
        file.open(QIODevice::WriteOnly | QIODevice::Text );
    }

    //添加新城市及其信号槽
    newCity=new AddCity;
    connect(newCity,SIGNAL(tomainWidget(QString)),this,SLOT(fromNewCity(QString)));


    //添加生活指数窗口
    weatherlifeindex = new WeatherLifeIndex;

    //信号与槽清空 子窗口text
    connect(this,SIGNAL(toSubDialog()), newCity, SLOT(fromMainWidget()));



    /*根据ip获取地址，
  根据地址获取code
  根据code获取天气*/


    //根据ip获取当前城市名中文
    manager_GetCityZh = new QNetworkAccessManager(this);
    connect(manager_GetCityZh, SIGNAL(finished(QNetworkReply*)),
            this,SLOT(replyFinished_GetCityZh(QNetworkReply*)));
    manager_GetCityZh->get(QNetworkRequest(
                               QUrl("https://restapi.amap.com/v3/ip?&output=xml&key=e330e2881ed7de96854e770c71a6a6bb")));



    //获取weatherInfo
    manager_GetWearherInfo = new QNetworkAccessManager(this);
    connect(manager_GetWearherInfo, SIGNAL(finished(QNetworkReply*)),
            this,SLOT(replyFinished_GetWeatherInfo(QNetworkReply*)));
    // manager->get(QNetworkRequest(
    //                 QUrl("https://geoapi.qweather.com/v2/city/lookup?location=wuhan&key=af50a832027844f692de411f1ad9655d")));



    //获取citycode
    manager_GetvCityCode = new QNetworkAccessManager(this);
    connect(manager_GetvCityCode, SIGNAL(finished(QNetworkReply*)),
            this,SLOT(replyFinished_GetCityCode(QNetworkReply*)));
}


//根据ip获取城市汉字
void Widget::replyFinished_GetCityZh(QNetworkReply *reply)
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QString all = codec->toUnicode(reply->readAll());
    qDebug()<<all<<endl;
    weather.city_zh = all.mid(all.indexOf("city")+5, (all.indexOf("市")-1) - (all.indexOf("city")+4));
    //qDebug()<<weather.city_zh<<endl;
    ui->comboBox_CityNow->addItem(weather.city_zh);
    writeByLine(weather.city_zh);
    findPyFromZh(weather.city_zh);

    QString citypy_url = "https://geoapi.qweather.com/v2/city/lookup?location=%1&key=af50a832027844f692de411f1ad9655d";
    citypy_url = citypy_url.arg(weather.city_py);

    manager_GetvCityCode->get(QNetworkRequest(
                                  QUrl(citypy_url)));
    reply->deleteLater();
}


//根据城市拼音获取城市code
void Widget::replyFinished_GetCityCode(QNetworkReply *reply){
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QString all = codec->toUnicode(reply->readAll());

    weather.city_code = all.mid(all.indexOf("id")+5, (all.indexOf("lat")-3) - (all.indexOf("id")+5));
    qDebug()<<"the city code is "<<weather.city_code<<endl;

    QString weather_info = "https://devapi.qweather.com/v7/weather/now?location=%1&key=af50a832027844f692de411f1ad9655d";
    weather_info = weather_info.arg(weather.city_code);
    manager_GetWearherInfo->get(QNetworkRequest(QUrl(weather_info)));

    reply->deleteLater();
}


//获取天气信息
void Widget::replyFinished_GetWeatherInfo(QNetworkReply *reply)
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QString all = codec->toUnicode(reply->readAll());
    qDebug()<<all<<endl;
    //ui->textBrowser->setText(all);

    display(all);
    reply->deleteLater();
}





//combobox改变触发事件
void Widget::on_comboBox_CityNow_currentIndexChanged(int index)
{
    findPyFromZh(ui->comboBox_CityNow->currentText());
    qDebug()<<"current city is "<<weather.city_py<<endl;
    QString citypy_url = "https://geoapi.qweather.com/v2/city/lookup?location=%1&key=af50a832027844f692de411f1ad9655d";
    citypy_url = citypy_url.arg(weather.city_py);

    manager_GetvCityCode->get(QNetworkRequest(
                                  QUrl(citypy_url)));

    qDebug()<<"combox changed..."<<endl;
    QString weather_url = "https://devapi.qweather.com/v7/weather/now?location=%1&key=af50a832027844f692de411f1ad9655d";
    weather_url = weather_url.arg(weather.city_code);
    manager_GetWearherInfo->get(QNetworkRequest(QUrl(weather_url)));
}


//显示天气信息
void Widget::display(QString all){
    //获取当前地区
    weather.city = ui->comboBox_CityNow->currentText();

    //天气解析
    weather.text_begin = all.indexOf("text")+7;
    weather.text_end = all.indexOf("wind360")-3;

    weather.text =
            all.mid(weather.text_begin, weather.text_end - weather.text_begin);
    //    ui->textBrowser_chuli->setPlainText(jixitianqixianshi);
    ui->text->setText(weather.text);



    //风向解析
    weather.windDir_begin = all.indexOf("windDir")+10;
    weather.windDir_end = all.indexOf("windScale")-3;
    weather.windDir =
            all.mid(weather.windDir_begin, weather.windDir_end - weather.windDir_begin);
    //    ui->textBrowser_chuli->setPlainText(wenduxianshi);
    ui->windDir->setText(weather.windDir);

    //风ji解析
    weather.windScale_begin = all.indexOf("windScale")+12;
    weather.windScale_end = all.indexOf("windSpeed")-3;
    weather.windScale =
            all.mid(weather.windScale_begin,
                    weather.windScale_end - weather.windScale_begin) + "级";
    //    ui->textBrowser_chuli->setPlainText(wenduxianshi);
    //qDebug()<<weather.windScale<<endl;
    ui->windScale->setText(weather.windScale);

    //温度解析
    weather.temp_begin = all.indexOf("temp")+7;
    weather.temp_end = all.indexOf("feelsLike")-3;
    weather.temp =
            all.mid(weather.temp_begin, weather.temp_end - weather.temp_begin) + "度";
    //    ui->textBrowser_chuli->setPlainText(wenduxianshi);
    ui->temp->setText(weather.temp);


    //空气shi度解析
    weather.humidity_begin = all.indexOf("humidity")+11;
    weather.humidity_end = all.indexOf("precip")-3;
    weather.humidity =
            "湿度"+ all.mid(weather.humidity_begin, weather.humidity_end - weather.humidity_begin);
    ui->humidity->setText(weather.humidity);




    //icon解析
    weather.icon_begin = all.indexOf("icon")+7;
    weather.icon_end = all.indexOf("text")-3;

    weather.icon =
            all.mid(weather.icon_begin, weather.icon_end - weather.icon_begin);
    qDebug()<<"the icon number is "<<weather.icon<<endl;
    //        QImage image((":/new/image/%1.png").arg(weather.icon.toInt()));
    //        ui->label_image->setPixmap(QPixmap::fromImage(image));
    //        ui->label_image->show();
    QString iconPath = ":/new/image/%1.png";
    iconPath = iconPath.arg(weather.icon);
    QImage image(iconPath);
    ui->label_image->setPixmap(QPixmap::fromImage(image));
    ui->label_image->show();

}

//根据汉字城市名查找城市py
void Widget::findPyFromZh(QString Zh){

    QFile file(":/new/city_code.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            QString line = file.readLine();
            if(line.contains(Zh)){
                weather.city_py =  line.mid(line.indexOf(Zh)+3, line.indexOf("\n")-3);
                //qDebug()<<"the py of now city is "<<weather.city_py<<endl;
            }
            //qDebug() << line;
        }
        file.close();

    }
}


void Widget::writeByLine(QString cityname){
    //    QFile file("C:\\Users\\00\\Desktop\\QT xiaochengxu\\QWeaherReport\\savedCities.txt");
    //    QTextStream ts(&file);
    //    bool isok = file.open(QIODevice::WriteOnly);
    //    if(isok == true){
    //        ts.seek()
    //        qDebug()<<"write success!"<<endl;
    //    }
    //    else qDebug()<<"Fuck"<<endl;
    //    file1.close();

    QFile file("./config.txt");  //创建文件对象

    file.open(QIODevice::ReadWrite|QIODevice::Text);	//以读且写的方式打开

    QTextCodec *codec=QTextCodec::codecForName("GBK");	 //防止乱码

    QByteArray array=file.readAll();
    //读取原文件内容（必须先读出来，才不会被新内容## 标题覆盖掉)

    QString str=cityname;	//字符串，名字可变，这里只是举例

    QTextStream out(&file);		//输入流

    out<<"\n"<<str;			//写入内容

    file.close();              //关闭文件流

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_addCity_clicked()
{
    newCity->show();
    emit toSubDialog();
}


//添加新城市后的一系列处理
void Widget::fromNewCity(QString newCityName){
    qDebug()<<"the name of the new city is "<<newCityName<<endl;
    ui->comboBox_CityNow->addItem(newCityName);
    ui->comboBox_CityNow->setCurrentIndex(ui->comboBox_CityNow->count()-1);
    //ui->comboBox_CityNow->setItemText(0,newCityName);
    weather.city_zh = newCityName;
    writeByLine(weather.city_zh);
    findPyFromZh(weather.city_zh);

    QString citypy_url = "https://geoapi.qweather.com/v2/city/lookup?location=%1&key=af50a832027844f692de411f1ad9655d";
    citypy_url = citypy_url.arg(weather.city_py);

    manager_GetvCityCode->get(QNetworkRequest(
                                  QUrl(citypy_url)));

}

void Widget::on_btn_toLife_clicked()
{
    weatherlifeindex->show();
    city_code_toAll = weather.city_code;
}
