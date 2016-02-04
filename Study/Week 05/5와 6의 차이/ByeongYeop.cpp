#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int a, b;

	cin >> a >> b;

	string a_string = to_string(a);
	string b_string = to_string(b);

	for (int i = 0; i < 7; i++) {
		if ((i < a_string.length()) && (a_string[i] == '6'))
			a_string[i] = '5';
		if ((i < b_string.length()) && (b_string[i] == '6'))
			b_string[i] = '5';
	}

	cout << stoi(a_string) + stoi(b_string) << " ";

	for (int i = 0; i < 7; i++) {
		if ((i < a_string.length()) && (a_string[i] == '5'))
			a_string[i] = '6';
		if ((i < b_string.length()) && (b_string[i] == '5'))
			b_string[i] = '6';
	}

	cout << stoi(a_string) + stoi(b_string) << " ";
}
