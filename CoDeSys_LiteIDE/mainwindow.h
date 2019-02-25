#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void removeSubTab(int index);

private:
    Ui::MainWindow *ui;

    //File Menu
    QAction *new_file;
    QAction *open_file;
    QAction *save_file;
    QAction *exit_file;
    //Edit Menu
    QAction *copy_edit;
    QAction *paste_edit;
    QAction *cut_edit;
    QAction *allSelect_edit;
    //Build Menu
    QAction *build_build;
    QAction *rebuild_build;
    //Online Menu
    QAction *logIn_online;
    QAction *logOut_online;
    //Debug Menu
    QAction *debug_debug;
    //Help Menu
    QAction *about_help;

    QDockWidget *center;

    QTabWidget *tab;
    QPushButton *btn;
};

#endif // MAINWINDOW_H
