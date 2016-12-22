#include <iostream>
#include <time.h>

using::std::cout;
using::std::endl;
using::std::flush;

//정수배열 길이
#define NUMOFARR 50
//값비교 매크로
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int maxSum(int *arr, int p);

int main(int argc, char* argv[])
{
	int *arr = new int[NUMOFARR]();
	
	srand((unsigned int)time(NULL));
	cout << "random number: ";
	for (int i = 0; i < NUMOFARR; i++)
	{
		//0~50 구간의 정수 구하기
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
	//수행횟수 구하기
	int count = 0;
	//최대값, 최대값이 나오는 구간 s <= p <= t
	int max = 0, s, t;

	//s는 0부터 p까지
	for (int k = 0; k < p; k++)
	{
		//t는 s(k)부터 배열 끝까지
		for (int i = k; i < NUMOFARR; i++)
		{
			int tmp = 0;
			//s(k)부터 t(i)까지 값이 합 구하기
			for (int j = k; j <= i; j++)
			{
				tmp += arr[j];
				count++;
			}
			//구한 합이 현재 최대값보다 클경우
			if (tmp > max)
			{
				//교체
				max = tmp;
				s = k;	t = i;
			}
		}
	}

	cout << "Count: " << count << endl;
	cout << "index: " << s << ", " << t << endl;
	return max;
}