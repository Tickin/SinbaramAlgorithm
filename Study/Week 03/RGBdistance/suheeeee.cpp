// RGB distance

#include <iostream>
#include <fstream>
using namespace std;

int board[1000][3];
int cache[1000][3];
int n;

void printCache(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cout << cache[i][j] << " ";
        }cout << endl;
    }
}


void run(int p){
    if ( p == n-1 ) {
        int mini = cache[n-1][0];

        if (mini > cache[n-1][1]) mini = cache[n-1][1];
        if (mini > cache[n-1][2]) mini = cache[n-1][2];

        cout << mini << endl;
    }

    else {
        // R 0 G1 B2
        // case 1 : G > R
        // case 2 : B > R
        // case 3 : R > G
        // case 4 : B > G
        // case 5 : R > B
        // case 6 : G > B
        int a = cache[p][1] + board[p+1][0];
        int b = cache[p][2] + board[p+1][0];
        if ( a < b )    cache[p+1][0] = a;
        else            cache[p+1][0] = b;

        a = cache[p][0] + board[p+1][1];
        b = cache[p][2] + board[p+1][1];
        if ( a < b )    cache[p+1][1] = a;
        else            cache[p+1][1] = b;

        a = cache[p][0] + board[p+1][2];
        b = cache[p][1] + board[p+1][2];
        if ( a < b )    cache[p+1][2] = a;
        else            cache[p+1][2] = b;

        //printCache();
        run(p+1);
    }
}

int main(){
    cin >> n;

    // make board
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> board[i][j];

    cache[0][0] = board[0][0];
    cache[0][1] = board[0][1];
    cache[0][2] = board[0][2];

    run(0);
}
