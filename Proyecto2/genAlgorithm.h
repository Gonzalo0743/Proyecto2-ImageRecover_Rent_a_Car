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
	/**
	*@brief This are the total of rows and columns that the image has, each cell is a pixel
	*/
	int imageWidth, imageHeight;
	/**
	*@brief These values represent the coordinates where the image has no color
	*/
	int missingXPos = 0 , missingYPos = 0; 
	/**
	*@brief This vaue indicates the length of the square with no color on the image
	*/
	int missingSindeLen = 2; 
	
	/**
	*@brief Amount of generations created by the algorithm
	*/
	int generation = 0;
	/**
	*@brief Mat object with the whole image represented as a matrix of bgr values
	*/
	Mat fullImage;
	/**
	*@brief Section of the image that is being used as a target by the algorithm
	*/
	Mat Target;

	/**
	*@brief This value represents the amount of members of the population for each generation
	*/
	int populationSize = 20;
	/**
	*@brief This vector saves the population of each generation
	*/
	vector<genome*> population;
	/**
	*@brief This is the value of the maximum fitness that a member of the population must reach
	*/
	int fitnessTarget;
	/**
	*@brief If a member of the population reaches the fitness target, its memory location will be saved in this pointer
	*/
	genome* topGen;

	//Methods-----------------|
	/**
	*@brief Constructor for the genetic algorithm
	*/
	genAlgorithm();
	/**
	*@brief Receives an string with the path of an image and converts it into a Mat object
	*@param Stirng, the path of the image that will beloaded
	*/
	void loadImage(string path);
	/**
	*@brief Once the image has been loaded, it defines the fitness target that must be reached
	*/
	void defineMaxFitness();
	/**
	*@brief Selects a section of the image that will be used as a target
	*/
	void defineTarget();
	/**
	*@brief Generates the first population of genomes and stores it
	*/
	void createPopulation();
	/**
	*@brief Goes across the members of the current population calculating its fitness, also checks if the fitness value
	* of each member has reached the fitness target
	*@return Boolean, if the fitness target has been reached it returns true, else returns false
	*/
	bool naturalSelection();
	/**
	*@brief Sorts the members of the population on a decreasing order based on their fitness value
	*/
	void sortPopulation();
	/**
	*@brief Takes two members of the current population and mixes them togheter. It takes a half of the matrix of the first genome
	* and merges it with the other half of the second genome, it does the same with the remaining matrices creating two new individuals
	*/
	void crossover();
	/**
	*@brief It takes each value of a given matrix and there`s a posibility of mutating one or some of the rgb values 
	* form a cell of the matrix
	*@param A Mat object wich is the matrix that will be analyzed
	*@return returns a the matrix, could be the same or it could have some different values.
	*/
	Mat mutation(Mat mutableGen);
	/**
	*@brief Gets the current generation index
	*@return integer that represents the amount of generations that had been creted at the time
	*/
	int getGeneration();
	/**
	 * @brief Function to generate random numbers on given range
	 * @param Two integers, the starting and ending points of the range to calculate
	 * @return An Integer between the given values
	 */
	int random_num(int start, int end);
};