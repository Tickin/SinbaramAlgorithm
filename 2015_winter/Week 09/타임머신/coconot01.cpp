#include<iostream>
#define INFI 1000000000

using namespace std;
int cityTocity[500][500];
int result[500];

bool bellman(int cityNum)
{
	result[0] = 0;
	for (int i = 1; i < cityNum; i++)
	{
		result[i] = INFI;
	}

	for (int k = 0; k < cityNum; k++)
	{
		for (int i = 0; i < cityNum; i++)
		{
			for (int j = 0; j < cityNum; j++)
			{
				if (cityTocity[i][j] != INFI)
				{
					if ((result[j] > result[i] + cityTocity[i][j]))
					{
						result[j] = result[i] + cityTocity[i][j];
					}
				}
			}
		}
	}

	for (int i = 0; i < cityNum; i++)
	{
		for (int j = 0; j < cityNum; j++)
		{
			if (cityTocity[i][j] != INFI)
			{
				if (result[j] > result[i] + cityTocity[i][j])
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	int cityNum; cin >> cityNum;
	int busNum; cin >> busNum;

	for (int i = 0; i < cityNum; i++)
	{
		for (int j = 0; j < cityNum; j++)
		{
			cityTocity[i][j] = INFI;
			if (i == j) cityTocity[i][j] = 0;
		}
	}

	int cityA, cityB, spendTime;
	for (int i = 0; i < busNum; i++)
	{
		cin >> cityA >> cityB >> spendTime;
		if (cityTocity[cityA - 1][cityB - 1] > spendTime)
		{
			cityTocity[cityA - 1][cityB - 1] = spendTime;
		}
	}

	if (!bellman(cityNum))
	{
		cout << -1 << endl;
	}
	else
	{
		for (int i = 1; i < cityNum; i++)
		{
			if (result[i] == INFI) cout << -1 << endl;
			else cout << result[i] << endl;
		}
	}
	return 0;
}