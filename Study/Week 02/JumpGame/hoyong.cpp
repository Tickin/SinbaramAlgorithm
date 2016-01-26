#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	int mat[100][100];
	int mat2[100][100];
	int count;
	int size;
	//ifstream fin("i.inp");
	//ofstream fout("i.out");
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> size;
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				cin >> mat[j][k];
				mat2[j][k] = 0;
			}
		}


		int x = 0, y = 0;
		mat2[0][0] = 1;
		int idx =0;
		int key = 0;
		int l,m;
		for (int k = 0; k < size; k++)
		{
			for (int j = 0; j < size; j++)
			{
				if (mat2[j][k] == 1)
				{
					idx = mat[j][k];
					x = j + idx;
					y = k + idx;
					if (x < size)
					{
						mat2[x][k] = 1;
					}
					if (y < size)
					{
						mat2[j][y] = 1;
					}
				}
			}
		}

			if (mat2[size-1][size-1] == 1)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}




			


	}
}