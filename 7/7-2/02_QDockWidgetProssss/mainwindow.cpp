#include "mainwindow.h"


#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    DockWidgetFunc();

}

MainWindow::~MainWindow()
{
}


void MainWindow::DockWidgetFunc()
{
    setWindowTitle("QDockWidget类停靠窗口测试.");

    QTextEdit *tedit=new QTextEdit(this); // 定义QTextEdit对象作为主窗口
    tedit->setText("国防科技大学，中南大学，湖南大学，湖南师范大学");
    tedit->setAlignment(Qt::AlignCenter);
    setCentralWidget(tedit); //将编辑框控件设置为主窗口的中央窗体

    // 创建停靠窗口1
    QDockWidget *dw1=new QDockWidget("停靠窗口（一）",this);
    dw1->setFeatures(QDockWidget::DockWidgetMovable); // 可移动特性
    dw1->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);

    QTextEdit *qtedit1=new QTextEdit();
    qtedit1->setText("浙江大学（Zhejiang University），简称“浙大”，位于浙江省杭州市，是中华人民共和国教育部直属的综合性全国重点大学，位列国家“双一流”、 [106]  “211工程”、“985工程”，是九校联盟（C9） [113]  、中国大学校长联谊会、环太平洋大学联盟、世界大学联盟、全球大学校长论坛、全球高校人工智能学术联盟、国际应用科技开发协作网、新工科教育国际联盟、全球能源互联网大学联盟、CDIO工程教育联盟、医学“双一流”建设联盟成员，入选“珠峰计划”、“强基计划”、“2011计划”、“111计划”、卓越工程师教育培养计划、卓越医生教育培养计划、卓越法律人才教育培养计划、卓越农林人才教育培养计划、全国首批深化创新创业教育改革示范高校、学位授权自主审核单位。曾培养出厉绥之、束星北、李政道等杰出校友。");
    dw1->setWidget(qtedit1);
    addDockWidget(Qt::RightDockWidgetArea,dw1);


    // 创建停靠窗口2
    QDockWidget *dw2=new QDockWidget("停靠窗口（二）",this);
    dw2->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable); // 关闭 浮动

    QTextEdit *qtedit2=new QTextEdit();
    qtedit2->setText("复旦大学，简称“复旦”，位于直辖市上海，是中华人民共和国教育部直属的全国重点大学，中央直管高校， [145]  由教育部与上海市重点共建， [148]  位列国家“双一流”、“985工程”、“211工程”建设高校， [150]  入选珠峰计划、强基计划、111计划、2011计划、卓越医生教育培养计划、卓越法律人才教育培养计划、国家建设高水平大学公派研究生项目、新工科研究与实践项目、中国政府奖学金来华留学生接收院校、深化创新创业教育改革示范高校、首批学位授权自主审核单位，是环太平洋大学联盟、九校联盟、全球大学高研院联盟、中国大学校长联谊会、东亚研究型大学协会、新工科教育国际联盟、医学“双一流”建设联盟、长三角研究型大学联盟、 长三角高校智库联盟、中俄综合性大学联盟成员，是一所综合性研究型大学。");
    dw2->setWidget(qtedit2);
    addDockWidget(Qt::RightDockWidgetArea,dw2);

}
