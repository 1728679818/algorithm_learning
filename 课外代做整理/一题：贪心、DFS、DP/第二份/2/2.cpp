#include <iostream>
using namespace std;

int main()
{
	int k = 0;
	cin >> k;	 

	int c100 = k / 100; k %= 100;
	int c50 = k / 50; k %= 50;
	int c20 = k / 20; k %= 20;
	int c10 = k / 10; k %= 10;
	int c5 = k / 5; k %= 5;
	int c2 = k / 2; k %= 2;
	int c1 = k;
	int ans = c100 + c50 + c20 + c10 + c5 + c2 + c1;
	printf("������Ҫ%4d��ֽ��\n", ans);
	printf("������Ҫ 100Ԫֽ��%4d��\n", c100);
	printf("������Ҫ  50Ԫֽ��%4d��\n", c50);
	printf("������Ҫ  20Ԫֽ��%4d��\n", c20);
	printf("������Ҫ  10Ԫֽ��%4d��\n", c10);
	printf("������Ҫ   5Ԫֽ��%4d��\n", c5);
	printf("������Ҫ   2Ԫֽ��%4d��\n", c2);
	printf("������Ҫ   1Ԫֽ��%4d��\n", c1);
	
	return 0;
}
