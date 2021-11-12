#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
	int src, dest, weight;
};

typedef pair<int, int> cityPair;

class AdjGraph
{
public:
	int  nodeAmount = 5;

	vector<string> totalCities = {"Qieburg", "Prego", "Fester", "Ontson", "Andosas", "Adarora", "Elesbury", "Phison", "Cartago", "San Jose", "Limon", "Puntarenas", "Guanacaste", "Heredia", "Alajuela"};
	vector<string> pickedCities;
	vector<cityPair> edges;
	
	AdjGraph();
	void selectCities();
	void makeConnections();
	int random_num(int start, int end);
};

