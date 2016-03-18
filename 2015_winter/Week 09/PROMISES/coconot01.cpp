#include<iostream>
#include<algorithm>
#define INFI 1000000000
using namespace std;

int highWayDis[200][200];

void ployd(int cityNum)
{
	bool result = false;
	for (int k = 0; k < cityNum; k++)
	{
		for (int i = 0; i < cityNum; i++)
		{
			for (int j = 0; j < cityNum; j++)
			{
				if (highWayDis[i][j] > highWayDis[i][k] + highWayDis[k][j])
				{
					highWayDis[i][j] = highWayDis[i][k] + highWayDis[k][j];
				}
			}
		}
	}
}

void ployd2(int cityNum, int startCity, int endCity)
{
	int case1, case2, case3;
	for (int i = 0; i < cityNum; i++)
	{
		for (int j = 0; j < cityNum; j++)
		{
			case1 = highWayDis[i][j];
			case2 = highWayDis[i][startCity] + highWayDis[endCity][j] + highWayDis[startCity][endCity];
			case3 = highWayDis[i][endCity] + highWayDis[startCity][j] + highWayDis[startCity][endCity];

			highWayDis[i][j] = min(case1,min(case2,case3));

		}
	}
}

int main()
{
	int testCase; cin >> testCase;
	for (; testCase > 0; testCase--)
	{
		int cityNum; cin >> cityNum;
		int curWayNum; cin >> curWayNum;
		int newWayNum; cin >> newWayNum;

		for (int i = 0; i < cityNum; i++)
		{
			for (int j = 0; j < cityNum; j++)
			{
				highWayDis[i][j] = INFI;
				if (i == j) highWayDis[i][j] = 0;
			}
		}

		int startCity, endCity, spendTime;
		for (int i = 0; i < curWayNum; i++)
		{
			cin >> startCity >> endCity >> spendTime;
			highWayDis[startCity][endCity] = spendTime;
			highWayDis[endCity][startCity] = spendTime;
		}
		ployd(cityNum);

		int noWaySum = 0;
		int tmpTime;
		for (int i = 0; i < newWayNum; i++)
		{
			cin >> startCity >> endCity >> spendTime;
			tmpTime = highWayDis[startCity][endCity];
			if (tmpTime > spendTime)
			{
				highWayDis[startCity][endCity] = spendTime;
				highWayDis[endCity][startCity] = spendTime;
				ployd2(cityNum, startCity, endCity);
			}
			else
			{
				noWaySum++;
			}
		}
		cout << noWaySum << endl;
	}
	return 0;
}