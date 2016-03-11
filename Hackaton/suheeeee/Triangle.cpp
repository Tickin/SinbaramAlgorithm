#include <iostream>
using namespace std;

int triangle[100][100];
int path[100][100];
const int INFI = 1000000000;

void makeTriangle(int h){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < i + 1; j++){
            int tmp; cin >> tmp;
            triangle[i][j] = tmp;
        }
    }
}

void shortestPath(int h){
    path[0][0] = triangle[0][0];
    for(int i = 1; i < h; i++){
        for(int j = 0; j < i + 1; j++){
            // case 1 왼쪽 끝
            if (j == 0){ path[i][j] = path[i-1][0] + triangle[i][j]; }

            // case 2 오른쪽 끝 값
            else if(j == i){ path[i][j] = path[i-1][j-1] + triangle[i][j]; }

            // case 3 중간 값
            else{
                int tmp1 = path[i-1][j-1] + triangle[i][j];
                int tmp2 = path[i-1][j] + triangle[i][j];
                if (tmp1 > tmp2){ path[i][j] = tmp1; }
                else            { path[i][j] = tmp2; }
            }
        }
    }
    int maxi = path[h-1][0];
    for(int i = 1; i < h; i++){
        if( path[h-1][i] > maxi ){ maxi = path[h-1][i]; }
    }
    cout << maxi << endl;
}
int main(){
    int tc; cin >> tc;

    for(int i = 0; i < tc; i++){
        int h = 0; cin >> h;
        makeTriangle(h);
        shortestPath(h);
    }
    return 0;
}
