#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("图形绘制综合案例分析（双缓冲机制）");
    drawWidget=new DrawWidget;
    setCentralWidget(drawWidget); // 将刚才创建对象作为主窗口的中心窗口

    CreateToolBarFunc(); // 调用此函数实现创建工具栏

    setMinimumSize(600,400);

    dispstyle();

    drawWidget->setWidth(spinboxlabelwidth->value()); // 初始化线宽度
    drawWidget->setColor(Qt::black); // 初始化线颜色


}

MainWindow::~MainWindow()
{
}



void MainWindow::CreateToolBarFunc() // 创建工具条
{
    QToolBar *toolBar=addToolBar("Tool");
    labelstyle=new QLabel("线型风格：");
    comboboxlabelstyle=new QComboBox;
    comboboxlabelstyle->addItem("SolidLine",static_cast<int>(Qt::SolidLine)); // 实线
    comboboxlabelstyle->addItem("DashLine",static_cast<int>(Qt::DashLine)); //
    comboboxlabelstyle->addItem("DashDotDotLine",static_cast<int>(Qt::DashDotDotLine));
    comboboxlabelstyle->addItem("DotLine",static_cast<int>(Qt::DotLine)); // 虚线

    // 为什么不出现虚线？activeated改为activated
    connect(comboboxlabelstyle,SIGNAL(activated(int)),this,SLOT(dispstyle()));

    labelwidth=new QLabel("线型宽度：");
    spinboxlabelwidth=new QSpinBox;
    connect(spinboxlabelwidth,SIGNAL(valueChanged(int)),drawWidget,SLOT(setWidth(int)));

    colorbutton=new QToolButton;
    QPixmap pixmap(20,20);
    pixmap.fill(Qt::black);
    colorbutton->setIcon(QIcon(pixmap));
    connect(colorbutton,SIGNAL(clicked()),this,SLOT(dispcolor()));

    clearbutton=new QToolButton;
    clearbutton->setText("清除绘制");
    connect(clearbutton,SIGNAL(clicked()),drawWidget,SLOT(clearFunc()));

    toolBar->addWidget(labelstyle);
    toolBar->addWidget(comboboxlabelstyle);
    toolBar->addWidget(labelwidth);
    toolBar->addWidget(spinboxlabelwidth);
    toolBar->addWidget(colorbutton);
    toolBar->addWidget(clearbutton);
}


void MainWindow::dispstyle()
{
    drawWidget->setStyle(comboboxlabelstyle->itemData(comboboxlabelstyle->currentIndex(),
                                                      Qt::UserRole).toInt());



}


void MainWindow::dispcolor()
{
    QColor color=QColorDialog::getColor(static_cast<int>(Qt::black),this);
    if(color.isValid())
    {
        drawWidget->setColor(color);
        QPixmap ps(20,20);
        ps.fill(color);
    }


}
