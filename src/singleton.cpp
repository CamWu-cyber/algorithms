/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

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
