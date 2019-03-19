#include <iostream>

using namespace std;

void find_numbers_appear_once(int *data, int length, int *num1, int *num2)
{
	if (!data)
		return;
	//�������ֻ����һ�ε��������������Ϊ������ͬ���������һ����Ϊ��	
	int temp = 0;
	for (int i=0; i<length; i++) {
		temp ^= *(data+i);
	}
	//�ҳ���һ��bitΪ1��λ�����λ�����������Ķ����Ʊ�ʾһ����ͬ 
	int index = 0;
	while ((temp & 0x01 == 0) && (index < 8 * sizeof(int))) {
		temp >>= 1;
		index++;
	}
	//�Դ˶�������з��飬��ΪҪ��ռ临�Ӷ�ΪO(1)�����Ա�����ʹ�� 
	for (int i=0; i<length; i++) {
		if (*(data+i) & (1 << index))
			*num1 ^= *(data+i);
		else
			*num2 ^= *(data+i);
	}
}

int main(int argc, char **argv)
{
	int data[] = {1,1,2,2,3,5,5,4,6,6};
	int num1 = 0, num2 = 0;
	find_numbers_appear_once(data, 10, &num1, &num2);
	cout << "num1: " << num1 << "\nnum2: " << num2 << endl;
	
	return 0;
}
