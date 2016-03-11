#include<iostream>

using namespace std;

int townToTown[50][50];

int main()
{
	int testCase; cin >> testCase;

	for (; testCase; testCase--)
	{
		int townNum; cin >> townNum;
		int totalDay; cin >> totalDay;
		int startTown; cin >> startTown;
		double result[50];
		double tmpResult[50];

		for (int i = 0; i < townNum; i++)
		{
			for (int j = 0; j < townNum; j++)
			{
				cin >> townToTown[i][j];;
			}
			result[i] = 0;
			tmpResult[i] = 0;
		}

		result[startTown] = 1;
		
		for (int k = 0; k < totalDay; k++)
		{
			for (int i = 0; i < townNum; i++)
			{
				int totalWay = 0;
				for (int j = 0; j < townNum; j++)
				{
					if (townToTown[i][j] == 1)
					{
						totalWay++;
					}
				}

				for (int j = 0; j < townNum; j++)
				{
					if (townToTown[i][j] == 1)
					{
						tmpResult[j] += result[i] / totalWay;
					}
				}
			}
			for (int j = 0; j < townNum; j++)
			{
				result[j] = tmpResult[j];
				tmpResult[j] = 0;
			}
		}
		
		int getRateNum; cin >> getRateNum;
		int getRateTown[50];
		for (int i = 0; i < getRateNum; i++)
		{
			cin >> getRateTown[i];
		}

		for (int i = 0; i < getRateNum; i++)
		{
			printf("%0.8f\n", result[getRateTown[i]]);
		}
	}

	return 0;
}