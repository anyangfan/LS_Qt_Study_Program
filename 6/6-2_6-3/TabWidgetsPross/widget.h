#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QTabWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QTabWidget *tabWidgetUI;

private slots:
    void MsgCommit();
};
#endif // WIDGET_H
