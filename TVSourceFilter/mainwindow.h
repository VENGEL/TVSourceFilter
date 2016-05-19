#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "FliterImpliment.h"

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
    void on_BtnGetPath_clicked();

    void on_BtnGetInfo_clicked();

private:
    Ui::MainWindow *ui;

    FliterImpliment m_Filter;
};

#endif // MAINWINDOW_H
