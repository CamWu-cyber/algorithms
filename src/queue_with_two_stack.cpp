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
#include <stack>

using namespace std;

template <typename T>
class CQueue {
public:
	CQueue();
	~CQueue();	
	void appendTail(const T& value);
	T& deleteHead();
	void printQueue();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T>
CQueue<T>::CQueue()
{
	while(!stack1.empty())
		stack1.pop();
	while(!stack2.empty())
		stack2.pop();
}

template <typename T>
CQueue<T>::~CQueue()
{
	while(!stack1.empty())
		stack1.pop();
	while(!stack2.empty())
		stack2.pop();
}

template <typename T>
void CQueue<T>::appendTail(const T& value)
{
	stack1.push(value);
}

template <typename T>
T& CQueue<T>::deleteHead()
{
	if(!stack2.empty()) {
		// top ���ص���ջ�������� 
		T& res = stack2.top();
		stack2.pop();
		return res;
	} else if(!stack1.empty()) {
		while(!stack1.empty()) {
			T& res = stack1.top();
			stack2.push(res);
			stack1.pop();
		}
		T& res = stack2.top();
		stack2.pop();
		return res;
	}
}

template <typename T>
void CQueue<T>::printQueue()
{
	if(!stack2.empty()) {
		T& ref = stack2.top();
		size_t stack_size = stack2.size();
		T* top = &ref;
		while(stack_size) {
			cout << *top << ' ';
			stack_size--;
			//windows�е�ջ�Ǵӵ͵�ַ��ߵ�ַ������ 
			top--;
		}
	}
	if(!stack1.empty()) {
		size_t stack_size = stack1.size();
		T& ref = stack1.top();
		//���ÿ��Կ����Ǳ�������ĳһ�ڴ��ֱ��ʹ�ã�ͨ��&��ȡ��ַ 
		T* bottom = &ref;
		//ջ����Ҫ��ͨ��ջ��ָ���ȥ(stack_size-1) 
		bottom = bottom - stack_size + 1;
		while(stack_size) {
			stack_size--;
			cout << *(bottom++) << ' ';
			//cout << bottom++ << ' ';
		}
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	CQueue<int> queue;
	queue.appendTail(1);
	queue.appendTail(2);
	queue.appendTail(3);
	queue.appendTail(4);
	queue.appendTail(5);
	
	queue.deleteHead();
	queue.deleteHead();
	
	queue.printQueue();
	
	queue.appendTail(6);
	queue.appendTail(7);
	queue.appendTail(8);
	queue.appendTail(9);
	
	queue.printQueue();
	
	queue.deleteHead();
	
	queue.printQueue();
	
	queue.deleteHead();
	queue.deleteHead();
	queue.deleteHead();
	queue.deleteHead();
	
	queue.printQueue();
	
	return 0;
}
