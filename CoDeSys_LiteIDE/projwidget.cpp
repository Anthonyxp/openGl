#include "projwidget.h"
#include "ui_projwidget.h"
#include <QtXml/QDomDocument>
#include <QTreeWidget>
#include <QFile>
#include <QDebug>
#include <QMenu>

ProjWidget::ProjWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjWidget)
{
    ui->setupUi(this);
}

ProjWidget::~ProjWidget()
{
    delete ui;
}

bool ProjWidget::parseProjXml(QString projPath)
{
    //打开或创建文件
    QFile file(projPath); //相对路径、绝对路径、资源路径都行
    if(!file.open(QFile::ReadOnly))
        return false;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return false;
    }
    file.close();

//    mTreeWidge = new QTreeWidget(this);
//    ui->mTreeWidge->setFixedSize(width,height);
    ui->mTreeWidge->setHeaderLabel("soluation");
    connect(ui->mTreeWidge,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this
            ,SLOT(treeItemDClicked(QTreeWidgetItem*,int)));//检测点击事件，信号槽机制
    connect(ui->mTreeWidge,SIGNAL(itemPressed(QTreeWidgetItem*,int))
            , this,SLOT(itemPressedSlot(QTreeWidgetItem*,int)));//检测鼠标右键

    QDomElement root=doc.documentElement(); //返回根节点
    qDebug()<<root.nodeName();

    QTreeWidgetItem *mRoot = new QTreeWidgetItem(ui->mTreeWidge);
    mRoot->setText(0,root.nodeName());
    mRoot->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);


    QDomNode node=root.firstChild(); //获得第一个子节点
    while(!node.isNull())  //如果节点不空
    {
        if(node.isElement()) //如果节点是元素
        {
            QDomElement e=node.toElement(); //转换为元素，注意元素和节点是两个数据结构，其实差不多
            qDebug()<<e.tagName(); //打印键值对，tagName和nodeName是一个东西

            QTreeWidgetItem *mChild1 = new QTreeWidgetItem(mRoot);
            mChild1->setText(0,e.tagName());
            mChild1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt:: ItemIsSelectable);

            QDomNodeList list=e.childNodes();
            for(int i=0;i<list.count();i++) //遍历子元素，count和size都可以用,可用于标签数计数
            {
                QDomNode n=list.at(i);
                if(node.isElement())
                {
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    if(n.nodeName() == e.tagName().at(0))
                    {

                        QTreeWidgetItem *mChild2 = new QTreeWidgetItem(mChild1);
                        mChild2->setText(0,n.toElement().attribute("name"));
                        mChild2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt:: ItemIsSelectable);


                    }

                }

            }
        }
        node=node.nextSibling(); //下一个兄弟节点,nextSiblingElement()是下一个兄弟元素，都差不多
    }

    ui->mTreeWidge->show();

    return true;
}

void ProjWidget::treeItemDClicked(QTreeWidgetItem* item,int column)
{
    if (item->childCount() == 0)
    {
        //打开文件
        emit openFile(item->text(column));
    }

}

void ProjWidget::itemPressedSlot(QTreeWidgetItem * pressedItem, int column)
{
    if(qApp->mouseButtons() == Qt::RightButton)   //判断是否为右键
    {
        QMenu *menu = new QMenu(ui->mTreeWidge);
        if (pressedItem->childCount() == 0)   //在我的QTreeWidget对象中，有三个QTreeWidgetItem对象，其中有一个内容为“Ａ”
        {
            QAction deleteWell(QString::fromLocal8Bit("&删除"),this);//删除
            QAction reNameWell(QString ::fromLocal8Bit("&重命"),this);//重命名
            //在界面上删除该item
            connect(&deleteWell, SIGNAL(triggered()), this, SLOT(deleteItem()));
            connect(&reNameWell,SIGNAL(triggered()),this,SLOT(renameItem()));

            menu->addAction(&deleteWell);
            menu->addAction(&reNameWell);
            menu->exec(QCursor::pos());  //在当前鼠标位置显示
        }
    }
}

void ProjWidget::deleteItem()
{


}

