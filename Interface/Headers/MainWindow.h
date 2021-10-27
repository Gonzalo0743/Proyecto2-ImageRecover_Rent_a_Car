//
// Created by gonzalo on 24/10/21.
//

#ifndef UNTITLED_MAINWINDOW_H
#define UNTITLED_MAINWINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <string>
#include <QImage>
#include <QWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "RentWindow.h"
#include "ImageWindow.h"

class MainWindow : public QWidget{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void start();

private slots:
    void on_RentButton_clicked(bool checked);
    void on_IRButton_clicked(bool checked);

private:

    QImage* titleImage;
    QLineEdit* userInput;
    QPushButton* RentButton;
    QPushButton* IRButton;
    QLabel* titleLabel;
    RentWindow* Rent;
    ImageWindow* IRecovery;

};

#endif //UNTITLED_MAINWINDOW_H
