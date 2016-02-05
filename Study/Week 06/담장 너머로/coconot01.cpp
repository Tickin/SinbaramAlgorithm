#include<iostream>

using namespace std;

int people[30];
bool peopleAdjArea[30][200];
int area[200][250];
int dualArea[200][200];
typedef struct minInfo {
	int minSum;
	int minPlace;
}_minInfo;

bool isAdj(int, int, int);

void initializeArea(int areaNum, int townNum)
{
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 250; j++)
		{
			area[i][j] = 0;
		}
	}
	int adjTownNum;
	for (int i = 0; i < areaNum; i++)
	{
		cin >> adjTownNum;
		for (int j = 0; j < adjTownNum; j++)
		{
			cin >> area[i][j];
		}
	}
}

void makeDualArea(int areaNum, int townNum)
{
	for (int i = 0; i < areaNum; i++)
	{
		for (int j = 0; j < areaNum; j++)
		{
			if (i == j)
			{
				dualArea[i][j] = 0;
			}
			else
			{
				if (isAdj(i, j, townNum))
				{
					dualArea[i][j] = 1;
				}
				else
				{
					dualArea[i][j] = 1000;
				}
			}
		}
	}
}

bool isAdj(int a, int b, int townNum)
{
	int a_num = 0, b_num = 0;

	for (int i = 0; i < townNum; i++)
	{
		if (area[a][i] == 0)
		{
			break;
		}
		a_num++;
	}

	for (int i = 0; i < townNum; i++)
	{
		if (area[b][i] == 0)
		{
			break;
		}
		b_num++;
	}

	int a_first = area[a][a_num-1], a_second;
	int b_first, b_second;

	for (int i = 0; i < a_num; i++)
	{
		a_second = area[a][i];
		b_first = area[b][b_num - 1];
		for (int j = 0; j < b_num; j++)
		{
			b_second = area[b][j];
			if ((a_first == b_first && a_second == b_second) || (a_first == b_second && a_second == b_first))
			{
				return true;
			}
			b_first = b_second;
		}
		a_first = a_second;
	}

	return false;
}

void peopleAdj(int areaNum, int townNum, int peopleNum)
{
	for (int k = 0; k < peopleNum; k++)
	{
		for (int i = 0; i < areaNum; i++)
		{
			for (int j = 0; j < areaNum; j++)
			{
				if (area[i][j] == 0)break;
				if (area[i][j] == people[k])
				{
					peopleAdjArea[k][i] = true;
					break;
				}
				else
				{
					peopleAdjArea[k][i] = false;
				}
			}
		}
	}
}

void floyd(int areaNum)
{
	for (int k = 0; k < areaNum; k++)
	{
		for (int i = 0; i < areaNum; i++)
		{
			for (int j = 0; j < areaNum; j++)
			{
				if (dualArea[i][j] > dualArea[i][k] + dualArea[k][j])
				{
					dualArea[i][j] = dualArea[i][k] + dualArea[k][j];
				}
			}
		}
	}
}

_minInfo findMinResult(int areaNum, int townNum, int peopleNum)
{
	minInfo tmpMin;
	tmpMin.minSum = 10000000;
	tmpMin.minPlace = 0;
	
	int tmpPeopleMinDis, tmpMinSum;

	for (int place = 0; place < areaNum; place++)
	{
		tmpMinSum = 0;
		for (int tmppeople = 0; tmppeople < peopleNum; tmppeople++)
		{
			tmpPeopleMinDis = 100000000;
			for (int adjArea = 0; adjArea < areaNum; adjArea++)
			{
				if (peopleAdjArea[tmppeople][adjArea] == true)
				{
					if (dualArea[place][adjArea] < tmpPeopleMinDis)
					{
						tmpPeopleMinDis = dualArea[place][adjArea];
					}
				}
			}
			tmpMinSum += tmpPeopleMinDis;
		}

//		cout << place + 1 << " : " << tmpMinSum << endl;
		if (tmpMinSum < tmpMin.minSum)
		{
			tmpMin.minPlace = place + 1;
			tmpMin.minSum = tmpMinSum;
		}
	}

	return tmpMin;
}

void test(int areaNum, int townNum, int peopleNum)
{
	/*
	int people[30];
	bool peopleAdjArea[30][200];
	bool area[200][250];
	int dualArea[200][200];
	*/
	for (int i = 0; i < peopleNum; i++)
	{
		cout << i << " : " << people[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < peopleNum; i++)
	{
		cout << endl;
		for (int j = 0; j < areaNum; j++)
		{
			cout << peopleAdjArea[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < areaNum; i++)
	{
		cout << endl;
		for (int j = 0; j < townNum; j++)
		{
			cout << area[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < areaNum; i++)
	{
		cout << endl;
		for (int j = 0; j < areaNum; j++)
		{
			cout << dualArea[i][j];
		}
	}
}

int main()
{
	int areaNum, townNum, peopleNum;
	_minInfo minInfo;

	cin >> areaNum >> townNum >> peopleNum;

	for (int i = 0; i < peopleNum; i++)
	{
		cin >> people[i];
	}

	initializeArea(areaNum, townNum);
	makeDualArea(areaNum, townNum);
	
	/*
	cout << endl;
	for (int i = 0; i < areaNum; i++)
	{
		cout << endl;
		for (int j = 0; j < areaNum; j++)
		{
			printf("%5d  ", dualArea[i][j]);
			//cout << dualArea[i][j];
		}
	}*/
	peopleAdj(areaNum, townNum, peopleNum);
	floyd(areaNum);

	minInfo = findMinResult(areaNum, townNum, peopleNum);

	cout << minInfo.minSum << endl;
	cout << minInfo.minPlace << endl;

//	test(areaNum, townNum, peopleNum);

	return 0;
}