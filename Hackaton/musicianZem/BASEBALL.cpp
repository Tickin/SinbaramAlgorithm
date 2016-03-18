#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#define TEAMCOUNT 8
using namespace std;

typedef struct WSL{
	int win, same, lose;
	int sum;
	double average;
	WSL( int w=0, int s=0, int l=0 ) {
		win = w; same = s; lose = l;
	}
	void calculate() {
		sum = win + same + lose;
		if( sum == 0 ) average = 0;
		else average = win / (double) sum;
	}
	friend bool operator < ( const WSL& a, const WSL& b ) {
		return a.sum < b.sum;
	}
	friend bool operator == ( const WSL& a, const WSL& b ) {
		return a.win == b.win && a.same == b.same && a.lose == b.lose;
	}
}WSL;

typedef struct BEST {
	string name;
	double average;
	friend bool operator < ( const BEST& a, const BEST& b ) {
		return ( a.average <= b.average );
	}
} BEST;

int main() {
	int testCase; cin >> testCase;
	while( testCase-- ) {
		map<string, WSL> before;
		for(int i=0; i<TEAMCOUNT; i++) {
			string name; cin >> name;
			int win, same, lose; cin >> win >> same >> lose;
			WSL wsl( win, same, lose );
			before.insert( pair<string, WSL>( name, wsl ) );
		} // insert 8 teams.

		string findTeam; cin >> findTeam;
		int restFight; cin >> restFight;
		for(int i=0; i<restFight; i++) {
			string left, right; cin >> left >> right;
			if( left == findTeam ) { before[ left ].win++; }
			else { before[ left ].lose++; }

			if( right == findTeam ) { before[ right ].win++; }
			else { before[ right ].lose++; }
		} // win lose check.

		list<BEST> after;
		for(map<string,WSL>::iterator it = before.begin(); it != before.end(); it++ ) {
			it->second.calculate();
			BEST best;
			best.name = it->first;
			if( it->second.sum == 0 ) best.average = 0;
			else {
				best.average = (double)it->second.win / (double)it->second.sum;
				if( best.name == findTeam ) {
					best.average += 0.002;
				}
			}
			list<BEST>::iterator lit = after.begin();
			while( lit != after.end() ) {
				if( lit->average > best.average ) {
					lit++; continue;
				}
				if( lit->average == best.average ) {
					if( best.name != findTeam ) {
						lit++;
					}
				}
				break;
			}
			after.insert( lit, best );
		}
		int count = 0;
		for( list<BEST>::iterator it = after.begin(); it != after.end(); it++ ) {
			if( it->name == findTeam ) break;
			else count++;
			//cout << it->name << " " << it->average << endl;
		}
		if( count < 4 ) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}