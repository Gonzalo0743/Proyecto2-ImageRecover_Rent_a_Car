#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

class genome
{
public:
	/**
	 * @brief DNA of the current genome, which represents an image as a matrix, and its values are bgr vectors
	 */
	Mat DNA;

	/**
	 * @brief When a DNA is set, its first half will be saved here
	 */
	Mat firstHalf;

	/**
	 * @brief When a DNA is set, its second half will be saved here
	 */
	Mat secondHalf;

	/**
	 * @brief Fitness value of the current genome
	 */
	int fitness;
	
	/**
	 * @brief Constructor
	 */
	genome();
	
	/**
	* @brief Overloaded constructor, here we could use a Mat as a base and then just modify
	* the color values inside it
	*/
	genome(Mat baseDNA);

	/**
	 * @brief This function takes a Mat and sets it to the DNA varible, it also triggers the split funct
	 * @param Recieves a Mat object
	 */
	void setDNA(Mat newDNA);

	/**
	 * @brief In the future this method might accept a value as a parameter to determine 
	 * where to split the Mat, for now it will be always in half
	 */
	void split();

	/**
	 * @brief Caculates the fitness value using the functions fitness by order and fitness by comparison
	 * the result is set to the fitness atribute of this class
	 * @param This function recives a Mat Object Which is taken as the Target to be reached
	 */
	void calcFitness(Mat TargetDNA);

	/**
	 * @brief Takes a set of vector with three spaces which represent the bgr values of the target and another
	 * vector which represents the bgr of the current genome and checks if they have the same order on their values
	 * @param Two Vec3b to compare them 
	 * @return True if they have the same order, false if they don't
	 */
	bool fitnessByOrder(Vec3b rgbTarget, Vec3b rgbDNA);

	/**
	 * @brief Takes a set of vector with three spaces which represent the bgr values of the target and another
	 * vector which represents the bgr of the current genome and compares the values of each color channel.
	 * @param Two Vec3b to compare them 
	 * @return An integer that represents the closeness of the 6 values enterd on the vectors
	 */
	int fitnessByComparison(Vec3b rgbTarget, Vec3b rgbDNA);

	/**
	 * @brief Depending on the range of proximity of the values given, it returns a determined value. 
	 * @param two integer values two compare them
	 * @return An integer depending on how close the values are to each other
	 */
	int determineClosness(int targetVal, int dnaVal);

	/**
	 * @brief Prints the values of the DNA of the current genome
	 */
	void printDNA();

	/**
	 * @brief Prints the values of the splited DNA of the current genome
	 */
	void printSplit();

	/**
	 * @brief Function to generate random numbers on given range
	 * @param Two integers, the starting and ending points of the range to calculate
	 * @return An Integer between the given values
	 */
	int random_num(int start, int end);

	~genome();

};

