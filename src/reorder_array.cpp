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

//#define DEBUG

#ifdef DEBUG
#define debug(numbers, length) print_numbers(numbers, length)
#else
#define debug(numbers, length)
#endif

void print_numbers(int numbers[], int length)
{
	int len = 0;
	while(len<length) {
		cout << numbers[len] << ' ';
		len++;
	}
	cout << endl;
	#ifdef DEBUG
	len = 0;
	while(len<length) {
		cout << (numbers[len])%2 << ' ';
		len++;
	}
	cout << endl;
	#endif
}

void reorder(int numbers[], int length)
{
	if(!numbers || length<=0)
		return;
	int* head,* tail;
	head = numbers; 
	tail = numbers+length-1;
	bool odd = false, even = false;
	//int & 0x01 �������⣬������ȷ�ж���ż�� 
	while(head<tail && head != tail) { //head!=tail������ֹȫ��������ȫ��ż����ָ�볬����Χ 
		//if((*head)&0x01) { //���������ָ�����β�����ߣ�ż����ֹͣ 
		if((*head)%2) {
			++head;			
		} else {
			odd = true;
		}
		//if((*tail)&0x01 == 0) { //�����ż������ͷ�����ߣ�������ֹͣ 
		if((*tail)%2 == 0) {
			--tail;
		} else {
			even = true;
		}
		if(odd && even) {
			odd = false;
			even = false;
			int temp = *head;
			*head = *tail;
			*tail = temp;
			head++;
			tail--;
			debug(numbers, 15);
		}			
	}
}

int main(int argc, char** argv)
{
	int numbers_test1[15] = {1, 21, 2, 3, 4, 5, 6, 7, 8, 9, 0, 13, 22, 22, 33};
	debug(numbers_test1, 15);
	reorder(numbers_test1, 15);
	print_numbers(numbers_test1, 15);
	
	int numbers_test2[5] = {1, 3, 5, 7, 9};
	reorder(numbers_test2, 5);
	print_numbers(numbers_test2, 5);
	
	int numbers_test3[5] = {0, 2, 4, 6, 8};
	reorder(numbers_test3, 5);
	print_numbers(numbers_test3, 5);
	
	int numbers_test4[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
	reorder(numbers_test4, 10);
	print_numbers(numbers_test4, 10);	
	
	int numbers_test5[10] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
	reorder(numbers_test5, 10);
	print_numbers(numbers_test5, 10);
	
	return 0;
} 
