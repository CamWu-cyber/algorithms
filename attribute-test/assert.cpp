#include <iostream>
#include <cassert>

using namespace std;

bool assert_test(bool bl)
{
	cout << "assert_test: " << bl << endl;
	
	return bl;
}

int main(int argc, char **argv)
{
	//assert������ŵ��Ǻ�������ô������ִ�к�����Ȼ����ݷ���ֵ
	//�ж��Ƿ�assert�ɹ��� 
	assert(assert_test(true));
	assert(assert_test(false));
	
	return 0;
}
