#ifndef RCWINDOW_H
#define RCWINDOW_H

#include <QMainWindow>


namespace Ui {
class RCWindow;
}

class RCWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RCWindow(QWidget *parent = nullptr);
    ~RCWindow();


private slots:

    void on_pushButton_ciudades_clicked();

    void on_pushButton_calcular_clicked();

private:
    Ui::RCWindow *ui;

};

#endif // RCWINDOW_H
