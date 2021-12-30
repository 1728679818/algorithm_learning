#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll; 

int patition(int a[], int left, int right){ //�� left ~  right ���л��� 
	int x = a[left];  
	while(left < right){ // ���ֲ��ҵ����� 
		while(left<right && a[right]>=x) right--; // �������Դ�����a[right]>=x, �Ҷ�����ƽ� 
		a[left] = a[right];	//��ֵ 
		while(left<right && a[left]<=x) left++; // �������Դ�����a[left]<=x, ������ұƽ� 
		a[right] = a[left];	//��ֵ 
	}
	a[left] = x; // ��x��ֵ����˵� 
	return left; // ������˵���±� 
}

void find(int a[], int left, int right, int k){	//�� left ~  right Ѱ�� 
	int pos = patition(a, left, right);	// ������left~right����Ѱ�ң������ز���λ�� 
	if(pos == k) printf("%d\n", a[pos]);  // ����鵽��λ�ã������λ�õ�Ԫ�� 
	else if(pos > k) find(a, left, pos-1, k);	// �����ѯ��λ�ô���k������߽��Ų��� 
	else find(a, pos+1, right, k);	// �����ѯ��λ��С��k�� ���ұ߽��Ų��� 
}

int main(){
	int n, k, a[100005]; // ���峤�ȣ�λ���������� 
	cout << "�������鳤�Ⱥ�Ҫ���ҵ�����λ��:" << endl; // �����ʾ��Ϣ 
	scanf("%d%d", &n, &k);	// �������鳤�Ⱥ�λ�� 
	cout << "��������ÿ��Ԫ��" << endl;	// �����ʾ��Ϣ 
	for(int i=1; i<=n; i++) scanf("%d", a+i);	// ��������Ԫ�� 
	find(a, 1, n, k);
}
