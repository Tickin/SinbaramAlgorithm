#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string input1, input2;
	string::iterator it1, it2;

	cin >> n;
	cin >> input1;

	for (int i = 0; i < n; i++)
	{
		cin >> input2;
		for (it1 = input1.begin(), it2 = input2.begin(); it1 != input1.end(), it2 != input2.end(); it1++, it2++)
		{
			if (*it1 != *it2)
			{
				*it1 = '?';
			}
		}
	}

	cout << input1 << endl;

	return 0;
}