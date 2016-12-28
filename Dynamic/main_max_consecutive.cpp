//연속부분 수열 중 최대합 구하기
#include <iostream>
#include <time.h>

using::std::cout;
using::std::endl;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define LEN 1000

int max_sum1(int *s, int n);
int max_sum2(int *s, int n);
int max_sum_dynamic(int *s, int n);

int memory[LEN + 1];

int main(int argc, char* argv[])
{
	int s[LEN];
	srand(unsigned int(time(NULL)));
	for (int i = 0; i < LEN; i++)
	{
		s[i] = (rand() % 100) - 50;
		cout << s[i] << ", ";
	}
	cout << endl;

	cout << "Result: " << max_sum_dynamic(s, LEN) << endl;

	return 0;
}

int max_sum_dynamic(int *s, int n)
{
	memory[1] = s[0];
	for (int i = 2; i <= n; i++)
		memory[i] = max(memory[i - 1] + s[i - 1], s[i - 1]);

	int max = memory[1];
	for (int i = 2; i <= n; i++)
	{
		max = max(memory[i], max);
	}

	return max;
}

int max_sum1(int *s, int n)
{
	if (n == 1)
		return s[0];
	return max(max_sum2(s, n), max_sum1(s, n - 1));
}

int max_sum2(int *s, int n)
{
	if (n == 1)
		return s[0];
	return max(max_sum2(s, n - 1) + s[n - 1], s[n - 1]);
}