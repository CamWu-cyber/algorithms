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

template <typename Dtype>
class MergeSort {
public:
	MergeSort() {}
	~MergeSort() {}
	
	static void sort(Dtype *data, int length);
private:
	static void do_sort(Dtype *data, int start, int end);
	static void do_merge(Dtype *data, int start, int middle, int end);
};

template <typename Dtype>
void MergeSort<Dtype>::sort(Dtype *data, int length)
{
	if (data == NULL || length <=0)
		return;
	
	do_sort(data, 0, length-1);
}

template <typename Dtype>
void MergeSort<Dtype>::do_sort(Dtype *data, int start, int end)
{
	if (start == end)
		return;
	std::cout << "do_sort" << std::endl;
	/* �͵�һ������ֵ��������� start=1, end=2 --> middle=1 */	
	int middle = (start + end) >> 1;
	if (middle > start)
		do_sort(data, start, middle);
	// ��ֵ�ָ��Ұ벿�� 
	/* 
		��start=1��end=2ʱ��middle=1�������ѭ���ˣ� 
		��������ֶβ��������֣�Ҫ��middle�ָ��ϰ벿�ֲſ���
		�ϰ벿���� start �� middle 
		��벿���� middle+1 �� end 
	*/	
	if (middle < end)
		do_sort(data, middle+1, end);
		
	do_merge(data, start, middle+1, end);
}

template <typename Dtype>
void MergeSort<Dtype>::do_merge(Dtype *data, int start, int middle, int end)
{
	int left_size = middle - start;
	int right_size =  end - middle + 1;
	Dtype start_array[left_size];
	Dtype middle_array[right_size];
	
	std::cout << "do_merge" << std::endl;
	
	for (int i=0; i<left_size; i++) {
		start_array[i] = data[start+i];
	}
	
	for (int i=0; i<right_size; i++) {
		middle_array[i] = data[middle+i];
	}
	
	int left = 0, right = 0;
	while (left < left_size && right < right_size) {
		if (start_array[left] < middle_array[right]) {
			data[start++] = start_array[left++];
		} else {
			data[start++] = middle_array[right++];
		}
	}
	
	while (left < left_size) {
		data[start++] = start_array[left++];
	}
	
	while (right < right_size) {
		data[start++] = middle_array[right++];
	}
}
