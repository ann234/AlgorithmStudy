//���� ���
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

//s: ����� ����, setSize: ������ ũ��, n: n�� �߿���, k: k���� �̴� ����
void print_comb(int s[], int setSize, int n, int k, int index)
{
	//k���� ���� �̾��� ���
	if (k == 0)
	{
		cout << "{";
		for (int i = 0; i < setSize; i++)
			cout << s[i] << " ";
		cout << "}";
	}
	//k���� ���� �ʾҴµ� ��� n���� ���ڸ� ��ȸ���� ��� ����
	else if (index == n)
	{
		return;
	}
	else
	{
		//setSize��°�� ���� ��ġ�� ���ڸ� ����
		s[setSize] = index;
		//�� index�� �̴� ��� setSize�� ����, 1���� �̾����Ƿ� k - 1�� ����
		print_comb(s, setSize + 1, n, k - 1, index + 1);
		//�Ȼ̴� ��� setSize�� �������� �ʴ´�. 
		print_comb(s, setSize, n, k, index + 1);
	}
}

//�ߺ�����
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
		//�ߺ��ؼ� ���� �� �����Ƿ� index�� �̾��� ��� setSize, k�� ��ȭ�ϰ� index�� �������� �ʴ´�
		print_rcomb(s, setSize + 1, n, k - 1, index);
		print_rcomb(s, setSize, n, k, index + 1);
	}
}