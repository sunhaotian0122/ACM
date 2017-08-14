#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;

const int maxn = 1e6+5;
const int mod = 998244353;
ll l,r,k,prime[maxn],num,sz[maxn],res[maxn];
bool isprime[maxn];

void get_Prime()
{
    num = 0;
    memset(isprime,true,sizeof(isprime));
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i]) prime[num++] = i;
        for(int j=0;j<num&&prime[j]*i<maxn;j++)
        {
            isprime[i*prime[j]] = false;
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    int t;
    get_Prime();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&l,&r,&k);
        for(ll i=l;i<=r;i++)
        {
            sz[i-l] = i;
            res[i-l] = 1;
        }
        for(int i=0;i<num&&prime[i]*prime[i]<=r;i++)
        {
            for(ll j=prime[i]*(l/prime[i]);j<=r;j+=prime[i])
            {
                if(j<l) continue;
                ll cnt=0;
                while(sz[j-l]%prime[i]==0)
                {
                    cnt++;
                    sz[j-l]/=prime[i];
                }
                res[j-l] = (res[j-l]*(cnt*k+1))%mod;
            }
        }
        ll ans=0;
        for(ll i=l;i<=r;i++)
        {
            if(sz[i-l]>1) res[i-l] = (res[i-l]*(k+1))%mod;
            ans = (ans+res[i-l])%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
