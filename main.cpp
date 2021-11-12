// C++ program to create target string, starting from
// random string using Genetic Algorithm
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "genAlgorithm.h"
#include "AdjGraph.h"

using namespace std;
using namespace cv;

int main(){
	//AdjGraph adj;
	//adj.selectCities();
	//adj.makeConnections();

	genAlgorithm* genetic = new genAlgorithm();
	genetic->loadImage("/Users/fantu/Pictures/Patrones-Proyecto-Datos2/ball.png");
	genetic->defineTarget();
	genetic->createPopulation();
	genetic->naturalSelection();
	genetic->sortPopulation();
	//genetic->crossover();

	/*Vec3b arr1 = {89, 53, 102};
	Vec3b arr2 = { 89, 53, 90 };

	genome testGen;
	cout << testGen.fitnessByOrder(arr1, arr2);*/
	
	// { 30,100,155 }
	/*int fitness = 0;

	Vec3b arr1 = { 61,125,138 };
	Vec3b arr2 = { 20,120,232 };

	genome testGen;

	if (testGen.fitnessByOrder(arr1, arr2)) {
		fitness += 1;
	}
	fitness += testGen.fitnessByComparison(arr1, arr2);
	
	cout << "fitness: " << fitness;*/

} 