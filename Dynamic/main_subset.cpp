//부분집합 구하기
#include <iostream>

using::std::cout;
using::std::endl;

#define max(a, b) ( (a)>(b) ? (a) : (b) )

//n: 구하려는 합, m: 부분집합을 구성할 정수들의 개수, s: 부분집합을 구성할 정수들의 배열
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
	//어느 정수 배열이든 합이 0인 부분집합은 무조건 존재하므로 true(1)
	for (int i = 0; i <= m; i++)
	{
		memory[i][0] = 1;
	}
	//공집합은 합이 0이므로 false(0)
	for (int i = 0; i <= n; i++)
	{
		memory[0][i] = 0;
	}
	
	//정수 배열의 i번째 정수까지 사용하는 경우
	for (int i = 1; i <= m; i++)
	{
		//부분집합의 합이 j를 달성하는 경우
		for (int j = 1; j <= n; j++)
		{
			//정수 배열의 i번째 정수를 사용하는 경우, 사용하지 않는 경우로 나눈 뒤 가능여부를 볼 것인데
			//i번째 정수를 사용하는 경우 그것이 구하려는 합보다는 작아야 한다.
			if (j >= s[i - 1])
			{
				//i번째 정수를 사용하는 경우와 사용하지 않는 경우를 둘 다 검토한 후
				//부분집합이 존재한다면 memory[i][j]에 true(1)을 넣는다.
				memory[i][j] = max(memory[i - 1][j], memory[i - 1][j - s[i - 1]]);
			}
		}
	}

	int _sum = n;
	//m부터 1까지
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