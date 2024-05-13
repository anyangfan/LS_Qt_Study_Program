#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QListView>
#include <QStringListModel> // 字符串列表模型
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

private:
    QListView *listview1;
private slots:
    void SlotClickedFunc(const QModelIndex &index);

};
#endif // WIDGET_H
