#include <iostream>
#include <cstdlib>

using namespace std;

// if you want more detail info, open `#define DEBUG`. 
//#define DEBUG

#ifdef DEBUG
#define debug(data, start, end) print(data, start, end)
#else
#define debug(data, start, end)
#endif

int random_in_range(int start, int end)
{
	if(start==end) {
		return start;
	} else {
		int index = rand()%(end-start) + start;	
		return index;	
	}
}

template <typename T>
void swap(T* v1, T* v2)
{
	T temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

void print(int data[], int start, int end)
{
	if(start>end) {
		cout << "invalid input" << endl;
	} else {
		while(start<=end) {
			cout << data[start] << ' ';
			start++;
		}
	}
	cout << endl;
}

int partition(int data[], int length, int start, int end)
{
	if(data==NULL || length<=0 || start<0 || end>=length) {
		return false;
	}	
	
	int index = random_in_range(start, end);
	#ifdef DEBUG
	cout << "random data[index]: " << data[index] << endl;
	#endif
	debug(data, start, end);
	swap<int>(&data[index], &data[end]);
	debug(data, start, end);
	// smallָ������(������ǰָ���)��С��data[index]������
	//�Ҳ��(������ָ��ָ���)��index֮����Ǵ���data[index]������
	//��˵����� < data[index]������ʱ��small++���������ָ���Ƿ����
	//�������˵������֮���� > data[index]�����ݣ���ô�Ͱ�С�Ľ�������
	//����data[index]��ĩβ�û������б���С����֮�䣬��small++ 
	int small = start-1;
	for(index=start; index<end; ++index) {
		if(data[index]<data[end]) {
			++small;
			#ifdef DEBUG
			cout << "small: " << small << " index: " << index << "--"; 
			#endif
			if(small!=index) {
				swap<int>(&data[index], &data[small]);
			}
			debug(data, start, end); 
		}
	}
	++small;
	swap<int>(&data[small], &data[end]);
	debug(data, start, end);
	
	return small;
}

void quick_sort(int data[], int length, int start, int end)
{
	//ԭ�� void ����Ҳ�ǿ��� return�����ǲ��ܴ����κη��ز�����������뱨�� 
	if(start==end)
		return;
	//�����ʵ���Բ������ڴ˺�������ɵ� 
	int index = partition(data, length, start, end);
	if(index>start)
		quick_sort(data, length, start, index-1);
	if(index<end)
		quick_sort(data, length, index+1, end);
}

int main(int argc, char** argv)
{
	int data[10] = {9, 11, 5, 30, 7 ,13 ,22 ,4, 8, 18};
	
	print(data, 0, 9);
	quick_sort(data, 10, 0, 9);
	print(data, 0, 9);
	
	return 0;
}
