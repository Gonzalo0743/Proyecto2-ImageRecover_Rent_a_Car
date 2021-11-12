#include "genAlgorithm.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "genome.h"

using namespace std;
using namespace cv;

/**
*@brief Constructor for the genetic algorithm
*/
genAlgorithm::genAlgorithm()
{
}

/**
*@brief Receives an string with the path of an image and converts it into a Mat object
*@param Stirng, the path of the image that will beloaded
*/
void genAlgorithm::loadImage(string path)
{
    Mat image = imread(path, IMREAD_COLOR);
    this->fullImage = image;

    this->imageWidth = image.cols;
    this->imageHeight = image.rows;

    this->defineMaxFitness();

    /* Loop that takes the brg code of each pixel of an image
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {

            cout << "Color code: " << image.at<Vec3b>(i, j) << endl;

            cout << "color blue: " << double(image.at<Vec3b>(i, j)[0]) << endl;
            cout << "color green: " << double(image.at<Vec3b>(i, j)[1]) << endl;
            cout << "color red: " << double(image.at<Vec3b>(i, j)[2]) << endl;
        }
    }*/
}

/**
*@brief Once the image has been loaded, it defines the fitness target that must be reached
*/
void genAlgorithm::defineMaxFitness()
{
    this->fitnessTarget = 2 * this->missingSindeLen * 31;
    cout << "MAX FIT : " << this->fitnessTarget << endl;
}

/**
*@brief Selects a section of the image that will be used as a target
*/
void genAlgorithm::defineTarget()
{
    int targetXpos = this->missingXPos + this->missingSindeLen;
    int targetYpos = this->missingYPos;

    Mat croppedImg = this->fullImage(Range(targetYpos, targetYpos + this->missingSindeLen), Range(targetXpos, targetXpos + this->missingSindeLen));

    this->Target = croppedImg;

    /*Prints the values of the cropped image to check if it has been cutted propperly
    for (int i = 0; i < croppedImg.rows; i++) {
        for (int j = 0; j < croppedImg.cols; j++) {

            cout << "Color code: " << croppedImg.at<Vec3b>(i, j) << endl;

            cout << "color blue: " << double(croppedImg.at<Vec3b>(i, j)[0]) << endl;
            cout << "color green: " << double(croppedImg.at<Vec3b>(i, j)[1]) << endl;
            cout << "color red: " << double(croppedImg.at<Vec3b>(i, j)[2]) << endl;

        }
    }*/
}

/**
*@brief Generates the first population of genomes and stores it
*/
void genAlgorithm::createPopulation()
{

    if (this->generation == 0) {
        for (int i = 0; i < this->populationSize; i++) {
            Mat dst = this->Target.clone();
            genome* gene = new genome(dst);
            this->population.push_back(gene);
        }
    }
    this->generation++;
}

/**
*@brief Goes across the members of the current population calculating its fitness, also checks if the fitness value
* of each member has reached the fitness target
*@return Boolean, if the fitness target has been reached it returns true, else returns false
*/
bool genAlgorithm::naturalSelection()
{
    for (int i = 0; i < this->populationSize; i++) {
        this->population[i]->calcFitness(this->Target);
        if (this->population[i]->fitness >= this->fitnessTarget) 
        {   
            this->topGen = this->population[i];
            return true;
        }
    }
    return false;
}


/**
*@brief Sorts the members of the population on a decreasing order based on their fitness value
*/
void genAlgorithm::sortPopulation()
{
    for (int k = 1; k < this->populationSize; k++) {
        genome* temp = this->population[k];
        int tempFit = temp->fitness;
        int j = k - 1;
        while (j >= 0 && tempFit >= this->population[j]->fitness) {
            this->population[j + 1] = this->population[j];
            j = j - 1;
        }
        this->population[j + 1] = temp;
    }
}

/**
*@brief Takes two members of the current population and mixes them togheter. It takes a half of the matrix of the first genome
* and merges it with the other half of the second genome, it does the same with the remaining matrices creating two new individuals
*/
void genAlgorithm::crossover()
{
    vector<genome*> newGeneration;
    for (int i = 0; i < this->populationSize; i += 2) {
        Mat newGenomeOne;
        Mat newGenomeTwo;
        
        newGenomeOne.push_back(this->population[i]->firstHalf);
        newGenomeOne.push_back(this->population[i + 1]->secondHalf);

        newGenomeTwo.push_back(this->population[i + 1]->firstHalf);
        newGenomeTwo.push_back(this->population[i]->secondHalf);

        genome* g1 = new genome();
        g1->setDNA(this->mutation(newGenomeOne));
        
        
        genome* g2 = new genome();
        g2->setDNA(this->mutation(newGenomeTwo));
        
        newGeneration.push_back(g1);
        newGeneration.push_back(g2);
    }

    //this->population.clear();
    this->population = newGeneration;
    /*for (auto p : newGeneration)
    {
        delete p;
    }*/
    newGeneration.clear();
    this->generation++;

    cout << "New GEN" << endl;
    /*for (int i = 0; i < this->populationSize; i++) {
        this->population[i]->printDNA();
    }*/
}


/**
*@brief It takes each value of a given matrix and there`s a posibility of mutating one or some of the rgb values
* form a cell of the matrix
*@param A Mat object wich is the matrix that will be analyzed
*@return returns a the matrix, could be the same or it could have some different values.
*/
Mat genAlgorithm::mutation(Mat mutableGen)
{
    for (int i = 0; i < mutableGen.rows; i++) {
        for (int j = 0; j < mutableGen.cols; j++) {
            Vec3b pixColor = mutableGen.at<Vec3b>(i, j);
            int chosen = this->random_num(0, 99);
            if (chosen <= 60) 
            {
                pixColor[0] = random_num(0, 255);
                pixColor[1] = random_num(0, 255);
                pixColor[2] = random_num(0, 255);
            }
            else if (chosen <= 70)
            {
                pixColor[this->random_num(0, 2)] = random_num(0, 255);
                pixColor[this->random_num(0, 2)] = random_num(0, 255);
            }
            else if (chosen <= 80)
            {
                pixColor[this->random_num(0, 2)] = random_num(0, 255);
            }
        }
    }
    return mutableGen;
}

/**
*@brief Gets the current generation index
*@return integer that represents the amount of generations that had been creted at the time
*/
int genAlgorithm::getGeneration()
{
    return this->generation;
}

/**
* @brief Function to generate random numbers on given range
* @param Two integers, the starting and ending points of the range to calculate
* @return An Integer between the given values
*/
int genAlgorithm::random_num(int start, int end)
{
    int range = (end - start) + 1;
    int random_int = start + (rand() % range);
    return random_int;
}