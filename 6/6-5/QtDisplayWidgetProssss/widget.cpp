#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1:调用函数
    textlabelFunc();

    // 2:调用函数
    textbrowserFuncReadTxt();


    // 3:初始化进程条
    ui->progressBar->setRange(0,1000000);
    ui->progressBar->setValue(0);

    // 4:
    InitFunc();
    // 信号与槽函数连接
    connect(timers,&QTimer::timeout,this,&Widget::on_timerout);

}

Widget::~Widget()
{
    delete ui;
}

// 1:
void Widget::textlabelFunc()
{
    QString fName("d:\\666.jpg");

    QImage *qimg=new QImage;

    if(!(qimg->load(fName))) // 判断加载图片
    {
        QMessageBox::information(this,"失败","加载jpg图片失败，请重新检查?");
        delete  qimg;

        return;
    }

    ui->labeljpg->setPixmap(QPixmap::fromImage(*qimg));
}

// 2:
void Widget::textbrowserFuncReadTxt()
{
    QString qStrdData;
    QFile qfile("d:\\testfile.txt");

    if(!(qfile.open(QIODevice::ReadOnly|QIODevice::Text)))
    {
        QMessageBox::warning(this,"失败","打开文件失败，请重新检查?");
    }

    while (!qfile.atEnd())
    {
        QByteArray ay=qfile.readLine();
        QString strs(ay);
        qStrdData.append(strs);
    }

    ui->textBrowser->setText(qStrdData);
}

void Widget::on_pushButtonProgressBar_clicked()
{
    for(int i=1;i<=1000000;i++)
    {
        for(int j=0;j<1;j++)
        {
            ui->progressBar->setValue(i);
        }
    }
}

void Widget::on_pushbtnstart_clicked()
{
    timers->start(); // 1s触发一次操作
    ui->pushbtnstart->setEnabled(false);
    ui->pushbtnpause->setEnabled(true);
    ui->pushbtnreset->setEnabled(true);

}

void Widget::on_pushbtnpause_clicked()
{
    timers->stop(); // 1s触发一次操作
    ui->pushbtnstart->setEnabled(true);
    ui->pushbtnpause->setEnabled(false);
    ui->pushbtnreset->setEnabled(true);

}

void Widget::on_pushbtnreset_clicked()
{
    timers->stop(); // 1s触发一次操作
    iValues=0;

    ui->lcdNumber->display(iValues);

    ui->pushbtnstart->setEnabled(true);
    ui->pushbtnpause->setEnabled(true);
    ui->pushbtnreset->setEnabled(false);

}

void Widget::InitFunc()
{
    timers=new QTimer(this);
    timers->setInterval(1000); // 定时周期为1s
    timers->stop();

}

void Widget::on_timerout()
{
    iValues++;
    ui->lcdNumber->display(iValues);
}
