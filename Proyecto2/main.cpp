#include "mainwindow.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "genAlgorithm.h"
#include "mainwindow.h"

using namespace std;
using namespace cv;

#include <QApplication>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
    bool found = false;
    int maxGenerations = 10;
    genAlgorithm* genetic = new genAlgorithm();
    genetic->loadImage("/Users/fantu/Pictures/Patrones-Proyecto-Datos2/ball.png");
    genetic->defineTarget();
    genetic->createPopulation();
    while (genetic->getGeneration() != maxGenerations) {
        if (genetic->naturalSelection() == true)
        {
            found = true;
            break;
        }
        genetic->sortPopulation();
        genetic->crossover();
    }

    if (found) {
        genetic->topGen->printDNA();
    }
    else {
        cout << "I wasn`t able to find your image... please try again" << endl;
    }
}
