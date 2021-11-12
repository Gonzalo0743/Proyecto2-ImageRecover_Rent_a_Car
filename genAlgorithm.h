#pragma once

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

class genAlgorithm
{
public:
	//Atributes----------------|
	int imageWidth, imageHeight;
	int missingXPos = 0 , missingYPos = 0; // Here theese atributes have to be given by default to the program
	int missingSindeLen = 2; // Here this atribute has to be given by default to the program
	
	int generation = 0;
	Mat fullImage;
	Mat Target;

	int populationSize = 20;
	vector<genome*> population;

	//Methods-----------------|

	genAlgorithm();
	void loadImage(string path);
	void defineTarget();
	void createPopulation();
	void naturalSelection();
	void sortPopulation();
	void crossover();
	int random_num(int start, int end);

};

