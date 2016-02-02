#include <iostream>
#include <string>

using namespace std;

int main() {
	string num1, num2;
	cin >> num1 >> num2;
	
	for (int i = 0; i < num1.size(); i++) {
		if (num1[i] == '6')
			num1[i] = '5';
	}

	for (int i = 0; i < num2.size(); i++) {
		if (num2[i] == '6')
			num2[i] = '5';
	}

	int n1 = stoi(num1);
	int n2 = stoi(num2);
	int min = n1 + n2;

	for (int i = 0; i < num1.size(); i++) {
		if (num1[i] == '5')
			num1[i] = '6';
	}

	for (int i = 0; i < num2.size(); i++) {
		if (num2[i] == '5')
			num2[i] = '6';
	}

	n1 = stoi(num1);
	n2 = stoi(num2);
	int max = n1 + n2;

	cout << min << endl;
	cout << max << endl;

	return 0;
}