#include "keyboardevent.h"

keyboardevent::keyboardevent(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("键盘事件测试：控制老虎动向");

    setAutoFillBackground(true);

    // QPalette是Qt中调度板类
    QPalette plet=this->palette();
    plet.setColor(QPalette::Window,Qt::white);
    setPalette(plet);

    setMinimumSize(800,600);
    setMaximumSize(800,600);

    width=size().width();
    height=size().height();

    pix=new QPixmap(width,height);
    pix->fill(Qt::white);

    image.load(":/images/images/a.jpg");

    startx=30;
    starty=30;
    step=30;


    drawpixfunc(); // 调用函数绘制


    resize(800,600);

}

keyboardevent::~keyboardevent()
{
}


void keyboardevent::drawpixfunc()
{
    pix->fill(Qt::green);

    QPainter *painter=new QPainter;
    QPen pen(Qt::DashDotLine); // 点划线

    for(int i=step;i<width;i=i+step) // 竖线
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(i,0),QPoint(i,height));
        painter->end();
    }

    for(int j=step;j<height;j=j+step) // 横线
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(0,j),QPoint(width,j));
        painter->end();
    }


    painter->begin(pix);
    painter->drawImage(QPoint(startx,starty),image);
    painter->end();

}

void keyboardevent::paintEvent(QPaintEvent *)
{
    QPainter pt;
    pt.begin(this);
    pt.drawPixmap(QPoint(0,0),*pix);
    pt.end();
}

void keyboardevent::keyPressEvent(QKeyEvent *evt) // 键盘按钮控制老虎动向
{
    startx=startx-startx%step;
    starty=starty-starty%step;

    if(evt->key()==Qt::Key_Left)
    {
        startx=(startx-step<0)?startx:startx-step;
    }
    if(evt->key()==Qt::Key_Right)
    {
        startx=(startx+step+image.width()>width)?startx:startx+step;
    }

    if(evt->key()==Qt::Key_Up)
    {
        starty=(starty-step<0)?starty:starty-step;
    }
    if(evt->key()==Qt::Key_Down)
    {
        starty=(starty+step+image.height()>height)?starty:starty+step;
    }



    // 调用绘制
    drawpixfunc();
    update();
}
