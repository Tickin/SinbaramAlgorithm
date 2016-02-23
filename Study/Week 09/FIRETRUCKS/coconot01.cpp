#include <iostream>
#include <queue>
#include <vector>

#define INFI 1000000000
using namespace std;

int placeToplace[1000][1000];
int result[1000];
int firePlace[1000];

void dijkstra(int firePlaceNum, int fireStationNum, int placeNum)
{
	for (int i = 0; i < firePlaceNum; i++)
	{
		cin >> firePlace[i];
	}
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < placeNum; i++) result[i] = INFI;
	int tmpPlace;
	for (int i = 0; i < fireStationNum; i++) {
		cin >> tmpPlace;
		result[tmpPlace - 1] = 0;
		pq.push(make_pair(0, tmpPlace));
	}
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second - 1;
		pq.pop();

		if (result[here] < cost) continue;

		for (int i = 0; i < placeNum; i++)
		{
			if (placeToplace[here][i] != INFI)
			{
				int there = i;
				int nextDist = cost + placeToplace[here][i];
				if (result[there] > nextDist)
				{
					result[there] = nextDist;
					pq.push(make_pair(-nextDist, there + 1));
				}
			}
		}
	}

}

int main()
{
	int testCase; cin >> testCase;
	for (; testCase > 0; testCase--)
	{
		int placeNum; cin >> placeNum;
		int roadNum; cin >> roadNum;
		int firePlaceNum; cin >> firePlaceNum;
		int fireStationNum; cin >> fireStationNum;

		int startPlace, endPlace, spendTime;
		for (int i = 0; i < placeNum; i++)
		{
			for (int j = 0; j < placeNum; j++)
			{
				placeToplace[i][j] = INFI;
			}
		}
		for (int i = 0; i < roadNum; i++)
		{
			cin >> startPlace >> endPlace >> spendTime;
			placeToplace[startPlace-1][endPlace-1] = spendTime;
			placeToplace[endPlace-1][startPlace-1] = spendTime;
		}

		dijkstra(firePlaceNum,fireStationNum,placeNum);

		int minSum = 0;
		for (int i = 0; i < firePlaceNum; i++)
		{
			minSum += result[firePlace[i] - 1];
		}

		cout << minSum << endl;
	}
	return 0;
}