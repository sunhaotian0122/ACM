#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxx;
void ex_gcd(ll a,ll b,ll &d,ll &x,ll &y)
{
    if(!b){d=a;x=1;y=0;}
    else{ex_gcd(b,a%b,d,y,x);y -= x*(a/b);}
}
ll solve(ll x,ll y)
{
    ll k,s,g;
    ex_gcd(2*n,-2*m,g,k,s);
    if((y-x)%g) return maxx+1;
    else
    {
        ll mod = (-2*m)/g;
        if(mod<0) mod = -mod;
        k *= (y-x)/g;
        k = (k%mod+mod)%mod;
        ll time=2*k*n+x;
        if(time<0||time>maxx) return maxx+1;
        return time;
    }
}
ll answer(ll x,ll y)
{
    ll g = __gcd(n,m);
    maxx = n / g * m;
    ll ans = maxx + 1;
    ans = min(ans,solve(-x,-y));
    ans = min(ans,solve(-x,y));
    ans = min(ans,solve(x,-y));
    ans = min(ans,solve(x,y));
    if(ans==maxx+1) return -1;
    else return ans;
}
int main()
{
    ll x,y,k;
    while(~scanf("%I64d%I64d%I64d",&n,&m,&k))
    {
        for(int i=0;i<k;i++)
        {
            scanf("%I64d%I64d",&x,&y);
            printf("%I64d\n",answer(x,y));
        }
    }
    return 0;
}
