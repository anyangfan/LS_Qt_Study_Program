#include <QCoreApplication> // Qt提供一个事件循环

#include <QDebug> // 输出流

#include <iostream>
using namespace std;

#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 1:QString 提供二元"+"操作符应用，功能一样"+="
    /*QString str1="Ling";
    str1=str1+"Sheng EDU!";
    qDebug()<<str1; // 打印信息
    qDebug()<<qPrintable(str1); // 去掉双引号

    QString str2="12345";
    str2+="ABCDE";
    qDebug()<<qPrintable(str2); // 去掉双引号*/

    // 2:QString::append()函数
    /*QString str1="Good";
    QString str2="bye";
    str1.append(str2); // str1="Good bye"
    qDebug()<<qPrintable(str1);
    str1.append(" Hello world!");
    qDebug()<<qPrintable(str1); // str1="Goodbye Hello world!"*/

    // 3:QString::sprintf()函数
    /*QString strtemp;
    strtemp.sprintf("%s","Hello ");
    qDebug()<<qPrintable(strtemp);
    strtemp.sprintf("%s","Hello world.");
    qDebug()<<qPrintable(strtemp);

    strtemp.sprintf("%s %s","Welcome","to you.");
    qDebug()<<qPrintable(strtemp);*/

    // 4.1:QString::arg()函数
    /*QString strTemp;
    strTemp=QString("%1 was born in %2.").arg("Sunny").arg(2000);
    qDebug()<<strTemp;*/

    // 4.2:QString::startsWith()函数
    /*QString strTemp="How are you";
    qDebug()<<strTemp.startsWith("How",Qt::CaseSensitive); // true
    qDebug()<<strTemp.startsWith("are",Qt::CaseSensitive); // false*/

    // 5:QString::contains()函数
    /*QString strTemp="How are you";
    qDebug()<<strTemp.contains("How",Qt::CaseSensitive); // true*/

    // 6:QString::toInt()函数
    /*QString str="25";
    bool isloop;

    int hex=str.toInt(&isloop,16); // isloop=true hex=37
    qDebug()<<"isloop="<<isloop<<","<<"hex="<<hex<<endl;*/


    // 7:QString::compare()函数
    /*int a1 = QString::compare("abcd","ABCD",Qt::CaseInsensitive); // 大小写不敏感
    int b1 = QString::compare("about","Cat",Qt::CaseSensitive);
    int c1 = QString::compare("abcd","Cat",Qt::CaseInsensitive);
    cout<<"a1="<<a1<<","<<"b1="<<b1<<","<<"c1="<<c1<<endl;*/

    // 8:Qt将QString转换成ASCII码
    /*QString str="ABC abc";
    QByteArray bytes=str.toUtf8();
    for(int i=0;i<str.size();i++)
        qDebug()<<int(bytes.at(i));*/

    // 9:QDateTime QByteArray
    QDateTime dt;
    QString strDT=dt.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    qDebug()<<strDT<<endl;

    QByteArray a1("Qt Creator Hello World.");
    QByteArray b1=a1.toLower(); // 将字符串大写字母转小写，小写不变
    qDebug()<<b1<<endl;
    QByteArray c1=a1.toUpper();
    qDebug()<<c1<<endl;

    return a.exec();
}























