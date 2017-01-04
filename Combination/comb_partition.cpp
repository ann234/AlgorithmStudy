//Spanning tree를 최대한 edge를 끊지 않고 이등분하는 경우 구하기
#include <iostream>
#include <time.h>

#define MAXN 10

using::std::cout;
using::std::cin;
using::std::endl;

//friend_count: 한 vertex의 edge 개수, friend_list: vertex와 이어진 다른 vertex의 index
int friend_count[MAXN], friend_list[MAXN][MAXN];
//edge의 끊어짐을 최소로해서 나눌 때의 경우
int partition[MAXN];
//최소 끊어짐 수
int min_broken = MAXN * MAXN;

//s: partition의 한 부분, setSize, n, k, index
void getPartition(int s[], int n, int k, int index);

int main(int argc, char *argv[])
{
	//vertex 개수 입력
	int n;
	cout << "input n: ";
	cin >> n;
	if (n % 2 != 0)
	{
		cout << "짝수만 입력해야 합니다";
		return 0;
	}

	//각 vertex당 edge 입력
	for (int i = 0; i < n; i++)
	{
		int nFriend;
		cout << i << ": ";
		cin >> nFriend;

		friend_count[i] = nFriend;
		for (int j = 0; j < nFriend; j++)
		{
			cin >> friend_list[i][j];
		}
	}

	int *s = new int();
	getPartition(s, n, n / 2, 0);

	for (int i = 0; i < n; i++)
		cout << partition[i] << " ";

	return 0;
}

void evaluate_graph(int s[], int n)
{
	int nBroken = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < friend_count[s[i]]; j++)
		{
			//처음 검사하는 vertex인 경우, vertex와 이어진 다른 vertex가 서로 떨어지게 된 경우
			if (i < friend_list[i][j] && s[i] != s[friend_list[i][j]])
				nBroken++;
		}
	}
	
	if (nBroken < min_broken)
	{
		min_broken = nBroken;
		for (int i = 0; i < n; i++)
			partition[i] = s[i];
	}
}

void getPartition(int s[], int n, int k, int index)
{
	if (k == 0)
	{
		for (int i = index; i < n; i++)
			s[i] = 0;
		evaluate_graph(s, n);
	}
	else if (index == n)
		return;
	else
	{
		s[index] = 0;
		getPartition(s, n, k, index + 1);
		s[index] = 1;
		getPartition(s, n, k - 1, index + 1);
	}
}