#include <iostream>
#include <string>
using namespace std;

int sixToFive(string );
int fiveToSix(string );

int main(){
    string a, b;
    cin >> a >> b;
    int tmpA = sixToFive(a);
    int tmpB = sixToFive(b);
    cout << tmpA + tmpB << endl;
    tmpA = fiveToSix(a);
    tmpB = fiveToSix(b);
    cout << tmpA + tmpB;
}

int sixToFive(string tmp){
    int loop  = tmp.length();
    int result = 0;
    int n = 1;

    for(int i = 1; i < loop; i++) n = n * 10;

    for(int i = 0; i < loop; i++){
        if ( tmp[i] == '6' ) tmp[i] = '5';

        result += (tmp[i] - '0') * n;
        n = n / 10;
    }
    return result;
}
int fiveToSix(string tmp){
    int loop  = tmp.length();
    int result = 0;
    int n = 1;

    for(int i = 1; i < loop; i++) n = n * 10;

    for(int i = 0; i < loop; i++){
        if ( tmp[i] == '5' ) tmp[i] = '6';

        result += (tmp[i] - '0') * n;
        n = n / 10;
    }
    return result;
}
