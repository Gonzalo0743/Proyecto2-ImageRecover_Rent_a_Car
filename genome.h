#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

/*
- Vector of genes
- fitness value
- 
*/
class genome
{
public:
	Mat DNA;
	Mat firstHalf;
	Mat secondHalf;
	int fitness;
	
	genome();
	
	// for this genome method we could use a Mat as a base and then just modify
	//the color values inside it
	genome(Mat baseDNA);

	//In the future this method might accept a value as a parameter to determine
	//where to split the Mat, for now it will be always in half
	void split();

	void calcFitness(Mat TargetDNA);

	bool fitnessByOrder(Vec3b rgbTarget, Vec3b rgbDNA);

	int fitnessByComparison(Vec3b rgbTarget, Vec3b rgbDNA);

	int determineClosness(int targetVal, int dnaVal);

	void printDNA();

	// Function to generate random numbers in given range
	int random_num(int start, int end);

};

