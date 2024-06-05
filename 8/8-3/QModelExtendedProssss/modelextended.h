#ifndef MODELEXTENDED_H
#define MODELEXTENDED_H

#include <QAbstractTableModel>
#include <QVector>
#include <QMap>
#include <QStringList>



class ModelExtended : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModelExtended(QObject *parent = 0);


public:
    // 系统自的model相关的函数进行重新定义
    virtual int rowCount(const QModelIndex &parent=QModelIndex()) const; // 行
    virtual int columnCount(const QModelIndex &parent=QModelIndex()) const; // 列
    QVariant data(const QModelIndex &index,int role) const; // 显示数据
    QVariant headerData(int section,Qt::Orientation orientateion,int role) const; // 设置表头数据

public slots:
private:
    // QVector向量容器（QVector是QT对所有数组的封装
    QVector<short> empindex;
    QVector<short> empnameindex;

    // QMap是Qt通用容器，它存储（键，值），并提供与键相关联的值的快速查找
    QMap<short,QString> empno;
    QMap<short,QString> empname;

    // QStringList类提供一个字符串列表，
    // QStringList添加QString字符串，直接用<<来添加字符串
    QStringList viewlisttitle; // 表视图标题名称
    QStringList empdepartment; // 存放员工所在部门

    void ModelFunc();



};

#endif // MODELEXTENDED_H
