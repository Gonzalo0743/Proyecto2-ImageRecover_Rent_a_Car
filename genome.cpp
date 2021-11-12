#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "genome.h"
//Default constructor
genome::genome() {};

genome::genome(Mat baseDNA)
{   
    for (int i = 0; i < baseDNA.rows; i++) {
        for (int j = 0; j < baseDNA.cols; j++) {

            Vec3b pixColor = baseDNA.at<Vec3b>(i, j);

            pixColor[0] = random_num(0, 255);
            pixColor[1] = random_num(0, 255);
            pixColor[2] = random_num(0, 255);

            baseDNA.at<Vec3b>(i, j) = pixColor;
        }
    }

    /*cout << "===Base DNA===" << endl;
    for (int i = 0; i < baseDNA.rows; i++) {
        for (int j = 0; j < baseDNA.cols; j++) {

            cout << "Color code: " << baseDNA.at<Vec3b>(i, j) << endl;

            cout << "color blue: " << double(baseDNA.at<Vec3b>(i, j)[0]) << endl;
            cout << "color green: " << double(baseDNA.at<Vec3b>(i, j)[1]) << endl;
            cout << "color red: " << double(baseDNA.at<Vec3b>(i, j)[2]) << endl;
        }
    }*/


    this->DNA = baseDNA;
    this->split();
}

void genome::split()
{
    int widthLen = this->DNA.cols;

    int splitPivot = widthLen / 2;

    Mat imageFirstCrop = this->DNA(Range(0, this->DNA.rows), Range(0, splitPivot));
    Mat imageSecondCrop = this->DNA(Range(0, this->DNA.rows), Range(splitPivot, widthLen));

    this->firstHalf = imageFirstCrop;
    this->secondHalf = imageSecondCrop;

    /* For now both cases do the SAME - Added just in case there is some error with odd lengths
    if (widthLen % 2 == 0) {
        int splitPivot = widthLen / 2;

        Mat imageFirstCrop = this->DNA(Range(0, this->DNA.rows), Range(0, splitPivot));
        Mat imageSecondCrop = this->DNA(Range(0, this->DNA.rows), Range(splitPivot, widthLen));

        this->firstHalf = imageFirstCrop;
        this->secondHalf = imageSecondCrop;
    }

    else{
        int splitPivot = widthLen / 2;

        Mat imageFirstCrop = this->DNA(Range(0, this->DNA.rows), Range(0, splitPivot));
        Mat imageSecondCrop = this->DNA(Range(0, this->DNA.rows), Range(splitPivot, widthLen));

        this->firstHalf = imageFirstCrop;
        this->secondHalf = imageSecondCrop;
    }*/
}


//Vamos a comparar el DNA del genome con el Target DNA sigueindo
//algunos parámetros, con el propósito de determinar cual tiene el
//mayor nivel de fitness
void genome::calcFitness(Mat TargetDNA)
{
    cout << "===Target DNA===" << endl;
    for (int i = 0; i < TargetDNA.rows; i++) {
        for (int j = 0; j < TargetDNA.cols; j++) {

            cout << "Color code: " << TargetDNA.at<Vec3b>(i, j) << endl;
        }
    }

    cout << endl;

    cout << "===Base DNA===" << endl;
    for (int i = 0; i < this->DNA.rows; i++) {
        for (int j = 0; j < this->DNA.cols; j++) {

            cout << "Color code: " << this->DNA.at<Vec3b>(i, j) << endl;
        }
    }

    cout << endl;

    int fitnessCounter = 0;

    for (int i = 0; i < this->DNA.rows; i++) {
        for (int j = 0; j < this->DNA.cols; j++) {

            Vec3b targetNucleotide = TargetDNA.at<Vec3b>(i, j);
            Vec3b nucleotide = this->DNA.at<Vec3b>(i, j);
            
            if (this->fitnessByOrder(targetNucleotide, nucleotide)) {
                fitnessCounter += 1;
            }

            fitnessCounter += this->fitnessByComparison(targetNucleotide, nucleotide);
        }
    }
    this->fitness = fitnessCounter;

    cout << "Fitness val for this gen: " << this->fitness << endl;
    cout << endl;
}

bool genome::fitnessByOrder(Vec3b rgbTarget, Vec3b rgbDNA)
{       
    bool MAX = false;
    bool MIN = false;

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            if (rgbTarget[0] >= rgbTarget[1] && rgbTarget[0] >= rgbTarget[2]) {
                if (rgbDNA[0] >= rgbDNA[1] && rgbDNA[0] >= rgbDNA[2]) {
                    MAX = true;
                }
                else {
                    return false;
                }
            }
            else if (rgbTarget[0] <= rgbTarget[1] && rgbTarget[0] <= rgbTarget[2]) {
                if (rgbDNA[0] <= rgbDNA[1] && rgbDNA[0] <= rgbDNA[2]) {
                    MIN = true;
                }
                else {
                    return false;
                }
            }
            else if (rgbDNA[0] >= rgbDNA[1] && rgbDNA[0] >= rgbDNA[2]) {
                return false;
            }
            else if (rgbDNA[0] <= rgbDNA[1] && rgbDNA[0] <= rgbDNA[2]) {
                return false;
            }
        }
        else if (i == 1) {
            if (rgbTarget[1] <= rgbTarget[2] && rgbDNA[1] <= rgbDNA[2]) {
                return true;
            }
            else if (rgbTarget[1] >= rgbTarget[2] && rgbDNA[1] >= rgbDNA[2]) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

int genome::fitnessByComparison(Vec3b rgbTarget, Vec3b rgbDNA)
{
    int totalSum = 0;
    int orderArray[3];
    bool max = false;
    bool min = false;

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            if (rgbTarget[0] >= rgbTarget[1] && rgbTarget[0] >= rgbTarget[2]) {
                max = true;
                orderArray[0] = 3;
            }
            else if (rgbTarget[0] >= rgbTarget[1] || rgbTarget[0] >= rgbTarget[2]) {
                orderArray[0] = 2;
            }
            else {
                min = true;
                orderArray[0] = 1;
            }
        }
        else if (i == 1) {
            if (max == false && min == false) {
                if (rgbTarget[1] >= rgbTarget[2]) {
                    orderArray[1] = 3;
                    orderArray[2] = 1;
                }
                else {
                    orderArray[1] = 1;
                    orderArray[2] = 3;
                }
            }
            else if (max == true) {
                if (rgbTarget[1] >= rgbTarget[2]) {
                    orderArray[1] = 2;
                    orderArray[2] = 1;
                }
                else {
                    orderArray[1] = 1;
                    orderArray[2] = 2;
                }
            }
            else {
                if (rgbTarget[1] >= rgbTarget[2]) {
                    orderArray[1] = 3;
                    orderArray[2] = 2;
                }
                else {
                    orderArray[1] = 2;
                    orderArray[2] = 3;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        totalSum += orderArray[i] * determineClosness(rgbTarget[i],rgbDNA[i]);
    }

    return totalSum;
}

int genome::determineClosness(int targetVal, int dnaVal)
{
    int result = abs(targetVal - dnaVal);
    
    if (result == 0) {
        return 5;
    }
    else if (result <= 26) {
        return 4;
    }
    else if (result <= 52) {
        return 3;
    }
    else if (result <= 78) {
        return 2;
    }
    else if (result <= 104) {
        return 1;
    }
    else {
        return 0;
    } 
}

void genome::printDNA()
{
    cout << "===DNA===" << endl;
    for (int i = 0; i < this->DNA.rows; i++) {
        for (int j = 0; j < this->DNA.cols; j++) {

            cout << "Color code: " << this->DNA.at<Vec3b>(i, j) << endl;
        }
    }
    cout << endl;
}

int genome::random_num(int start, int end)
{
    int range = (end - start) + 1;
    int random_int = start + (rand() % range);
    return random_int;
}
