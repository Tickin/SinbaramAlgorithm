#include<iostream>
using namespace std;
int main()
{
	int A, B; cin >> A >> B;
	int tmpA = A;
	cout << tmpA / B << '.';
	for (int i = 0; i < 10; i++){
		tmpA = (tmpA%B)*10;
		cout << tmpA / B;
	}
	return 0;
}