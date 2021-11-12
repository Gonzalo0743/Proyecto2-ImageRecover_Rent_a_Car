#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "irwindow.h"
#include "rcwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Chalo/Documents/Qt Projects/Proyecto2/Resources/ProgramTitle.png");
    ui->label_pic->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_IR_clicked()
{
    irwindow = new IRWindow(this);
    irwindow->show();
    this->hide();
}


void MainWindow::on_pushButton_RC_clicked()
{
    rcwindow = new RCWindow(this);
    rcwindow->show();
    this->hide();
}
