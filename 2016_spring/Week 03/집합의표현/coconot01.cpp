#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int cache[1000001];

int findRoot(int start)
{
	while (cache[start] != start)
	{
		start = cache[start];
	}
	return start;
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i <= N; i++)
	{
		cache[i] = i;
	}
	int operation, aPoint, bPoint;
	while (M--){
		scanf("%d %d %d", &operation, &aPoint, &bPoint);
		if (operation == 0){
			int aRoot = findRoot(aPoint);
			int bRoot = findRoot(bPoint);
			if (aRoot == bRoot) {
				continue;
			}
			else if (aRoot < bRoot) {
				cache[bRoot] = aRoot;
			}
			else {
				cache[aRoot] = bRoot;
			}
		}
		else {
			if (findRoot(aPoint) == findRoot(bPoint)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}