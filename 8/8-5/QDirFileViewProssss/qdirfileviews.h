#ifndef QDIRFILEVIEWS_H
#define QDIRFILEVIEWS_H

#include <QDialog>

#include <QListWidget>  // 列表框
#include <QListWidgetItem>
#include <QLineEdit> // 单行输入框/单行编辑框

#include <QDir> // 获取操作路径及底层文件系统
#include <QFileInfoList> // 获取指定目录的基本数据信息

#include <QVBoxLayout> // 垂直布局

#include <QStringList>



class QDirFileViews : public QDialog
{
    Q_OBJECT

public:
    QDirFileViews(QWidget *parent = nullptr);
    ~QDirFileViews();


private:
    QLineEdit *filelineedit; // 显示所选择目录名称
    QListWidget *filelistwidget; // 列表框：展示目录和文件
    QVBoxLayout *glayout; // 垂直布局

public:
    void dispfileinfolist(QFileInfoList list); // 显示目录和文件所对应图标

public slots:
    void dispdir(QDir dir);
    void dispdirshow(QListWidgetItem *item);



};
#endif // QDIRFILEVIEWS_H
