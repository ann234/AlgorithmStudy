//최대이익 구하기
#include <iostream>

using::std::cout;
using::std::endl;

int r[4][5] = { {0, 0, 0, 0, 0},
{ 0, 2, 4, 6, 9 },
{ 0, 3, 5, 6, 8 },
{ 0, 1, 3, 7, 9 } };

int max_return[4][5];

void invest(int company, int money);

int main(int argc, char* argv[])
{
	//r[i][j]: i기업에 j만원 투자했을 시 얻을 수 있는 금액
	int r[3][4] = { {2, 4, 6, 9},
				{ 3, 5, 6, 8 },
				{ 1, 3, 7, 9 } };

	invest(3, 4);
	cout << max_return[3][4] << endl;

	return 0;
}

void invest(int company, int money)
{
	//아무 회사에도 투자하지 않는 경우
	for (int i = 0; i <= 4; i++)
	{
		max_return[0][i] = r[0][i];
	}
	//회사에 0원을 투자하는 경우
	for (int i = 0; i <= 3; i++)
	{
		max_return[i][0] = r[i][0];
	}

	//1번 회사부터 투자 시
	for (int i = 1; i <= 3; i++)
	{
		//만원부터 j원까지 투자해봐서 각각 높은 경우를 max_return[i][j]에 저장
		for (int j = 1; j <= 4; j++)
		{
			int max = -1;
			for (int k = 0; k <= j; k++)
			{
				int tmp = r[i][j] + max_return[i - 1][money - j];
				if (tmp > max)
					max = tmp;
			}
			max_return[i][j] = max;
		}
	}
}