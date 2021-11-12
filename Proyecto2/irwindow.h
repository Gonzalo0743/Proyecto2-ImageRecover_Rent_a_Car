#ifndef IRWINDOW_H
#define IRWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

namespace Ui {
class IRWindow;
}

class IRWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit IRWindow(QWidget *parent = nullptr);
    ~IRWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::IRWindow *ui;
};

#endif // IRWINDOW_H
