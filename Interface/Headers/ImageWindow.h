//
// Created by gonzalo on 26/10/21.
//

#ifndef UNTITLED_IMAGEWINDOW_H
#define UNTITLED_IMAGEWINDOW_H

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

class ImageWindow : public QWidget{
    Q_OBJECT

public:
    ImageWindow(QWidget *parent = nullptr);
    void start();

/** private slots:
    void on_RentButton_clicked(bool checked);
    void on_IRButton_clicked(bool checked);
    **/

private:
    QImage* titleImage;
    //QLineEdit* userInput;
    //QPushButton* RentButton;
    //QPushButton* IRButton;
    QLabel* titleLabel;

};

#endif //UNTITLED_IMAGEWINDOW_H
