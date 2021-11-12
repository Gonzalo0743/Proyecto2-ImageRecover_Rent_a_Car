#include "irwindow.h"
#include "ui_irwindow.h"

IRWindow::IRWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IRWindow)
{
    ui->setupUi(this);
}

IRWindow::~IRWindow()
{
    delete ui;
}

void IRWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images(*.png *.jpg *.gif)"));
    if(QString::compare(filename,QString())!=0){
        QImage image;
        bool valid = image.load(filename);

        if(valid){
            ui->lbl_image->setPixmap(QPixmap::fromImage(image));
        }
        else{
            //Error handling
        }
    }

}

