#include <bits/stdc++.h>
using namespace std;
#define time_ (printf("%.6f\n", double(clock())/CLOCKS_PER_SEC))

typedef long long ll;
const int maxn = 1e5+5;

int mu[maxn],vis[maxn],prime[maxn];

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
        for(int j=0;j<num && prime[j]*i<maxn;j++)
        {
            vis[prime[j]*i]=1;
            if(i%prime[j]==0)
            {
                mu[prime[j]*i]=0;
                break;
            }
            else mu[prime[j]*i] = -mu[i];
        }
    }
}

int main()
{
    int T;
    int a,b,c,d,k;
    Moblus();
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k==0)
        {
            printf("Case %d: 0\n",ca);
            continue;
        }
        b /= k;
        d /= k;
        if(b>d) swap(b,d);
        ll ans=0,repeat=0;
        for(int i=1;i<=b;i++)
        {
            ans += (ll)mu[i]*(b/i)*(d/i);
            repeat += (ll)mu[i]*(b/i)*(b/i);
        }
        printf("Case %d: %lld\n",ca,ans-repeat/2);
    }
    return 0;
}
