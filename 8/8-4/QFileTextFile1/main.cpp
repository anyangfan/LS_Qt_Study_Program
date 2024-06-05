#include <QCoreApplication>

#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 1:创建QFile对象，指定操作的相关文件
    QFile qfs("d:/qfiletext.txt");

    // 2:打开文件进行写操作 ReadOnly ReadWrite Append Truncate
    if(!qfs.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<"打开文件失败，请生重新检查？";
    }
    else
    {
        qDebug()<<"恭喜你，打开文件成功！";
    }

    // 3:向打开的文件写数据信息
    qfs.write("零声教育--");
    qfs.write("Qt开发工程师课程\n");
    qfs.write("腾讯课堂：C/C++后台开发银牌机构");

    // 4:关闭文件
    qfs.close();



    // 读取文件数据
    if(!qfs.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"打开文件失败，请生重新检查？";
    }
    else
    {
        qDebug()<<"恭喜你，打开文件成功（读取数据）！";
    }

    // 定义字符指针
    char *pStr=new char[200];
    qint64 rcount=qfs.readLine(pStr,200);

    while((rcount!=0) && (rcount!=-1))
    {
        qDebug()<<pStr;
        rcount=qfs.readLine(pStr,200);
    }

    qfs.close();


    return a.exec();
}
