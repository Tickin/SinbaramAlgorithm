#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <iterator>
#include <algorithm>
using namespace std;
struct Edge { int to, co; };
int a,b,c, visited[50000];
int sl[50000][111];
vector<Edge> linkd[50000];

int main(){
	int testCase; cin >> testCase;
	while( testCase-- ){ 
		int N, M, S; cin >> N >> M >> S;
		memset( visited, 0, sizeof (visited));
		memset( sl, 0, sizeof (sl) );
		for( int i=0; i<N; i++ ) linkd[i].clear();
		for( int i=0; i<M; i++ ) {
			int from, to, weight; cin >> from >> to >> weight;
			from--;to--;
			Edge e;
			e.to = to; e.co = weight;
			linkd[from].push_back( e );
		}

		int ans = 0;
		for(int here = 0; here < N; here++ ){
			for( vector<Edge>::iterator it = linkd[here].begin(); it != linkd[here].end(); it++ ){
				sl[it->to][1] = max( sl[it->to][1], (int) it->co ); ans = max(ans, sl[it->to][1]);
				for( int i = 1; i < S; i++ )
					sl[it->to][i+1] = max( sl[it->to][i+1] , sl[here][i] + it->co ), ans = max(ans, sl[it->to][i+1]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}