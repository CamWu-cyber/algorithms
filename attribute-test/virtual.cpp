#include <iostream>

class CVirtual {
public:
	//virtual void show_something() = 0;
	/*virtual*/ void show_something() {
		std::cout << "CVirtual" << std::endl;
	}
};

class CInstance: public CVirtual {
public:
	explicit CInstance(int var): var(var) {}
	virtual void show_something();
	int var;
};

void CInstance::show_something()
{
	std::cout << "CInstance variable: " << var << std::endl;
}

class CIns: public CInstance {
public:
	explicit CIns(int test): CInstance(233), test(test) {}
	virtual void show_something();
	int test;
};

void CIns::show_something()
{
	std::cout << "CIns variable: " << test << std::endl;
}

/*
	�麯����������ʵ�ֶ�̬�ԣ���������ʵ��ָ�븳ֵ������
	�������ͬ������ʱ��ִ�е��������е�ʵ��
	���������������������⣬����Լ���������ʵ�ָ��ຯ���ſ�ʵ����
	����Ԥ���ӿڵ�����
	�����麯���������ͬ������ʱ��ִ���Լ���ʵ�� 
*/

int main(int argc, char **argv)
{
	CVirtual *cvirtual = new CInstance(20);
	cvirtual->show_something();
	CInstance *cinstance = new CIns(666);
	cinstance->show_something();
		
	return 0;	
} 
