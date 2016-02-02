#include<iostream>
#include<string>

using namespace std;

int main()
{
	string input1, input2;
	int min1, min2, max1, max2;
	string::iterator it;

	cin >> input1;
	cin >> input2;

	for (it = input1.begin(); it != input1.end(); it++)
	{
		if (*it == '6')
		{
			*it = '5';
		}
	}
	for (it = input2.begin(); it != input2.end(); it++)
	{
		if (*it == '6')
		{
			*it = '5';
		}
	}

	min1 = stoi(input1);
	min2 = stoi(input2);

	for (it = input1.begin(); it != input1.end(); it++)
	{
		if (*it == '5')
		{
			*it = '6';
		}
	}
	for (it = input2.begin(); it != input2.end(); it++)
	{
		if (*it == '5')
		{
			*it = '6';
		}
	}

	max1 = stoi(input1);
	max2 = stoi(input2);

	cout << min1 + min2 << endl;
	cout << max1 + max2 << endl;

	return 0;
}