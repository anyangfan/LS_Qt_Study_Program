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
/*
当鼠标在部件上移动时，将调用此函数。它创建了一个名为 painter 的新 QPainter 对象，
用于绘制。然后，使用类变量 style、widthss 和 color 指定的样式、宽度和颜色设置了一个 QPen。

它开始在 pix QPixmap 对象上绘制（绘图区域）使用绘制器。
它从 startpos（上一次记录的鼠标位置）画一条线到当前鼠标位置（e->pos()），
然后结束绘制。在更新 startpos 后，调用 update() 触发重新绘制事件并更新部件的外观。 
*/

void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(QPoint(0,0),*pix);
    /* 
    painter.drawPixmap(QPoint(0,0), *pix);是在DrawWidget类的paintEvent()函数中找到的一行代码。让我们来解析一下这行代码：
    painter：这是一个QPainter对象，负责在小部件的绘画区域执行绘图操作。
    drawPixmap：这是QPainter类的一个方法，用于将一个像素图（即图像）绘制到绘画区域上。
    QPoint(0,0)：这指定了像素图将被绘制到的目标矩形的左上角。在这种情况下，它将像素图绘制在小部件绘画区域的左上角坐标(0,0)处。
    *pix：这是一个指向名为pix的QPixmap对象的指针。*pix对指针进行解引用以访问实际的QPixmap对象。
    因此，总体而言，painter.drawPixmap(QPoint(0,0), *pix);将pix QPixmap对象的内容绘制到小部件的绘画区域上，从小部件的左上角(0,0)开始。这个操作有效地在绘制事件期间将绘图的当前状态（线条、形状等）显示在小部件表面上。
    */
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



