//graycode 알고리즘
#include <iostream>

//n-bit gray code를 만드려면 
//1. (n-1)-bit gray code 앞에 0을,
//2. 역순 (n-1)-bit gray code 앞에 1을 붙이고 더한다.
//Ex) 2bit gray code: 00/01/11/10 -> 3bit gray code: 000/001/011/010/110/111/101/111

using::std::cout;
using::std::endl;

void print_code(int code[], int len);
void print_gray(int code[], int index, int n);
void print_gray_reverse(int code[], int index, int n);

int main(int argc, char* argv[])
{
	//만들 gray code의 bit 설정
	int* code = new int[4];
	print_gray(code, 0, 4);
}

//(len)bit 하나를 출력한다
void print_code(int code[], int len)
{
	for (int i = 0; i < len; i++)
		cout << code[i];
	cout << endl;
}

//code는 gray code의 한 bit 문자열
void print_gray(int code[], int index, int n)
{
	//index와 n이 같다: n-bit gray code 한 부분을 완성했다.
	if (index == n)
	{
		//출력하고 끝냄
		print_code(code, n);
		return;
	}

	//gray code 만들기
	code[index] = 0;
	print_gray(code, index + 1, n);
	//역순 gray code 만들기
	code[index] = 1;
	print_gray_reverse(code, index + 1, n);
}

void print_gray_reverse(int code[], int index, int n)
{
	if (index == n)
	{
		print_code(code, n);
		return;
	}

	//역순 gray code는 1으로 시작한다.
	code[index] = 1;
	print_gray_reverse(code, index + 1, n);
	code[index] = 0;
	print_gray(code, index + 1, n);
}