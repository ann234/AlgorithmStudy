//최단경로 개수 구하는 문제
#include <iostream>

using::std::cout;
using::std::endl;

//map: 전체 지도를 나타내는 2차원 행렬
void pathFinder(int *map[], int size);
int pathFinder_enjoy(int *map[], int size, int i, int j);
//void pathFinder_enjoy(int *map[], int size, int curEnjoy, int limit);

int main(int argc, char* argv[])
{
	unsigned int size = 10;
	int **map;
	map = new int*[size];
	for (int i = 0; i < size; i++)
	{
		map[i] = new int[size];
		for (int j = 0; j < size; j++)
			map[i][j] = -1;
	}

	map[1][2] = 0;	map[1][3] = 0;	map[2][2] = 0;
	pathFinder(map, size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
		

	return 0;
}

void pathFinder(int *map[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//외곽에 위치한 경우
			if (i == 0 || j == 0)
				map[i][j] = 1;
			else if(map[i][j] != 0)
			{
				map[i][j] = map[i - 1][j] + map[i][j - 1];
			}
		}
	}
}

int pathFinder_enjoy(int *map[], int size, int i, int j)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//외곽에 위치한 경우
			if (i == 0 || j == 0)
				return map[i][j];
			if (i == 0)
				return pathFinder_enjoy(map, size, i, j - 1) + pathFinder_enjoy(map, size, i, j);
			if (j == 0)
				return pathFinder_enjoy(map, size, i - 1, j) + pathFinder_enjoy(map, size, i, j);
			return pathFinder_enjoy(map, size, i - 1, j) + 
				pathFinder_enjoy(map, size, i, j - 1) + pathFinder_enjoy(map, size, i, j);
		}
	}
}

//void pathFinder_enjoy(int i, int j, int *map[], int size, int curEnjoy, int limit)
//{
//
//	pathFinder_enjoy(i + 1, j, map, size, curEnjoy + map[i + 1][j], limit - map[i + 1][j]);
//}