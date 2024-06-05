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
