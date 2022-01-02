#include <iostream>
#include <cstring>
using namespace std;
 
int dfs(char* pre,char* in,int n)   //��������ĸ߶�
{
    if(n == 0)    //��û�н�㣬Ϊ����
    {
        return 0;
    }
    int i;
    for(i = 0; i < n; i++)
    {
        if(in[i] == pre[0])  //�ҵ�������������λ��
        {
            break;
        }
    }
    int left = dfs(pre+1,in,i);  //�����������
    int right = dfs(pre+i+1,in+i+1,n-i-1);   //�����������
    return max(left,right)+1;  //��������������ȵĽϴ�ֵ�еĽϴ�ֵ+�����
}
int main()
{
    int n;
    cin >> n;
    char pre[n+1],in[n+1];  //���������
    cin >> pre >> in;
    cout << dfs(pre,in,n) << endl;
    return 0;
}
