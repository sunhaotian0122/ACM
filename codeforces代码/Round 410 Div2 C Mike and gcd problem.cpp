#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5+5;
ll n,sz[maxn];

ll gcd(ll a,ll b)
{
    return b==0 ? a : gcd(b,a%b);
}

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&sz[i]);
    ll g = sz[1];
    for(int i=2;i<=n;i++)
    {
        g = gcd(g,sz[i]);
    }
    if(g>1)
    {
        printf("YES\n0\n");
        return 0;
    }
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        if(sz[i]&1)
        {
            if(sz[i+1]&1)
            {
                ans++;
                sz[i+1] += sz[i];
            }
            else
            {
                ans += 2;
                sz[i+1] = 2*sz[i];
            }
        }
    }
    if(sz[n]&1) ans += 2;
    printf("YES\n%I64d\n",ans);
    return 0;
}
