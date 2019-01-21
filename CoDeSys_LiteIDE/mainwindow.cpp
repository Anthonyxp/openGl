#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //File Menu
    new_file = new QAction("新建工程",this);
    new_file->setShortcut(tr("ctrl+n"));
    ui->menu_F->addAction(new_file);
}

MainWindow::~MainWindow()
{
    delete ui;
}
