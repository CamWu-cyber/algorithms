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
#include <list>

using namespace std;

struct TreeNode {
	TreeNode(): left(NULL), right(NULL) {}
	struct TreeNode *left;
	struct TreeNode *right;
};

//���������ڵ�����ת��Ϊ����Ĺ����ڵ�����
//ͨ�����������������ת��Ϊ�Ӹ��ڵ㵽������ڵ���������� 
bool GetNodePath(TreeNode *root, TreeNode *node, list<TreeNode *>& path)
{
	if (!root)
		return false;
	
	if (root == node)
		return true;
		
	//����root��ÿ���ӽڵ㣬���еݹ�����Ƿ��ܹ���������ڵ� 	
	
} 

TreeNode *GetLastCommonNode(const list<TreeNode *>&path1,
							const list<TreeNode *>&path2) 
{
	/*
				a
				b
				c
			   / \
			  d   e
			  f   g
		�����Ǵ�a��ʼ�ģ�����ֻ��Ҫͬʱ�����������ߣ��ҵ�����
		�����ڵ㼴��	
	*/
	
	 
}

int main(int argc, char **argv)
{
	cout << "NOTINSTANCE!" << endl; 
} 
