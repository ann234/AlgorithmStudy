//여러 종류의 지폐가 주어지고
//지폐를 이용해서 특정 금액을 지불하는 방법의 가지수 구하기
#include <iostream>

using::std::cout;
using::std::endl;

//amount: 계산할 금액,	bills: 사용할 지폐,	n: 지폐 종류 개수
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
	//마지막 지폐인 경우
	if (n - 1 == 0)
	{
		//마지막 지폐로 금액을 전부 낼 수 있는 경우
		if ( (amount % bills[n - 1]) == 0 )
			return 1;
		else
			return 0;
	}

	int count = 0;

	//현재 가격에서 지불하려는 지폐의 값을 나눠서 몫을 구함.
	int t = amount / bills[n - 1];
	for (int i = 0; i <= t; i++)
	{
		//현재 지불 금액(amount) - bills[n - 1]지폐 i장의 금액을 뺀 금액을 넣고
		//다음 지폐로 지불할 수 있는 경우의 수를 구함(재귀)
		count += pay(amount - (bills[n - 1] * i), bills, n - 1);
	}

	return count;
}