#include<iostream>

using namespace std;

int board[20000];

int getmax(int start, int end)
{
	if (start == end - 1)
	{
		return board[start];
	}
	else
	{
		int boundary = (end + start) / 2;
		int left = getmax(start, boundary);
		int right = getmax(boundary, end);

		int height = board[boundary];
		int width = 1;
		int tmpmax = board[boundary];
		int max = tmpmax;

		int leftBoard = boundary, rightBoard = boundary;
		bool leftinc = true, rightinc = true;
		while (1)
		{
			if (leftinc == true)
			{
				if (leftBoard - 1 >= start) leftBoard -= 1;
				else leftinc = false;
			}
			if (rightinc == true)
			{
				if (rightBoard + 1 < end) rightBoard += 1;
				else rightinc = false;
			}

			if (leftinc == true)
			{
				if (rightinc == true)
				{
					if (board[leftBoard] > height)
					{
						width++;
						rightBoard--;
						tmpmax = height * width;
						if (tmpmax > max) max = tmpmax;
					}
					else if (board[rightBoard] > height)
					{
						width++;
						leftBoard++;
						tmpmax = height * width;
						if (tmpmax > max) max = tmpmax;
					}
					else if (board[leftBoard] > board[rightBoard])
					{
						width++;
						height = board[leftBoard];
						rightBoard--;
						tmpmax = height * width;
						if (tmpmax > max) max = tmpmax;
					}
					else
					{
						width++;
						height = board[rightBoard];
						leftBoard++;
						tmpmax = height * width;
						if (tmpmax > max) max = tmpmax;
					}
				}
				else
				{
					if (board[leftBoard] > height)
					{
						width++;
						tmpmax = height * width;
						if (tmpmax > max) max = tmpmax;
					}
					else
					{
						width++;
						height = board[leftBoard];
						tmpmax = height * width;
						if (tmpmax > max) max = tmpmax;
					}
				}
			}
			else
			{
				if (rightinc == true)
				{
					if (board[rightBoard] > height)
					{
						width++;
						tmpmax = height * width;
						if (tmpmax > max) max = tmpmax;
					}
					else
					{
						width++;
						height = board[rightBoard];
						tmpmax = height * width;
						if (tmpmax > max) max = tmpmax;
					}
				}
				else
				{
					break;
				}
			}

		}

		if (left > max) max = left;
		if (right > max) max = right;
		return max;
	}
	
}

int main()
{
	int testCase;
	int boardNum;
	cin >> testCase;

	for (int test = 0; test < testCase; test++)
	{
		cin >> boardNum;
		for (int i = 0; i < boardNum; i++)
		{
			cin >> board[i];
		}

		cout << getmax(0, boardNum) << endl;

	}

	return 0;
}