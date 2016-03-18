#include <iostream>

using namespace std;
int board[50];
int cache[50][50];
int n, left, right;

int max(int x, int y)
{
	if (x < y)return y;
	else return x;
}

int numberGame(int left, int right)
{
	int ret = cache[left][right];
	if (ret != -2000000000) return ret;
	if (left > right) return 0;

	ret = max(board[left] - numberGame(left + 1, right), board[right] - numberGame(left, right - 1));

	if (right - left >= 2)
	{
		ret = max(ret, -numberGame(left + 2, right));
		ret = max(ret, -numberGame(left, right - 2));
	}

	cache[left][right] = ret;
	return ret;
}

int main()
{
	int caseT;
	cin >> caseT;

	for (int T = 0; T < caseT; T++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> board[i];
			for (int j = 0; j < n; j++)
			{
				cache[i][j] = -2000000000;
			}
		}

		cout << numberGame(0, n - 1) << endl;
	}

	return 0;
}