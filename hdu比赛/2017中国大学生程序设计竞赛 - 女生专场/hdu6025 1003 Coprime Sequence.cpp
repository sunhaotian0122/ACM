#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int sz[maxn],pre[maxn],pos[maxn];

int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}

int main()
{
    int T,n,ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&sz[i]);
            if(i==1) pre[i] = sz[i];
            else pre[i] = gcd(pre[i-1],sz[i]);
        }
        for(int i=n;i>0;i--)
        {
            if(i==n) pos[i] = sz[i];
            else pos[i] = gcd(pos[i+1],sz[i]);
        }
        ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(i==1) ans = max(ans,pos[i+1]);
            else if(i==n) ans = max(ans,pre[i-1]);
            else ans = max(ans,gcd(pre[i-1],pos[i+1]));
        }
        printf("%d\n",ans);
    }
    return 0;
}
