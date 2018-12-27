#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* add_to_head(ListNode** pHead, int value)
{
	if(pHead) {
		if(*pHead) {
			ListNode* pHead_ = *pHead;
			*pHead = new ListNode();
			(*pHead)->m_nValue = value;
			(*pHead)->m_pNext = pHead_;
		} else {
			*pHead = new ListNode();
			(*pHead)->m_nValue = value;
		}
		return *pHead;
	}
}

//�˺��������а�ȫ��� 
ListNode* find_prev(ListNode* root, ListNode* find)
{
	ListNode* prev;
	while(root->m_pNext!=find)
		root = root->m_pNext;
	prev = root;
	return prev;
} 

//��Ҫ˼����ǣ�����˽ڵ㲻�����������һ��
//��������һ�����ƹ�����Ȼ��ǰ��ָ��ָ����һ������һ��
//���ɾ����һ�� 
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if(pListHead) {
		if(*pListHead) {
			if(*pListHead==pToBeDeleted) { //�������ڵ���ͷ�� 
				/*if(pToBeDeleted->m_pNext==NULL) { //�������ڵ�Ψһ�� 
					*pListHead = NULL;
					delete pToBeDeleted;
				} else {
					*pListHead = pToBeDeleted->m_pNext;
					delete pToBeDeleted;
				}*/
				//���Լ򻯴���
				*pListHead = pToBeDeleted->m_pNext;
				delete pToBeDeleted;
			} else if(pToBeDeleted->m_pNext==NULL) { //����˽ڵ���β����ֻ�ܴ�ͷ����
				ListNode* prev = find_prev(*pListHead, pToBeDeleted);
				prev->m_pNext = NULL;
				delete pToBeDeleted;
			} else { //ֻʣ�����м䲿�ֵ������ 
				ListNode* pNext = pToBeDeleted->m_pNext;
				ListNode* pNextNext = pNext->m_pNext;
				pToBeDeleted->m_nValue = pNext->m_nValue;
				pToBeDeleted->m_pNext = pNextNext;
				delete pNext; 
			}
		}
	} 
}

void print_list_head_to_tail(ListNode* pHead)
{
	if(pHead) {
		ListNode* head = pHead;
		cout << head->m_nValue << ' ';
		while(head->m_pNext) {
			head = head->m_pNext;
			cout << head->m_nValue << ' ';
		}
		cout << endl;
	}
}
//��������и����裬�Ǿ������Ǹ����Ľڵ�һ�����ڴ������� 
int main(int argc, char** argv)
{
	ListNode* root = NULL;
	ListNode* node6 = add_to_head(&root, 6);
	ListNode* node5 = add_to_head(&root, 5);
	ListNode* node4 = add_to_head(&root, 4);
	ListNode* node3 = add_to_head(&root, 3);
	ListNode* node2 = add_to_head(&root, 2);
	ListNode* node1 = add_to_head(&root, 1);
	
	print_list_head_to_tail(root);
	
	DeleteNode(&root, node3);
//	DeleteNode(&root, node4); ���±ߵĳ���ͬ�������� 
	print_list_head_to_tail(root);
	//����Ϊ��ʵ�� O(1) ��ɾ��Ч�ʣ�����ɾ��node5��ʱ����ʵnode6�Ѿ���������
	//����ִ��ɾ��node6�Ż���� 
	DeleteNode(&root, node5);
	//DeleteNode(&root, node6);�滻Ϊ�ٴ�ɾ��node5�ſ��ԣ���Ϊ��ʱ����β�� 
	DeleteNode(&root, node5);
	print_list_head_to_tail(root);
	
	DeleteNode(&root, node1);
	print_list_head_to_tail(root);
	
	DeleteNode(&root, node2);
	DeleteNode(&root, node3);
	print_list_head_to_tail(root);
	
	return 0;
} 
