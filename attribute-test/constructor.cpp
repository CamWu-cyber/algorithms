#include <iostream>

using namespace std;

//#define DEBUG

#ifdef DEBUG
#define debug(numbers, length) print_numbers(numbers, length)
#else
#define debug(numbers, length)
#endif

class constructor
{
public:
	int value;
	constructor(): value(10) {}
};
//�ְ� main д�� ~ ~ ~ ~ ~ ~ ~ 
//������ʾ��18 undefined reference to `WinMain@16' 
int main(int argc, char** argv)
{
	constructor* ctr = new constructor[5];
	char* ch = new char[5];
	cout << ctr->value << ' ';
	//��һ�ַ��ʷ��� 
	for(int i=0; i<5; i++) {
		//ctr����Ϊ���������õģ�ctr[i]����ʵ�������ˣ�������ָ���� 
		/* 
		constructor ct = ctr[i];
		cout << ct.value << ' ';
		*/
		cout << ctr[i].value << ' ';
	}
	
	cout << endl;
	//�ڶ��ַ��ʷ��� 
	constructor* end = ctr+5-1;
	cout << end->value << ' ';
	for(;end>=ctr;end--) {
		cout << end->value << ' ';
	}
	
	return 0;
}
