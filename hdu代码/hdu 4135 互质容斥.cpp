#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;

ll a,b,totle;
int n,m;
vector<int> f;

ll solve(ll x)
{
    ll ans = 0;
    for(ll i=1;i<=totle;i++)
    {
        int se=1,cnt=0;
        for(int j=0;j<m;j++)
        {
            if((i>>j)&1) se *= f[j],cnt++;
        }
        if(cnt&1) ans += x/se;
        else ans -= x/se;
    }
    return x-ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%lld%lld%d",&a,&b,&n);
        f.clear();
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                f.push_back(i);
                while(n%i==0) n /= i;
            }
        }
        if(n!=1) f.push_back(n);
        m = f.size();
        totle = (1<<m)-1;
        printf("Case #%d: %lld\n",ca,solve(b)-solve(a-1));
    }
    return 0;
}
