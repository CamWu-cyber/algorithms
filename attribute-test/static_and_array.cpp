#include <iostream>

using namespace std;

void static_test()
{
	static int count = 0;
	cout << count++ << endl;
}

int main(int argc, char** argv)
{
	static_test();
	static_test();
	static_test();
	static_test();
	
	int array_test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int* pTest = &array_test[5];
	//ԭ������ķ����ǿ���д ������ֵ �ģ����� 
	cout << m[-2];
	
	return 0;
} 
