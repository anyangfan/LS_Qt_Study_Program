#include "drawwidget.h"

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix=new QPixmap(size());
    pix->fill(Qt::white);

    // 设置绘制区窗口最小尺寸
    setMinimumSize(600,400);

}

void DrawWidget::setStyle(int s) // 设置线风格
{
    style=s;

}

void DrawWidget::setWidth(int w) // 设置线宽度
{
    widthss=w;

}

void DrawWidget::setColor(QColor c) // 设置线颜色
{
    color=c;

}

void DrawWidget::clearFunc() // 清除函数
{
    QPixmap *cPix=new QPixmap(size());
    cPix->fill(Qt::white);
    pix=cPix;
    update();
}

void DrawWidget::mousePressEvent(QMouseEvent *e)
{
    startpos=e->pos();

}

void DrawWidget::mouseMoveEvent(QMouseEvent *e)
{
    QPainter *painter=new QPainter;
    QPen pen;
    pen.setStyle((Qt::PenStyle)style);
    pen.setWidth(widthss);
    pen.setColor(color);

    painter->begin(pix);
    painter->setPen(pen);
    painter->drawLine(startpos,e->pos());
    painter->end();

    startpos=e->pos();
    update();

}

void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(QPoint(0,0),*pix);

}

void DrawWidget::resizeEvent(QResizeEvent *event)
{
    if(height()>pix->height() || width()>pix->width())
    {
        QPixmap *newPix=new QPixmap(size());
        newPix->fill(Qt::white);

        QPainter ps(newPix);

        ps.drawPixmap(QPoint(0,0),*pix);
        pix=newPix;
    }

    QWidget::resizeEvent(event);

}



