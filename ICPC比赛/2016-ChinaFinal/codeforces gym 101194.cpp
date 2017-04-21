#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
ll n,m,k;
ll mod = 1e9+7;

ll pow_mod(ll a,ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int t;
    ll ans;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        ans = 0;
        scanf("%lld%lld%lld",&n,&m,&k);
        for(ll i=1;i<k;i++)
        {
            ans = (ans+pow_mod(i,n+m-2))%mod;
        }
        ans = ans*pow_mod(k,(n-1)*(m-1))%mod;
        ans = ans*n%mod*m%mod;
        ans = (ans+pow_mod(k,m*n))%mod;
        if(n==1&&m==1) ans=(ans+1)%mod;
        printf("Case #%d: %lld\n",ca,ans);
    }
    return 0;
}
