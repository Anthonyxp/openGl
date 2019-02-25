#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>
#include <QTreeWidget>
#include <QTextEdit>
#include <projwidget.h>
#include <QLabel>
#include "centerwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //File Menu
    new_file = new QAction(tr("新建工程"),this);
    new_file->setShortcut(tr("ctrl+n"));
    ui->menu_F->addAction(new_file);

    open_file = new QAction(tr("打开"),this);
    open_file->setShortcut(tr("ctrl+o"));
    ui->menu_F->addAction(open_file);

    exit_file = new QAction(tr("退出"),this);
    ui->menu_F->addAction(exit_file);

    save_file = new QAction(tr("保存"),this);
    save_file->setShortcut(tr("ctrl+s"));
    ui->menu_F->addAction(save_file);

    //Edit Menu
    copy_edit = new QAction(tr("复制"),this);
    copy_edit->setShortcut(tr("ctrl+c"));
    ui->menu_E->addAction(copy_edit);

    paste_edit = new QAction(tr("粘贴"),this);
    paste_edit->setShortcut(tr("ctrl+V"));
    ui->menu_E->addAction(paste_edit);

    cut_edit = new QAction(tr("剪贴"),this);
    cut_edit->setShortcut(tr("ctrl+X"));
    ui->menu_E->addAction(cut_edit);

    allSelect_edit = new QAction(tr("全选"),this);
    allSelect_edit->setShortcut(tr("ctrl+A"));
    ui->menu_E->addAction(allSelect_edit);

    //Build Menu
    build_build = new QAction(tr("构建"),this);
    build_build->setShortcut(tr("F7"));
    ui->menu_B->addAction(build_build);

    rebuild_build = new QAction(tr("重新构建"),this);
    rebuild_build->setShortcut(tr("F11"));
    ui->menu_B->addAction(rebuild_build);

    //Online Menu
    logIn_online = new QAction(tr("在线"),this);
    logIn_online->setShortcut(tr("ctrl +I"));
    ui->menu_O->addAction(logIn_online);

    logOut_online = new QAction(tr("离线"),this);
    logOut_online->setShortcut(tr("ctrl +O"));
    ui->menu_O->addAction(logOut_online);

    //Debug Menu
    debug_debug = new QAction(tr("调试"),this);
    debug_debug->setShortcut(tr("F3"));
    ui->menu_D->addAction(debug_debug);

    //About Menu
    about_help = new QAction(tr("关于"),this);
    about_help->setShortcut(tr("F12"));
    ui->menu_H->addAction(about_help);

    //中心停靠窗
    center = new QDockWidget();    //中心停靠窗
    //setCentralWidget(center);      //中心窗口部件，QMainWindow::centerwidget
//    tab = new QTabWidget();
//    tab->setTabsClosable(true);
//    connect(tab,SIGNAL(tabCloseRequested(int)),this,SLOT(removeSubTab(int)));
//    tab->addTab(new QTextEdit("tab1"),"Tab1");
//    tab->addTab(new QTextEdit("tab2"),"Tab2");
//    tab->addTab(new QTextEdit("tab3"),"Tab3");
//    tab->addTab(new QTextEdit("tab4"),"Tab4");

    CenterWidget *cWidget = new CenterWidget();

    setCentralWidget(cWidget);      //中心窗口部件，QMainWindow::centerwidget


    //左停靠窗
    QDockWidget *mLeftDock = new QDockWidget(tr("项目浏览器"),this);
    mLeftDock->setFeatures(QDockWidget::AllDockWidgetFeatures);

    ProjWidget *dd = new ProjWidget(); //工程管理树状图
    dd->setFixedWidth(255);
//    dd->setFixedHeight(600);
    dd->parseProjXml("F:\\openGl\\CoDeSys_LiteIDE\\debug\\test.xml");

    mLeftDock->setWidget(dd);    //将树控件添加到左停靠窗中
    addDockWidget(Qt::LeftDockWidgetArea,mLeftDock);

    //右停靠窗
    QDockWidget *mRightDock = new QDockWidget(tr("配置窗口"),this);
    mRightDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QTextEdit *dock2Text = new QTextEdit(tr("右侧"));
    mRightDock->setWidget(dock2Text);
    addDockWidget(Qt::RightDockWidgetArea,mRightDock);

    //底部停靠窗
    QDockWidget *mBottomDock = new QDockWidget(tr("底部"),this);
    mBottomDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QTextEdit *dock3Text = new QTextEdit(tr("底部"));
    mBottomDock->setWidget(dock3Text);
    addDockWidget(Qt::BottomDockWidgetArea,mBottomDock);

     btn = new QPushButton("Open");
     ui->mainToolBar->addWidget(btn);
     //设置不显示label边框
//     ui->statusBar->setStyleSheet(QString("QStatusBar::item{border:0px}"));
     //设置不显示右边的大小控制点
     ui->statusBar->setSizeGripEnabled(true);
     ui->statusBar->addWidget(new QLabel(tr(""),this));
     ui->statusBar->addWidget(new QLabel(tr("离线"),this));
     ui->statusBar->addWidget(new QLabel(tr("模式"),this));
     ui->statusBar->addWidget(new QLabel(tr("警告"),this));
     ui->statusBar->addWidget(new QLabel(tr("错误"),this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::removeSubTab(int index)
{
    tab->removeTab(index);
}
