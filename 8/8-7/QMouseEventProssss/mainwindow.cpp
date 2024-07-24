#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("测试鼠标事件程序");

    statuslabel=new QLabel;
    statuslabel->setText("鼠标在当前窗口坐标为：");
    statuslabel->setFixedWidth(200);

    mouselabelpos=new QLabel;
    mouselabelpos->setText("");
    mouselabelpos->setFixedWidth(200);

    // 在状态栏当中添加窗口小控件对象
    statusBar()->addPermanentWidget(statuslabel);
    statusBar()->addPermanentWidget(mouselabelpos);

    this->setMouseTracking(true); // 鼠标实时追踪

    resize(800,600);

    disppicture(); // 调用显示图片
}

MainWindow::~MainWindow()
{
}

// 鼠标移动
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    mouselabelpos->setText("("+QString::number(e->x())+","+QString::number(e->y())+")");

}

// 判断鼠标按键
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QString qstr="("+QString::number(e->x())+","+QString::number(e->y())+")";
    if(e->button()==Qt::LeftButton)
    {
        statusBar()->showMessage("用户已按下鼠标[左键]坐标"+qstr);
    }
    else if(e->button()==Qt::RightButton)
    {
        statusBar()->showMessage("用户已按下鼠标[右键]坐标"+qstr);
    }
    else if(e->button()==Qt::MidButton)
    {
        statusBar()->showMessage("用户已按下鼠标[中键]坐标"+qstr);
    }



}

// 释放鼠标按键
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    QString qstr="("+QString::number(e->x())+","+QString::number(e->y())+")";

    statusBar()->showMessage("用户已释放鼠标坐标"+qstr,20);

}

void MainWindow::disppicture()
{
    QString filenames(":/images/a.jpg");

    QImage *image=new QImage;
    QLabel *imagelabel=new QLabel(this);

    imagelabel->move(20,20); //
    imagelabel->setFixedSize(700,400);

    if(!(image->load(filenames)))
    {
        QMessageBox::information(this,"失败","加载图片失败，请重新检查？");
        delete  image;
        return;
    }

    imagelabel->setPixmap(QPixmap::fromImage(*image));

}
