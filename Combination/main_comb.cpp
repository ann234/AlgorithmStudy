//조합 출력
#include <iostream>
#include <time.h>

using::std::cout;
using::std::endl;

void print_comb(int s[], int setSize, int n, int k, int index);
void print_rcomb(int s[], int setSize, int n, int k, int index);

int main(int argc, char *argv[])
{
	int n = 4, k = 2;
	int *s = new int[k];
	print_rcomb(s, 0, n, k, 0);

	return 0;
}

//s: 출력할 집합, setSize: 집합의 크기, n: n개 중에서, k: k개를 뽑는 조합
void print_comb(int s[], int setSize, int n, int k, int index)
{
	//k개를 전부 뽑았을 경우
	if (k == 0)
	{
		cout << "{";
		for (int i = 0; i < setSize; i++)
			cout << s[i] << " ";
		cout << "}";
	}
	//k개를 뽑지 않았는데 모든 n개의 숫자를 순회했을 경우 종료
	else if (index == n)
	{
		return;
	}
	else
	{
		//setSize번째에 현재 서치한 숫자를 삽입
		s[setSize] = index;
		//이 index를 뽑는 경우 setSize를 증가, 1개를 뽑았으므로 k - 1을 해줌
		print_comb(s, setSize + 1, n, k - 1, index + 1);
		//안뽑는 경우 setSize는 증가하지 않는다. 
		print_comb(s, setSize, n, k, index + 1);
	}
}

//중복조합
void print_rcomb(int s[], int setSize, int n, int k, int index)
{
	if (k == 0)
	{
		cout << "{";
		for (int i = 0; i < setSize; i++)
			cout << s[i] << " ";
		cout << "}";
	}
	else if (index == n)
		return;
	else
	{
		s[setSize] = index;
		//중복해서 뽑을 수 있으므로 index를 뽑았을 경우 setSize, k만 변화하고 index는 증가하지 않는다
		print_rcomb(s, setSize + 1, n, k - 1, index);
		print_rcomb(s, setSize, n, k, index + 1);
	}
}