#include <QCoreApplication>

#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 将qnumber里面的数据写入到文件
    qint32 qnumber[3]={1,2,3};

    // 将qnumber数据以二进制方式存储到字节数组当中
    QByteArray bytearray;
    bytearray.resize(sizeof(qnumber));

    for(int i=0;i<3;i++)
    {
        // for循环利用指针将每个整数复制到字符数组里面去
        memcpy(bytearray.data()+i*sizeof(qint32),&(qnumber[i]),sizeof(qint32));
    }

    // 将bytearray字节数组存储至对应文件当中QFileBinaryByte.dat
    QFile qfs("d:/QFileBinaryByte.dat");

    if(!qfs.open(QIODevice::WriteOnly))
    {
        qDebug()<<"打开文件失败，请生重新检查？";
    }
    else
    {
        qDebug()<<"恭喜你，打开文件成功！";
    }

    qfs.write(bytearray);
    qfs.close();



    // 先打开，再读取
    qfs.open(QIODevice::ReadOnly);
    QByteArray byteArry=qfs.readAll();

    // 输出读取的二进制数据
    qDebug()<<"byteArry："<<byteArry;

    // 将二进制数据转化为整数
    char *ctemp=byteArry.data();
    while(*ctemp)
    {
        qDebug()<<*(qint32*)ctemp;
        ctemp=ctemp+sizeof (qint32);
    }

    qfs.close();


    return a.exec();
}
