#include "irwindow.h"
#include "ui_irwindow.h"

/**
 * @brief Crea la ventana de Image Recovery
 * @param parent genera la ventana de image recovery
 */
IRWindow::IRWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IRWindow)
{
    ui->setupUi(this);
}
/**
 * @brief Borra la ventana de image recovery
 */
IRWindow::~IRWindow()
{
    delete ui;
}
/**
 * @brief Acciona el boton para subir una imagen
 */
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

