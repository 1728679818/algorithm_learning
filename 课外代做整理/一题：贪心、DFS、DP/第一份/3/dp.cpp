#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// �����ʼ״̬ 
	float k;
	cin >> k;
	if (k - (int)k != 0) {
		cout << "����ǡ��֧��" << endl;
		return 0;
	}
	// ����dp���飬 ������ֵΪk 
	vector<vector<int>> dp(7, vector<int>(k + 1, k));
	// a[] ��¼������ֵ 
	int a[] = { 1,2,5,10,20,50,100 };
	// ��ʼʱ���洢���׷����� 
	for (int i = 0; i <= k; i++) dp[0][i] = i;
	// �Ժ�����ֵ����ö�� 
	for (int i = 1; i < 7; i++)
	{
		// ���0~k�����н�� 
		for (int j = 0; j <= k; j++)
		{
			// �����ǰ���С�������ø�С�����ȥ�� 
			if (j < a[i]) dp[i][j] = dp[i - 1][j];
			// ���������ά������Сֵ 
			else dp[i][j] = min(dp[i][j - a[i]] + 1, dp[i - 1][j]);
		}
	}
	// �������״̬ 
	cout << dp[6][k] << endl;
	return 0;
}
