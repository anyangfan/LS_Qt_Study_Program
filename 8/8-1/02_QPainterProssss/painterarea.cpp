#include "painterarea.h"

PainterArea::PainterArea(QWidget *parent) : QWidget(parent)
{
    setPalette(QPalette(Qt::red)); // 调色板来改变背景颜色

    setAutoFillBackground(true); // Qt窗口是否需要绘制背景

    // 设置最小尺寸
    setMinimumSize(410,410);

}

void PainterArea::setShape(shape sh)  // 此函数实现绘制形状
{
    shp=sh;
    update();

}

void PainterArea::setPen(QPen sh)
{
    pen=sh;
    update();
}

void PainterArea::setBrush(QBrush sh)
{
    brsh=sh;
    update();

}

void PainterArea::paintEvent(QPaintEvent *) // 重绘事件
{
    QPainter p(this);
    p.setPen(pen);
    p.setBrush(brsh);

    QRect rect(55,110,290,180);

    switch (shp) {
    case Line: // 直线
        p.drawLine(rect.topLeft(),rect.bottomRight());
        break;
    case Rectangle: // 矩形
        p.drawRect(rect);
        break;
    default:
        break;
    }
}

void PainterArea::setfillrule(Qt::FillRule rle) // 填充规则
{
    fillrle=rle;
    update(); // 重新绘制区域窗体

}
