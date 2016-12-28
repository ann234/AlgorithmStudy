//graycode �˰���
#include <iostream>

//n-bit gray code�� ������� 
//1. (n-1)-bit gray code �տ� 0��,
//2. ���� (n-1)-bit gray code �տ� 1�� ���̰� ���Ѵ�.
//Ex) 2bit gray code: 00/01/11/10 -> 3bit gray code: 000/001/011/010/110/111/101/111

using::std::cout;
using::std::endl;

void print_code(int code[], int len);
void print_gray(int code[], int index, int n);
void print_gray_reverse(int code[], int index, int n);

int main(int argc, char* argv[])
{
	//���� gray code�� bit ����
	int* code = new int[4];
	print_gray(code, 0, 4);
}

//(len)bit �ϳ��� ����Ѵ�
void print_code(int code[], int len)
{
	for (int i = 0; i < len; i++)
		cout << code[i];
	cout << endl;
}

//code�� gray code�� �� bit ���ڿ�
void print_gray(int code[], int index, int n)
{
	//index�� n�� ����: n-bit gray code �� �κ��� �ϼ��ߴ�.
	if (index == n)
	{
		//����ϰ� ����
		print_code(code, n);
		return;
	}

	//gray code �����
	code[index] = 0;
	print_gray(code, index + 1, n);
	//���� gray code �����
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

	//���� gray code�� 1���� �����Ѵ�.
	code[index] = 1;
	print_gray_reverse(code, index + 1, n);
	code[index] = 0;
	print_gray(code, index + 1, n);
}