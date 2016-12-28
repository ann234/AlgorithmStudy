//부분집합 출력하기
//집합의 크기 n을 받으면 {0, 1, 2, ... n - 1}의 부분집합을 출력하는 프로그램
#include <iostream>

using::std::cout;
using::std::endl;

//s: 출력할 부분집합, setSize: 부분집합의 크기, n: 집합의 크기
void print_subset(int s[], int setSize, int n, int index);
void print_arr(int s[], int setSize);

int main(int argc, char* argv[])
{
	int n = 5;
	int *s = new int[n];

	print_subset(s, 0, n, 0);

	return 0;
}

void print_subset(int s[], int setSize, int n, int index)
{
	//끝까지 탐색했을 경우 출력
	if (index == n)
	{
		print_arr(s, setSize);
		return;
	}

	s[setSize] = index;
	//index의 원소를 포함하는 경우
	//setSize를 증가시켜 안전하게 index가 s에 저장되도록 한다.
	print_subset(s, setSize + 1, n, index + 1);
	//포함하지 않는 경우
	//setSize를 증가시키지 않아 다음 함수 호출때 s[setSize]에 index + 1이 덮어씌워지도록 한다.
	print_subset(s, setSize, n, index + 1);
}

void print_arr(int s[], int setSize)
{
	for (int i = 0; i < setSize; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}