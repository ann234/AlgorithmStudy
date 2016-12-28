#include <iostream>
#include <time.h>

using::std::cout;
using::std::endl;
using::std::cin;
using::std::flush;

int poly(int n, int first);
unsigned poly_dynamic(int n, int first);

static int** dynamicArr;

int main(int argc, char* argv[])
{
	//Polyomino�� ������ �簢�� ����
	int nQuad = 200;
	dynamicArr = new int*[nQuad + 1];
	
	for (int i = 0; i <= nQuad; i++)
	{
		dynamicArr[i] = (int*)malloc(sizeof(int) * (nQuad + 1));
		for (int j = 0; j <= nQuad; j++)
			dynamicArr[i][j] = -1;
	}

	//�����
	unsigned ret = 0;
	//ù ���� ����(i) ���� for��

	//����ð� ����
	clock_t begin, end;
	//��� polyomino
	/*begin = clock();

	for (int i = 1; i <= nQuad; i++)
		ret += poly(nQuad, i);

	end = clock();
	cout << "Run time: " << ((end - begin) / CLOCKS_PER_SEC) << endl;
	cout << "result: " << ret % 10000000 << endl;*/

	//���� polyomino
	ret = 0;
	begin = clock();

	for (int i = 1; i <= nQuad; i++)
		ret += poly_dynamic(nQuad, i);

	end = clock();
	cout << "Run time: " << ((end - begin) / CLOCKS_PER_SEC) << endl;
	cout << "result: " << ret % 10000000 << endl;

	getchar();
}

//n : �־��� �簢�� ����	first : ù ���� ������ �簢�� ����
unsigned poly_dynamic(int n, int first)
{
	int ret = 0;

	//�����迭�� ���� ����Ǿ� �ִ� ���
	if (dynamicArr[n][first] > 0)
	{
		//������ ���
		return dynamicArr[n][first];
	}

	//���� �˰���
	//���� �簢�� ������ �����Ϸ��� polyomino�� ù ���� ������ ������
	//�ᱹ �� �� �ۿ� �ȸ�������Ƿ� ����� ���� 1
	if (n == first)
	{
		//�����迭�� n������ ù �ٿ� first��ŭ �װ� ���� �� �ִ� polyomino ����� �� ����
		dynamicArr[n][first] = 1;
		return 1;
	}
	else
	{
		//ù ���� �����ϰ� ���� �簢�� ����(n - first)�� ���� ���� ������ �簢���� ����(i)��
		//�̾ ���� ���� polyomino ����� ���� ����
		for (int i = 1; i <= n - first; i++)
		{
			//n - first������ ù �� i���� ���� �� �ִ� polyomino ����� �� ���ϰ�
			int count = poly_dynamic(n - first, i);
			//�����迭�� ����
			dynamicArr[n - first][i] = count;

			//(i + first - 1)�� ���ϴ� ������ ���� �ٰ� �̹� �ٿ��� ������ �� �ִ� ��츦 ���ϱ� ����?
			//���
			//����	�̷��� ���� i = 3, first = 2 �̹Ƿ� (3 + 2 - 1)=4 �� 4���� ��ġ ��찡 ����.
			ret += (i + first - 1) * count % 10000000;
			ret %= 10000000;
		}
		return ret;
	}
}

int poly(int n, int first)
{
	int count = 0;

	//���
	//���� �簢�� ������ �����Ϸ��� polyomino�� ù ���� ������ ������
	//�ᱹ �� �� �ۿ� �ȸ�������Ƿ� ����� ���� 1
	if (n == first)
	{
		return 1;
	}
	else 
	{
		//ù ���� �����ϰ� ���� �簢�� ����(n - first)�� ���� ���� ������ �簢���� ����(i)��
		//�̾ ���� ���� polyomino ����� ���� ����
		for (int i = 1; i <= n - first; i++)
		{
			//(i + first - 1)�� ���ϴ� ������ ���� �ٰ� �̹� �ٿ��� ������ �� �ִ� ��츦 ���ϱ� ����?
			//���
			//����	�̷��� ���� i = 3, first = 2 �̹Ƿ� (3 + 2 - 1)=4 �� 4���� ��ġ ��찡 ����.
			count += (i + first - 1) * poly(n - first, i);
		}
		//cout << "(" << n - first << "," << first << ") : " << count * first << endl;
		return count;
	}
}