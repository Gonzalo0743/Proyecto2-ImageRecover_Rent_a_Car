#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>

#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "irwindow.h"
#include "rcwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_IR_clicked();

    void on_pushButton_RC_clicked();

private:
    Ui::MainWindow *ui;
    //QString currentFile = "";
    IRWindow *irwindow;
    RCWindow *rcwindow;
};
#endif // MAINWINDOW_H
