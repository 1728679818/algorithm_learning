#include <iostream>
using namespace std;
int a[7] = { 1,2,5,10,20,50,100 }; // ��ֵ 
int num[7], sol[7], ans = 0x3fffffff; // num[]��¼�м� 
void dfs(int st,int k,int cnt)
{
	// �˳������� ��������С��� 
	if (st == 0)
	{
		// ��С�����������ʣ���kֵ 
		num[0] = k;
		// ����������ʣ��kֵ 
		cnt += k;
		// ά����С������������ǰ������������sol[]. 
		if (cnt < ans)
		{
			ans = cnt;
			for (int i = 0; i < 7; i++) sol[i] = num[i];
		}
		return;
	}
	// �Ӵ���ֵ��ʼ�ݹ�����	
	for (int i = 0; i * a[st] <= k; i++)
	{
		// num[]�洢��ǰ��ֵ�����ü��� 
		num[st] = i;
		// ����С, ʣ�������, ��ǰ������������i 
		dfs(st - 1, k - i * a[st], cnt + i);
	}
}
int main()
{
	float k;
	scanf("%lf", &k);
	if (k - (int)k != 0) {
		cout << "����ǡ��֧��" << endl;
		return 0;
	}
	dfs(6, k, 0);

	printf("��Ҫʹ��%4d��ֽ��\n", ans);
	for (int i = 0; i < 7; i++)
		printf("ʹ����ֵ%4dԪֽ��%4d��\n", a[i], sol[i]);
	
	return 0;
}
