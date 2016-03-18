#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int>* hapchu[100001];
	int testCase; cin >> testCase;
	while( testCase -- ) {
		memset( hapchu, 0, sizeof(hapchu) );
		int N, M; cin >> N >> M; // N point M line
		for( int i=0; i<M; i++ ) {
			int x, y; cin >> x >> y;

			if (hapchu[x] == 0 && hapchu[y] == 0) { // make new
				hapchu[x] = new vector<int>();
				hapchu[y] = hapchu[x];
				hapchu[x]->push_back(x);
				hapchu[x]->push_back(y);
			}
			
			else if (hapchu[x] == 0) { // Not new but x 0
				hapchu[x] = hapchu[y];
				hapchu[y]->push_back(x);
			}
			
			else if (hapchu[y] == 0) { // y 0
				hapchu[y] = hapchu[x];
				hapchu[x]->push_back(y);
			}
			
			else if (hapchu[x] != hapchu[y]) { // else
				for(vector<int>::iterator it = hapchu[y]->begin(); it != hapchu[y]->end(); it++ ) {
					hapchu[x]->push_back( *it ); // x에 y를
				}
				vector<int> *temp = hapchu[y];
				for (vector<int>::iterator it = temp->begin(); it != temp->end(); it++) {
					hapchu[*it] = hapchu[x];
				}
				delete temp;
			}

		} // pointer가 꼬리 향하게 수정해보기
		
		int maxSize = 0;
		
		for(int i=1; i<=N; i++) {
			if( hapchu[i] ) {
				maxSize = max(maxSize, (int)hapchu[i]->size());
			}
		}
		cout << maxSize << endl;
	}

	return 0;
}