#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

int patition(int a[], int left, int right){ //�� left ~  right ���л��� 
	int x = a[left];
	while(left < right){
		while(left<right && a[right]>=x) right--;
		a[left] = a[right];
		while(left<right && a[left]<=x) left++;
		a[right] = a[left];
	}
	a[left] = x;
	return left;
}

void find(int a[], int left, int right, int k){	//�� left ~  right Ѱ�� 
	int pos = patition(a, left, right);
	if(pos == k) printf("%d\n", a[pos]);
	else if(pos > k) find(a, left, pos-1, k);
	else find(a, pos+1, right, k);
}

int main(){
	int n, k, a[100005];
	cout << "�������鳤�Ⱥ�Ҫ���ҵ�����λ��:" << endl; 
	scanf("%d%d", &n, &k);
	cout << "��������ÿ��Ԫ��" << endl;
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	find(a, 1, n, k);
}
