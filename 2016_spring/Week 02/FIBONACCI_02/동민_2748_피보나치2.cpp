#include <iostream>
using namespace std;

long long mem[95];

int main(){
	int num; cin >> num;

	mem[0] = 0;
	mem[1] = 1;
	for (int k = 2; k <= num; k++){
		mem[k] = mem[k - 1] + mem[k - 2];
	}

	cout << mem[num];

}