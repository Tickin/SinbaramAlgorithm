#include<iostream>
#include<string>
using namespace std;

string cmd[50];
string result;
void   makeResult(int n){
    result = cmd[0];
    int length = result.length();

    for(int i = 1; i < n; i++){
        for(int j = 0; j < length; j++){
            if (cmd[i][j] != result[j]) result[j] = '?';
        }
    }

    cout << result;
}
int main(){
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        cin >> cmd[i];
    }
    makeResult(n);
}
