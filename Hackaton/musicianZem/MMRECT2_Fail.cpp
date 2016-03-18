#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
struct Point{ 
	int x, y;
	Point( int _x=0, int _y=0 ) {
		x = _x; y = _y;
	}
};
Point pt[ 20000 ];
int testCase, N, maxSize=0, minSize=300000, x, y, i, j, findr;
Point p;
int main() {
	scanf("%d", &testCase);
	while( testCase -- ) {
		scanf("%d", &N);
		for(i=0; i<N; i++) {
			scanf("%d%d", &x, &y);
			p.x = x; p.y = y;
			pt[i] = p;
		}
		for(i=1; i<N; i++) {
			for(j=0; j<i; j++) {
				if( pt[i].x - pt[j].x == pt[i].y - pt[j].y || pt[i].x - pt[j].x == pt[i].y + pt[j].y ) {
					findr = pt[i].x - pt[j].y;
					if( findr == 0 ) findr = pt[i].x + pt[j].x;
					if( findr < 0 ) findr *= -1;
					if( maxSize < findr ) maxSize = findr;
					if( minSize > findr ) minSize = findr;
				}
			}
		}
		printf("%d %d\n", minSize, maxSize);
	}

	return 0;
}