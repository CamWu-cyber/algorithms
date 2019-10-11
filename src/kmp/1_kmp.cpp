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
#include <vector>

using namespace std;

int brute_search(string &str, string &tpl)
{
	if (!tpl.size() || !str.size())
		return -1;
		
	int i = 0, j = 0;
	while (i<str.size() && j<tpl.size()) {
		if (str[i] == tpl[j]) {
			i++;
			j++;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}
	
	if (j == tpl.size())
		return i - j;
	
	return -1;
}

void get_next(string &src, vector<int> &next)
{
	next.resize(src.size());
	next[0] = -1;
	
	int k = -1;
	int j = 0;
	while (j < next.size() - 1)
	{
		//p[k]��ʾǰ׺��p[j]��ʾ��׺
		if (k == -1 || src[j] == src[k]) 
		{
			++k;
			++j;
			next[j] = k;
		}
		else 
		{
			k = next[k];
		}
	}
} 

int kmp_debug(string &src, string &tmpl)
{
	if (!src.size() || !tmpl.size())
		return -1;
		
	vector<int> next;
	get_next(tmpl, next);
	
	int i = 0, j = 0;
	int src_size = src.size(), tmpl_size = tmpl.size();
	cout << "src size: " << src_size
	     << " --- tmpl size: " << tmpl_size << endl;
	while (i < src_size && j < tmpl_size) {
		cout << "while loop start" << endl;
		cout << "while i: " << i << " while j: " << j << endl;
		if ((j == -1) || (src[i] == tmpl[j])) {
			i++;
			j++;
			cout << "i: " << i << " j: " << j << endl;
		} else {
			j = next[j];
			cout << "i: " << i << " j: " << j << endl;
		}
		cout << "while loop end" << endl;
	}
	cout << "while end" << endl;
	if (j == tmpl.size()) {
		return i - j;
	} else {
		return -1;
	}
}

int kmp(string &src, string &tmpl)
{
	if (!src.size() || !tmpl.size())
		return -1;
		
	vector<int> next;
	get_next(tmpl, next);
	
	int i = 0, j = 0;
	while (i < (int)src.size() && j < (int)tmpl.size()) {
		if ((j == -1) || (src[i] == tmpl[j])) {
			i++;
			j++;
		} else {
			j = next[j];
		}
	}

	if (j == tmpl.size()) {
		return i - j;
	} else {
		return -1;
	}
}

int main()
{	
	string tmpl = "abcdabd";
	vector<int> next;
	get_next(tmpl, next); 
	for (int i=0; i<next.size(); i++) {
		cout << next[i] << ' ';
	}
	cout << endl;
	
	string src = "abcddfabcdabddfa";
	
	cout << "brute search: " 
         << brute_search(src, tmpl) << endl;	
	cout << "kmp: " << kmp(src, tmpl) << endl;
	
	/*
	size_t ���Ͷ�����cstddefͷ�ļ��У����ļ���C��׼���ͷ�ļ�stddef.h��C++�档
	����һ���������ص�unsigned���ͣ����С���Ա�֤�洢�ڴ��ж���Ĵ�С��
	
	int test = -1;
	unsigned int test_value = 2;
	// cout << (test < tmpl.size());
	cout << (test < test_value);
	*/
	
	return 0;
} 
