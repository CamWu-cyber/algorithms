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
#include <list>

using namespace std;

int solution1(int n, int m)
{
	if (n<1 || m<1)
		return -1;
		
	list<int> numbers;
	for (int i=0; i<n; i++) {
		numbers.push_back(i);
	}
	
	list<int>::iterator current = numbers.begin();
	list<int>::iterator end = numbers.end();
	while (numbers.size()>1) {
		//��ǰ��ָ����ǵ�һ��������Ӧ�ô� 1 ��ʼ���� 
		for (int i=1; i<m; i++) {
			current++;
			if (current == end) {
				current = numbers.begin();
			}
		}
		
		current++;
		list<int>::iterator next = current;
		if (next == end) {
			next = numbers.begin();
		}
		current--;
		cout << "erase: " << *current << endl;
		numbers.erase(current);
		current = next;
	}
	
	return *current;
}
//���ƹ�ʽΪ�� f(n,m) = 0, n=1
//					  = [f(n-1, m) + m] % n, n>1 
int solution2_1(int n, int m)
{
	if (m<1 || n<1)
		return -1;
	//��ʾn=1ʱ���ʣ�������	
	int last = 0;
	for (int i=2; i<=n; i++) {
		//���ݵ��ƹ�ʽ��������Ƶ���һ����i+1�������һ��ʣ�����
		//һֱ������Ƶ� n���� 
		last = (last+m) % i;
	}
	
	return last;
} 

int solution2_2(int n, int m)
{
	if (m<1 || n<1)
		return -1;
	if (n == 1) {
		return 0;
	}
	return (solution2_2(n-1, m) + m) % n;
}

int main(int argc, char **argv)
{
	int n1 = 10, m1 = 3;
	cout << "solution1--the last is: " << solution1(n1, m1) << endl;
	cout << "solution2_1--the last is: " << solution2_1(n1, m1) << endl;
	cout << "solution2_2--the last is: " << solution2_2(n1, m1) << endl;
	int n2 = 5, m2 = 3;
	cout << "solution1--the last is: " << solution1(n2, m2) << endl;
	cout << "solution2_1--the last is: " << solution2_1(n2, m2) << endl;
	cout << "solution2_2--the last is: " << solution2_2(n2, m2) << endl;
	int n3 = 15, m3 = 6;
	cout << "solution1--the last is: " << solution1(n3, m3) << endl;
	cout << "solution2_1--the last is: " << solution2_1(n3, m3) << endl;
	cout << "solution2_2--the last is: " << solution2_2(n3, m3) << endl;
	cout << "solution1--the last is: " << solution1(m3, n3) << endl;
	cout << "solution2_1--the last is: " << solution2_1(m3, n3) << endl;
	cout << "solution2_2--the last is: " << solution2_2(m3, n3) << endl;
	
	return 0;
}
