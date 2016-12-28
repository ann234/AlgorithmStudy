//이항연산 동적 프로그래밍
#include <iostream>

using::std::cout;
using::std::endl;

//N개 중에서 R개를 고를 경우의 수
#define N 50
#define R 20

//결과값 저장해 둘 이차원 배열
int** cache;

//재귀적 이항연산
int choose(int n, int r);
//동적 이항연산
int choose_dynamic(int n, int r);

int main(int argc, char* argv[])
{
	//0~N개 중에서
	cache = new int*[N + 1];
	for (int i = 0; i < N; i++)
	{
		//0~R개를 뽑는 경우
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