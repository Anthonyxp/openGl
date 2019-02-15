#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>
#include <QTreeWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //File Menu
    new_file = new QAction("新建工程",this);
    new_file->setShortcut(tr("ctrl+n"));
    ui->menu_F->addAction(new_file);

    //中心停靠窗
    center = new QDockWidget();    //中心停靠窗
    //setCentralWidget(center);      //中心窗口部件，QMainWindow::centerwidget
    tab = new QTabWidget();
    tab->addTab(new QTextEdit("tab1"),"Tab1");
    tab->addTab(new QTextEdit("tab2"),"Tab2");
    tab->addTab(new QTextEdit("tab3"),"Tab3");
    tab->addTab(new QTextEdit("tab4"),"Tab4");
    setCentralWidget(tab);      //中心窗口部件，QMainWindow::centerwidget

    //左停靠窗
    QDockWidget *mLeftDock = new QDockWidget("Project",this);
    mLeftDock->setFeatures(QDockWidget::AllDockWidgetFeatures);

    //树，用于显示文件和文件管理
    QTreeWidget *mTreeWidge = new QTreeWidget(this);
    for(int j = 0; j<3; j++)
    {
        QString mRootName = "root" + QString::number(j+1);
        QTreeWidgetItem *mRoot = new QTreeWidgetItem(mTreeWidge);
        mRoot->setText(0,mRootName);

        mRoot->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);

        QString mItemName;

        for(int i = 0; i < 3; i++)
        {
            mItemName = "child" + QString::number(i+1);
            QTreeWidgetItem *mChild1 = new QTreeWidgetItem(mRoot);
            mChild1->setText(0,mItemName);

            mChild1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt:: ItemIsSelectable);

        }

    }

    mLeftDock->setWidget(mTreeWidge);    //将树控件添加到左停靠窗中
    addDockWidget(Qt::LeftDockWidgetArea,mLeftDock);

    //右停靠窗
    QDockWidget *mRightDock = new QDockWidget("配置窗口",this);
    mRightDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QTextEdit *dock2Text = new QTextEdit("右侧");
    mRightDock->setWidget(dock2Text);
    addDockWidget(Qt::RightDockWidgetArea,mRightDock);

    //底部停靠窗
    QDockWidget *mBottomDock = new QDockWidget("底部",this);
    mBottomDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QTextEdit *dock3Text = new QTextEdit("底部");
    mBottomDock->setWidget(dock3Text);
    addDockWidget(Qt::BottomDockWidgetArea,mBottomDock);

     btn = new QPushButton("Open");
     ui->mainToolBar->addWidget(btn);
}

MainWindow::~MainWindow()
{
    delete ui;
}
