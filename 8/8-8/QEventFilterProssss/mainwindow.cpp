#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Qt事件过滤器--测试程序");

    // 展示图片
    label1jpg=new QLabel;
    image1jpg.load("d:/a.jpg");
    label1jpg->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    label1jpg->setPixmap(QPixmap::fromImage(image1jpg));

    label2jpg=new QLabel;
    image2jpg.load("d:/b.jpg");
    label2jpg->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    label2jpg->setPixmap(QPixmap::fromImage(image2jpg));

    label3jpg=new QLabel;
    image3jpg.load("d:/c.jpg");
    label3jpg->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    label3jpg->setPixmap(QPixmap::fromImage(image3jpg));


    // UI布局
    labeldispinfo=new QLabel("鼠标按键提示信息!");
    labeldispinfo->setAlignment(Qt::AlignHCenter); //AlignCenter窗口中心对齐

    QHBoxLayout *hlayout=new QHBoxLayout;
    hlayout->addWidget(label1jpg);
    hlayout->addWidget(label2jpg);
    hlayout->addWidget(label3jpg);

    QWidget *wgt=new QWidget(this);
    QVBoxLayout *vlayout=new QVBoxLayout(wgt);
    vlayout->addLayout(hlayout);
    vlayout->addWidget(labeldispinfo);

    setCentralWidget(wgt); // 中心窗口部件

    // 安装事件过滤
    label1jpg->installEventFilter(this);
    label2jpg->installEventFilter(this);
    label3jpg->installEventFilter(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


 bool MainWindow::eventFilter(QObject *watched,QEvent *event) // 事件过滤
 {
     if(watched==label1jpg)
     {
         if(event->type()==QEvent::MouseButtonPress)// 鼠标按键，发生在窗户区域
         {
             QMouseEvent *mevent=(QMouseEvent*)event;
             if(mevent->buttons() & Qt::LeftButton)
             {
                 labeldispinfo->setText("鼠标左键被按下：[左边图片]");
             }
             else if(mevent->buttons() & Qt::MidButton)
             {
                 labeldispinfo->setText("鼠标中键被按下：[左边图片]");
             }
             else if(mevent->buttons() & Qt::RightButton)
             {
                 labeldispinfo->setText("鼠标右键被按下：[左边图片]");
             }

             QMatrix matrix;
             matrix.scale(2,2);
             QImage tempimage=image1jpg.transformed(matrix);
             label1jpg->setPixmap(QPixmap::fromImage(tempimage));
         }

         if(event->type()==QEvent::MouseButtonRelease) // 鼠标释放
         {
             labeldispinfo->setText("鼠标按键已经释放：[左边图片]");
             label1jpg->setPixmap(QPixmap::fromImage(image1jpg));
         }
     }
     else if(watched==label2jpg)
     {
         if(event->type()==QEvent::MouseButtonPress)// 鼠标按键，发生在窗户区域
         {
             QMouseEvent *mevent=(QMouseEvent*)event;
             if(mevent->buttons() & Qt::LeftButton)
             {
                 labeldispinfo->setText("鼠标左键被按下：[中间图片]");
             }
             else if(mevent->buttons() & Qt::MidButton)
             {
                 labeldispinfo->setText("鼠标中键被按下：[中间图片]");
             }
             else if(mevent->buttons() & Qt::RightButton)
             {
                 labeldispinfo->setText("鼠标右键被按下：[中间图片]");
             }

             QMatrix matrix;
             matrix.scale(2.5,2.5);
             QImage tempimage=image2jpg.transformed(matrix);
             label2jpg->setPixmap(QPixmap::fromImage(tempimage));
         }

         if(event->type()==QEvent::MouseButtonRelease) // 鼠标释放
         {
             labeldispinfo->setText("鼠标按键已经释放：[中间图片]");
             label2jpg->setPixmap(QPixmap::fromImage(image2jpg));
         }
     }
     else if(watched==label3jpg)
     {
         if(event->type()==QEvent::MouseButtonPress)// 鼠标按键，发生在窗户区域
         {
             QMouseEvent *mevent=(QMouseEvent*)event;
             if(mevent->buttons() & Qt::LeftButton)
             {
                 labeldispinfo->setText("鼠标左键被按下：[右边图片]");
             }
             else if(mevent->buttons() & Qt::MidButton)
             {
                 labeldispinfo->setText("鼠标中键被按下：[右边图片]");
             }
             else if(mevent->buttons() & Qt::RightButton)
             {
                 labeldispinfo->setText("鼠标右键被按下：[右边图片]");
             }

             QMatrix matrix;
             matrix.scale(3,3);
             QImage tempimage=image3jpg.transformed(matrix);
             label3jpg->setPixmap(QPixmap::fromImage(tempimage));
         }

         if(event->type()==QEvent::MouseButtonRelease) // 鼠标释放
         {
             labeldispinfo->setText("鼠标按键已经释放：[右边图片]");
             label3jpg->setPixmap(QPixmap::fromImage(image3jpg));
         }
     }


     return QMainWindow::eventFilter(watched,event);
 }
