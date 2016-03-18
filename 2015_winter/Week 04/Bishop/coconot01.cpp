#include<iostream>

using namespace std;

int oddBoard[10][10];
int evenBoard[10][10];
//int board[10][10];
int realMax = 0;
int tmpMax = 0;
int n = 0;

void addBoard(int board[10][10], int row, int col)
{
	tmpMax++;
	board[row][col]++;
	for (int i = 1; i < n; i++)
	{
		if (col - i >= 0 && row - i >= 0) board[row - i][col - i]++;
		if (col - i >= 0 && row + i <= n) board[row + i][col - i]++;
		if (col + i <= n && row - i >= 0) board[row - i][col + i]++;
		if (col + i <= n && row + i <= n) board[row + i][col + i]++;
	}
}

void backBoard(int board[10][10], int row, int col)
{
	tmpMax--;
	board[row][col]--;
	for (int i = 1; i < n; i++)
	{
		if (col - i >= 0 && row - i >= 0) board[row - i][col - i]--;
		if (col - i >= 0 && row + i <= n) board[row + i][col - i]--;
		if (col + i <= n && row - i >= 0) board[row - i][col + i]--;
		if (col + i <= n && row + i <= n) board[row + i][col + i]--;
	}
}

void checkBoard(int board[10][10], int row, int col)
{
	bool check = false;
	for (int i = row; i < n; i++)
	{
		if (i == row)
		{
			for (int j = col; j < n; j++)
			{
				if (board[i][j] == 0)
				{
					check = true;
					addBoard(board, i, j);
					checkBoard(board, i, j);
				}
			}
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 0)
				{
					check = true;
					addBoard(board, i, j);
					checkBoard(board, i, j);
				}
			}
		}
	}
	if (check == false)
	{
		if (tmpMax > realMax) realMax = tmpMax;
	}
	backBoard(board, row, col);
}

int main()
{
	int tmp, finalMax;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			if (tmp == 0)
			{
				if ((i + j) % 2 == 1)
				{
					oddBoard[i][j] = 1;
					evenBoard[i][j] = 1;
				}
				else
				{
					evenBoard[i][j] = 1;
					oddBoard[i][j] = 1;
				}
			}
			else
			{
				if ((i + j) % 2 == 1)
				{
					oddBoard[i][j] = 0;
					evenBoard[i][j] = 1;
				}
				else
				{
					evenBoard[i][j] = 0;
					oddBoard[i][j] = 1;
				}
			}
		}
	}

	checkBoard(oddBoard, 0, 0);
	finalMax = realMax;
	realMax = 0;
	tmpMax = 0;
	checkBoard(evenBoard, 0, 0);
	finalMax += realMax;
	cout << finalMax;
	return 0;
}