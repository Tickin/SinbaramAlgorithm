#include <iostream>
#include <string>
using namespace std;

struct team{
    string name;
    int w;
    int d;
    int l;
    float r;
    team(string _s, int _w, int _d, int _l):name(_s),w(_w), d(_d), l(_l), r(0){
        if((_w + _d + _l) == 0) { r = 0; }
        else                    { r = (float)_w / (float)(_w + _d + _l); }
    }
    team(){}
};

team t[8];

void makeBoard(){
    for(int i = 0; i < 8; i++){
        string s; int _w, _d, _l;
        cin >> s >> _w >> _d >> _l;
        team tmp(s, _w, _d, _l);
        t[i] = tmp;
    }
}
int findLabel(string s){
    for(int i = 0; i < 8; i++){
        if(s == t[i].name){ return i; }
    }
    return -1;
}
void runGame(string my){
    int loop; cin >> loop;
    int myLabel = findLabel(my);

    for(int i = 0; i < loop; i++){
        string a, b; cin >> a >> b;
        if(a == my && b != my){
            t[myLabel].w += 1;
            t[findLabel(b)].l += 1;
        }
        else if (a != my && b == my){
            t[findLabel(a)].l += 1;
            t[myLabel].w += 1;
        }
        else{
            t[findLabel(a)].d += 1;
            t[findLabel(b)].d += 1;
        }
    }

    for(int i = 0; i < 8; i++){
        int sum = t[i].w + t[i].d + t[i].l;
        if(sum == 0) { t[i].r = 0; }
        else         { t[i].r = (float)t[i].w / (float)sum; }
    }

    int ranking = 1;
    for(int i = 0; i < 8; i++){
        if(i == myLabel) {}
        else {
            if(t[myLabel].r < t[i].r){ ranking += 1; }
        }
    }
    if( ranking > 4 ){ cout << "NO" <<endl; }
    else             { cout << "YES" << endl; }
}
int main(){
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        makeBoard();
        string my; cin >> my;
        runGame(my);
    }
    return 0;
}
