#include<iostream>

using namespace std;

int main()
{
	bool board[100][100];
	int cmpNum, linkNum;
	int tmpSend, tmpReceive, result = 0;

	cin >> cmpNum;
	cin >> linkNum;

	for (int i = 0; i < cmpNum; i++)
	{
		for (int j = 0; j < cmpNum; j++)
		{
			if (i == j) board[i][j] = true;
			else board[i][j] = false;
		}
	}

	for (int i = 0; i < linkNum; i++)
	{
		cin >> tmpSend >> tmpReceive;
		board[tmpSend - 1][tmpReceive - 1] = true;
		board[tmpReceive - 1][tmpSend - 1] = true;
	}

	for (int k = 0; k < cmpNum; k++)
	{
		for (int i = 0; i < cmpNum; i++)
		{
			for (int j = 0; j < cmpNum; j++)
			{
				if (board[i][k] == true && board[k][j] == true)
				{
					board[i][j] = true;
				}
			}
		}
	}
	
	for (int i = 1; i < cmpNum; i++)
	{
		if (board[0][i] == true)
		{
			result++;
		}
	}

	cout << result << endl;

	return 0;
}