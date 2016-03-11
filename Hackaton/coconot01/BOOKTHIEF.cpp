#include <iostream>
#include <stdlib.h>
using namespace std;

struct book {
	int size;
	int value;
	int num;
};

int cache[10001];
book books[100];

int mycomp(const void* a, const void* b)
{
	book* tmpA = (book*)a;
	book* tmpB = (book*)b;

	double rateA = (double)tmpA->value / tmpA->size;
	double rateB = (double)tmpB->value / tmpB->size;

	if (rateA == rateB)
	{
		return tmpB->num - tmpA->num;
	}
	else if(rateA > rateB)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

void initializeCache(int V)
{
	for (int i = 0; i < V + 1; i++)
	{
		cache[i] = 0;
	}
}

int getResult(int N, int V)
{
	int tmpNum;
	for (int i = 0; i < N; i++)
	{
		for (int k = V; k >= books[i].size; k--)
		{
			tmpNum = cache[k];
			for (int j = 0; j < books[i].num + 1; j++)
			{
				if (k - (books[i].size*j) < 0) break;
				else if (tmpNum < cache[k - (books[i].size*j)] + books[i].value*j) tmpNum = cache[k - (books[i].size*j)] + books[i].value*j;
			}
			cache[k] = tmpNum;
		}
	}

	return cache[V];
}

int main()
{
	int testCase; cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int N, V; cin >> N >> V;
		initializeCache(V);
		for (int i = 0; i < N; i++)
		{
			cin >> books[i].size >> books[i].value >> books[i].num;
		}

		qsort(books, N, (sizeof(int)) * 3, mycomp);

		cout << getResult(N, V) << endl;
	}
	return 0;
}