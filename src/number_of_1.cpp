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
#include <cstring>
#include <cstdlib>

using namespace std;

int power_base_10(int n)
{
	int result = 1;
	for(int i = 0; i < n; i++)
		result *= 10;
	
	return result;
}

int number_of_1(char *str_num, int length)
{
	if (length <= 0)
		return 0;
		
	int first = *str_num - '0';
	if (length == 1) {
		if (first == 0)
			return 0;
		else
			return 1;
	}
	
	int first_num = 0;
	int other_num = 0;
	//�������λ�� 1 ������µ����� 
	if (first == 1) //��һλΪ 1 ����� 
		first_num = atoi(str_num + 1) + 1;
	else //��һλ >1 ���������ʱ���λΪ 1 �����¶������ 
		first_num = power_base_10(length - 1);
	//�������λ�� 2 ����������� 
	/* 
	if (first == 2)
		other_num = number_of_1(str_num + 1, length - 1);
	else if (first > 2){
		int other = power_base_10(length - 1) - 1;
		char str_num[20];
		sprintf(str_num, "%d", other);
		int len_other = strlen(str_num);
		other_num = (first - 2) * number_of_1(str_num, len_other);
		other_num += number_of_1(str_num + 1, length - 1);
	}
	
	int other = power_base_10(length - 1) - 1;
	char str_num_[20];
	sprintf(str_num, "%d", other);
	int len_other = strlen(str_num_);
	int recursive_num = number_of_1(str_num_, len_other);
	*/
	
	other_num = first * (length - 1) * power_base_10(length - 2);
	int recursive_num = number_of_1(str_num+1, length-1);
	
	return (first_num + other_num + recursive_num);	
}

int number_of_1_between_1_and_n(int n)
{
	if (n <= 0)
		return 0;
		
	char str_num[20];
	sprintf(str_num, "%d", n);
	int length = strlen(str_num);
	//cout << length;
	return number_of_1(str_num, length);
} 

int stupid_solution(int n)
{
	if (n <= 0)
		return 0;
		
	int result = 0;
	for (int i=1; i<=n; i++) {
		int temp = i;
		while (temp) { //����ĳ�������ж��ٸ� 1 
			if (temp%10 == 1)
				result++;
			temp = temp / 10;
		}
	}
	
	return result;
}

int my_solution(int n)
{
	if (n <= 0)
		return 0;
		
	int result = 0;
	char str_num[20];
	sprintf(str_num, "%d", n);
	
	int num_len = strlen(str_num);
	//������֪��ʮ�������ж���λ��Ȼ��������е�������һ�𿴳��Ǿ���
	//�����ͱ���˱���ÿһ���ж��ٸ� 1 �������� 
	//���������ֵ n ��������������λ�������������� 
	//��ͳһ׼������ײ�����һ�� 0 
	//��һ��ÿ 10 ����(0-9)����һ�� 1 ���ظ� 1 �Σ�����һ�����ڵ����� >1 ʱ���� 1 ���֣�������಻���� 1 
	//�ڶ���ÿ 100 ��������һ�� 1 �������ظ� 10 �Σ�����һ�����ڵ����� >10 ʱ���� 1 ���֣�������಻���� 10
	//������ÿ 1000��������һ�� 1 �������ظ� 100 �Σ�����һ�����ڵ����� >100 ʱ���� 1 ���֣�������಻���� 100
	//�Դ����ƣ���ÿһ�н��м��� 
	for (int i=0; i<num_len; i++) {
		//���� 1 ������ 
		int base = power_base_10(i+1);
		//���� 1 �������� 
		int quotient = (n+1) / base;
		//����һ�����ڵ� 
		int remainder = (n+1) % base;
		//���� 1 ���ظ��Ĵ��� 
		base /= 10;
		//���������г��ֵ��ܴ��� 
		result += base * quotient;
		//���������� 1 �Ĵ��� 
		if (remainder > base) { //������һ�е��ظ�����ʱ�Ż���� 1 
			remainder -= base;  //���� 1 �Ĵ��� 
			if (remainder > base)	//�ܴ�����������һ�����ڳ��� 
				remainder = base;
		} else {
			remainder = 0; //���û�г��֣���Ϊ 0 
		}
		result += remainder;
	}
	
	return result;
}

void Test(int n, int answer)
{
	int number_of_1 = number_of_1_between_1_and_n(n);
	if (number_of_1 == answer)
		cout << "success-->";
	else
		cout << "failed-->" << n << "-->";
	cout << "number_of_1: " << number_of_1 << endl;
	number_of_1 = stupid_solution(n);
	if (number_of_1 == answer)
		cout << "success-->";
	else
		cout << "failed-->" << n << "-->";
	cout << "stupid solution: " << number_of_1 << endl;
	number_of_1 = my_solution(n);
	if (number_of_1 == answer)
		cout << "success-->";
	else
		cout << "failed-->" << n << "-->";
	cout << "my solution: " << number_of_1 << endl;
}

int main(int argc, char** argv)
{
	Test(1, 1);//1
	Test(5, 1);//1
	Test(9, 1);//1
	Test(10, 2);//2
	Test(55, 16);//16
	Test(99, 20);//20
	//��������� 
	Test(9999, 4000);//4000
	Test(10000, 4001);//4001
	Test(21345, 18821);//18821
	Test(174396, 164777);//164777
	Test(0, 0);//0
	
	return 0;	
}
