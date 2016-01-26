#include <iostream>
#include <fstream>

using namespace std;

void cut(int **board, int size, int px, int py, int **result);
bool equalBox(int** board, int size, int px, int py);

int main() {
	fstream fin("paper.inp");

	int size;
	fin >> size;

	int** board = new int*[size];
	for (int i = 0; i < size; i++)
		board[i] = new int[size];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			fin >> board[i][j];
	}

	int* result = new int[3];
	for (int i = 0; i < 3; i++)
		result[i] = 0;

	cut(board, size, 0, 0, &result);

	for (int i = 0; i < 3; i++)
		cout << result[i] << endl;
}

void cut(int **board, int size, int px, int py, int **result) {
	if (equalBox(board, size, px, py))
		(*result)[board[px][py] + 1]++;
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cut(board, size / 3, px + (size / 3)*i, py + (size / 3)*j, result);
			}
		}
	}
}

bool equalBox(int** board, int size, int px, int py) {
	int sample = board[px][py];

	for (int i = px; i < px + size; i++) {
		for (int j = py; j < py + size; j++) {
			if (board[i][j] != sample)
				return false;
		}
	}
	return true;
}
