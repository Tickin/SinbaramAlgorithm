#include <iostream>
#include <cstring>
using namespace std;
int injub[50][50];
int findPoint[50];
double calbefore[50];
double cal_after[50];
int cango[50];
// 마을수50 일수100
int main() {
	int testCase; cin >> testCase;
	while( testCase-- ) {
		int pointCount, dayCount, start;
		cin >> pointCount >> dayCount >> start;
		memset( injub, 0, sizeof(injub));
		memset( findPoint, 0, sizeof( findPoint ) );
		

		for(int i=0; i<pointCount; i++) {
			for(int j=0; j<pointCount; j++) {
				cin >> injub[i][j];
			}
		}
		int findCount; cin >> findCount;
		for(int i=0; i<findCount; i++) {
			cin >> findPoint[i];
		}
		for(int i=0; i<pointCount; i++) {
			int sum = 0;
			for(int j=0; j<pointCount; j++) {
				if( injub[i][j] ) sum++;
			}
			cango[i] = sum;
			calbefore[i] = 0;
			cal_after[i] = 0;
		}
		calbefore[start] = 1;

		for(int i=0; i<dayCount; i++) {
			for(int j=0; j<pointCount; j++) {
				for(int k=0; k<pointCount; k++) {
					if( injub[j][k] ) 
						cal_after[j] += calbefore[k]/cango[k];
				}
			}

			for(int j=0; j<pointCount; j++) {
				calbefore[j] = cal_after[j];
				cal_after[j] = 0;
			}
		}
		for(int i=0; i<findCount; i++) {
			printf("%.8f ", calbefore[findPoint[i]]);
		}cout << endl;
	}

	return 0;
}