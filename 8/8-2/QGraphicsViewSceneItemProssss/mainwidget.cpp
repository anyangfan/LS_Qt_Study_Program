#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    //设置可执行程序目录为当前目录
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    
    setWindowTitle("GraphicsView图形视图架构--应用程序测试");
    iAngle=3;
    scalevalues=3;
    leanvalues=3;

    // 场景
    QGraphicsScene *sence=new QGraphicsScene;
    sence->setSceneRect(-200,-200,380,380);
    QPixmap *pixmap=new QPixmap("../../00_material_lib/1.jpg");

    // 图元
    pixitem=new PixItem(pixmap);
    sence->addItem(pixitem); // 将图元添加到场景
    pixitem->setPos(0,0);

    // 视图
    view=new QGraphicsView; // new视图
    view->setScene(sence);
    view->setMinimumSize(800,600);


    controlframe=new QFrame;
    CreateControlFrameFunc();


    // 主窗体布局设计
    QHBoxLayout *hlayout=new QHBoxLayout;
    hlayout->addWidget(view);
    hlayout->addWidget(controlframe);

    setLayout(hlayout); // 向布局中添加子布局

}

MainWidget::~MainWidget()
{
}

void MainWidget::rotateFunc(int val) // 旋转
{
    view->rotate(val-iAngle);
    iAngle=val;
}

void MainWidget::scaleFunc(int val)  // 缩放
{
    qreal qs;
    if(val>scalevalues)
        qs=pow(1.1,(val-scalevalues));
    else
        qs=pow(1/1.1,(scalevalues-val));
    view->scale(qs,qs);
    scalevalues=val;

}

void MainWidget::leanFunc(int val)   // 倾斜
{
    view->shear((val-leanvalues)/2.0,0);
    leanvalues=val;

}





void MainWidget::CreateControlFrameFunc() // 创建控件框架
{
    // 旋转
    QSlider *rotatesilder=new QSlider;
    rotatesilder->setOrientation(Qt::Horizontal);
    rotatesilder->setRange(0,360);

    QHBoxLayout *rotatelayout=new QHBoxLayout;
    rotatelayout->addWidget(rotatesilder);

    QGroupBox *rotategroup=new QGroupBox("图形旋转");
    rotategroup->setLayout(rotatelayout);


    // 缩放
    QSlider *scalesilder=new QSlider;
    scalesilder->setOrientation(Qt::Horizontal);
    scalesilder->setRange(0,2*scalevalues);
    scalesilder->setValue(scalevalues);

    QHBoxLayout *scalelayout=new QHBoxLayout;
    scalelayout->addWidget(scalesilder);

    QGroupBox *scalegroup=new QGroupBox("图形缩放");
    scalegroup->setLayout(scalelayout);

    // 倾斜
    QSlider *leansilder = new QSlider;
    leansilder->setOrientation(Qt::Horizontal);
    leansilder->setRange(0,2*leanvalues);
    leansilder->setValue(leanvalues);

    QHBoxLayout *leanlayout = new QHBoxLayout;
    leanlayout->addWidget(leansilder);

    QGroupBox *leangroup = new QGroupBox(tr("图形倾斜"));
    leangroup->setLayout(leanlayout);


    // 信号与槽函数连接
    connect(rotatesilder,SIGNAL(valueChanged(int)),this,SLOT(rotateFunc(int)));
    connect(scalesilder,SIGNAL(valueChanged(int)),this,SLOT(scaleFunc(int)));
    connect(leansilder,SIGNAL(valueChanged(int)),this,SLOT(leanFunc(int)));



    // 控制面板设计布局
    QVBoxLayout *vlayoutframe=new QVBoxLayout;
    vlayoutframe->addWidget(rotategroup);
    vlayoutframe->addWidget(scalegroup);
    vlayoutframe->addWidget(leangroup);

    controlframe->setLayout(vlayoutframe);

}
