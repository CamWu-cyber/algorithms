#include <iostream>

using namespace std;

//#define DEBUG

#ifdef DEBUG
#define debug(number) print_binary(number)
#else
#define debug(number)
#endif

void print_binary(int number)
{
	cout << '[' << number << "]: "; 
	unsigned int flag = 0x80000000, count = 0;
	while(count<32) {
		if(number&flag) {
			cout << '1';
		} else {
			cout << '0';
		}
  		 	
		flag = flag >> 1;
		count++;
	}
	cout << endl;
}
//���� ���� ʱ��������ѭ�� 
int numbers_in_binary_v1(int number)
{
	int count = 0;
	while(number) {
		if(number&0x01) {
			count++;
		}
		number = number >> 1;
	}
	
	return count;
}

int numbers_in_binary_v2(int number)
{
	int res = 0, count = 0;
	int flag = 0x01;
	while(count<32) {
		if(number&flag)
			res++;
		flag = flag << 1;
	}
	
	return res;
}
//ͨ�� -1 Ȼ��ͨ����ԭ����Ϊ������������ұߵ� 1 ȥ�� 
int numbers_in_binary_v3(int number)
{
	int res = 0;
	while(number) {
		res++;
		debug(number-1);
		debug(-1);
		number = (number-1) & number;
		debug(number);
	}
	
	return res;
}

int main(int argc, char** argv)
{
	signed int test = 0x80000002;
	//������Ϊ����ʱ�����λ�ĸ�����ʶλ 1 �ᴫ����ȥ��Ϊ�˱��ָ��������λ������ 1
	//���м�����е� 1 �ĸ�����Ҫͨ���ⲿ�ƶ���־λ����ɣ������������ѭ�� 
	debug(test);
	debug(test>>1);
	debug(test>>5);
	
	cout << numbers_in_binary_v3(test);
	
	return 0;
}
