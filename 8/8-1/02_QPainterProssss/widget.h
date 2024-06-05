#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "painterarea.h"
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>

#include <QColorDialog>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private:
    PainterArea *labelshapeArea;

    QLabel *labelshape;
    QComboBox *comboboxshape;

    QGridLayout *glayout;

private slots:
    void dispShapeFunc(int);




};
#endif // WIDGET_H
