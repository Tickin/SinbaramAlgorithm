#include<iostream>
#include<cstdio>

#define NUMBERLENGTH 2500
#define ONEDEGIT 10000

using namespace std;

typedef struct _longlong {
	unsigned int h[NUMBERLENGTH];
} longlong;

longlong cache[1001], result;

void assign(longlong *a, unsigned int b) {
	int i;
	for (i = 0; i < NUMBERLENGTH; i++) {
		a->h[i] = b%ONEDEGIT;
		b /= ONEDEGIT;
	}
}

void add(longlong *c, const longlong *a, const longlong *b) {
	int carry = 0;
	for (int i = 0; i < NUMBERLENGTH; i++) {
		c->h[i] = a->h[i] + b->h[i] + carry;
		carry = c->h[i] / ONEDEGIT;
		c->h[i] %= ONEDEGIT;
	}
}

void print(const longlong *a) {
	int sw = 0;
	for (int i = NUMBERLENGTH - 1; i >= 0; i--) {
		if (!(sw == 0 && a->h[i] == 0)) {
			if (sw == 0) {
				printf("%d", a->h[i]);
				sw = 1;
			}
			else {
				printf("%04d", a->h[i]);
			}
		}
	}
	if (sw == 0) {
		printf("%d", 0);
	}
	printf("\n");
}

void getCache() {
	longlong a, b;
	assign(&cache[1], 2);
	assign(&cache[2], 5);
	assign(&cache[3], 13);
	for (int i = 4; i < 1001; i++) {
		assign(&a, 0);
		assign(&b, 0);

		add(&a, &cache[i - 2], &cache[i - 3]);
		add(&b, &a, &cache[i - 1]);
		add(&cache[i], &b, &cache[i - 1]);
	}
}

int main() {

	getCache();
	int n;
	while (scanf("%d", &n) != EOF) {
		print(&cache[n]);
	}

	return 0;
}