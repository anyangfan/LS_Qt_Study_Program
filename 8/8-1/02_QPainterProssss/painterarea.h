#ifndef PAINTERAREA_H
#define PAINTERAREA_H

#include <QWidget>

// QPen 钢笔（画笔）是基本的图形对象，绘制直线、曲线、多边形等形状
#include <QPen>

// QBrush 画刷是基本的图形对象，主要用于填充，比如矩形、多边形等形状
#include <QBrush>

#include <QPainter>

class PainterArea : public QWidget
{
    Q_OBJECT
public:
    explicit PainterArea(QWidget *parent = nullptr);

    // 绘制直线、长方形（矩形）
    enum shape{Line,Rectangle};

    void setShape(shape);  // 此函数实现绘制形状
    void setPen(QPen);
    void setBrush(QBrush);
    /* 
    函数 void setShape(shape);, void setPen(QPen);, void setBrush(QBrush); 的作用：
    void setShape(shape);: 这个函数是 PainterArea 类的一个公有成员函数，用于设置绘图区域的形状。
    void setPen(QPen);: 这个函数是 PainterArea 类的一个公有成员函数，用于设置绘图区域绘制形状时所使用的画笔（QPen）。
    void setBrush(QBrush);: 这个函数是 PainterArea 类的一个公有成员函数，用于设置绘图区域绘制形状时所使用的画刷（QBrush）。
    这三个函数的作用都是改变 PainterArea 类对象的属性，从而影响绘图区域的绘制结果。通过调用这些函数，可以动态地改变绘图区域的形状、画笔和画刷，使得绘图区域能够以不同的方式呈现出用户所期望的图形。
    */

    void paintEvent(QPaintEvent *); // 重绘事件
    void setfillrule(Qt::FillRule); // 填充规则

signals:

public slots:
private:
    shape shp;
    QPen pen;
    QBrush brsh;
    Qt::FillRule fillrle;

};

#endif // PAINTERAREA_H
