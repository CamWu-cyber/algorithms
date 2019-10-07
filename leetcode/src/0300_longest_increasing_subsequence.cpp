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

/*
	��Ŀ��
		����һ��������������飬�ҵ���������������еĳ��ȡ�

	ʾ��:
		����: [10,9,2,5,3,7,101,18]
		���: 4 
	����: 
		��������������� [2,3,7,101]�����ĳ����� 4��
	
	˵��:	
		���ܻ��ж�������������е���ϣ���ֻ��Ҫ�����Ӧ�ĳ��ȼ��ɡ�
		���㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(n2) ��
	
	����: 
		���ܽ��㷨��ʱ�临�ӶȽ��͵� O(n log n) ��?

*/

#include <iostream>
#include <vector>

using namespace std;

// O(n^2)
void solution_1(vector<int> &array)
{
	if (array.size() == 0)
		return;
	
	// ��¼��Ӧλ�õ� ���г��ȣ���ʼ��Ϊ 1����Ϊ���ٰ����Լ� 
	vector<int> lis(array.size());
	vector<vector<int> > lis_array(array.size()); 	
	for (int i=0; i<array.size(); i++) {
		lis[i] = 1;
		vector<int> temp;
		temp.push_back(array[i]);
		lis_array[i] = temp;
	}
	// ����ÿ��Ԫ�� 
	for (int i=0; i<array.size(); i++) {
		for (int j=0; j<i; j++) {
			// ���ڵ� i ��Ԫ��ǰ���Ѿ��������������
			// �ҳ��뵱ǰԪ������������������� 
			if (array[j] < array[i]) {
				/*
				lis[i] = max(lis[i], lis[j]+1);
				*/
				
				if (lis[i] < lis[j]+1) {
					lis_array[i].clear();
					lis_array[i] = lis_array[j];
					lis_array[i].push_back(array[i]);
					lis[i] = lis[j]+1;
				}
				
			}
		}
	}
	
	int index = 1;
	for (int i=0; i<array.size(); i++) {
		if (lis[i] > lis[index])
			index = i;
	}
	
	cout << "max lis: " << lis[index] << endl;
	cout << "sequence:\n";
	
	for (int i=0; i<lis_array[index].size(); i++) {
		cout << lis_array[index][i] << ' ';
	}
	
	cout << endl;
}


// O(nlogn)
void solution_2(vector<int> &array)
{
    /*
        example: 3, 2, 5, 9, 1, 10, 7
        �÷������ڽ���һ�ָ��ǲ�����������С������Ȼ�Ḳ��ǰ�ߵ���
        �����������û�иı䣬�Ҹ��ǲ����ı����еĳ��Ⱥ������
        ��ô������еĳ�����Ȼ��ʾ��ʼ�Ǹ��ϳ����Ǹ�����
        ֱ��ȫ�������ǵ�
        3 -> 2 -> 2, 5 -> 2, 5, 9 -> 1, 5, 9
        -> 1, 5, 9, 10 -> 1, 5, 7, 10
        ֻ�е�����С������������������ˣ���ô������вŴ����µ�����
        ����������еĴ�С��Ȼ�ǵ��ڱ������ǵ����Ǹ���������
    */
    
	if (array.size() == 0)
		return;
	
	// ������﷨������ temp �� size ֱ�Ӿͷ����ˣ���push_back��ʱ���Ǵ�
	// size ֮��ʼ�� 	
	//vector<int> temp(array.size() / 2);
	vector<int> temp; 
	temp.push_back(array[0]);
	for (int i=0; i<array.size(); i++) {
		if (array[i] > temp.back()) {
			temp.push_back(array[i]);
		} else {
			auto it = lower_bound(temp.begin(),temp.end(), array[i]);
			*it = array[i];
		}
	}
	
	cout << "solution 2: " << temp.size() << endl;
}

int main(int argc, char **argv)
{
	vector<int> array;
	
	array.push_back(7);
	array.push_back(1);
	array.push_back(5);
	array.push_back(4);
	array.push_back(3);
	array.push_back(2);
	array.push_back(9);
	array.push_back(6);
	array.push_back(8);
	array.push_back(10);
	array.push_back(17);
	array.push_back(11);
	array.push_back(55);
	array.push_back(54);
	array.push_back(13);
	array.push_back(24);
	array.push_back(29);
	array.push_back(56);
	array.push_back(18);
	array.push_back(11);
	
	solution_1(array);
	solution_2(array);
	
	return 0;
} 
