#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 3e5+5;
ll b[maxn],a[maxn];
int n,k;

bool judge(int x)
{
    for(int i=1;i<=x;i++) a[i] = b[i];
    int p=x+1;
    for(int i=x+1;i<=x*k;i++)
    {
        while(b[p]<2*a[i-x] && p<=n) p++;
        if(p==n+1) return false;
        a[i] = b[p];
        p++;
    }
    return true;
}

int solve(int l,int r)
{
    int mid;
    while(l<r)
    {
        mid = (l+r+1)/2; //��֤mid��һ����l�����
        if(judge(mid)) l = mid; //���������l����֤l==r������
        else r = mid-1; //����mid-1��r����֤r==l������
    }
    return l; //����l��r���ɣ���Ϊ����ʱl==r
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        sort(b+1,b+n+1);
        printf("Case #%d: %d\n",ca,solve(0,n/k));
    }
    return 0;
}
