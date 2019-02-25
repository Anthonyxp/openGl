#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>

namespace Ui {
class CenterWidget;
}

class CenterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CenterWidget(QWidget *parent = 0);
    ~CenterWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CenterWidget *ui;
};

#endif // CENTERWIDGET_H
