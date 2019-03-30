#include <iostream>
#include <math.h>

using namespace std;

void calc_prob1(int num, int count, int *sums, int sum)
{
	if (count == 0) {
		sums[sum-num]++;
	} else {
		for (int i=1; i<=6; i++) {
			calc_prob1(num, count-1, sums, sum+i);
		}
	}	
}

void solution1(int num)
{
	if (num <= 0)
		return;
		
	int max_sum = num * 6;
	int *sums = new int[max_sum - num + 1];
	
	for (int i=0; i<(max_sum-num+1); i++) {
		*(sums+i) = 0;
	}
	
	calc_prob1(num, num, sums, 0);
	
	int total = pow(6, num);
	for (int i=0; i<(max_sum-num+1); i++) {
		double prob = double(*(sums+i))/double(total);
		cout << "sum: " << i+num << " freq: " << *(sums+i) << " prob: " << prob << endl;
	}
}

void solution2(int num)
{
	if (num <= 0)
		return;
	
	const int maxValue = 6;
	
	int *prob[2];
	prob[0] = new int[num*maxValue + 1];
	prob[1] = new int[num*maxValue + 1];
	
	for (int i=0; i<(num*maxValue + 1); i++) {
		prob[0][i] = 0;
		prob[1][i] = 0;
	}
	
	for (int i=1; i<=maxValue; i++) {
		prob[0][i] = 1;
		prob[1][i] = 1;
	}
	
	int flag = 0;
	
	for (int n=2; n<=num; n++) {
//		for (int i=(n-1)*maxValue; i<n*maxValue; i++) {
//			for (int j=(n-2)*maxValue; j<(n-1)*maxValue; j++) {
//				prob[flag][i] += prob[1-flag][j];
//			}
//		}

//		for (int i=n; i<n*maxValue; i++) {
//			int max = std::max(i-maxValue, 0); 
//			for (int j=max; j<i; i++) {
//				
//			}
//		} 

		//����Ҫ���µĽ������� 
		for (int i=n; i<maxValue*n; i++) {
			prob[1-flag][i] = 0;
		} 
		//�����ݽ��и��� 
		for (int sum=n; sum<=maxValue*n; sum++) {
			int min, max; 
//			int i;
//			for (i=1; i<=maxValue; i++) {
//				if ((sum-i) == 0) break;
//			}
//			min = sum - i + 1;
//��������Ҫ����������䣬���ȷ�����ұ߽�
//��Ϊ��һ��ɸ����С��Ϊn��������һ��ɸ�ӵ���С��Ϊn-1
//��sum-6���ܻ��n-1��С�������ζ�ų��߽���
//Ҳ���ܱ����󣬵���������sumС����Ҫȡ���sum���Ǹ����֣�������Ҫȡ������max 
			min = std::max(n-1, sum-6);
//�ұ߽���������Ϊ��sum-1, (n-1)*maxValue�� Ϊ�˲����ұ߽磬����Ҫȥ�����Ǹ���
//��min 
			max = std::min(sum-1, (n-1)*maxValue);
			
//			for (int s=(sum-min); s<=sum; s++) {
//			for (int s=n-1; s<=(sum-1); s++) {
			for (int s=min; s<=max; s++) {
				prob[1-flag][sum] += prob[flag][s];
			}
		} 
		
		flag = 1 - flag;
	}
	
	int total = pow(6, num);
	for (int i=num; i<=(num*maxValue); i++) {
		int count = prob[flag][i];
		double prob = double(count)/double(total);
		cout << "sum: " << i << " freq: " << count << " prob: " << prob << endl;
	} 
	
	delete[] prob[0];
	delete[] prob[1];
} 

int main(int argc, char **argv)
{
	cout << "dices = 1" << endl;
	solution1(1);
	cout << "dices = 2" << endl;
	solution1(2);
	cout << "dices = 3" << endl;
	solution1(3);
	cout << "dices = 1" << endl;
	solution2(1);
	cout << "dices = 2" << endl;
	solution2(2);
	cout << "dices = 3" << endl;
	solution2(3);	
	
	return 0;
} 
