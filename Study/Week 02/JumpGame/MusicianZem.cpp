#include <iostream>
using namespace std;
int N, n;
int arr[100][100];
bool brr[100][100];
void check( int i, int j ) {
    if( brr[i][j] ) {
        if( arr[i][j] + j < n ) {
            brr[i][j + arr[i][j]] = true;
        }
        if( arr[i][j] + i < n ) {
            brr[i + arr[i][j]][j] = true;
        }
    }
}

int main( void ) {
	//scanf("%d", &N);
	cin >> N;
	while( N-- ) { 
		//scanf("%d", &n);
		cin >> n;
		for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> arr[i][j] ;
				brr[i][j] = false;
            }
		}
		brr[0][0] = true;
		for(int i=0; i<n; i++) for(int j=0; j<n; j++) check(i, j);
		if( brr[n-1][n-1] ) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
