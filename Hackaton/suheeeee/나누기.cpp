#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    float a, b; cin >> a >> b;
    printf("%.9f", (float)a/b);
}

/*

    double dx;
    char format[14];
    dx = (double)1.25;
    sprintf(format, "%%.%df\n", 2);
    printf(format, dx);

    sprintf(format, "%%.%df\n", 4);
    printf(format, dx);

*/
