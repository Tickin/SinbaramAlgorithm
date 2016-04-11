#include <stdio.h>
#include <string.h>

unsigned long long int N;

void multi(unsigned long long int t[4], unsigned long long int m[4]) {
    unsigned long long int m0, m1, m2, m3;

    m0 = ( t[0]*m[0] + t[1]*m[2] ) % 1000000;
    m1 = ( t[0]*m[1] + t[1]*m[3] ) % 1000000;
    m2 = ( t[2]*m[0] + t[3]*m[2] ) % 1000000;
    m3 = ( t[2]*m[1] + t[3]*m[3] ) % 1000000;

    m[0] = m0;
    m[1] = m1;
    m[2] = m2;
    m[3] = m3;
}

void square(unsigned long long int m[4]) {
    unsigned long long int m0, m1, m2, m3;

    m0 = ( m[0]*m[0] + m[1]*m[2] ) % 1000000;
    m1 = ( m[0]*m[1] + m[1]*m[3] ) % 1000000;
    m2 = ( m[2]*m[0] + m[3]*m[2] ) % 1000000;
    m3 = ( m[2]*m[1] + m[3]*m[3] ) % 1000000;

    m[0] = m0;
    m[1] = m1;
    m[2] = m2;
    m[3] = m3;
}


void power(unsigned long long int m[4], unsigned long long int exp) {
    unsigned long long int t[4];
    if (exp == 1) {
        return ;
    }
    else if (exp % 2 == 0) {
        square(m);
        power(m, exp/2);
    }
    else {
        memcpy(t, m, 4 * sizeof(unsigned long long int));
        square(m);
        power(m, exp/2);
        multi(t, m);
    }
}

unsigned long long int fibo(unsigned long long int n) {
    unsigned long long int A[4] = {1, 1, 1, 0};

    if (n < 2)
        return n;
    power(A, n);
    return A[2];
}


int main() {
    scanf("%llu", &N);

    printf("%llu", fibo(N));

    return 0;
}
