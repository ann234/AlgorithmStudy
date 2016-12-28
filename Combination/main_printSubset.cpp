//�κ����� ����ϱ�
//������ ũ�� n�� ������ {0, 1, 2, ... n - 1}�� �κ������� ����ϴ� ���α׷�
#include <iostream>

using::std::cout;
using::std::endl;

//s: ����� �κ�����, setSize: �κ������� ũ��, n: ������ ũ��
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
	//������ Ž������ ��� ���
	if (index == n)
	{
		print_arr(s, setSize);
		return;
	}

	s[setSize] = index;
	//index�� ���Ҹ� �����ϴ� ���
	//setSize�� �������� �����ϰ� index�� s�� ����ǵ��� �Ѵ�.
	print_subset(s, setSize + 1, n, index + 1);
	//�������� �ʴ� ���
	//setSize�� ������Ű�� �ʾ� ���� �Լ� ȣ�⶧ s[setSize]�� index + 1�� ����������� �Ѵ�.
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