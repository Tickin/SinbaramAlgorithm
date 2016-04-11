#include <stdio.h>

unsigned int N;

unsigned int fibo(int n) {
    unsigned int T0, T1, T2;
    int i;

    if (n < 2)
        return n;
    else
        T0 = 0;
        T1 = 1;
        for(i = 1; i < n; i++) {
            T2 = (T0 + T1) % 1000000;
            T0 = T1;
            T1 = T2;
        }
        return T2;
}


int main() {
    scanf("%d", &N);

    printf("%u", fibo(N));

    return 0;
}
