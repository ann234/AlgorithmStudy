//�κ����� ���ϱ�
#include <iostream>

using::std::cout;
using::std::endl;

#define max(a, b) ( (a)>(b) ? (a) : (b) )

//n: ���Ϸ��� ��, m: �κ������� ������ �������� ����, s: �κ������� ������ �������� �迭
int subset(int n, int m, int *s);
void subset_dynamic(int n, int m, int *s);

int **memory;

int main(int argc, char* argv[])
{
	int s[5] = { 1, 2, 3, 4, 5 };
	int sum = 12;

	memory = new int*[5 + 1];
	for (int i = 0; i <= 5; i++)
	{
		memory[i] = new int[sum + 1];
	}
	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= sum; j++)
			memory[i][j] = 0;

	//cout << subset(sum, 5, s) << endl;

	subset_dynamic(sum, 5, s);

	return 0;
}

int subset(int n, int m, int *s)
{
	if (m == 0)
	{
		if (n == 0)
			return 1;
		else
			return 0;
	}
	
	return max(subset(n - s[m - 1], m - 1, s), subset(n, m - 1, s));
}

void subset_dynamic(int n, int m, int *s)
{
	//��� ���� �迭�̵� ���� 0�� �κ������� ������ �����ϹǷ� true(1)
	for (int i = 0; i <= m; i++)
	{
		memory[i][0] = 1;
	}
	//�������� ���� 0�̹Ƿ� false(0)
	for (int i = 0; i <= n; i++)
	{
		memory[0][i] = 0;
	}
	
	//���� �迭�� i��° �������� ����ϴ� ���
	for (int i = 1; i <= m; i++)
	{
		//�κ������� ���� j�� �޼��ϴ� ���
		for (int j = 1; j <= n; j++)
		{
			//���� �迭�� i��° ������ ����ϴ� ���, ������� �ʴ� ���� ���� �� ���ɿ��θ� �� ���ε�
			//i��° ������ ����ϴ� ��� �װ��� ���Ϸ��� �պ��ٴ� �۾ƾ� �Ѵ�.
			if (j >= s[i - 1])
			{
				//i��° ������ ����ϴ� ���� ������� �ʴ� ��츦 �� �� ������ ��
				//�κ������� �����Ѵٸ� memory[i][j]�� true(1)�� �ִ´�.
				memory[i][j] = max(memory[i - 1][j], memory[i - 1][j - s[i - 1]]);
			}
		}
	}

	int _sum = n;
	//m���� 1����
	for (int i = m; i >= 0; i--)
	{
		if (_sum > 0)
		{
			if(memory[i][_sum] == 1)
			{
				cout << s[i - 1] << ", ";
				_sum = _sum - s[i - 1];
			}
		}
	}
}