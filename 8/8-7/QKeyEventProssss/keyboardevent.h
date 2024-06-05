#ifndef KEYBOARDEVENT_H
#define KEYBOARDEVENT_H

#include <QWidget>


#include <QKeyEvent>
#include <QPaintEvent>
#include <QPainter>

class keyboardevent : public QWidget
{
    Q_OBJECT

public:
    keyboardevent(QWidget *parent = nullptr);
    ~keyboardevent();


    void drawpixfunc();
    void paintEvent(QPaintEvent *);

    void keyPressEvent(QKeyEvent *); // 键盘按钮控制老虎动向

private:
    QPixmap *pix;
    QImage image;
    int startx;
    int starty;
    int width; // 获取窗口宽度
    int height; // 获取窗口高度
    int step; // 步长

};
#endif // KEYBOARDEVENT_H
