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

void print_matrix(int* matrix, int height, int width, int count=0)
{
	//������Ҫ��ӡ�ľ����С 
	int height_ = (height-2*count);
	int width_  = (width-2*count);
	if(matrix && height_>0 && width_>0) {
		if(height_==1) {
			for(int wi=0; wi<width_; wi++) {
				cout << matrix[wi] << ' ';
			}
			cout << endl;
		} else if(width_==1) { //��Ȼ��һ�У�����������Ӿ���
			//��ô������Ҫ����ԭ���� width ���� 
			for(int hi=0; hi<height_; hi++) {
				cout << matrix[hi*width] << ' ';
			}
			cout << endl;
		} else {
			//��ӡ��һ�� 
			for(int wi=0; wi<width_; wi++) {
				cout << matrix[wi] << ' ';
			}
			//��ӡ�ұߵ�һ�� 
			//�����еĵ�һ����ַΪ��matrix+width_-1 
			int base = width_-1;
			for(int hi=1; hi<height_; hi++) {
				cout << matrix[base+hi*width] << ' ';
			}
			//��ӡ���һ��
			//�������һ�еĵ�һ����ַΪ�� base+(height_-1)*width
			base += (height_-1)*width;
			for(int wi=1; wi<width_; wi++) {
				cout << matrix[base-wi] << ' ';
			} 
			//��ӡ��ߵ�һ�� 
			//���ֵ�һ����ַΪ��base-wi+2
			base += 1-width_;
			for(int hi=1; hi<height_-1; hi++) {
				cout << matrix[base-hi*width] << ' ';
			}
			//��Ӧ���������Σ���Ϊ����ľ���ָ�뻹�Ǵ��� height*width ��
			//�����ݹ������������ͨ������count������ָʾ��һ�ε����ľ����С 
			/*
			print_matrix(matrix+width+1, height - 2, width - 2);
			*/
			count++;
			print_matrix(matrix+width+1, height, width, count);
		}
	}
}

int main(int argc, char** argv)
{
	int matrix_test1[5][5] = { 1,  2,  3,  4,  5,\
														 16, 17, 18, 19, 6,\
														 15, 24, 25, 20, 7,\
														 14, 23, 22, 21, 8,\
														 13, 12, 11, 10, 9};
	int matrix_test2[1][1] = {1};
	int matrix_test3[2][2] = {1, 2, 4, 3}; 
	int matrix_test4[2][3] = {1, 2, 3, 6, 5, 4};
	int matrix_test5[3][2] = {1, 2, 6, 3, 5, 4};
	int matrix_test6[5][1] = {1, 2, 3, 4, 5};  
	int matrix_test7[1][5] = {1, 2, 3, 4, 5}; 
	print_matrix(&matrix_test1[0][0], 5, 5);
	print_matrix(&matrix_test2[0][0], 1, 1);
	print_matrix(&matrix_test3[0][0], 2, 2);
	print_matrix(&matrix_test4[0][0], 2, 3);
	print_matrix(&matrix_test5[0][0], 3, 2);
	print_matrix(&matrix_test6[0][0], 5, 1);
	print_matrix(&matrix_test7[0][0], 1, 5);
	
	return 0;
}
