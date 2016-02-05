#include<iostream>
#include<cstdlib>

using namespace std;

int mycomp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int linkBoard[100][100];
	int confNum = 0;
	int confMemNum[100];
	int confMember[100][100];
	bool isUsedPerson[100];
	int people, link;
	int firstPerson, secondPerson;
	int bossNum[100];

	cin >> people >> link;

	for (int i = 0; i < people; i++)
	{
		for (int j = 0; j < people; j++)
		{
			if (i == j)
			{
				linkBoard[i][j] = 0;
			}
			else
			{
				linkBoard[i][j] = 1000;
			}
		}
	}

	for (int i = 0; i < link; i++)
	{
		cin >> firstPerson >> secondPerson;
		linkBoard[firstPerson-1][secondPerson-1] = 1;
		linkBoard[secondPerson-1][firstPerson-1] = 1;
	}

	int tmpLink;
	for (int k = 0; k < people; k++)
	{
		for (int i = 0; i < people; i++)
		{
			for (int j = 0; j < people; j++)
			{
				tmpLink = linkBoard[i][k] + linkBoard[k][j];
				if (linkBoard[i][j] > tmpLink)
				{
					linkBoard[i][j] = tmpLink;
				}
			}
		}
	}
	/*
	for (int i = 0; i < people; i++)
	{
		cout << endl;
		for (int j = 0; j < people; j++)
		{
			printf("%5d ", linkBoard[i][j]);
			//cout << linkBoard[i][j];
		}
	}*/

	for (int i = 0; i < 100; i++)
	{
		isUsedPerson[i] = false;
	}
	
	for (int i = 0; i < people; i++)
	{
		if (isUsedPerson[i] == false)
		{
			confMemNum[confNum] = 0;
			for (int j = 0; j < people; j++)
			{
				if (linkBoard[i][j] != 1000)
				{
					confMember[confNum][confMemNum[confNum]] = j;
					confMemNum[confNum]++;
					isUsedPerson[j] = true;
				}
			}
			confNum++;
		}
	}

	cout << confNum << endl;

	int realMin, tmpMin, minMem;
	for (int i = 0; i < confNum; i++)
	{
		realMin = 10000;
		minMem = 1000;
		for (int j = 0; j < confMemNum[i]; j++)
		{
			tmpMin = 0;
			for (int k = 0; k < confMemNum[i]; k++)
			{
				tmpMin += linkBoard[confMember[i][j]][confMember[i][k]];
			}
			if (realMin > tmpMin)
			{
				realMin = tmpMin;
				minMem = confMember[i][j];
			}
		}
		bossNum[i] = minMem + 1;
	}

	qsort(bossNum, confNum, 4, mycomp);

	for (int i = 0; i < confNum; i++)
	{
		cout << bossNum[i] << endl;
	}

	return 0;
}