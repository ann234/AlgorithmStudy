//중복순열 구하기
#include <iostream>
#include <time.h>

using::std::cout;
using::std::cin;
using::std::endl;

void rperm(int s[], int n, int k, int index);

int main(int argc, char *argv[])
{
	int n = 3, k = 2;
	//int *s = (int*)malloc(sizeof(int) * n * k);
	int *s = new int[n * k];
	rperm(s, 0, 3, 2);

	//free(s);
	delete []s;
	return 0;
}

void rperm(int s[], int setSize, int n, int k)
{
	if (setSize == k)
	{
		for (int i = 0; i < k; i++)
			cout << s[i] << " ";
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		s[setSize] = i;
		rperm(s, setSize + 1, n, k);
	}
}