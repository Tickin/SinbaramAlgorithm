#include <iostream>
using namespace std;

short lengthBoard[100][100];
bool probBoard[100][100];

int main(void) {
	int testCase;
	int size;

	cin >> testCase;

	for (int test = 0; test < testCase; test++) {
		cin >> size;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cin >> lengthBoard[i][j];
				probBoard[i][j] = false;
			}
		}

		probBoard[0][0] = true;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (probBoard[i][j] == true)
				{
					if ((j + lengthBoard[i][j] < size))
						probBoard[i][j + lengthBoard[i][j]] = true;

					if ((i + lengthBoard[i][j] < size))
						probBoard[i + lengthBoard[i][j]][j] = true;
				}
			}
		}

		if (probBoard[size - 1][size - 1])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
