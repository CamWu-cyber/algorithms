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
