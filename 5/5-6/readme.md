# QMap_QHash_QVector

详细内容参考:material_lib\6.QMap类 & QHash类 & QVector类.pdf

## QMap

- 1:创建QMap实例，第一个参数为QString类型的键，第二个参数为int类型的值
- 2:Delete data informaton key
- 3:Traversal英/trəˈvərs(ə)l/ QMap
- 3.1 iterator `QMapIterator<QString, int> itr(qmap);`
- 3.2 STL template `QMap<QString, int>::const_iterator stritr = qmap.constBegin();`
- 4.find
- 5.1 modify - calling the insert() function to overwrite the value of the key
- 5.2 modify - using the [] operator to modify the value of the key
- 6 search
- 7 output : key-value
- 8 QMultiMap `QMultiMap<QString, QString> multimap;`

## QHash

- 1 QHash 类
- 2 QHash 内部的迭代器 QHashIterator 类 `QHash<QString, int>::const_iterator iterator;`

## QVector

- 1 QVector 类
- 2 赋值方式 `<<`,`append()`
- 3 元素个数 `count()`
- 4 遍历
- 5 删除
- 6 判断容器是否包含某个元素
