#include "Interface/Headers/MainWindow.h"

MainWindow::MainWindow(QWidget *parent):QWidget(parent){

    //Setting the Sizes and the Title
    setWindowTitle("Rent a car & Image Recovery");
    setMinimumSize(800,600);
    setMaximumSize(800,600);
    setStyleSheet("background-color:white");

    //Show title image
    titleImage=new QImage();
    titleImage->load("GUI/ProgramTitle.png");
    titleLabel = new QLabel(this);
    titleLabel->setPixmap(QPixmap::fromImage(*titleImage));
    titleLabel->setGeometry(10,0,234,163);

    //Showing the buttons
    RentButton = new QPushButton("SELECT",this);
    RentButton->setCheckable(true);
    RentButton->setGeometry(200,350,140,30);
    connect(RentButton, SIGNAL(clicked(bool)),this,SLOT(on_RentButton_clicked(bool)));

    IRButton = new QPushButton("SELECTS", this);
    IRButton->setCheckable(true);
    IRButton->setGeometry(500,350,140,30);
    connect(IRButton, SIGNAL(clicked(bool)),this,SLOT(on_IRButton_clicked(bool)));

    Rent = new RentWindow();
    IRecovery = new ImageWindow();
}

void MainWindow::on_RentButton_clicked(bool checked) {
    if(checked){

        this->hide();

        Rent->show();
        //Rent->start();
    }

}

void MainWindow::on_IRButton_clicked(bool checked) {
    if(checked){

        this->hide();

        IRecovery->show();
    }

}


