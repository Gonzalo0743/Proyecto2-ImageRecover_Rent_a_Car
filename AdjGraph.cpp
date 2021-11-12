#include "AdjGraph.h"

AdjGraph::AdjGraph() {

}

void AdjGraph::selectCities()
{
	for (int i = 0; i < this->nodeAmount; i++) {
		int pickedIndex = this->random_num(0, 14);
		string pickedCity = this->totalCities[pickedIndex];
		this->pickedCities.push_back(pickedCity);
	}

	for (string i : this->pickedCities) {
		cout << "City: " << i << endl;
	}
}	

void AdjGraph::makeConnections()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (j != i) {
				if (this->random_num(0, 9) < 3) {
					int setDist = this->random_num(0, 29);
					this->edges.push_back(make_pair(j, setDist));
				}
			}
		}
	}

	for (int i = 0; i < this->nodeAmount; i++)
	{
		// Function to print all neighboring vertices of a given vertex
		for (cityPair v : this->edges)
		{
			cout << "(" << i << ", " << v.first <<
				", " << v.second << ") ";
		}
		cout << endl;
	}
}

int AdjGraph::random_num(int start, int end)
{
	int range = (end - start) + 1;
	int random_int = start + (rand() % range);
	return random_int;
}
