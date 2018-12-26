#include <iostream>

using namespace std;

double power_v1(double base, int exp)
{
	double res = 1.0;
	while(exp) {
		res = res * base;
		exp--;
	}	
	return res;
}
//������ڱ�ʾС��ʱ����������ֱ���ж�ĳ��С����ĳ��С���Ƿ����
//ֻ��ͨ���������Ĳ�ֵ�Ƿ��㹻С���ж������Ƿ���� 
bool equal(double num1, double num2)
{
	if((num1-num2>-0.0000001)&&(num1-num2<0.0000001))
	  return true;
  return false;
}

double power_v2(double base, int exp)
{
	double res = 1.0;
	bool negative = 0;
	if(equal(base, 0.0))
    return base;
	if(base==1.0)
	  return 1.0;
	if(exp<0) {
		exp = -exp;
		negative = 1;
	}
	if(exp==0) {
		return res;
	} else if(exp==1) {
		if(negative)
			return 1/base;
		return base;			
	} else if(exp%2) { //����Ч���������� exp&0x01 �����ж� 
		res = power_v2(base, (exp-1)/2);
		res = res * res; 
		if(negative)
		  return 1/(res*base);
		return res*base;
	} else {
		res = power_v2(base, exp/2);
		if(negative)
		  return 1/(res*res);
		return res*res;
	}
}

void Test(double base)
{
	cout << power_v2(base, 0) << endl;
	cout << power_v2(base, 1) << endl;
	cout << power_v2(base, 2) << endl;
	cout << power_v2(base, 5) << endl;
	
	cout << power_v2(base, -0) << endl;
	cout << power_v2(base, -1) << endl;
	cout << power_v2(base, -2) << endl;
	cout << power_v2(base, -5) << endl;
}

int main(int argc, char** argv)
{
	double test1 = 5.5;
	double test2 = 1.0;
	double test3 = 0.0;
	
	Test(test1);
	Test(test2);
	Test(test3);
	
	return 0;
}
