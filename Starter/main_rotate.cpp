#include <iostream>

using std::cout;
using std::endl;

int rotateArr(int arr[], int s, int t, bool flag);

int main(int argc, char* argv)
{
	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	if (rotateArr(arr, 3, 7, true) < 0)
		cout << "error";

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	getchar();
	return 0;
}

int rotateArr(int arr[], int s, int t, bool flag)
{
	if (sizeof(arr) <= 0)
		return -1;

	//오른쪽 회전
	if (flag && s < t)
	{
		int last = arr[t];
		for (int i = t; i > s; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[s] = last;
	}
	else
	{
		int last = arr[s];
		for (int i = s; i < t; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[t] = last;
	}

	return 0;
}