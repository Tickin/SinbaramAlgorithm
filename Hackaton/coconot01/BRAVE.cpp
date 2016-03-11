#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
	int testCase; cin >> testCase;
	vector<int>* board[100001];
	while (testCase--)
	{
		int N; cin >> N;
		int M; cin >> M;
		memset(board, 0, sizeof(board));
		for (int i = 0; i < M; i++)
		{
			int x, y; cin >> x >> y;

			if (board[x] == 0 && board[y] == 0)
			{
				board[x] = new vector<int>();
				board[y] = board[x];
				board[x]->push_back(x);
				board[x]->push_back(y);
			}
			else if (board[x] == 0)
			{
				board[x] = board[y];
				board[y]->push_back(x);
			}
			else if (board[y] == 0)
			{
				board[y] = board[x];
				board[x]->push_back(y);
			}
			else if (board[x] != board[y])
			{
				for (vector<int>::iterator it = board[x]->begin(); it != board[x]->end(); ++it)
				{
					board[y]->push_back(*it);
				}
				vector<int>* tmp = board[x];
				for (vector<int>::iterator it = tmp->begin(); it != tmp->end(); it++)
				{
					board[*it] = board[y];
				}
				delete tmp;
			}
		}

		int maxSize = 0;
		for (int i = 1; i < N; i++)
		{
			if (board[i])
			{
				maxSize = max(maxSize,(int)board[i]->size());
			}
		}

		cout << maxSize << endl;
	}
	return 0;
}