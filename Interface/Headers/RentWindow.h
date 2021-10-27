
#ifndef UNTITLED_RENTWINDOW_H
#define UNTITLED_RENTWINDOW_H

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

class RentWindow : public QWidget{
Q_OBJECT

public:
    RentWindow(QWidget *parent = nullptr);
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

#endif //UNTITLED_RENTWINDOW_H
