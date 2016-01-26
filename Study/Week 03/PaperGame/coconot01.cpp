#include <iostream>

using namespace std;

int board[2200][2200];
int numOfMinus = 0;
int numOfZero = 0;
int numOfPlus = 0;

void calculate(int row, int col, int size)
{
	int base = board[row][col];
	if (size == 1)
	{
		if (base == -1) numOfMinus++;
		else if (base == 0) numOfZero++;
		else if (base == 1) numOfPlus++;
		return;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (board[row + i][col + j] != base)
				{
					calculate(row, col, size / 3);
					calculate(row, col + (size / 3), size / 3);
					calculate(row, col + (size / 3) * 2, size / 3);
					calculate(row + (size / 3), col, size / 3);
					calculate(row + (size / 3), col + (size / 3), size / 3);
					calculate(row + (size / 3), col + (size / 3) * 2, size / 3);
					calculate(row + (size / 3) * 2, col, size / 3);
					calculate(row + (size / 3) * 2, col + (size / 3), size / 3);
					calculate(row + (size / 3) * 2, col + (size / 3) * 2, size / 3);
					return;
				}
			}
		}
		if (base == -1) numOfMinus ++;
		else if (base == 0) numOfZero ++;
		else if (base == 1) numOfPlus ++;
		return;
	}
	
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	calculate(0,0,n);

	cout << numOfMinus << endl;
	cout << numOfZero << endl;
	cout << numOfPlus << endl;

	return 0;
}