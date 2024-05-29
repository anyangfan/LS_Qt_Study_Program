#include "mainwindow.h"

#include <QSplitter>
#include <QTextEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 1：拆分窗口（分割窗口、分裂窗口布局）
    QSplitter *spMainWindow=new QSplitter(Qt::Horizontal,0);
    QTextEdit *txteditmain=new QTextEdit("左边主窗口",spMainWindow);

    // 2：拆分右边部分窗口
    QSplitter *spRight=new QSplitter(Qt::Vertical,spMainWindow);
    QTextEdit *txteditup=new QTextEdit("右边上部分窗口",spRight);
    QTextEdit *txteditdown=new QTextEdit("右边下部分窗口",spRight);

    // 3：
    QSplitter *sptest=new QSplitter(Qt::Vertical,spRight);
    QTextEdit *txtedittest=new QTextEdit("零声教育-Qt开发工程师课程",sptest);

    // 4:
    QSplitter *sptestend=new QSplitter(Qt::Horizontal,spMainWindow);
    QTextEdit *txtedittestend=new QTextEdit("Qt开发工程师课程--Vico老师",sptestend);

    spMainWindow->setWindowTitle("Splitter类拆分窗口测试");
    spMainWindow->show();

}

MainWindow::~MainWindow()
{
}

