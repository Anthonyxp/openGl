#include "centerwidget.h"
#include "ui_centerwidget.h"

CenterWidget::CenterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CenterWidget)
{
    ui->setupUi(this);
    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(removeSubTab(int)));
}

CenterWidget::~CenterWidget()
{
    delete ui;
}

void CenterWidget::on_pushButton_clicked()
{
//    emit openProj(projName);
    ui->stackedWidget->setCurrentIndex(1);
}
