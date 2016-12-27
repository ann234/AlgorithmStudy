//�ִ����� ���ϱ�
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
	//r[i][j]: i����� j���� �������� �� ���� �� �ִ� �ݾ�
	int r[3][4] = { {2, 4, 6, 9},
				{ 3, 5, 6, 8 },
				{ 1, 3, 7, 9 } };

	invest(3, 4);
	cout << max_return[3][4] << endl;

	return 0;
}

void invest(int company, int money)
{
	//�ƹ� ȸ�翡�� �������� �ʴ� ���
	for (int i = 0; i <= 4; i++)
	{
		max_return[0][i] = r[0][i];
	}
	//ȸ�翡 0���� �����ϴ� ���
	for (int i = 0; i <= 3; i++)
	{
		max_return[i][0] = r[i][0];
	}

	//1�� ȸ����� ���� ��
	for (int i = 1; i <= 3; i++)
	{
		//�������� j������ �����غ��� ���� ���� ��츦 max_return[i][j]�� ����
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