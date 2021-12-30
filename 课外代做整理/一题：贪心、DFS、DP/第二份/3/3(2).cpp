#include <vector>
#include <iostream>
using namespace std;

int main()
{
	float k = 0;
	cin >> k;
	if (k - (int)k != 0) {
		cout << "����ǡ��֧��" << endl;
		return 0;
	}
	// ����άdp����ѹά 
	vector<int> dp(k + 1, k);
	// ��¼������ֵ 
	int a[] = { 1,2,5,10,20,50,100 };
	dp[0] = 0;
	// ��С����ö��������ֵ 
	for (int i = 0; i < 7; i++)
	{
		// ά����ǰ����������Щ״̬ת�ƹ��� 
		for (int j = a[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
		}
	}
	// ����ܽ��Ϊk �Ľ�� 
	cout << dp[k] << endl;
	return 0;
}
