#include <iostream>
#include <list>

using namespace std;

#define DEBUG

#ifdef DEBUG
#define debug(para, str) printf(para, str)
#else
#define debug(para, str)
#endif


int main(int argc, char **argv)
{
	//���typedef����Ҫ���嵽�������У����򱨴�Ӧ���Ǻ�ϵͳ�Դ���make_pair��ͻ�� 
	typedef pair<int, float> make_pair;
    list<make_pair> list_pair_test;
    list_pair_test.push_back(make_pair(1, 1.1));
    list_pair_test.push_back(make_pair(1, 2.2));
    list_pair_test.push_back(make_pair(1, 3.3));
    list_pair_test.push_back(make_pair(2, 1.1));
    list_pair_test.push_back(make_pair(2, 2.2));
    list_pair_test.push_back(make_pair(2, 3.3));
    list_pair_test.push_back(make_pair(1, 1.1));
    list_pair_test.push_back(make_pair(1, 2.2));
    list_pair_test.push_back(make_pair(1, 3.3));
    list_pair_test.push_back(make_pair(2, 1.1));
    list_pair_test.push_back(make_pair(2, 2.2));
    list_pair_test.push_back(make_pair(2, 3.3));
    
    list<make_pair>::iterator it_begin = list_pair_test.begin();
	list<make_pair>::iterator it_end = list_pair_test.end();
	//list�п��Գ����ظ���first��second 
    for (; it_begin != it_end; it_begin++)
    	cout << "pair.first: " << (*it_begin).first << "-->" \
			 << "pair.second: " << (*it_begin).second << endl;

    return 0;
}
