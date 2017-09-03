#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
const int maxn = 1e6+5;
bool vis[maxn];
ll prime[maxn],mu[maxn],eular[maxn];
ll num[maxn],ans[maxn];
int n;

void Moblus_Eular()
{
    for(int i=1;i<maxn;i++)
    {
        for(int j=i;j<maxn;j+=i)
            num[j]++;
    }
    for(int i=2;i<maxn;i++)
    {
        num[i] += num[i-1];
        num[i] %= mod;
    }
    memset(vis,false,sizeof(vis));
    int cnt=0;
    mu[1]=1;
    eular[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i])
        {
            mu[i]=-1;
            eular[i] = i-1;
            prime[cnt++]=i;
        }
        for(int j=0;j<cnt && prime[j]*i<maxn;j++)
        {
            vis[prime[j]*i]=true;
            if(i%prime[j]==0)
            {
                mu[prime[j]*i]=0;
                eular[i*prime[j]] = eular[i]*prime[j];
                break;
            }
            else
            {
                mu[prime[j]*i] = -mu[i];
                eular[i*prime[j]] = eular[i]*(prime[j]-1);
            }
        }
    }
    for(int i=1;i<maxn;i++)
    {
        for(int j=i;j<maxn;j+=i)
        {
            ans[j] += (mu[j/i]*num[i])%mod;
            ans[j] %= mod;
        }
    }
    ans[1] = (ans[1]+eular[1]-1)%mod;
    for(int i=2;i<maxn;i++)
    {
        ans[i] = (ans[i]+eular[i]-1)%mod;
        ans[i] = (ans[i]+ans[i-1])%mod;
    }
}

int main()
{
    Moblus_Eular();
    while(~scanf("%d",&n))
    {
        printf("%lld\n",ans[n]);
    }
    return 0;
}
