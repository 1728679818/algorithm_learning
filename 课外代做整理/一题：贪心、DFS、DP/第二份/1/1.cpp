#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int q[N];

int quick_select(int l, int r, int k) { // ����ѡ���� 
    if (l >= r) {	// �����˵����Ҷ˵��غϣ�������˵��ֵ 
        return q[l];
    }
    int x = q[l + r >> 1]; // x == (l+r)/2 ��Ϊ��˵����Ҷ˵���м�ֵ 
    int i = l - 1, j = r + 1; //  i, j ����Ϊ�µ����� 
    while (i < j) { // ��������˵�С���Ҷ˵�ʱ 
        do i++; while (q[i] < x); // ������˵����ұƽ� 
        do j--; while (q[j] > x); // �����Ҷ˵�����ƽ� 
        if (i < j) {
            swap(q[i], q[j]);  
        }
    }
    // l - j �� j-l+1������
    int sl = j - l + 1;
    if (k <= sl) { // �ж�Ӧ�����λ����Ұ�ν�����һ�β��� 
        quick_select(l, j, k);
    } else {
        quick_select(j + 1, r, k - sl);
    }
}

int main() {
    // ������� 
    cin >> n >> k;
    for (int i = 0; i < n; i++) { //�������� 
        cin >> q[i];
    }

    cout << quick_select(0, n - 1, k) << endl; // ���ÿ���ѡ���������ؽ�� 
    return 0;
}
