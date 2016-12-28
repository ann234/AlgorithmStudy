//n과 m을 입력받아서(n >= m), m개의 자연수를 더해서 n을 만드는 모든 방법 출력 프로그램
#include <iostream>

using::std::cout;
using::std::endl;

//nums: 합해서 sum이 만들어지는 자연수들을 저장한 배열
//index: 현재 nums를 구성하고 있는 자연수의 개수. 0부터 시작해 n까지
//sum: 구하고자 하는 합.
//n: 몇 개의 자연수로 합을 만들건지
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
	//자연수 개수가 한계치일 경우
	if (index == n)
	{
		//자연수 배열의 합이 구하고자 했던 자연수와 같을 경우
		if (sum == 0)
		{
			for (int i = 0; i < n; i++)
			{
				//배열 안의 자연수 출력
				cout << nums[i] << ", ";
			}
			cout << endl;
			return 1;
		}
		return 0;
	}

	//1부터 목표값까지
	for (int i = 1; i <= sum; i++)
	{
		//index번째 배열에 자연수 i 저장
		nums[index] = i;
		//index + 1번째 숫자로 넘어가며 목표값에 더한 i값을 빼준다.
		makeNaturalNum(nums, index + 1, sum - i, n);
	}
}