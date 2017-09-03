#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 320005;
const int len = 1e5+5;
const int p_m = 105;
const int mod = 1e9+7;
ll l,r,k,prime[maxn];
int num;
ll dp[len][p_m],inv2;
bool isprime[maxn];
map<ll,int> mp;

ll pow_mod(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}

void get_Prime()
{
    num = 0;
    memset(isprime,true,sizeof(isprime));
    for(ll i=2;i<maxn;i++)
    {
        if(isprime[i])
        {
            prime[++num] = i;
            mp[i]=num;
        }
        for(int j=1;j<=num&&prime[j]*i<maxn;j++)
        {
            isprime[i*prime[j]] = false;
            if(i%prime[j]==0) break;
        }
    }
}

void init()
{
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<len;i++)
    {
        for(int j=0;j<p_m;j++)
        {
            if(j==0)
            {
                dp[i][j] = (i+1)*i/2;
                dp[i][j] %= mod;
            }
            else
            {
                dp[i][j] = dp[i][j-1]-prime[j]*dp[i/prime[j]][j-1]%mod;
                dp[i][j] = (dp[i][j]+mod)%mod;
            }
        }
    }
    inv2 = pow_mod(2,mod-2);
}

ll dfs(ll x,int a)
{
    if(x<len && a<p_m) return dp[x][a];
    if(a==0) return x%mod*(x%mod+1)%mod*inv2%mod;
    if(x<=1) return x;
    if(a && prime[a]>x)
    {
        while(a && prime[a]>x) a--;
        return dfs(x,a);
    }
    return (dfs(x,a-1)-prime[a]*dfs(x/prime[a],a-1)%mod+mod)%mod;
}

int main()
{
    int t;
    get_Prime();
    init();
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%lld%lld%lld",&l,&r,&k);
        printf("Case #%d: ",ca);
        if(k>=maxn)
        {
            bool flag = false;
            for(int i=1;i<=num && prime[i]*prime[i]<=k;i++)
            {
                if(k%prime[i]==0)
                {
                    flag=true;
                    break;
                }
            }
            if(flag) printf("0\n");
            else
            {
                if(k<=r && k>=l) printf("%lld\n",k%mod);
                else printf("0\n");
            }
        }
        else
        {
            ll ans;
            if(mp[k]>0)
            {
                ans = dfs(r/k,mp[k]-1)*k%mod-dfs((l-1)/k,mp[k]-1)*k%mod;
                ans = (ans+mod)%mod;
                printf("%lld\n",ans);
            }
            else printf("0\n");
        }
    }
    return 0;
}
