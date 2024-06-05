#ifndef PIXITEM_H
#define PIXITEM_H

#include <QGraphicsItem> // 图元类
#include <QPixmap>
#include <QPainter>

class PixItem : public QGraphicsItem
{
public:
    PixItem(QPixmap *pixmap);

private:
    QPixmap pix;

public:
    // 此函数只刷新固定区域，重新实现：返回调整成实际物体所在位置的包含区域
    QRectF boundingRect() const;

    // 绘制操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // PIXITEM_H
