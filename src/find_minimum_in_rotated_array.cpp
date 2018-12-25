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
