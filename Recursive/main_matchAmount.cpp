//���� ������ ���� �־�����
//���� �̿��ؼ� Ư�� �ݾ��� �����ϴ� ����� ������ ���ϱ�
#include <iostream>

using::std::cout;
using::std::endl;

//amount: ����� �ݾ�,	bills: ����� ����,	n: ���� ���� ����
int pay(int amount, int bills[], int n);

int main(int argc, char* argv)
{
	int bills[] = { 1, 2, 5, 10, 20, 50 };
	int amount = 100;

	cout << pay(amount, bills, 6) << endl;

	return 0;
}

int pay(int amount, int bills[], int n)
{
	//������ ������ ���
	if (n - 1 == 0)
	{
		//������ ����� �ݾ��� ���� �� �� �ִ� ���
		if ( (amount % bills[n - 1]) == 0 )
			return 1;
		else
			return 0;
	}

	int count = 0;

	//���� ���ݿ��� �����Ϸ��� ������ ���� ������ ���� ����.
	int t = amount / bills[n - 1];
	for (int i = 0; i <= t; i++)
	{
		//���� ���� �ݾ�(amount) - bills[n - 1]���� i���� �ݾ��� �� �ݾ��� �ְ�
		//���� ����� ������ �� �ִ� ����� ���� ����(���)
		count += pay(amount - (bills[n - 1] * i), bills, n - 1);
	}

	return count;
}