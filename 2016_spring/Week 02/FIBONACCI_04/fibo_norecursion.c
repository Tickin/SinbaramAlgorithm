#include <stdio.h>

unsigned int N;

unsigned long long int fibo(int n) {
    unsigned long long int T0, T1, T2;
    int i;

    if (n < 2)
        return n;
    else
        T0 = 0;
        T1 = 1;
        for(i = 1; i < n; i++) {
            T2 = T0 + T1;
            T0 = T1;
            T1 = T2;
        }
        return T2;
}


int main() {
    scanf("%d", &N);

    printf("%llu", fibo(N));

    return 0;
}
