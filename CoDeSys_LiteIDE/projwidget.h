#ifndef PROJWIDGET_H
#define PROJWIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>

namespace Ui {
class ProjWidget;
}

class ProjWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProjWidget(QWidget *parent = 0);
    ~ProjWidget();

    bool parseProjXml(QString projPath);
    bool saveProjXml(QString projPath);


public slots:
    void treeItemDClicked(QTreeWidgetItem* item,int column);
    void itemPressedSlot(QTreeWidgetItem* item,int column);
    void deleteItem();

signals:
    void openFile(QString fileName);

private:
    Ui::ProjWidget *ui;
    int width;
    int height;
};

#endif // PROJWIDGET_H
