#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int sz[maxn],n;

int lowbit(int x)
{
    return x&(-x);
}

int update(int x,int num)
{
    while(x<=n)
    {
        sz[x] += num;
        x += lowbit(x);
    }
}

int query(int x)
{
    int ans = 0;
    while(x>0)
    {
        ans += sz[x];
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
    int a,b;
    while(~scanf("%d",&n)&&n!=0)
    {
        memset(sz,0,sizeof(sz));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            update(a,1);
            update(b+1,-1);
        }
        for(int i=1;i<=n;i++) printf("%d%c",query(i),(i==n ? '\n' : ' '));
    }
    return 0;
}
