#include <iostream>
#include <fstream>
using namespace std;

int     matrix[100][100] = {0,};
struct  dot{
    int x;
    int y;
};
bool    BoolMatrix[100][100] = {false,};
int     setMatrix();
void    printMatrix(int n);
void    scanMatrix(int n);
void    intialBool(int n);

int main(){
    int     c = 0;  // num of case
    cin >> c;

    while ( c > 0 ){
        // each case
        int n = setMatrix();
        //cout <<endl;
        //printMatrix(n);
        //cout << endl;

        intialBool(n);
        scanMatrix(n);

        c--;
    }
}
int setMatrix(){
    int n = 0;
    int in = 0;
    cin >> n;

    if ( n > 100 ){}
    else {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> in;
                if (in < 0 || in > 10) {
                    cout << "error with input data!"<<endl;
                    break;
                }
                else{ matrix[i][j] = in; }
            }
            if (in < 0 || in > 10) break;
        }
    }
    return n;
}
void printMatrix(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void printBoolMatrix(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << BoolMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
void goR(int oriX, int oriY, int jump){
    if  ((oriX + jump) > 99){}
    else{ BoolMatrix[oriX + jump][oriY] = true; }
}
void goD(int oriX, int oriY, int jump){
    if ((oriY + jump) > 99){}
    else{ BoolMatrix[oriX][oriY+jump] = true; }
}
void intialBool(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            BoolMatrix[i][j] = false;
        }
    }
    BoolMatrix[0][0] = true;
    //printBoolMatrix(n); cout << endl;
}
void scanMatrix(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if ( BoolMatrix[i][j] == true ){
                int jump = matrix[i][j];
                goR(i,j,jump);
                goD(i,j,jump);
            }
        }
    }
    //cout << endl;
    //printBoolMatrix(n);
    //cout << endl;
    if (BoolMatrix[n-1][n-1] == true) cout << "YES"<< endl;
    else cout << "NO"<<endl;
}
