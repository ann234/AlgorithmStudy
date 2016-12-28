#include <iostream>
#include <time.h>

using::std::cout;
using::std::endl;
using::std::flush;

//�����迭 ����
#define NUMOFARR 50
//���� ��ũ��
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int maxSum(int *arr, int p);

int main(int argc, char* argv[])
{
	int *arr = new int[NUMOFARR]();
	
	srand((unsigned int)time(NULL));
	cout << "random number: ";
	for (int i = 0; i < NUMOFARR; i++)
	{
		//0~50 ������ ���� ���ϱ�
		int randN = (rand() % 100) - 50;
		arr[i] = randN;
		cout << randN << ", ";
	}
	cout << endl;

	int ret = maxSum(arr, 10);
	cout << "result: " << ret << endl;

	return 0;
}

int maxSum(int *arr, int p)
{
	//����Ƚ�� ���ϱ�
	int count = 0;
	//�ִ밪, �ִ밪�� ������ ���� s <= p <= t
	int max = 0, s, t;

	//s�� 0���� p����
	for (int k = 0; k < p; k++)
	{
		//t�� s(k)���� �迭 ������
		for (int i = k; i < NUMOFARR; i++)
		{
			int tmp = 0;
			//s(k)���� t(i)���� ���� �� ���ϱ�
			for (int j = k; j <= i; j++)
			{
				tmp += arr[j];
				count++;
			}
			//���� ���� ���� �ִ밪���� Ŭ���
			if (tmp > max)
			{
				//��ü
				max = tmp;
				s = k;	t = i;
			}
		}
	}

	cout << "Count: " << count << endl;
	cout << "index: " << s << ", " << t << endl;
	return max;
}