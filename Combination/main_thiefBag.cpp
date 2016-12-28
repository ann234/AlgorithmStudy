//한정된 자산으로 최대 가치 구하기 문제
#include <iostream>
#include <time.h>

using::std::cout;
using::std::endl;

#define max(x, y) ((x) > (y) ? (x) : (y))

void evaluate_knapback(int s[], int setSize);
void subset_knapback(int s[], int setSize, int n, int index, int maxWeight);

int *curMaxItem;
int curMaxValue = 0;
int curMaxSize = 0;

int *weights, *values;

int main(int argc, char* argv[])
{
	int n = 10;
	int maxWeight = n * 2;
	weights = new int[n];
	values = new int[n];
	int *s = new int[n];
	curMaxItem = new int[n];

	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		weights[i] = rand() % 10 + 1;
		values[i] = rand() % 10 + 1;
	}
	
	subset_knapback(s, 0, n, 0, maxWeight);

	cout << "result: " << curMaxValue << endl;
	for (int i = 0; i < curMaxSize; i++)
	{
		cout << "{" << curMaxItem[i] << ", " << values[curMaxItem[i]] << ", " << weights[curMaxItem[i]] << "}";
	}
	cout << endl;

	return 0;
}

void evaluate_knapback(int s[], int setSize)
{
	int currentWeight, currentValue;
	currentWeight = currentValue = 0;

	for (int i = 0; i < setSize; i++)
	{
		currentValue += values[s[i]];
		currentWeight += weights[s[i]];
	}

	if (currentValue > curMaxValue)
	{
		curMaxValue = currentValue;
		curMaxSize = setSize;
		for (int i = 0; i < setSize; i++)
			curMaxItem[i] = s[i];
	}
}

void subset_knapback(int s[], int setSize, int n, int index, int maxWeight)
{
	if (maxWeight < 0)
		return;

	if (index == n)
	{
		evaluate_knapback(s, setSize);
		return;
	}

	s[setSize] = index;
	subset_knapback(s, setSize + 1, n, index + 1, maxWeight - weights[index]);
	subset_knapback(s, setSize, n, index + 1, maxWeight);
}