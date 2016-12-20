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
	//Polyomino를 구성할 사각형 개수
	int nQuad = 200;
	dynamicArr = new int*[nQuad + 1];
	
	for (int i = 0; i <= nQuad; i++)
	{
		dynamicArr[i] = (int*)malloc(sizeof(int) * (nQuad + 1));
		for (int j = 0; j <= nQuad; j++)
			dynamicArr[i][j] = -1;
	}

	//결과값
	unsigned ret = 0;
	//첫 줄의 개수(i) 따라 for문

	//수행시간 측정
	clock_t begin, end;
	//재귀 polyomino
	/*begin = clock();

	for (int i = 1; i <= nQuad; i++)
		ret += poly(nQuad, i);

	end = clock();
	cout << "Run time: " << ((end - begin) / CLOCKS_PER_SEC) << endl;
	cout << "result: " << ret % 10000000 << endl;*/

	//동적 polyomino
	ret = 0;
	begin = clock();

	for (int i = 1; i <= nQuad; i++)
		ret += poly_dynamic(nQuad, i);

	end = clock();
	cout << "Run time: " << ((end - begin) / CLOCKS_PER_SEC) << endl;
	cout << "result: " << ret % 10000000 << endl;

	getchar();
}

//n : 주어진 사각형 개수	first : 첫 줄을 구성할 사각형 개수
unsigned poly_dynamic(int n, int first)
{
	int ret = 0;

	//동적배열에 값이 저장되어 있는 경우
	if (dynamicArr[n][first] > 0)
	{
		//꺼내서 사용
		return dynamicArr[n][first];
	}

	//동적 알고리즘
	//남은 사각형 개수와 구성하려는 polyomino의 첫 줄의 개수가 같으면
	//결국 한 줄 밖에 안만들어지므로 경우의 수는 1
	if (n == first)
	{
		//동적배열에 n개에서 첫 줄에 first만큼 쌓고 만들 수 있는 polyomino 경우의 수 저장
		dynamicArr[n][first] = 1;
		return 1;
	}
	else
	{
		//첫 줄을 구성하고 남은 사각형 개수(n - first)와 다음 줄을 구성할 사각형의 개수(i)로
		//이어서 다음 줄의 polyomino 경우의 수를 구함
		for (int i = 1; i <= n - first; i++)
		{
			//n - first개에서 첫 줄 i개로 만들 수 있는 polyomino 경우의 수 구하고
			int count = poly_dynamic(n - first, i);
			//동적배열에 저장
			dynamicArr[n - first][i] = count;

			//(i + first - 1)을 곱하는 이유는 이전 줄과 이번 줄에서 조합할 수 있는 경우를 곱하기 위해?
			//□□
			//□□□	이러한 경우는 i = 3, first = 2 이므로 (3 + 2 - 1)=4 총 4가지 배치 경우가 생김.
			ret += (i + first - 1) * count % 10000000;
			ret %= 10000000;
		}
		return ret;
	}
}

int poly(int n, int first)
{
	int count = 0;

	//재귀
	//남은 사각형 개수와 구성하려는 polyomino의 첫 줄의 개수가 같으면
	//결국 한 줄 밖에 안만들어지므로 경우의 수는 1
	if (n == first)
	{
		return 1;
	}
	else 
	{
		//첫 줄을 구성하고 남은 사각형 개수(n - first)와 다음 줄을 구성할 사각형의 개수(i)로
		//이어서 다음 줄의 polyomino 경우의 수를 구함
		for (int i = 1; i <= n - first; i++)
		{
			//(i + first - 1)을 곱하는 이유는 이전 줄과 이번 줄에서 조합할 수 있는 경우를 곱하기 위해?
			//□□
			//□□□	이러한 경우는 i = 3, first = 2 이므로 (3 + 2 - 1)=4 총 4가지 배치 경우가 생김.
			count += (i + first - 1) * poly(n - first, i);
		}
		//cout << "(" << n - first << "," << first << ") : " << count * first << endl;
		return count;
	}
}