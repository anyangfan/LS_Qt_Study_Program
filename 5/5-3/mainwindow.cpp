#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    labFirst=new QLabel("LingShengEDU--Vico老师",this);
    labFirst->setGeometry(50,50,330,100);
    labFirst->setStyleSheet("QLabel{background-color:green;color:red}");
    labFirst->setFont(QFont("隶书",22));

}

MainWindow::~MainWindow()
{

}

