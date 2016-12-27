//n�� m�� �Է¹޾Ƽ�(n >= m), m���� �ڿ����� ���ؼ� n�� ����� ��� ��� ��� ���α׷�
#include <iostream>

using::std::cout;
using::std::endl;

//nums: ���ؼ� sum�� ��������� �ڿ������� ������ �迭
//index: ���� nums�� �����ϰ� �ִ� �ڿ����� ����. 0���� ������ n����
//sum: ���ϰ��� �ϴ� ��.
//n: �� ���� �ڿ����� ���� �������
int makeNaturalNum(int nums[], int index, int sum, int n);

int main(int argc, char* argv[])
{
	int sum = 10, count = 3;
	int *nums = new int[count];
	for (int i = 0; i < count; i++)
		nums[i] = 0;

	makeNaturalNum(nums, 0, sum, count);

	return 0;
}

int makeNaturalNum(int nums[], int index, int sum, int n)
{
	//�ڿ��� ������ �Ѱ�ġ�� ���
	if (index == n)
	{
		//�ڿ��� �迭�� ���� ���ϰ��� �ߴ� �ڿ����� ���� ���
		if (sum == 0)
		{
			for (int i = 0; i < n; i++)
			{
				//�迭 ���� �ڿ��� ���
				cout << nums[i] << ", ";
			}
			cout << endl;
			return 1;
		}
		return 0;
	}

	//1���� ��ǥ������
	for (int i = 1; i <= sum; i++)
	{
		//index��° �迭�� �ڿ��� i ����
		nums[index] = i;
		//index + 1��° ���ڷ� �Ѿ�� ��ǥ���� ���� i���� ���ش�.
		makeNaturalNum(nums, index + 1, sum - i, n);
	}
}