#include <bits/stdc++.h>
using namespace std;

const int maxn = 32005;

int n,c[maxn],ans[maxn];

int lowbit(int x)
{
    return x&(-x);
}

void update(int x)
{
    while(x<maxn)
    {
        c[x]++;
        x += lowbit(x);
    }
}

int query(int x)
{
    int ans = 0;
    while(x>0)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
    int x,y;
    while(~scanf("%d",&n))
    {
        memset(c,0,sizeof(c));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            ans[query(x+1)]++;
            update(x+1);
        }
        for(int i=0;i<n;i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
