#include <iostream>

using namespace std;

//#define DEBUG

#ifdef DEBUG
#define debug(str) print_string(str)
#else
#define debug(str)
#endif

void print_string(char *str)
{
	while (*str != '\0') {
		cout << *str;
		str++;
	}
	cout << ' ';
}

void permutation(char *str, char *next)
{
	if (*next == '\0') { //��nextָ�����һ���ַ�ʱ��˵��һ�����в����� 
		print_string(str);
	} else {
		//��ѭ���������ǰ� next ָ��ָ����ַ�����ַ�֮��Ľ�����һ���� 
		for (char *next_next=next; *next_next!='\0'; next_next++) {
			//���н�������һ�ν���Ϊ���� 
			char temp = *next;
			*next = *next_next;
			*next_next = temp;
			permutation(str, next+1);
			//����֮��ָ�ԭʼ˳�������ݹ����һ���ſ�����ʹ�� 
			temp = *next;
			*next = *next_next;
			*next_next = temp;
		}
	}
}

void permutation(char *str)
{
	if (str) {
		permutation(str, str);
	}
}

int main(int argc, char** argv)
{
	char str[4] = {'a', 'b', 'c', '\0'};
	permutation(str);

	return 0;	
}
