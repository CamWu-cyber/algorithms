#include <iostream>

#include "bubble.hpp"
#include "quick.hpp"
#include "straight_insert.hpp"
#include "shell.hpp"
#include "straight_select.hpp"
#include "heap.hpp"
#include "merge.hpp"

/*	���Ӷȣ�					ʱ�临�Ӷ�   �ռ临�Ӷ� 
	�������� 
		ð������(Bubble Sort):    O(n^2)��      O(1) 
		��������(Quick Sort):     O(nlogn)     O(nlogn)
	��������
		ֱ�Ӳ�������(Straight Insert Sort): O(n^2)    O(1) 
		shell����(Shell's Sort): O(N^1.3)    O(1)
	ѡ������
		ֱ��ѡ��(Straight Select Sort)   O(n^2)    O(1)
		������(Heap Sort):     O(nlogn)     O(1) 
*/

void showme(int *data, int length)
{
	for (int i=0; i<length; i++) {
		std::cout << data[i] << ' ';
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) 
{
	int data[17] = {6, 6, 38, 1, 9, -1, 6, 8, 4, 7, 9, 66, -5, 11, 64, 22, 44};
	const int nums = 9;
	//BubbleSort<int>::sort(data, nums);
	//showme(data, nums);
	/* nums = 13 �����Ϊ�Σ� */
	//QuickSort<int>::sort(data, nums);
	//showme(data, nums);
	
	//StraightInsertSort<int>::sort(data, nums);
	//showme(data, nums);
	
	//ShellSort<int>::sort(data, nums);
	//showme(data, nums);
	
	//StraightSelectSort<int>::sort(data, nums);
	//showme(data, nums);
	
	//HeapSort<int>::sort(data, nums);
	//showme(data, nums);
	
	MergeSort<int>::sort(data, nums);
	showme(data, nums);
	
	return 0;
}
