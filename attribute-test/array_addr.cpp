#include <iostream>

using namespace std;

int main()
{
	int test_a[5] = {1, 2, 3, 4, 5};
	int test_b[5] = {6, 7, 8, 9, 10};
	// ����������ָ�� 
	cout << "test_a addr: " << test_a << endl;
	cout << "test_b addr: " << test_b << endl;	
	// ��������ȡ��ַ����ֻ�������ָ�� 
	cout << "&test_a addr: " << &test_a << endl;
	cout << "&test_b addr: " << &test_b << endl;
	// ������ָ��ȡָ��֮�� + 1, �õ�����һ���������ֽ�����С��ƫ��
	// ��˵�� ȡ��ַ�� �ı��������������ʣ�ʹ������һ���������͵�ָ�� 
	cout << "&test_a + 1 addr: " << &test_a + 1 << endl;
	cout << "&test_b + 1 addr: " << &test_b + 1 << endl;
	
	return 0;
}
