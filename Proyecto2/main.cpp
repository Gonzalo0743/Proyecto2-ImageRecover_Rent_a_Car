#include "mainwindow.h"
#include <QApplication>

/**
 * @brief Ejecuta la ventana principañl
 * @param argc parametro necesario para crear la ventana
 * @param argv parametro necesario para crear la ventana
 */

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
