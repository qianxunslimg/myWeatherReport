#include "widget.h"
#include <QIcon>
#include <QApplication>
#include <QFile>
QString city_code_toAll;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //设置标题和Icon
    w.setWindowTitle("Weather report");
    QIcon icon(":/new/image/icon.png");
    w.setWindowIcon(icon);


    //设置样式表
    QFile qssFile(":/new/lightblue.css");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        QString qss = QLatin1String(qssFile.readAll()); //读取
        qApp->setStyleSheet(qss);  //设置
        qssFile.close();
    }



    //    QFile file1("C:\\Users\\00\\Desktop\\QT xiaochengxu\\QWeaherReport\\savedCities.txt");
    //    bool isok = file1.open(QIODevice::WriteOnly);
    //    if(isok == true){
    //        QString str = "wo daDas 大大 ";
    //        file1.write(str.toStdString().data());
    //        qDebug()<<"write success!"<<endl;
    //    }
    //    else qDebug()<<"Fuck"<<endl;
    //    file1.close();


    //    QFile file("C:\\Users\\00\\Desktop\\QT xiaochengxu\\QWeaherReport\\savedCities.txt");  //创建文件对象

    //   file.open(QIODevice::ReadWrite|QIODevice::Text);	//以读且写的方式打开

    //   QTextCodec *codec=QTextCodec::codecForName("GBK");	 //防止乱码

    //   QByteArray array=file.readAll();
    //               //读取原文件内容（必须先读出来，才不会被新内容## 标题覆盖掉)

    //   QString str="newName";	//字符串，名字可变，这里只是举例

    //   QTextStream out(&file);		//输入流

    //   out<<"\n"<<str;			//写入内容

    //   file.close();              //关闭文件流


    w.show();


    return a.exec();
}
