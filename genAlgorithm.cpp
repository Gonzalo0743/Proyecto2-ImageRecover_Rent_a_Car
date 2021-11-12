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

genAlgorithm::genAlgorithm()
{
}

void genAlgorithm::loadImage(string path)
{
    Mat image = imread(path, IMREAD_COLOR);
    this->fullImage = image;

    this->imageWidth = image.cols;
    this->imageHeight = image.rows;

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

void genAlgorithm::createPopulation()
{

    if (this->generation == 0) {
        for (int i = 0; i < this->populationSize; i++) {
            Mat dst = this->Target.clone();
            genome* gene = new genome(dst);
            this->population.push_back(gene);
            //this->population.push_back(genome(this->Target));
        }
    }
}

void genAlgorithm::naturalSelection()
{
    genome topGen;

    for (int i = 0; i < this->populationSize; i++) {
        this->population[i]->calcFitness(this->Target);
    }
}


// Sorts the individuals of the population based on their fitness value
void genAlgorithm::sortPopulation()
{
    /*for (int i = 0; i < this->populationSize; i++) {
        cout << "fitness: " << this->population[i]->fitness << endl;
    }*/

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

    /*cout << "\n Sorted Values: " << endl;
    for (int i = 0; i < this->populationSize; i++) {
        cout << "fitness: " << this->population[i]->fitness << endl;
    }*/

    cout << "===Sorted DNA===" << endl;
    for (int i = 0; i < this->populationSize; i++) {
        this->population[i]->printDNA();
    }
}

void genAlgorithm::crossover()
{
    vector<genome*> newGeneration;
    for (int i = 0; i < this->populationSize; i += 2) {
        Mat newGenomeOne;
        Mat newGenomeTwo;

        cout << "===Half DNA===" << endl;
        for (int i = 0; i < this->population[i]->firstHalf.rows; i++) {
            for (int j = 0; j < this->population[i]->firstHalf.cols; j++) {

                cout << "First Half: " << this->population[i]->firstHalf.at<Vec3b>(i, j) << endl;
            }
        }

        cout << "===Second Half DNA===" << endl;
        for (int i = 0; i < this->population[i]->secondHalf.rows; i++) {
            for (int j = 0; j < this->population[i]->secondHalf.cols; j++) {

                cout << "Second Half: " << this->population[i]->secondHalf.at<Vec3b>(i, j) << endl;
            }
        }
        
        newGenomeOne.push_back(this->population[i]->firstHalf);
        newGenomeOne.push_back(this->population[i + 1]->secondHalf);

        newGenomeTwo.push_back(this->population[i + 1]->firstHalf);
        newGenomeTwo.push_back(this->population[i]->secondHalf);

        cout << "===New Gen 1===" << endl;
        for (int i = 0; i < newGenomeOne.rows; i++) {
            for (int j = 0; j < newGenomeOne.cols; j++) {

                cout << "Color code: " << newGenomeOne.at<Vec3b>(i, j) << endl;
            }
        }

        cout << "===New Gen 2===" << endl;
        for (int i = 0; i < newGenomeTwo.rows; i++) {
            for (int j = 0; j < newGenomeTwo.cols; j++) {

                cout << "Color code: " << newGenomeTwo.at<Vec3b>(i, j) << endl;
            }
        }

        genome* g1 = new genome(newGenomeOne);
        genome* g2 = new genome(newGenomeTwo);
        
        newGeneration.push_back(g1);
        newGeneration.push_back(g2);
    }
    //this->population = newGeneration;
}

int genAlgorithm::random_num(int start, int end)
{
    int range = (end - start) + 1;
    int random_int = start + (rand() % range);
    return random_int;
}
