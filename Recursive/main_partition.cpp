//������ �˰���
#include <iostream>

using::std::cout;
using::std::endl;

#define MAXN 4

//n: ���ҵ� ����,	m: ������ ���� �Ѱ�ġ
int partition(int n, int m);

int** cache;

int main(int argc, char* argv)
{
	//cache �����ϱ�
	int limit = 4;
	cache = new int*[MAXN + 1];
	for (int i = 0; i < MAXN + 1; i++)
	{
		cache[i] = new int[limit + 1];
		for (int j = 0; j < limit + 1; j++)
		{
			cache[i][j] = -1;
		}
	}

	int ret = partition(MAXN, limit);
	cout << ret << endl;

	return 0;
}

int partition(int n, int m)
{
	////���ҵǷ��� ���ڰ� m���� ���� ���
	//if (n < m)
	//	m = n;
	////�� �̻� ���ҵ� ���ڰ� ���� ���
	//if (n == 0)
	//{
	//	cache[n][m] = 1;
	//	return 1;
	//}

	int count = 0;

	for (int i = 1; i <= n - 1; i++)
	{
		int next_partition;
		if (cache[n - i][i] > 0)
			next_partition = cache[n - i][i];
		else
		{
			next_partition = partition(n - i, i);
			cache[n - i][i] = next_partition;
		}

		count += next_partition;
	}

	return count + 1;
}