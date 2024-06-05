#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>

#include <QtGui>
#include <QMouseEvent> // 鼠标事件
#include <QPaintEvent> // 绘制事件
#include <QResizeEvent> // 实时获取窗口操作等大小
#include <QColor>
#include <QPixmap> // 显示图像
#include <QPainter>
#include <QPalette>
#include <QPen>


class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:

public slots:
    void setStyle(int); // 设置线风格
    void setWidth(int); // 设置线宽度
    void setColor(QColor); // 设置线颜色
    void clearFunc(); // 清除函数

private:
    QPixmap *pix; // 在屏幕上显示图像而设计和优化
    QPoint startpos;
    QPoint endPos;
    int style,widthss;
    QColor color;



};

#endif // DRAWWIDGET_H
