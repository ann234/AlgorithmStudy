//���׿��� ���� ���α׷���
#include <iostream>

using::std::cout;
using::std::endl;

//N�� �߿��� R���� �� ����� ��
#define N 50
#define R 20

//����� ������ �� ������ �迭
int** cache;

//����� ���׿���
int choose(int n, int r);
//���� ���׿���
int choose_dynamic(int n, int r);

int main(int argc, char* argv[])
{
	//0~N�� �߿���
	cache = new int*[N + 1];
	for (int i = 0; i < N; i++)
	{
		//0~R���� �̴� ���
		cache[i] = new int[R + 1];
		for (int j = 0; j < R + 1; j++)
			cache[i][j] = -1;
	}

	int ret = choose_dynamic(N, R);
	cout << ret << endl;

	return 0;
}

int choose(int n, int r)
{
	if (n == 0 || r == 0)
		return 1;

	return choose(n - 1, r - 1) + choose(n - 1, r);
}

int choose_dynamic(int n, int r)
{
	if (n == 0 || r == 0)
		return 1;

	int left, right;

	if (cache[n - 1][r - 1] > 0)
		left = cache[n - 1][r - 1];
	else
	{
		left = choose(n - 1, r - 1);
		cache[n - 1][r - 1] = left;
	}
	if (cache[n - 1][r] > 0)
		right = cache[n - 1][r];
	else
	{
		right = choose(n - 1, r);
		cache[n - 1][r] = right;
	}

	return left + right;
}