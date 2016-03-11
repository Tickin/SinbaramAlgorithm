#include <iostream>
#include <stdlib.h>
using namespace std;

struct slope {
	int start;
	int end;
	int weight;
};

int cache[50000][101];  // N * S
slope inputSlope[100000];
void initialize_cache(int N, int S)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < S + 1; j++)
		{
			cache[i][j] = 0;
		}
	}
}
int mycomp(const void* a, const void* b)
{
	slope* tmpA = (slope*)a;
	slope* tmpB = (slope*)b;

	if (tmpA->start == tmpB->start) {
		if (tmpA->end == tmpB->end) {
			return tmpA->weight - tmpB->weight;
		}
		else {
			return tmpA->end - tmpB->end;
		}
	}
	else {
		return tmpA->start - tmpB->start;
	}
}

int getResult(int N, int M, int S)
{
	int tmpResult, result = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < S; j++)
		{
			tmpResult = cache[inputSlope[i].start-1][j] + inputSlope[i].weight;
			if (cache[inputSlope[i].end-1][j + 1] < tmpResult) {
				cache[inputSlope[i].end-1][j + 1] = tmpResult;
				if (cache[inputSlope[i].end - 1][j + 1] > result) {
					result = cache[inputSlope[i].end - 1][j + 1];
				}
			}
		}
	}
	return result;
}

int main()
{
	int testCase; cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int N, M, S; cin >> N >> M >> S;
		initialize_cache(N,S);
		for (int i = 0; i < M; i++)
		{
			cin >> inputSlope[i].start >> inputSlope[i].end >> inputSlope[i].weight;
		}

		qsort(inputSlope, M, sizeof(slope), mycomp);

		cout << getResult(N, M, S) << endl;

	}

	return 0;
}