#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
#include <QComboBox>
#include <QToolButton>
#include <QSpinBox>

#include "drawwidget.h"

#include <QGridLayout>
#include <QColorDialog>
#include <QToolBar>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void CreateToolBarFunc(); // 创建工具条

private:
    DrawWidget *drawWidget;

    QGridLayout *glayout;

    QLabel *labelstyle;
    QComboBox *comboboxlabelstyle;

    QLabel *labelwidth;
    QSpinBox *spinboxlabelwidth;

    QToolButton *colorbutton;
    QToolButton *clearbutton;


private slots:
    void dispstyle();
    void dispcolor();






};
#endif // MAINWINDOW_H
