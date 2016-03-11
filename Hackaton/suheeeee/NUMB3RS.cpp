#include <iostream>
#include <stdio.h>
using namespace std;

int      Graph[50][50];
int connection[50];
double     rate[50][100];

void makeGraph(int n){
    for(int i = 0; i < n; i++){
        int summ = 0;
        for(int j = 0; j < n; j++){
            int tmp; cin >> tmp;
            Graph[i][j] = tmp;
            if (tmp == 1){summ += 1;}
        }
        connection[i] = summ;
    }
}
void printR(int n, int d){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            printf("%.9f ", rate[i][j]);
        }cout << endl;
    }
}
void calR(int n, int row, int day){
    for(int col = 0; col < n; col++){
        if(row == col){}
        else{
            if(Graph[row][col] == 1) {
                rate[col][day] += ((double)1 / (double) connection[row]) * (double)rate[row][day-1];
            }
        }
    }
}
void runDunibal(int n, int d, int p){
    // rate 초기화
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d + 1; j++){
            if(j == 0 && i == p){ rate[i][j] = (double)1;}
            else                { rate[i][j] = (double)0;}
        }
    }

    // 반복되는 날들
    for(int j = 1; j < d + 1; j++){
        for(int i = 0; i < n; i++){
            if(rate[i][j-1] > 0){
                calR(n,i,j);
            }
        }
    }
    //printR(n, d+1);
    int forprint[50];
    int loop; cin >> loop;
    for(int i = 0; i < loop; i++){ int tmp; cin >> tmp; forprint[i] = tmp;}
    for(int i = 0; i < loop; i++){ printf("%.9f ", rate[forprint[i]][d]); } cout << endl;
}

int main(){
    int tc; cin >> tc;

    for(int i = 0 ; i < tc; i++){
        int n, d, p; cin >> n >> d >> p;
        makeGraph(n);
        runDunibal(n, d, p);
    }
    return 0;
}
