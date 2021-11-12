#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "genome.h"

/**
* @brief Constructor
*/
genome::genome() {};

/**
* @brief Overloaded constructor, here we could use a Mat as a base and then just modify
* the color values inside it
*/
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

/**
 * @brief This function takes a Mat and sets it to the DNA varible, it also triggers the split funct
 * @param Recieves a Mat object
 */
void genome::setDNA(Mat newDNA)
{
    this->DNA = newDNA;
    this->split();
}

/**
* @brief In the future this method might accept a value as a parameter to determine
* where to split the Mat, for now it will be always in half
*/
void genome::split()
{
    int heightLen = this->DNA.rows;

    int splitPivot = heightLen / 2;

    Mat imageFirstCrop = this->DNA(Range(0, splitPivot), Range(0, this->DNA.cols));
    Mat imageSecondCrop = this->DNA(Range(splitPivot, heightLen), Range(0, this->DNA.cols));

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


/**
 * @brief Caculates the fitness value using the functions fitness by order and fitness by comparison
 * the result is set to the fitness atribute of this class
 * @param This function recives a Mat Object Which is taken as the Target to be reached
 */
void genome::calcFitness(Mat TargetDNA)
{
    /*cout << "===Target DNA===" << endl;
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

    cout << endl;*/

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



/**
* @brief Takes a set of vector with three spaces which represent the bgr values of the target and another
* vector which represents the bgr of the current genome and checks if they have the same order on their values
* @param Two Vec3b to compare them
* @return True if they have the same order, false if they don't
*/
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

/**
* @brief Takes a set of vector with three spaces which represent the bgr values of the target and another
* vector which represents the bgr of the current genome and compares the values of each color channel.
* @param Two Vec3b to compare them
* @return An integer that represents the closeness of the 6 values enterd on the vectors
*/
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

/**
* @brief Depending on the range of proximity of the values given, it returns a determined value.
* @param two integer values two compare them
* @return An integer depending on how close the values are to each other
*/
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

/**
* @brief Prints the values of the DNA of the current genome
*/
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

/**
* @brief Prints the values of the splited DNA of the current genome
*/
void genome::printSplit()
{
    cout << "===Split 1===" << endl;
    for (int i = 0; i < this->firstHalf.rows; i++) {
        for (int j = 0; j < this->firstHalf.cols; j++) {

            cout << "Color code: " << this->firstHalf.at<Vec3b>(i, j) << endl;
        }
    }
    cout << endl;

    cout << "===Split 2===" << endl;
    for (int i = 0; i < this->secondHalf.rows; i++) {
        for (int j = 0; j < this->secondHalf.cols; j++) {

            cout << "Color code: " << this->secondHalf.at<Vec3b>(i, j) << endl;
        }
    }
    cout << endl;
}

/**
* @brief Function to generate random numbers on given range
* @param Two integers, the starting and ending points of the range to calculate
* @return An Integer between the given values
*/
int genome::random_num(int start, int end)
{
    int range = (end - start) + 1;
    int random_int = start + (rand() % range);
    return random_int;
}

genome::~genome()
{
}
