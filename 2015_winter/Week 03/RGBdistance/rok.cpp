#include <iostream>
#include <fstream>

using namespace std;

int min(int* arr, int size);

int main() {
	ifstream fin("rgb.inp");
	int hNum;
	fin >> hNum;

	int** cost = new int*[hNum];
	for (int i = 0; i < hNum; i++)
		cost[i] = new int[3];

	for (int i = 0; i < hNum; i++) {
		for (int j = 0; j < 3; j++)
			fin >> cost[i][j];
	}

	int totalCost[3] = { 0, 0, 0 };

	for (int i = 0; i < hNum; i++) {
		int t1 = totalCost[1] + cost[i][0];
		if (t1 > totalCost[2] + cost[i][0])
			t1 = totalCost[2] + cost[i][0];

		int t2 = totalCost[0] + cost[i][1];
		if (t2 > totalCost[2] + cost[i][1])
			t2 = totalCost[2] + cost[i][1];

		int t3 = totalCost[0] + cost[i][2];
		if (t3 > totalCost[1] + cost[i][2])
			t3 = totalCost[1] + cost[i][2];

		totalCost[0] = t1;
		totalCost[1] = t2;
		totalCost[2] = t3;
	}

	int rgbMin = min(totalCost, 3);
	
	cout << rgbMin << endl;

	return 0;
}

int min(int* arr, int size) {
	int min = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < min)
			min = arr[i];
	}

	return min;
}