#include<iostream>
#include<string>

using namespace std;

struct baseballTeam {
	string name;
	int win;
	int draw;
	int lose;
};

baseballTeam inputTeam[8];

double getRate(int team)
{
	if (inputTeam[team].win + inputTeam[team].draw + inputTeam[team].lose == 0) return 0;
	else return (double)inputTeam[team].win / (inputTeam[team].win + inputTeam[team].draw + inputTeam[team].lose);
}

bool checkWinRate(int myTeam)
{
	double result[8];
	double myRate = 0;
	for (int i = 0; i < 8; i++)
	{
		result[i] = getRate(i);
		if (myTeam == i)
		{
			myRate = result[i];
		}
	}
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		if (result[i] > myRate) count++;
	}
	if (count > 3) return false;
	else return true;
}

int main()
{
	int testCase; cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		string myteamInput;
		string leftTeamInput, rightTeamInput;
		int myteam, leftTeam, rightTeam;
		int moreGameNum;
		for (int i = 0; i < 8; i++)
		{
			cin >> inputTeam[i].name >> inputTeam[i].win >> inputTeam[i].draw >> inputTeam[i].lose;
		}

		cin >> myteamInput;
		for (int i = 0; i < 8; i++)
		{
			if (myteamInput.compare(inputTeam[i].name) == 0) myteam = i;
		}

		cin >> moreGameNum;

		for (int i = 0; i < moreGameNum; i++)
		{
			cin >> leftTeamInput;
			cin >> rightTeamInput;
			for (int j = 0; j < 8; j++)
			{
				if (inputTeam[j].name.compare(leftTeamInput) == 0)
				{
					leftTeam = j;
				}
				else if (inputTeam[j].name.compare(rightTeamInput) == 0)
				{
					rightTeam = j;
				}
			}
			if (leftTeam == myteam)
			{
				inputTeam[leftTeam].win++;
				inputTeam[rightTeam].lose++;
			}
			else if (rightTeam == myteam)
			{
				inputTeam[leftTeam].lose++;
				inputTeam[rightTeam].win++;
			}
			else
			{
				inputTeam[leftTeam].draw++;
				inputTeam[rightTeam].draw++;
			}
		}

		if (checkWinRate(myteam)) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

	return 0;
}

