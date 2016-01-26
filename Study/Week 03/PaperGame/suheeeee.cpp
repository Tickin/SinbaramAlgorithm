#include <iostream>
using namespace std;

int     paper[2200][2200] = { 0, };
int     n;
int     minor = 0;
int     zero = 0;
int     one = 0;

struct point {
	int x;
	int y;
	int s;
	point(int _x, int _y, int _s) : x(_x), y(_y), s(_s) {}
};

int testSame(point p) {
	int n = paper[p.x][p.y];
	for (int i = p.x; i < p.x + p.s; i++)
		for (int j = p.y; j < p.y + p.s; j++)
			if (n != paper[i][j]) return -2;

	return n;
}

void cutPaper(point p) { // x, y 종이의 시작지점, s종이의 칸수
	int t = testSame(p);

	if (t != -2) {
		if (t == 1)  one++;
		else if (t == -1)  minor++;
		else if (t == 0)  zero++;
	}

	else if (p.s == 1) {
		if (paper[p.x][p.y] == 1) one++;
		else if (paper[p.x][p.y] == 0) zero++;
		else if (paper[p.x][p.y] == -1) minor++;
	}

	else {
		point nextP(p.x, p.y, p.s / 3);   cutPaper(nextP);
		nextP.y += nextP.s;                   cutPaper(nextP);
		nextP.y += nextP.s;                   cutPaper(nextP);
		nextP.x += nextP.s; nextP.y = p.y;    cutPaper(nextP);
		nextP.y += nextP.s;                   cutPaper(nextP);
		nextP.y += nextP.s;                   cutPaper(nextP);
		nextP.x += nextP.s; nextP.y = p.y;    cutPaper(nextP);
		nextP.y += nextP.s;                   cutPaper(nextP);
		nextP.y += nextP.s;                   cutPaper(nextP);
	}

}


int main() {
	cin >> n;

	// make board
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> paper[i][j];
		}
	}


	point start(1, 1, n);
	cutPaper(start);

	cout << minor << endl << zero << endl << one << endl;

}
