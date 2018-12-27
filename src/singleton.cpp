#include <iostream>

using namespace std;

class singleton_v1
{
public:
	int data_test;
	static singleton_v1& getInstance() {
		static singleton_v1 singleton;
		return singleton;
	}
private:	
	singleton_v1() {}
};

int main(int argc, char** argv)
{
	//ʹ�÷���ֵ�����òŻᷢ��ʹ�õ���ͬһ����ʵ�� 
	cout << "mysingleton1: ";
	singleton_v1& mysingleton1 = singleton_v1::getInstance();
	mysingleton1.data_test = 0;
	cout << mysingleton1.data_test << ' ';
	mysingleton1.data_test++;
	cout << mysingleton1.data_test << '\n';
	
	cout << "mysingleton2: ";
	singleton_v1& mysingleton2 = singleton_v1::getInstance();
	cout << mysingleton2.data_test << ' ';
	mysingleton2.data_test++;
	cout << mysingleton2.data_test << '\n';
	
	//ֱ�ӽ�����ֵ��ֵ���������������������ʹ��ͬһ�����ʵ�� 
	cout << "mysingleton3: ";
	singleton_v1 mysingleton3 = singleton_v1::getInstance();
	cout << mysingleton3.data_test << ' ';
	mysingleton3.data_test++;
	cout << mysingleton3.data_test << '\n';
	
	cout << "mysingleton4: ";
	singleton_v1 mysingleton4 = singleton_v1::getInstance();
	cout << mysingleton4.data_test << ' ';
	mysingleton4.data_test++;
	cout << mysingleton4.data_test << ' ';
	cout << mysingleton4.data_test << ' ';
	mysingleton4.data_test++;
	cout << mysingleton4.data_test << '\n';

	cout << "mysingleton1: " << mysingleton1.data_test << '\n';
	cout << "mysingleton2: " << mysingleton2.data_test << '\n';	
	cout << "mysingleton3: " << mysingleton3.data_test << '\n';
	cout << "mysingleton4: " << mysingleton4.data_test << '\n';
	
	//��������Կ�����ʵ��1��ʵ��2��������ͬһ��ʵ��
	//��ʵ��3��ʵ��4��ʵ��1��ʵ��2��ָͬ���ʵ���ĸ��������Ҹ������Լ�������
	//���ԣ�ֻ��ʹ���෵�ص����òſ���ʹ��ͬһ����ʵ�� 
	
	return 0;
}
