#include <bits/stdc++.h>
using namespace std;
#define time_ (printf("%.6f\n", double(clock())/CLOCKS_PER_SEC))
typedef long long ll;
const int INF =  0x3f3f3f3f;
const double pi = acos(-1.0);

const int maxn = 1e4+5;
int vis[maxn],prime[maxn],mu[maxn];
int sz[maxn],cnt[maxn];

void Moblus()
{
    memset(vis,0,sizeof(vis));
    int num=0;
    mu[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i])
        {
            prime[num++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<num && i*prime[j]<maxn;j++)
        {
            vis[prime[j]*i]=1;
            if(i%prime[j]==0)
            {
                mu[prime[j]*i]=0;
                break;
            }
            else mu[prime[j]*i]=-mu[i];
        }
    }
}

ll solve(int x)
{
    memset(sz,0,sizeof(sz));
    for(int i=1;i<=x;i++)
    {
        for(int j=i;j<=x;j+=i)
        {
            sz[i] += cnt[j];
        }
    }
    ll ans=0;
    for(int i=1;i<=x;i++)
    {
        if(sz[i]>=4)
        {
            ans += (ll)mu[i]*sz[i]*(sz[i]-1)*(sz[i]-2)*(sz[i]-3)/24;
        }
    }
    return ans;
}

int main()
{
    int n,m,tmp,ma;
    Moblus();
    while(~scanf("%d%d",&n,&m))
    {
        memset(cnt,0,sizeof(cnt));
        ma=0;
        for(int i=0;i<n*m;i++)
        {
            scanf("%d",&tmp);
            ++cnt[tmp];
            ma = max(ma,tmp);
        }
        if(n*m<4) printf("0\n");
        else printf("%lld\n",solve(ma));
    }
    return 0;
}
