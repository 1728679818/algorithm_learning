#include <iostream>
#include <iomanip>
using namespace std;
// ����a����洢��ֵ 
int a[7] = { 1,2,5,10,20,50,100 };
// ����num[] �洢�����е������� sol[] �洢���Ž⣬ ans�洢���������� 
int num[7], sol[7], ans = 0x3fffffff;
// dfs������ st��ʾ��ǰö�ٵ��ĸ��� k��ʾʣ��Ľ� cnt��ǰ�������� 
bool A(float a)
{   
    if(a-(int)a==0) //�����ڴ�a-(int)a
    return 0;
    else return 1;
}
void dfs(int st,int k,int cnt)
{
	// dfs �˳�������ö�ٵ����Ϊ1ʱ 
	if (st == 0)
	{
		// ʣ��Ľ�Ϊ ��ֵΪ1�Ľ������� ���� 
		num[0] = k;
		// ���������ϵ�ǰ��ʣ���� 
		cnt += k;
		// ά�����Ž� 
		if (cnt < ans)
		{
			ans = cnt;
			// ���𰸴������Ž������� 
			for (int i = 0; i < 7; i++) sol[i] = num[i];
		}
		// �˳�������� 
		return;
	}
	// ö������״̬�ռ� 
	for (int i = 0; i * a[st] <= k; i++)
	{
		// ��ǰ��ֵ���������� i 
		num[st] = i;
		// �Ե�ǰ������������ 
		dfs(st - 1, k - i * a[st], cnt + i);
	}
}
int main()
{
	// �����ʼ��� ����ֵ 
	float k;
	cin >> k;
	if(A(k)) {
		cout << "����ǡ��֧��" << endl;
		return 0;
	}
	//  ������ʼ 
	dfs(6, k, 0);

	// ����ܽ�� 
	cout << "��С��Ҫ" << setw(4) << ans << "��ֽ��" << endl;
	for (int i = 0; i < 7; i++) // ������Ž� 
	{
		cout << "ʹ����ֵ" << setw(4) << a[i] << "Ԫֽ��" << setw(4) << sol[i] << "��" << endl;
	}
	return 0;
}
