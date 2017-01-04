//Spanning tree�� �ִ��� edge�� ���� �ʰ� �̵���ϴ� ��� ���ϱ�
#include <iostream>
#include <time.h>

#define MAXN 10

using::std::cout;
using::std::cin;
using::std::endl;

//friend_count: �� vertex�� edge ����, friend_list: vertex�� �̾��� �ٸ� vertex�� index
int friend_count[MAXN], friend_list[MAXN][MAXN];
//edge�� �������� �ּҷ��ؼ� ���� ���� ���
int partition[MAXN];
//�ּ� ������ ��
int min_broken = MAXN * MAXN;

//s: partition�� �� �κ�, setSize, n, k, index
void getPartition(int s[], int n, int k, int index);

int main(int argc, char *argv[])
{
	//vertex ���� �Է�
	int n;
	cout << "input n: ";
	cin >> n;
	if (n % 2 != 0)
	{
		cout << "¦���� �Է��ؾ� �մϴ�";
		return 0;
	}

	//�� vertex�� edge �Է�
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
			//ó�� �˻��ϴ� vertex�� ���, vertex�� �̾��� �ٸ� vertex�� ���� �������� �� ���
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