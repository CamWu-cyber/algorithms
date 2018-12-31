#include <iostream>

using namespace std;

struct ListNode {
	ListNode(): m_pNext(NULL) {}
	int m_nKey;
	ListNode* m_pNext;
};

void add_to_head(ListNode** pHead, int value)
{
	if(pHead) {
		if(*pHead) {
			ListNode* pHead_ = *pHead;
			*pHead = new ListNode();
			(*pHead)->m_nKey = value;
			(*pHead)->m_pNext = pHead_;
		} else {
			*pHead = new ListNode();
			(*pHead)->m_nKey = value;
		}
	}
}

void print_list_head_to_tail(ListNode* pHead)
{
	if(pHead) {
		ListNode* head = pHead;
		cout << head->m_nKey << ' ';
		while(head->m_pNext) {
			head = head->m_pNext;
			cout << head->m_nKey << ' ';
		}
		cout << endl;
	}
}
//����˼·
//1.��ָ��Ϊ����������ų� 
//2.�ѽ���һ���ڵ��������⴦���
//3.�ж��Ƿ��ж��������ڵ�����������У�ʹ������ָ��
//  �ֱ�ָ��ǰһ������ǰ�ģ���һ������ת����ƽ��������ָ��
//4.��β���� 
void reverse_list(ListNode** root)
{
	if(!root || !(*root))
		return;
	if((*root)->m_pNext == NULL) { //��һ���ڵ� 
		return; 
	}
	//����ֻʣ�������������ڵ������� 
	ListNode* pCur, * pNext, * pPrev;
	pCur = *root; pNext = pCur->m_pNext;
	
	while(pNext->m_pNext) { //�������м�ڵ㶼��ת 
		pPrev = pCur;
		pCur = pNext;
		pNext = pCur->m_pNext;
		pCur->m_pNext = pPrev;		
	}
	//��β����
	pNext->m_pNext = pCur; //ԭ����β�ڵ� 
	(*root)->m_pNext = NULL; //ԭ����ͷ���ڵ�
	*root = pNext;
}

int main(int argc, char** argv)
{
	ListNode* root = NULL;
	add_to_head(&root, 1);
	print_list_head_to_tail(root);
	reverse_list(&root);
	print_list_head_to_tail(root);
	
	add_to_head(&root, 2);
	add_to_head(&root, 3);
	add_to_head(&root, 4);
	print_list_head_to_tail(root);
	reverse_list(&root);
	print_list_head_to_tail(root);
	
	add_to_head(&root, 5);
	add_to_head(&root, 6);
	add_to_head(&root, 7);
	add_to_head(&root, 8);	
	print_list_head_to_tail(root);
	reverse_list(&root);
	print_list_head_to_tail(root);
	
	return 0;
}
