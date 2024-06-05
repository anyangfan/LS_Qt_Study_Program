#include <QCoreApplication>

#include <QFile>
#include <QtDebug>
#include <QTextStream>
#include <QDataStream>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 写入数据到文件
    QFile qfs("d:/qtextstreamfile.txt");

    if(!qfs.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<"打开文件失败，请重新检查？";
    }
    else
    {
        qDebug()<<"恭喜你，打开文件成功！";
    }

    QTextStream qtextstreamwrite(&qfs);

    // 向文件写入数据
    qtextstreamwrite<<(QString)"零声教育-Qt开发工程师课程";

    qfs.close();


    // 从文件读取数据
    if(!qfs.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"打开文件失败，请重新检查？";
    }
    else
    {
        qDebug()<<"恭喜你，打开文件成功(读取数据......)！";
    }

    QTextStream qtextstreamread(&qfs);

    while(!qtextstreamread.atEnd())
    {
        QString strtemp;
        qtextstreamread>>strtemp;
        qDebug()<<strtemp;
    }

    qfs.close();



    return a.exec();
}
