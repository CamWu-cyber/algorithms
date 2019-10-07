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
#include <exception>

using namespace std;

int find_minimum(int numbers[], int length)
{
	if(numbers==NULL || length <= 0)
		throw new exception();
	
	//ԭ������ָ��ÿ��ָ�����֮ǰ���ü� * �ſ��ԣ����� 
	int head, tail, mid;
	head = 0;
	tail = length - 1;
	//�˳�ֵ�������û����ת�ĵ������� 
	mid = head;
	
	while(numbers[head]>=numbers[tail]) {
		if(tail-head==1) {
			mid = tail;
			break;
		}
		
		mid = (head+tail) / 2;
		if(numbers[mid]==numbers[head] && numbers[mid]==numbers[tail]) {
			int res = numbers[head];
			while(head<=tail) {
				if(res>numbers[head])
					res = numbers[head];
				head++;
			}
			return res;
		}
		//����ȼ�� <= �����������ȼ�� >= 
		//��������� = ����ôhead��mid�м����һ�������
		//������С����һ����mid��tail֮�䣬���ȼ�� >=
		//�������ܰ� = ��������䵽mid��tail��
		//����else if�е� = �Ƕ���ģ���ʹ��Ҳ����� if ��֧ 
		if(numbers[mid]>=numbers[head]) {
			head = mid;
		} /*else if(numbers[mid] <= numbers[head]) {
			tail = mid;
		}*/
		else if(numbers[mid] < numbers[head]) {
			tail = mid;
		}
	}	
		
	return numbers[mid];  
}

void Test(int numbers[], int length)
{
	try {
		int minimum = find_minimum(numbers, length);
		cout << minimum << endl;
	} catch(...) {
		cout << "Invalid parameters" << endl;
	}	
}

int main(int argc, char** argv)
{
	int test1[9] = {6, 7, 8, 9, 1, 2, 3, 4, 5};// 1
	int test2[9] = {1, 1, 1, 1, 0, 1, 1, 1, 1};// 0
	int test3[9] = {1, 1, 1, 0, 1, 1, 1, 1, 1};// 0
	int test4[9] = {1, 1, 1, 1, 1, 0, 1, 1, 1};// 0
	int test5[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};// 1
	
	Test(test1, 9);
	Test(test2, 9);
	Test(test2, 9);
	Test(test4, 9);
	Test(test5, 9);
	Test(NULL, 0);
	
	return 0;
}
