#include <iostream>

using namespace std;

int inverse_pairs(int *data, int *copy, int start, int end);
//�����û����� 
int inverse_pairs(int *data, int length)
{
	if (!data || length <= 0)
		return 0;
	
	//cout << "12" << endl;	
	int *copy = new int[length];
	for (int i=0; i<length; i++) {
		copy[i] = data[i];
	}
	int count = inverse_pairs(data, copy, 0, length - 1);
	
	//copy������ŵ�Ϊ��С�������������ǹ鲢���򣡣� 
	cout << "copy data: " << endl;
	for (int i=0; i<length; i++) {
		cout << copy[i] << ' ';
	}
	cout << endl;
	
	delete[] copy;
	
	return count;
}

//������ʵ�ֲ���
//start��end��ʾ��ԭʼ�����е�ƫ��
int inverse_pairs(int *data, int *copy, int start, int end)
{
	//��ȫ��� 
	if (!copy || start<0 || end<0 || start>end)
		return 0;
	//�ݹ���ֹ����	
	//if (start=end)
	if (start == end)
		return 0;
	
	//cout << "30" << endl;
	int length_ = (end - start) / 2;	
//	int left = inverse_pairs(data, copy, start, start+length_);	
//	int right = inverse_pairs(data, copy, start+length_+1, end);
	//�������Ҫ����ʹ�ã���Ϊ��ǰ��֧��Ҫʹ���ź�������ݣ���ǰ��֧ʹ�õ�����data
	//����ǰ��֧�޸ĵ���copy��������һ����֧��Ҫ�޸�data��������data����copyλ���ϴ���ݹ� 
	int left = inverse_pairs(copy, data, start, start+length_);	
	int right = inverse_pairs(copy, data, start+length_+1, end);
	//Ϊ��ÿ�αȽ϶��ܰ���������copy�ڴ��У�Ӧ�ô����������Ŀ�ʼ
	//�Ƚϣ���ָ�붼ָ��ĩβ 
	int *p1 = data + start + length_;
	int *p2 = data + end;
	//int *p3 = copy + end;
	int copyIndex = end; //���������ݵĴ洢ĩβ��ַΪend����Ϊ���Ǻ�data��Ӧ�ĳ��ȵ� 
	int count = 0;
	for(int i=start; i<=end; i++) {
		cout << *(data+i) << ' ';
	}
	cout << endl;
	while (p1 >= (data + start) && p2 >= (data + start + length_ + 1)) {
		if (*p1 > *p2) {
			//cout << "find" << endl;
			cout << *p1 << " > " << *p2 << endl; 
			//count += (end - start - length_); ����Ӧ���� + p2���������ĸ���
			//��Ϊp2�����ƶ��� 
			count += (p2 - data - start - length_);
			copy[copyIndex--] = *p1; 
			p1--;
		} else {
			//cout << "empty" << endl;
			copy[copyIndex--] = *p2;
			p2--;
		}
	}
	
	//����ʣ���û�и��Ƶ�copy��
	while (p1 >= (data + start)) {
		//cout << "p1" << endl;
		copy[copyIndex--] = *(p1--);
	} 
	while (p2 >= (data + start + length_ + 1)) {
		//cout << "p2" << endl;
		copy[copyIndex--] = *(p2--);
	}
	
	return left + right + count;
} 

int main(int argc, char **argv)
{
	int array[5] = {7, 5, 6, 4, 9};
	int count = inverse_pairs(array, 5);
	cout << "count: " << count << endl;
	
	for (int i=0; i<5; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
	
	int arr[4] = {7, 5, 6, 9};
	count = inverse_pairs(arr, 4);
	cout << "count: " << count << endl;
	
	for (int i=0; i<4; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	
	return 0;
}
