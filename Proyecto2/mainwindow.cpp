#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "irwindow.h"
#include "rcwindow.h"

/**
 * @brief Crea la ventana principal
 * @param parent genera la ventana principal
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Chalo/Documents/Qt Projects/Proyecto2/Resources/ProgramTitle.png");
    ui->label_pic->setPixmap(pix);

}
/**
 * @brief Borra la ventana principal
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Acciona el boton para pasar a la ventana de image recovery
 */
void MainWindow::on_pushButton_IR_clicked()
{
    irwindow = new IRWindow(this);
    irwindow->show();
    this->hide();
}

/**
 * @brief Acciona el boton para pasar a la ventana de rent a car
 */
void MainWindow::on_pushButton_RC_clicked()
{
    rcwindow = new RCWindow(this);
    rcwindow->show();
    this->hide();
}

