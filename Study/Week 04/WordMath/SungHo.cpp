#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int ChangeNum(char * Str)
{
	int len = strlen(Str);

	int Num = 0;
	int ten = 1;
	for (int i = len - 1; i > -1; i--)
	{
		Num += Str[i] * ten;
		ten *= 10;
	}
	return Num;
}

int FindMax(int * N, int len)
{
	int MaxNum=N[0];
	for (int i = 1; i < len; i++)
	{
		if (N[i] > MaxNum)
			MaxNum = N[i];
	}

	return MaxNum;
}

int Zeten(int N, int time)
{
	for (int i = 0; i < time-1; i++)
		N *= 10;
	return N;
}

typedef struct _Alpa {
	int popu;
	char AlPa;
}ALP;

int BiggerNum(const void *p1, const void * p2)
{
	ALP * a1 = (ALP*)p1;
	ALP * a2 = (ALP*)p2;
	if (a1->popu > a2->popu)
		return -1;
	else if (a1->popu < a2->popu)
		return 1;
	else
		return 0;
}

int main(void)
{
	int N;			//배열의 갯수
	string StrAlpa[10];			//알파벳 문자 저장
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		cin >> StrAlpa[i];
	}

	ALP Alpa[26] = { 0, };//알파벳의 빈도를 저장하기 위한 ALP배열
	int AlpaNum[26] = { 0, }; //각 알파벳이 가리키는 숫자를 저장하기 위한 배열

	for (int i = 0; i < 26; i++)
	{
		Alpa[i].AlPa = (char)('A' + i);
	}

	int Strlen[10];		//각 배열의 길이를 나타내는 배열

	for (int i = 0; i < N; i++)
	{
		Strlen[i] = StrAlpa[i].length();
	}

	int MaxLen = FindMax(Strlen, N);		//배열중 가장 큰 배열의 길이
	int tenNum = Zeten(1, MaxLen);			//그 길이에 해당하는 만큼의 10의 제곱 값

	char K;
	for (int i = 0; i < MaxLen; i++)//몇번째 알파벳
	{
		for (int j = 0; j < N; j++)//몇번째 배열
		{
			if (((Strlen[j] - MaxLen) + i )> -1)	// 배열의 인수 넘버가 0 이상인가
			{
				K = StrAlpa[j][i + (Strlen[j] - MaxLen)];//무슨 알파벳인지 알아내는 작업
				Alpa[K - 'A'].popu += tenNum;//해당 알파벳에 수 증가
			}
		}
		tenNum /= 10;
	}

	qsort(Alpa, 26, sizeof(ALP), BiggerNum);

	for (int i = 0; i < 9; i++)
	{
		K = Alpa[i].AlPa;
		if (Alpa[i].popu <= 0)
			break;
		AlpaNum[K-'A'] = 9 - i;
	}

	int Sum=0;

	for (int i = 0; i < N; i++)
	{
		tenNum = Zeten(1, Strlen[i]);
		for (int j = 0; j < Strlen[i]; j++)
		{
			K = StrAlpa[i][j];//무슨 알파벳인지 알아내는 작업
			Sum += AlpaNum[K-'A'] * tenNum;
			tenNum /= 10;
		}
	}

	cout << Sum << endl;

	return 0;

}
