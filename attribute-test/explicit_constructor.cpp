#include <iostream>

using namespace std;

class explicit_constructor
{
public:
	explicit explicit_constructor(int num) {
		cout << "explicit_constructor int num = " << num << endl;
	}	
	
	explicit explicit_constructor(char num) {
		cout << "explicit_constructor char num = " << num << endl;
	}
	//explicit_constructor() {cout << "explicit_constructor non" << endl;} 
};

static explicit_constructor exp_global('9');

int main(int argc, char **argv)
{
	//��û��Ĭ�Ϲ��캯��ʱ������������ʽ���캯��ʱ������ʹ����ʽ���캯�� 
	//explicit_constructor *exp_non = new explicit_constructor;
	explicit_constructor *exp_char = new explicit_constructor('6');
	explicit_constructor *exp_int = new explicit_constructor(6);
	
	return 0;
}
