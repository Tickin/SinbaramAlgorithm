#include <iostream>

using namespace std;
int RGBprice[1000][3];
int RGBdistance[1000][3];

int min(int x, int y)
{
	if (x > y) return y;
	else return x;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> RGBprice[i][j];
		}
	}
	RGBdistance[0][0] = RGBprice[0][0];
	RGBdistance[0][1] = RGBprice[0][1];
	RGBdistance[0][2] = RGBprice[0][2];
	for (int i = 1; i < n; i++)
	{
		RGBdistance[i][0] = min(RGBdistance[i - 1][1] + RGBprice[i][0], RGBdistance[i - 1][2] + RGBprice[i][0]);
		RGBdistance[i][1] = min(RGBdistance[i - 1][0] + RGBprice[i][1], RGBdistance[i - 1][2] + RGBprice[i][1]);
		RGBdistance[i][2] = min(RGBdistance[i - 1][0] + RGBprice[i][2], RGBdistance[i - 1][1] + RGBprice[i][2]);
	}

	if (RGBdistance[n - 1][0] < RGBdistance[n - 1][1])
	{
		if (RGBdistance[n - 1][0] < RGBdistance[n - 1][2]) cout << RGBdistance[n - 1][0];
		else cout << RGBdistance[n - 1][2];
	}
	else
	{
		if (RGBdistance[n - 1][1] < RGBdistance[n - 1][2]) cout << RGBdistance[n - 1][1];
		else cout << RGBdistance[n - 1][2];
	}
	return 0;
}