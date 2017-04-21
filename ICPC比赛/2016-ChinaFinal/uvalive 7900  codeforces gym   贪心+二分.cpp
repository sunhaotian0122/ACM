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
        mid = (l+r+1)/2; //保证mid是一个比l大的数
        if(judge(mid)) l = mid; //最后大的数给l，保证l==r，跳出
        else r = mid-1; //否则mid-1给r，保证r==l，跳出
    }
    return l; //返回l或r均可，因为跳出时l==r
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
