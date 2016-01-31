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
	int N;			//�迭�� ����
	string StrAlpa[10];			//���ĺ� ���� ����
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		cin >> StrAlpa[i];
	}

	ALP Alpa[26] = { 0, };//���ĺ��� �󵵸� �����ϱ� ���� ALP�迭
	int AlpaNum[26] = { 0, }; //�� ���ĺ��� ����Ű�� ���ڸ� �����ϱ� ���� �迭

	for (int i = 0; i < 26; i++)
	{
		Alpa[i].AlPa = (char)('A' + i);
	}

	int Strlen[10];		//�� �迭�� ���̸� ��Ÿ���� �迭

	for (int i = 0; i < N; i++)
	{
		Strlen[i] = StrAlpa[i].length();
	}

	int MaxLen = FindMax(Strlen, N);		//�迭�� ���� ū �迭�� ����
	int tenNum = Zeten(1, MaxLen);			//�� ���̿� �ش��ϴ� ��ŭ�� 10�� ���� ��

	char K;
	for (int i = 0; i < MaxLen; i++)//���° ���ĺ�
	{
		for (int j = 0; j < N; j++)//���° �迭
		{
			if (((Strlen[j] - MaxLen) + i )> -1)	// �迭�� �μ� �ѹ��� 0 �̻��ΰ�
			{
				K = StrAlpa[j][i + (Strlen[j] - MaxLen)];//���� ���ĺ����� �˾Ƴ��� �۾�
				Alpa[K - 'A'].popu += tenNum;//�ش� ���ĺ��� �� ����
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
			K = StrAlpa[i][j];//���� ���ĺ����� �˾Ƴ��� �۾�
			Sum += AlpaNum[K-'A'] * tenNum;
			tenNum /= 10;
		}
	}

	cout << Sum << endl;

	return 0;

}
