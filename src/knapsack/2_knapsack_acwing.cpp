#include <iostream>

/*
	��ȫ�������� 
*/ 

using namespace std; 

int knapsack_2d(int N, int V, int v[], int w[])
{
    int dp[N+1][V+1] = {0};
    /* �����Լ���ʼ�������崦�޷�ʵ��������� */
    for (int i=0; i<=N; i++) dp[i][0] = 0;
    for (int i=0; i<=V; i++) dp[0][i] = 0;
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=V; j++) {
            /* ��ѡ�� i ������� */
            dp[i][j] = dp[i-1][j];
            int iter = j / v[i];
            /* ѡ��� i �� k �� */
            for (int k=1; k<=iter; k++)  {
                /* ��� if ��û��Ҫ�ˣ���Ϊ k �Ѿ����������ֿ��� */
                //if (v[i] <= j) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k*v[i]]+k*w[i]);
                //}
            }
        }
    }
    
    return dp[N][V];
}

int knapsack_1d_v1(int N, int V, int v[], int w[])
{
    int dp[V+1] = {0};
    
    for (int i=1; i<=N; i++) {
        for (int j=V; j>=1; j--) {
            int iter = j / v[i];
            for (int k=1; k<=iter; k++) {
                // if (v[i] <= j) {
                    dp[j] = max(dp[j], dp[j-k*v[i]]+k*w[i]);
                // }
            }
        }
    }
    
    return dp[V];
}

/*
    v2 �㷨����
    ������ 0-1 �������⣬���ڿ������޴�ѡ
    f[i][j] --> -->
    ��ѡ�� i ����Ʒʱ��ѡ������� 0, 1, 2, ..., k �� k*v[i] <= j
    ��Ӧ���ܼ�ֵ�ֱ��漰�� f[i-1][j], f[i-1][j-v[i]], f[i-1][j-2*v[i]], ..., f[i-1][j-k*v[i]]
    ������Ӧ����������ֵ j, j-v[i], j-2*v[i], ..., j-k*v[i]
    ���� k*v[i] <= j����������ֵ��Χ�� j �� 0 ֮�������
    �� dp ��άΪ һάʱ���漰�����ܼ�ֵΪ f[j], f[j-v[i]], f[j-2*v[i]], ..., f[j-k*v[i]]
    ͬ���ģ���ʱ�漰������ֵ��Χ�� j �� 0 ֮������ݣ����ӵ�ǰ�㵽 0 ֮�������
    ������ʹ�� v1 �汾ʱ�����ҵ��� �������ǳ������ԭ��
    dp ���ȶ�Ӧ���ǲ�ͬ���������� 0, 1, 2, ..., V
    ������֪���ǣ�������һά dp�����Ե����ǲ�ȡ�� i ����Ʒʱ����ǰ��ֵ�͵��ڵ�ǰֵ������Ҫ����
    ����������Ʒ����Ϊ v[i], �������� 0,1, ..., v[i]-1 ֮�����ݶ����ֲ��䣬��Ϊ��������������
    ������Ϊ v[i] ʱ����ʱ���������������ȡ�Ͳ�ȡ
    ��ÿ���漰��ȡ�Ͳ�ȡ���� v[i] Ϊ������ֵģ�����0, v[i], 2*v[i], ..., V��¼�ľ��ǵ� i ��
    ��Ʒ��������Ϊ V �������ȡ��ͬ������ �ܼ�ֵ
*/

int knapsack_1d_v2(int N, int V, int v[], int w[])
{
    int dp[V+1] = {0};
    
    for (int i=1; i<=N; i++) {
        for (int j=v[i]; j<=V; j++) {
            dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    
    return dp[V];
}

int main()
{
    int N, V;
    cin>>N>>V;
    
    int v[N+1], w[N+1];
    
    v[0] = w[0] = 0;
    for (int i=1; i<=N; i++)
        cin>>v[i]>>w[i];
    
    // int res = knapsack_1d_v1(N, V, v, w);
    int res = knapsack_1d_v2(N, V, v, w);
    // int res = knapsack_2d(N, V, v, w);    

    cout << res;
    
    return 0;
}
