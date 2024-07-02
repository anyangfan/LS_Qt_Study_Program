#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>


#include <QGraphicsView> // 视图
#include <QGraphicsScene> // 场景
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSlider>

#include "pixitem.h"
#include <math.h>
#include <QDir>
#include <QCoreApplication>




class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public:
    void CreateControlFrameFunc(); // 创建控件框架

private:
    int iAngle; // 角度
    qreal scalevalues; // 缩放
    qreal leanvalues; // 倾斜

    QGraphicsView *view; // 视图对象
    QFrame *controlframe; // 控制边框样式
    PixItem *pixitem;


private slots:
    void rotateFunc(int); // 旋转
    void scaleFunc(int);  // 缩放
    void leanFunc(int);   // 倾斜

};
#endif // MAINWIDGET_H
