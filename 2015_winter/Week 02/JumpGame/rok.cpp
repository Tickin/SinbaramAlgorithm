#include <fstream>
#include <iostream>

using namespace std;

void findRoute(int **board, bool ***result, int size, int start, int end);

int main() {
	//ifstream fin("jumpgame.inp");
	int runNum, size;
	cin >> runNum;

	for (int run = 0; run < runNum; run++) {
		cin >> size;
		int **board = new int*[size];
		for (int i = 0; i < size; i++)
			board[i] = new int[size];

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				cin >> board[i][j];
		}

		bool **result = new bool*[size];
		for (int i = 0; i < size; i++)
			result[i] = new bool[size];

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				result[i][j] = false;
		}

		findRoute(board, &result, size, 0, 0);

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
			cout << result[i][j] << " ";
			}
			cout << endl;
			}

		if (result[size - 1][size - 1] == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		delete[] board, result;
	}
	return 0;
}

void findRoute(int **board, bool ***result, int size, int px, int py) {
	(*result)[px][py] = true;

	if (px + board[px][py] < size) {
		if ((*result)[px + board[px][py]][py] == false)
			findRoute(board, result, size, px + board[px][py], py);
	}

	if (py + board[px][py] < size) {
		if ((*result)[px][py + board[px][py]] == false)
			findRoute(board, result, size, px, py + board[px][py]);
	}
}