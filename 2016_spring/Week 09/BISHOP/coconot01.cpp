#include <iostream>
#include <vector>
#define MAX_A 64
#define MAX_B 64

using namespace std;

int N;
int chessBoard[8][8][3]; //x,y, 3thins(isPossible?, leftID, rightID)

int aNum, bNum;
bool adj[MAX_A][MAX_B];

vector<int> match_A;
vector<int> match_B;
vector<bool> visit;

bool dfs(int a)
{
	if (visit[a]) return false;
	visit[a] = true;
	for (int b = 0; b < bNum; b++)
	{
		if (adj[a][b])
		{
			if (match_B[b] == -1 || dfs(match_B[b]))
			{
				match_A[a] = b;
				match_B[b] = a;
				return true;
			}
		}
	}
	return false;
}

int bipartite()
{
	match_A = vector<int>(aNum, -1);
	match_B = vector<int>(bNum, -1);
	int size = 0;
	for (int start = 0; start < aNum; start++)
	{
		visit = vector<bool>(aNum, false);
		if (dfs(start)) size++;
	}
	return size;
}

void setID(int x, int y, int leftID)
{
	for (int i = 1; i < N; i++)
	{
		if (x - i >= 0 && y + i < N)
		{
			if (chessBoard[x - i][y + i][0] == 1) break;
			chessBoard[x - i][y + i][1] = leftID;
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (x + i < N && y - i >= 0)
		{
			if (chessBoard[x + i][y - i][0] == 1) break;
			chessBoard[x + i][y - i][1] = leftID;
		}
	}
}

void adjID(int x, int y, int rightID)
{
	adj[chessBoard[x][y][1]][rightID] = true;
	for (int i = 1; i < N; i++)
	{
		if (x - i >= 0 && y - i >= 0)
		{
			if (chessBoard[x - i][y - i][0] == 1) break;
			adj[chessBoard[x - i][y - i][1]][rightID] = true;
			chessBoard[x - i][y - i][2] = rightID;
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (x + i < N && y + i < N)
		{
			if (chessBoard[x + i][y + i][0] == 1) break;
			adj[chessBoard[x + i][y + i][1]][rightID] = true;
			chessBoard[x + i][y + i][2] = rightID;
		}
	}
}

int checkBoard()
{
	int leftID = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (chessBoard[i][j][0] == 0 && chessBoard[i][j][1] > leftID)
			{
				chessBoard[i][j][1] = leftID;
				setID(i, j, leftID);
				leftID++;
			}
		}
	}

	int rightID = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (chessBoard[i][j][0] == 0 && chessBoard[i][j][2] > rightID)
			{
				chessBoard[i][j][2] = rightID;
				adjID(i, j, rightID);
				rightID++;
			}
		}
	}

	aNum = leftID;
	bNum = rightID;

	return bipartite();
}

int main()
{
	int testCase; cin >> testCase;

	while (testCase--)
	{
		char tmpinput;
		cin >> N;
		for (int i = 0; i < MAX_A; i++)
		{
			for (int j = 0; j < MAX_B; j++)
			{
				adj[i][j] = false;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> tmpinput;
				chessBoard[i][j][1] = MAX_A;
				chessBoard[i][j][2] = MAX_B;
				if (tmpinput == '.') chessBoard[i][j][0] = 0;
				else chessBoard[i][j][0] = 1;
			}
		}
		cout << checkBoard() << endl;
	}

	return 0;
}