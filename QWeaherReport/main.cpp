#include "widget.h"
#include <QIcon>
#include <QApplication>
#include <QFile>
QString city_code_toAll;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //���ñ����Icon
    w.setWindowTitle("Weather report");
    QIcon icon(":/new/image/icon.png");
    w.setWindowIcon(icon);


    //������ʽ��
    QFile qssFile(":/new/lightblue.css");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        QString qss = QLatin1String(qssFile.readAll()); //��ȡ
        qApp->setStyleSheet(qss);  //����
        qssFile.close();
    }



    //    QFile file1("C:\\Users\\00\\Desktop\\QT xiaochengxu\\QWeaherReport\\savedCities.txt");
    //    bool isok = file1.open(QIODevice::WriteOnly);
    //    if(isok == true){
    //        QString str = "wo daDas ��� ";
    //        file1.write(str.toStdString().data());
    //        qDebug()<<"write success!"<<endl;
    //    }
    //    else qDebug()<<"Fuck"<<endl;
    //    file1.close();


    //    QFile file("C:\\Users\\00\\Desktop\\QT xiaochengxu\\QWeaherReport\\savedCities.txt");  //�����ļ�����

    //   file.open(QIODevice::ReadWrite|QIODevice::Text);	//�Զ���д�ķ�ʽ��

    //   QTextCodec *codec=QTextCodec::codecForName("GBK");	 //��ֹ����

    //   QByteArray array=file.readAll();
    //               //��ȡԭ�ļ����ݣ������ȶ��������Ų��ᱻ������## ���⸲�ǵ�)

    //   QString str="newName";	//�ַ��������ֿɱ䣬����ֻ�Ǿ���

    //   QTextStream out(&file);		//������

    //   out<<"\n"<<str;			//д������

    //   file.close();              //�ر��ļ���


    w.show();


    return a.exec();
}
