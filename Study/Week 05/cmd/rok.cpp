#include <iostream>
#include <string>

using namespace std;

int main() {
	int num;
	cin >> num;

	string result, temp;
	cin >> result;

	for (int i = 1; i < num; i++) {
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			if (result[j] != temp[j])
				result[j] = '?';
		}
	}
	
	cout << result << endl;

	return 0;
}