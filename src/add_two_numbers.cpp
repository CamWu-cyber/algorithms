#include <iostream>

using namespace std;
//�ӷ����Էֽ�Ϊ�����Ƶ� (��򣬲���λ��) + (λ�룬��λ) 
int add_ops(int num1, int num2)
{
	int carry = 0;
	int sum = 0;
	
	do {
		//����λ�� 
		sum = num1 ^ num2;
		//��λλ
		carry = (num1 & num2) << 1;
		//������һ��ѭ��������н�Ϊ�򽫽�λ������ 
		num1 = sum;
		num2 = carry; 
	} while (carry);
	
	return sum; 
}

void swap_ops(int a, int b)
{
	a = a + b; // a = a^b;
	b = a - b; // b = a^b;
	a = a - b; // a = a^b;
} 

int main(int argc, char **argv)
{
	cout << add_ops(10, 15) << endl;
	cout << add_ops(15, 13) << endl;
	cout << add_ops(66, 99) << endl;
	cout << add_ops(0, -99) << endl;
	cout << add_ops(-66, 99) << endl;
} 
