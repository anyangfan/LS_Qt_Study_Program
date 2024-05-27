#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>
#include <QDebug>


#include <QDir>
#include <QTextStream>
#include <QCoreApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    // 设置主空格的显示位置及大小
    this->setGeometry(300,200,1000,600);

    // 1:
    combobox=new QComboBox(this); // 实例化对象
    combobox->setGeometry(10,10,200,30);
    combobox->addItem("北京市");
    combobox->addItem("上海市");
    combobox->addItem("天津市");
    combobox->addItem("重庆市");
    combobox->addItem("湖南省");
    combobox->addItem("江西省");
    combobox->addItem("广东省");
    combobox->addItem("香港特别行政区");
    combobox->addItem("澳门特别行政区");

    // 信号槽函数连接实现
    connect(combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(comboboxIndex(int)));

    // 2:
    fontcombobox=new QFontComboBox(this);
    qlabels=new QLabel(this);
    fontcombobox->setGeometry(10,50,200,30);
    qlabels->setGeometry(10,70,300,50);

    // 信号与槽函数连接
    connect(fontcombobox,SIGNAL(currentFontChanged(QFont)),this,SLOT(fontcomboboxFunc(QFont)));

    // 3:
    lineedit=new QLineEdit(this);
    lineedit->setGeometry(10,150,200,30);
    pushbutton=new QPushButton(this);
    pushbutton->setGeometry(220,150,100,30);
    pushbutton->setText("点击我");
    qlabely=new QLabel(this);
    qlabely->setGeometry(10,200,400,30);
    qlabely->setText("你输入的内容为：");

    // 信号与槽函数连接
    connect(pushbutton,SIGNAL(clicked()),this,SLOT(pushbuttonclicked()));

    // 4:
    plaintedit=new QPlainTextEdit(this);
    plaintedit->setGeometry(10,250,400,200);
    radiobutton=new QRadioButton(this);
    radiobutton->setGeometry(300,220,200,30);
    radiobutton->setText("只读模式");

    // 设置工作目录为可执行程序的工作目录
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    /*
    该函数的作用是将当前工作目录设置为Qt应用程序的目录。
    具体来说，它使用QCoreApplication::applicationDirPath()获取应用程序所在目录的路径，
    并将其作为参数传递给QDir::setCurrent()函数，以设置当前工作目录。
    这样做的好处是确保应用程序在执行过程中访问到的文件路径都是相对于应用程序目录的，
    避免了因为工作目录设置不当导致的文件找不到等问题。
    */
    QFile fe("moc_mainwindow.cpp");
    fe.open((QFile::ReadOnly|QFile::Text));

    // 加载到文件流
    QTextStream strin(&fe);
    plaintedit->insertPlainText(strin.readAll());

    // 信号与槽函数连接
    connect(radiobutton,SIGNAL(clicked()),this,SLOT(radioButtonClicked()));


    // 5: 改变窗口背景颜色
    this->setStyleSheet("QMainWindow{background-color:rgba(250,220,120,100%)}");

    spinbox=new QSpinBox(this);
    spinbox->setGeometry(440,250,150,30);

    spinbox->setRange(0,100);
    spinbox->setSingleStep(10);
    spinbox->setValue(100);

    spinbox->setSuffix("%不透明度");

    // 信号与槽函数连接
    connect(spinbox,SIGNAL(valueChanged(int)),this,SLOT(spinboxValueChanged(int)));


    // 6:*dte/te/de
    dte=new QDateTimeEdit(QDateTime::currentDateTime(),this);
    dte->setGeometry(440,290,200,30);
    te=new QTimeEdit(QTime::currentTime(),this);
    te->setGeometry(440,330,200,30);
    de=new QDateEdit(QDate::currentDate(),this);
    de->setGeometry(440,370,200,30);


    // 7:
    hscrollbar=new QScrollBar(Qt::Horizontal,this);
    hscrollbar->setGeometry(0,500,1000,30);
    vscrollbar=new QScrollBar(Qt::Vertical,this);
    vscrollbar->setGeometry(970,0,30,500);

    // 8：
    kse=new QKeySequenceEdit(this);
    kse->setGeometry(400,530,200,30);
    // 信号与槽函数连接
    connect(kse,SIGNAL(keySequenceChanged(const QKeySequence &)),
             this,SLOT(keyseqeditChanged(const QKeySequence &)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


// 1:
void MainWindow::comboboxIndex(int index)
{
    qDebug()<<"你选择的区别是："<<combobox->itemText(index)<<endl;

    QMessageBox mybox(QMessageBox::Question,"信息",combobox->itemText(index),QMessageBox::Yes|QMessageBox::No);
    mybox.exec();
}

// 2:
void MainWindow::fontcomboboxFunc(QFont font)
{
    qlabels->setFont(font);
    QString qStr="零声教育 QT开发工程师";
    qlabels->setText(qStr);

}

// 3:
void MainWindow::pushbuttonclicked()
{
    QString qStr;
    qStr="你输入的内容为：";
    qStr=qStr+lineedit->text();

    qlabely->setText(qStr);
    lineedit->clear();
}

// 4:
void MainWindow::radioButtonClicked()
{
    if(radiobutton->isChecked()){
        plaintedit->setReadOnly(true);
    }
    else
        plaintedit->setReadOnly(false);
}

// 5:
void MainWindow::spinboxValueChanged(int x)
{
    double dx=(double)x/100;

    this->setWindowOpacity(dx);
}

// 8：
void MainWindow::keyseqeditChanged(const QKeySequence &key)
{
    if(key==QKeySequence(tr("Ctrl+Q")))
        this->close();
    else
        qDebug()<<key.toString()<<endl;

}
